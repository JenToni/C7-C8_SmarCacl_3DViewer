#include "stack.h"

double calculate(Node* stack) {
  Node* buff = NULL;
  double answer = 0;

  while (stack != NULL) {
    double number = 0;
    while (stack != NULL ? stack->priority == 0 : stack != NULL) {
      buff = pushback(buff, stack->value, stack->type, stack->priority);
      stack = popback(stack);
    }
    number = buff->value;
    if (buff->next != NULL && peak_type(stack) <= 7) {
      buff = popback(buff);
    }
    if (peak_type(stack) == add) {
      buff->value += number;
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == sub) {
      buff->value -= number;
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Div) {
      buff->value /= number;
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == mul) {
      buff->value *= number;
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == MOD) {
      buff->value = fmod(buff->value, number);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Pow) {
      buff->value = powf(buff->value, number);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Sin) {
      buff->value = sin(buff->value);
      stack = popback(stack);
      continue;
    }

    if (peak_type(stack) == Cos) {
      buff->value = cos(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Tan) {
      buff->value = tan(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Acos) {
      buff->value = acos(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Asin) {
      buff->value = asin(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Atan) {
      buff->value = atan(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Sqrt) {
      buff->value = sqrt(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Ln) {
      buff->value = log(buff->value);
      stack = popback(stack);
      continue;
    }
    if (peak_type(stack) == Log) {
      buff->value = log10(buff->value);
      stack = popback(stack);
      continue;
    }
  }
  answer = buff->value;
  while (buff) {
    buff = popback(buff);
  }
  return answer;
}
