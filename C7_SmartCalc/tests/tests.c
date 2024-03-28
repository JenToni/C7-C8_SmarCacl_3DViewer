#include "tests.h"
double result = 0.0;

START_TEST(test_plus) {
  char str[256] = "1.25+3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(1.25 + 3.45, result);
}
END_TEST

START_TEST(test_minus) {
  char str[256] = "1.25-3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(1.25 - 3.45, result);
}
END_TEST

START_TEST(test_mult) {
  char str[256] = "1.25*3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(1.25 * 3.45, result);
}
END_TEST

START_TEST(test_mult2) {
  char str[256] = "3*(4+7)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(3 * (4 + 7), result);
}
END_TEST

START_TEST(test_div) {
  char str[256] = "1.25/3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(1.25 / 3.45, result);
}
END_TEST

START_TEST(test_mod) {
  char str[256] = "1.25mod3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(fmod(1.25, 3.45), result);
}
END_TEST

START_TEST(test_pow) {
  char str[256] = "1.25^3.45";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(powf(1.25, 3.45), result);
}
END_TEST

START_TEST(test_x) {
  char str[256] = "x";
  result = s21_calc(str, 2.22);
  ck_assert_float_eq(result, 2.22);
}
END_TEST

START_TEST(test_brackets) {
  char str[256] = "(+5.23+1.25)*(0.25+0.001)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq((5.23 + 1.25) * (0.25 + 0.001), result);
}
END_TEST

START_TEST(test_sin) {
  char str[256] = "sin((5.23+1.25)*(0.25+0.001))";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(sin((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(test_cos) {
  char str[256] = "cos((5.23+1.25)*(0.25+0.001))";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(cos((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(test_tan) {
  char str[256] = "tan((5.23+1.25)*(0.25+0.001))";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(tan((5.23 + 1.25) * (0.25 + 0.001)), result);
}
END_TEST

START_TEST(test_asin) {
  char str[256] = "asin(7/7.7)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(asin(7 / 7.7), result);
}
END_TEST

START_TEST(test_acos) {
  char str[256] = "acos(7/7.7)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(acos(7 / 7.7), result);
}
END_TEST

START_TEST(test_atan) {
  char str[256] = "atan(7/7.7)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(atan(7 / 7.7), result);
}
END_TEST

START_TEST(test_sqrt) {
  char str[256] = "sqrt(1357-245)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(sqrt(1357 - 245), result);
}
END_TEST

START_TEST(test_ln) {
  char str[256] = "ln(1357-245)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(log(1357 - 245), result);
}
END_TEST

START_TEST(test_log) {
  char str[256] = "log(1357-245)";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(log10(1357 - 245), result);
}
END_TEST

START_TEST(test_combo) {
  char str[256] = "log(32+1)*7/11*432*(sin(2)*12-45+4)/2";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(log10(32 + 1) * 7 / 11 * 432 * (sin(2) * 12 - 45 + 4) / 2,
                     result);
}
END_TEST

START_TEST(test_combo_func) {
  char str[256] = "cos(sin(tan(-0.005)))";
  result = s21_calc(str, 0.0);
  ck_assert_float_eq(cos(sin(tan(-0.005))), result);
}
END_TEST

START_TEST(test_invalid_expr) {
  int ret = 0;
  char *expr = "log(32+1)*7/11*432*(sin(2)*12-45+4/2";
  ret = validate_str(expr);
  ck_assert_int_eq(ret, 0);

  char *str1 = "+";
  ret = validate_str(str1);
  ck_assert_int_eq(ret, 0);

  char *str2 = "++";
  ret = validate_str(str2);
  ck_assert_int_eq(ret, 0);

  char *str3 = ".";
  ret = validate_str(str3);
  ck_assert_int_eq(ret, 0);

  char *str4 = "2q";
  ret = validate_str(str4);
  ck_assert_int_eq(ret, 0);

  char *str5 = "1..";
  ret = validate_str(str5);
  ck_assert_int_eq(ret, 0);

  char *str7 = "m.^";
  ret = validate_str(str7);
  ck_assert_int_eq(ret, 0);

  char *str8 = "$m";
  ret = validate_str(str8);
  ck_assert_int_eq(ret, 0);

  char *str9 = "5mp";
  ret = validate_str(str9);
  ck_assert_int_eq(ret, 0);

  char *str10 = ")Q";
  ret = validate_str(str10);
  ck_assert_int_eq(ret, 0);

  char *str11 = "+-";
  ret = validate_str(str11);
  ck_assert_int_eq(ret, 0);

  char *str13 = "mod+";
  ret = validate_str(str13);
  ck_assert_int_eq(ret, 0);

  char *str14 = "1+ 2      -3";
  ret = validate_str(str14);
  ck_assert_int_eq(ret, 1);

  char *str16 = "x2";
  ret = validate_str(str16);
  ck_assert_int_eq(ret, 0);

  char *str17 = "x^2";
  ret = validate_str(str17);
  ck_assert_int_eq(ret, 1);

  char *str18 = "x^- ";
  ret = validate_str(str18);
  ck_assert_int_eq(ret, 0);

  char *str19 = "cos(cos(x))";
  ret = validate_str(str19);
  ck_assert_int_eq(ret, 1);

  char *str20 =
      "cos((20.2 - 10) * (10mod5 - 10^2) / 10.10 + 1 - cos(x - (10*9+ "
      "sin(2-10 - tan(x)))))";
  ret = validate_str(str20);
  ck_assert_int_eq(ret, 1);

  char *str21 =
      "cos((20..2 - 10) * (10mod.5 - 10.^2) / 10.10 + 1 - cos(x - (10*9+ "
      "sin(2-10))))";
  ret = validate_str(str21);
  ck_assert_int_eq(ret, 0);

  char *str22 =
      "cos((20.2 - 10) * (10mod5 - 10^2) / 10.10^ + 1 - cos(x - (10*9+ "
      "sin(2-10))))";
  ret = validate_str(str22);
  ck_assert_int_eq(ret, 0);

  char *str23 = "()+2";
  ret = validate_str(str23);
  ck_assert_int_eq(ret, 0);

  char *str24 = "ln(2)";
  ret = validate_str(str24);
  ck_assert_int_eq(ret, 1);

  char *str25 = "asin(2)";
  ret = validate_str(str25);
  ck_assert_int_eq(ret, 1);

  char *str26 = "2 + (2 - 2) *";
  ret = validate_str(str26);
  ck_assert_int_eq(ret, 0);

  char *str27 = "x1";
  ret = validate_str(str27);
  ck_assert_int_eq(ret, 0);

  char *str28 = "tan(2 - x^^-)";
  ret = validate_str(str28);
  ck_assert_int_eq(ret, 0);

  char *str29 = "2^-";
  ret = validate_str(str29);
  ck_assert_int_eq(ret, 0);
}
END_TEST

Suite *tests(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_plus);
  tcase_add_test(tc_core, test_minus);
  tcase_add_test(tc_core, test_mult);
  tcase_add_test(tc_core, test_mult2);
  tcase_add_test(tc_core, test_div);
  tcase_add_test(tc_core, test_mod);
  tcase_add_test(tc_core, test_pow);
  tcase_add_test(tc_core, test_x);
  tcase_add_test(tc_core, test_brackets);
  tcase_add_test(tc_core, test_sin);
  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_tan);
  tcase_add_test(tc_core, test_asin);
  tcase_add_test(tc_core, test_acos);
  tcase_add_test(tc_core, test_atan);
  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_ln);
  tcase_add_test(tc_core, test_log);
  tcase_add_test(tc_core, test_combo);
  tcase_add_test(tc_core, test_combo_func);
  tcase_add_test(tc_core, test_invalid_expr);

  suite_add_tcase(s, tc_core);

  return s;
}
