#include "test.h"
#include <unistd.h>

START_TEST(par_test1) {
  char path[20] = "../tests/test.obj";
  facet indices[1000] = {0};
  int count_index = parser_obj(path, indices);

  ck_assert_float_eq(indices[0].v1.x, 0.6134);
  ck_assert_float_eq(indices[0].v1.y, -21.9357);
  ck_assert_float_eq(indices[0].v1.z, 31.4441);

  ck_assert_float_eq(indices[0].v2.x, 0.6205);
  ck_assert_float_eq(indices[0].v2.y, -21.8541);
  ck_assert_float_eq(indices[0].v2.z, 31.4935);

  ck_assert_float_eq(indices[0].v3.x, 0.5534);
  ck_assert_float_eq(indices[0].v3.y, -21.8682);
  ck_assert_float_eq(indices[0].v3.z, 31.5159);

  ck_assert_float_eq(indices[1].v1.x, 0.6205);
  ck_assert_float_eq(indices[1].v1.y, -21.8541);
  ck_assert_float_eq(indices[1].v1.z, 31.4935);

  ck_assert_float_eq(indices[1].v2.x, 0);
  ck_assert_float_eq(indices[1].v2.y, 0);
  ck_assert_float_eq(indices[1].v2.z, 0);

  ck_assert_float_eq(indices[1].v3.x, 0);
  ck_assert_float_eq(indices[1].v3.y, 0);
  ck_assert_float_eq(indices[1].v3.z, 0);

    ck_assert_float_eq(indices[2].v1.x, 0);
  ck_assert_float_eq(indices[2].v1.y, 0);
  ck_assert_float_eq(indices[2].v1.z, 0);

  ck_assert_float_eq(indices[2].v2.x, 0);
  ck_assert_float_eq(indices[2].v2.y, 0);
  ck_assert_float_eq(indices[2].v2.z, 0);

  ck_assert_float_eq(indices[2].v3.x, 0);
  ck_assert_float_eq(indices[2].v3.y, 0);
  ck_assert_float_eq(indices[2].v3.z, 0);
  // ck_assert_int_eq(inp.len, res_len);
  ck_assert_int_eq(0, 0);
  // ck_assert_double_eq_tol(res, true, TEST_EPS);
}
END_TEST

// START_TEST(par_test1) {
//   char path[20] = "./none.obj";
//   indices = calloc(1,sizeof(face)*1000000);
//   count_index = parser_obj(filePaths, indices);
  
//   ck_assert_int_eq(strcmp(inp.str, res_str), 0);
//   ck_assert_int_eq(inp.len, res_len);
//   ck_assert_int_eq(err, 0);
//   ck_assert_double_eq_tol(res, true, TEST_EPS);
// }
// END_TEST


Suite *suite_s21_validate(void) {
  Suite *suite = suite_create("=== PARSING  TEST ===");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, par_test1);
  // tcase_add_test(tc, par_test2);
  // tcase_add_test(tc, par_test3);
  // tcase_add_test(tc, par_test4);
  // tcase_add_test(tc, par_test5);
  // tcase_add_test(tc, par_test6);
  // tcase_add_test(tc, par_test7);
  // tcase_add_test(tc, par_test8);
  // tcase_add_test(tc, par_test9);
  // tcase_add_test(tc, par_test10);
  // tcase_add_test(tc, par_test11);
  // tcase_add_test(tc, par_test12);
  // tcase_add_test(tc, par_test13);
  // tcase_add_test(tc, par_test14);
  // tcase_add_test(tc, par_test15);
  // tcase_add_test(tc, par_test16);

  suite_add_tcase(suite, tc);

  return suite;
}