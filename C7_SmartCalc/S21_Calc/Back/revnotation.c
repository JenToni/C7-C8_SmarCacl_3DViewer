
#include "stack.h"

Node* revnotation(Node* stack) {
  Node* s_ready = NULL;
  Node* s_sup = NULL;

  while (stack != NULL) {
    if (peak_priority(stack) == number_x) {
      s_ready = pushback(s_ready, stack->value, stack->type, stack->priority);
      stack = popback(stack);
      continue;
    }
    if (peak_priority(stack) != number_x && peak_type(stack) != OpenBracket &&
        peak_type(stack) != CloseBracket) {
      if (peak_priority(stack) <= peak_priority(s_sup) && s_sup &&
          peak_priority(s_sup) != und) {
        while (peak_priority(stack) <= peak_priority(s_sup) && s_sup &&
               peak_priority(s_sup) != und) {
          s_ready =
              pushback(s_ready, s_sup->value, s_sup->type, s_sup->priority);
          s_sup = popback(s_sup);
        }
        continue;
      } else
        s_sup = pushback(s_sup, stack->value, stack->type, stack->priority);
    }
    if (peak_type(stack) == OpenBracket) {
      s_sup = pushback(s_sup, stack->value, stack->type, stack->priority);
    }
    if (peak_type(stack) == CloseBracket) {
      while (s_sup->type != OpenBracket) {
        s_ready = pushback(s_ready, s_sup->value, s_sup->type, s_sup->priority);
        s_sup = popback(s_sup);
      }
      s_sup = popback(s_sup);
    }
    stack = popback(stack);
  }

  while (s_sup != NULL) {
    s_ready = pushback(s_ready, s_sup->value, s_sup->type, s_sup->priority);
    s_sup = popback(s_sup);
  }
  Node* rev_stack = revers_stack(s_ready);
  while (s_ready != NULL) s_ready = popback(s_ready);

  while (stack != NULL) stack = popback(stack);

  return rev_stack;
}