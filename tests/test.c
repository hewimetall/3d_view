#define _POSIX_C_SOURCE 200809L

#include "test.h"

#include <math.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

static int failures = 0;

static void fail(const char *file, int line, const char *fmt, ...) {
  va_list args;
  failures++;
  fprintf(stderr, "%s:%d: ", file, line);
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fputc('\n', stderr);
}

#define ASSERT_TRUE(expr) \
  do { \
    if (!(expr)) fail(__FILE__, __LINE__, "expected true: %s", #expr); \
  } while (0)

#define ASSERT_INT_EQ(actual, expected) \
  do { \
    int actual_value = (actual); \
    int expected_value = (expected); \
    if (actual_value != expected_value) { \
      fail(__FILE__, __LINE__, "expected %s == %d, got %d", #actual, expected_value, actual_value); \
    } \
  } while (0)

#define ASSERT_FLOAT_NEAR(actual, expected) \
  do { \
    double actual_value = (actual); \
    double expected_value = (expected); \
    if (fabs(actual_value - expected_value) > 0.0001) { \
      fail(__FILE__, __LINE__, "expected %s ~= %.6f, got %.6f", #actual, expected_value, actual_value); \
    } \
  } while (0)

static char *write_fixture(const char *contents) {
  char *path = strdup("/tmp/s21_view3d_obj_XXXXXX");
  ASSERT_TRUE(path != NULL);

  int fd = mkstemp(path);
  ASSERT_TRUE(fd >= 0);

  FILE *file = fdopen(fd, "w");
  ASSERT_TRUE(file != NULL);
  fputs(contents, file);
  fclose(file);
  return path;
}

static void test_parser_reads_supported_face_formats(void) {
  char *path = write_fixture(
      "# cube corner\n"
      "v 1.0 2.0 3.0\n"
      "v -4.5 5.25 6.75\n"
      "v 7.0 -8.0 9.0\n"
      "v 10.0 11.0 -12.0\n"
      "vt 0.1 0.2\n"
      "vn 0.0 1.0 0.0\n"
      "f 1/1/1 2/1/1 3/1/1\n"
      "f 1//1 3//1 4//1\n"
      "f 2 3 4\n");
  facet indices[4] = {0};

  ASSERT_INT_EQ(parser_obj(path, indices), 3);
  ASSERT_FLOAT_NEAR(indices[0].v1.x, 1.0);
  ASSERT_FLOAT_NEAR(indices[0].v2.y, 5.25);
  ASSERT_FLOAT_NEAR(indices[0].v3.z, 9.0);
  ASSERT_FLOAT_NEAR(indices[1].v2.x, 7.0);
  ASSERT_FLOAT_NEAR(indices[1].v3.z, -12.0);
  ASSERT_FLOAT_NEAR(indices[2].v1.x, -4.5);
  ASSERT_FLOAT_NEAR(indices[2].v2.y, -8.0);
  ASSERT_FLOAT_NEAR(indices[2].v3.x, 10.0);

  unlink(path);
  free(path);
}

static void test_parser_skips_invalid_lines_and_indices(void) {
  char *path = write_fixture(
      "o ignored-name\n"
      "f 1 2 3\n"
      "v 0 0 0\n"
      "v 1 0 0\n"
      "v 0 1 0\n"
      "v bad vertex\n"
      "f 1 2\n"
      "f 0 2 3\n"
      "f 1 2 9\n"
      "f 1/x/1 2/1/1 3/1/1\n"
      "f 1 2 3\n");
  facet indices[2] = {0};

  ASSERT_INT_EQ(parser_obj(path, indices), 1);
  ASSERT_FLOAT_NEAR(indices[0].v1.x, 0.0);
  ASSERT_FLOAT_NEAR(indices[0].v2.x, 1.0);
  ASSERT_FLOAT_NEAR(indices[0].v3.y, 1.0);

  unlink(path);
  free(path);
}

static void test_parser_missing_file_returns_zero(void) {
  facet indices[1] = {0};

  ASSERT_INT_EQ(parser_obj("/tmp/s21_view3d_missing.obj", indices), 0);
}

static void test_vector_helpers(void) {
  Vector3 scaled = scaleV((Vector3){6.454f, -1000.0f, 0.0f}, 0.1f);
  ASSERT_FLOAT_NEAR(scaled.x, 0.6454);
  ASSERT_FLOAT_NEAR(scaled.y, -100.0);
  ASSERT_FLOAT_NEAR(scaled.z, 0.0);

  Vector3 moved = moveV((Vector3){6.454f, -1000.0f, 0.0f}, (Vector3){-6.0f, 0.0f, 0.222f});
  ASSERT_FLOAT_NEAR(moved.x, 0.454);
  ASSERT_FLOAT_NEAR(moved.y, -1000.0);
  ASSERT_FLOAT_NEAR(moved.z, 0.222);

  Vector3 centered = centerV((Vector3){6.5f, -1000.0f, 0.0f}, (Vector3){-6.0f, 0.0f, 0.222f});
  ASSERT_FLOAT_NEAR(centered.x, 0.25);
  ASSERT_FLOAT_NEAR(centered.y, -500.0);
  ASSERT_FLOAT_NEAR(centered.z, 0.111);
}

static void test_matrix_math(void) {
  Matrix3 m1 = {-10.0f, 0.25f, 666.0f, 0.25f, 666.0f, -10.0f, 666.0f, -10.0f, 0.25f};
  Matrix3 m2 = {0.0f, 3000.0f, 1.1f, 1.1f, 0.0f, 3000.0f, 3000.0f, 1.1f, 0.0f};
  Matrix3 result = Matrix3Multiply(m1, m2);

  ASSERT_FLOAT_NEAR(result.m0, 1998000.25);
  ASSERT_FLOAT_NEAR(result.m1, -29267.4);
  ASSERT_FLOAT_NEAR(result.m2, 739.0);
  ASSERT_FLOAT_NEAR(result.m3, -29267.4);
  ASSERT_FLOAT_NEAR(result.m4, 739.0);
  ASSERT_FLOAT_NEAR(result.m5, 1998000.25);
  ASSERT_FLOAT_NEAR(result.m6, 739.0);
  ASSERT_FLOAT_NEAR(result.m7, 1998000.25);
  ASSERT_FLOAT_NEAR(result.m8, -29267.4);

  Vector3 unchanged = oper((Vector3){6.5f, -1000.0f, 0.0f}, (Vector3){0.0f, 0.0f, 0.0f});
  ASSERT_FLOAT_NEAR(unchanged.x, 6.5);
  ASSERT_FLOAT_NEAR(unchanged.y, -1000.0);
  ASSERT_FLOAT_NEAR(unchanged.z, 0.0);

  Vector3 around_x = oper((Vector3){0.0f, 1.0f, 0.0f}, (Vector3){(float)M_PI_2, 0.0f, 0.0f});
  ASSERT_FLOAT_NEAR(around_x.x, 0.0);
  ASSERT_FLOAT_NEAR(around_x.y, 0.0);
  ASSERT_FLOAT_NEAR(around_x.z, -1.0);

  Vector3 around_y = oper((Vector3){0.0f, 0.0f, 1.0f}, (Vector3){0.0f, (float)M_PI_2, 0.0f});
  ASSERT_FLOAT_NEAR(around_y.x, -1.0);
  ASSERT_FLOAT_NEAR(around_y.y, 0.0);
  ASSERT_FLOAT_NEAR(around_y.z, 0.0);

  Vector3 around_z = oper((Vector3){1.0f, 0.0f, 0.0f}, (Vector3){0.0f, 0.0f, (float)M_PI_2});
  ASSERT_FLOAT_NEAR(around_z.x, 0.0);
  ASSERT_FLOAT_NEAR(around_z.y, -1.0);
  ASSERT_FLOAT_NEAR(around_z.z, 0.0);
}

static void test_input_validation(void) {
  ASSERT_INT_EQ(chrbrk('4', "12345"), 0);
  ASSERT_INT_EQ(chrbrk('x', "12345"), 1);
  ASSERT_FLOAT_NEAR(validVal("123.5"), 123.5);
  ASSERT_FLOAT_NEAR(validVal("-0.25"), -0.25);
  ASSERT_FLOAT_NEAR(validVal("0"), 0.0);
  ASSERT_FLOAT_NEAR(validVal(""), 0.0);
  ASSERT_FLOAT_NEAR(validVal("12.3.4"), 0.0);
  ASSERT_FLOAT_NEAR(validVal("1-2"), 0.0);
  ASSERT_FLOAT_NEAR(validVal("abc"), 0.0);
}

int main(void) {
  test_parser_reads_supported_face_formats();
  test_parser_skips_invalid_lines_and_indices();
  test_parser_missing_file_returns_zero();
  test_vector_helpers();
  test_matrix_math();
  test_input_validation();

  if (failures != 0) {
    fprintf(stderr, "%d test assertion(s) failed\n", failures);
    return 1;
  }

  puts("All unit tests passed");
  return 0;
}