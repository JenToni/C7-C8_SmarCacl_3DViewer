#include "stack.h"

Node* pushback(Node* head, double value, type type, int priority) {
  Node* new = (Node*)malloc(sizeof(Node));
  new->next = head;
  new->priority = priority;
  new->type = type;
  new->value = value;
  return new;
}

Node* push_all(Node* stack_old, Node* stack_new) {
  Node* p = (Node*)malloc(sizeof(Node));
  p->priority = stack_old->priority;
  p->type = stack_old->type;
  p->value = stack_old->value;
  p->next = stack_old = stack_new;
  return p;
}

Node* revers_stack(Node* stack) {
  Node* p = stack;
  Node* new_stack = NULL;
  while (p) {
    new_stack = push_all(p, new_stack);
    p = p->next;
  }
  return new_stack;
}

Node* popback(Node* New) {
  if (!New)
    return NULL;
  else {
    Node* Old = New->next;
    free(New);
    return Old;
  }
}

type peak_type(Node* New) {
  type type = -1;
  if (New != NULL) type = New->type;
  return type;
}

type peak_priority(Node* New) {
  type priority = -1;
  if (New != NULL) priority = New->priority;
  return priority;
}
