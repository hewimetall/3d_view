#include "test.h"

START_TEST(par_test1) {
  char path[50] = "/home/nooo_sm/s21_school/3d_view/tests/test.obj";
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

  ck_assert_float_eq(indices[1].v2.x, 0.5534);
  ck_assert_float_eq(indices[1].v2.y, -21.8682);
  ck_assert_float_eq(indices[1].v2.z, 31.5159);

  ck_assert_float_eq(indices[1].v3.x, 0.6134);
  ck_assert_float_eq(indices[1].v3.y, -21.9357);
  ck_assert_float_eq(indices[1].v3.z, 31.4441);

    ck_assert_float_eq(indices[2].v1.x, 0.5534);
  ck_assert_float_eq(indices[2].v1.y, -21.8682);
  ck_assert_float_eq(indices[2].v1.z, 31.5159);

  ck_assert_float_eq(indices[2].v2.x, 0.6134);
  ck_assert_float_eq(indices[2].v2.y, -21.9357);
  ck_assert_float_eq(indices[2].v2.z, 31.4441);

    ck_assert_float_eq(indices[2].v3.x, 0.6205);
  ck_assert_float_eq(indices[2].v3.y, -21.8541);
  ck_assert_float_eq(indices[2].v3.z, 31.4935);

  ck_assert_float_eq(indices[3].v1.x, 0);
  ck_assert_float_eq(indices[3].v1.y, 0);
  ck_assert_float_eq(indices[3].v1.z, 0);
  
  ck_assert_float_eq(indices[3].v2.x, 0);
  ck_assert_float_eq(indices[3].v2.y, 0);
  ck_assert_float_eq(indices[3].v2.z, 0);

  ck_assert_float_eq(indices[3].v3.x, 0);
  ck_assert_float_eq(indices[3].v3.y, 0);
  ck_assert_float_eq(indices[3].v3.z, 0);

  ck_assert_int_eq(count_index, 3);
}
END_TEST

START_TEST(par_test2) {
  char path[20] = "./none.obj";
  facet indices[1000] = {0};
  int count_index = parser_obj(path, indices);
  
  ck_assert_int_eq(count_index, 0);
}
END_TEST

START_TEST(scale_test) {
  Vector3 v = {6.454, -1000, 0};
  float scale = 0.1;
  v = scaleV(v, scale);
  ck_assert_float_eq(v.x, 0.6454);
  ck_assert_float_eq(v.y, -100);
  ck_assert_float_eq(v.z, 0);
}
END_TEST

START_TEST(move_test) {
  Vector3 v = {6.454, -1000, 0};
  Vector3 move = {-6, 0, 0.222};
  v = moveV(v, move);
  ck_assert_float_eq(v.x, 0.454);
  ck_assert_float_eq(v.y, -1000);
  ck_assert_float_eq(v.z, 0.222);
}
END_TEST

START_TEST(center_test) {
  Vector3 v1 = {6.5, -1000, 0};
  Vector3 v2 = {-6, 0, 0.222};
  Vector3 v = centerV(v1, v2);
  ck_assert_float_eq(v.x, 0.25);
  ck_assert_float_eq(v.y, -500);
  ck_assert_float_eq(v.z, 0.111);
}
END_TEST

START_TEST(mult_test) {
  Matrix3 m1 = {-10,0.25,666,0.25,666,-10,666,-10,0.25};
  Matrix3 m2 = {0, 3000, 1.1,1.1,0, 3000, 3000, 1.1, 0};
  Matrix3 result = Matrix3Multiply(m1, m2);
    ck_assert_float_eq(0.25, 0.25);
  ck_assert_float_eq(result.m0, 1998000.275) ;
    ck_assert_float_eq(result.m1, -29267.4);
    ck_assert_float_eq(result.m2, 739) ;
    ck_assert_float_eq(result.m3, -29267.4) ;
    ck_assert_float_eq(result.m4,739 );
    ck_assert_float_eq(result.m5, 1998000.275);
    ck_assert_float_eq(result.m6, 739 );
    ck_assert_float_eq(result.m7, 1998000.275);
    ck_assert_float_eq(result.m8, -29267.4);
}
END_TEST

// Matrix3 Matrix3RotateX(float angle){
//     Matrix3 result = { 1.0f, 0.0f, 0.0f,
//                        0.0f, cosf(angle), -sinf(angle),
//                        0.0f, sinf(angle), cosf(angle) };
//     return result;
// }

// Matrix3 Matrix3RotateY(float angle){
//     Matrix3 result = { cosf(angle), 0.0f, sinf(angle),
//                        0.0f, 1, 0.0f,
//                        -sinf(angle), 0, cosf(angle) };
//     return result;
// }

// Matrix3 Matrix3RotateZ(float angle){
//     Matrix3 result = { cosf(angle), -sinf(angle), 0.0f,
//                        sinf(angle), cosf(angle), 0.0f,
//                        0.0f, 0.0f, 1.0f};
//     return result;
// }


// Vector3 oper(Vector3 vec, Vector3 rotate) {
//     Matrix3 m3 = Matrix3Multiply(Matrix3Multiply(Matrix3RotateX(rotate.x),Matrix3RotateY(rotate.y)), Matrix3RotateZ(rotate.z));
//     return MATRIX3_MULTIPLY_VECTOR3(m3,vec);
// }


Suite *suite_s21_validate(void) {
  Suite *suite = suite_create("=== PARSING  TEST ===");
  TCase *tc = tcase_create("tc");

  tcase_add_test(tc, par_test1);
  tcase_add_test(tc, par_test2);
  tcase_add_test(tc, scale_test);
  tcase_add_test(tc, move_test);
  tcase_add_test(tc, center_test);
  tcase_add_test(tc, mult_test);
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