
#include "stack.h"

Node* parser(char* str, double x) {
  Node* stack = NULL;
  char pars_str[256];
  int len = strlen(str);
  for (int i = 0, p = 0; i < len; i++) {
    if (strchr("0123456789.", str[i]) != NULL) {
      pars_str[p++] = str[i];
      if ((strchr("0123456789.", str[i + 1]) == NULL) || (i + 1 == len)) {
        stack = pushback(stack, atof(pars_str), number, number_x);
        memset(pars_str, 0, p + 1);
        p = 0;
        continue;
      }
    } else if (str[i] == 'x') {
      stack = pushback(stack, x, number, number_x);
    } else if (str[i] == '(') {
      if (strchr("0123456789", str[i + 1]) != NULL && str[i + 1] != '-' &&
          str[i + 1] != '+') {
        stack = pushback(stack, 0, OpenBracket, -1);
        stack = pushback(stack, 0, number, number_x);
        stack = pushback(stack, 0, add, add_sub);
      } else
        stack = pushback(stack, 0, OpenBracket, -1);
    } else if (str[i] == ')')
      stack = pushback(stack, 0, CloseBracket, -1);
    else if (str[i] == '+') {
      if (peak_type(stack) == OpenBracket || peak_type(stack) == und) {
        stack = pushback(stack, 0, number, number_x);
        stack = pushback(stack, 0, add, add_sub);
      } else
        stack = pushback(stack, 0, add, add_sub);
    } else if (str[i] == '-') {
      if (peak_type(stack) == OpenBracket || peak_type(stack) == und) {
        stack = pushback(stack, 0, number, number_x);
        stack = pushback(stack, 0, sub, add_sub);
      } else
        stack = pushback(stack, 0, sub, add_sub);
    } else if (str[i] == '*')
      stack = pushback(stack, 0, mul, Mod);
    else if (str[i] == '/')
      stack = pushback(stack, 0, Div, Mod);
    else if (str[i] == '^')
      stack = pushback(stack, 0, Pow, POW);
    else if (strncmp(str + i, "sin", 3) == 0) {
      i += 2;
      stack = pushback(stack, 0, Sin, trig);
    } else if (strncmp(str + i, "cos", 3) == 0) {
      i += 2;
      stack = pushback(stack, 0, Cos, trig);
    } else if (strncmp(str + i, "tan", 3) == 0) {
      i += 2;
      stack = pushback(stack, 0, Tan, trig);
    } else if (strncmp(str + i, "asin", 4) == 0) {
      i += 3;
      stack = pushback(stack, 0, Asin, trig);
    } else if (strncmp(str + i, "acos", 4) == 0) {
      i += 3;
      stack = pushback(stack, 0, Acos, trig);
    } else if (strncmp(str + i, "atan", 4) == 0) {
      i += 3;
      stack = pushback(stack, 0, Atan, trig);
    } else if (strncmp(str + i, "sqrt", 4) == 0) {
      i += 3;
      stack = pushback(stack, 0, Sqrt, trig);
    } else if (strncmp(str + i, "ln", 2) == 0) {
      i += 1;
      stack = pushback(stack, 0, Ln, trig);
    } else if (strncmp(str + i, "log", 3) == 0) {
      i += 2;
      stack = pushback(stack, 0, Log, trig);
    } else if (strncmp(str + i, "mod", 3) == 0) {
      i += 2;
      stack = pushback(stack, 0, MOD, Mod);
    }
  }
  Node* rev_stack = revers_stack(stack);
  while (stack != NULL) stack = popback(stack);
  return rev_stack;
}