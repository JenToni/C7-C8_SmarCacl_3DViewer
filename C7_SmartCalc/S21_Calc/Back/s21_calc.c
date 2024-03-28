
#include "stack.h"

Node* parser(char* str, double x);
Node* revnotation(Node* stack);
int validate_str(char* str);

double s21_calc(char* str, double x) {
  double answer = 0;

  answer = calculate(revnotation(parser(str, x)));

  return answer;
}
