#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum priority {
  number_x = 0,
  add_sub = 1,  // -+
  Mod = 2,      // Mod * /
  POW = 3,      // ^
  trig = 4,     // type 8-16
};

typedef enum {
  und = -1,
  number = 0,    // '0-9'
  x,             // 'X'
  add,           // '+'
  sub,           // '-'
  Div,           // '/'
  mul = 5,       // '*'
  MOD,           // 'Mod'
  Pow,           // '^'
  Sin,           // sin(x)
  Cos,           // cos(x)
  Tan = 10,      // tan(x)
  Acos,          // acos(x)
  Asin,          // asin(x)
  Atan,          // atan(x)
  Sqrt,          // sqrt(x)
  Ln = 15,       // ln(x)
  Log,           // log(x)
  OpenBracket,   // '('
  CloseBracket,  // ')'
} type;

typedef struct Node Node;

struct Node {
  double value;
  int priority;
  int type;
  Node* next;
};

double s21_calc(char* str, double x);
Node* pushback(Node* head, double value, type type, int priority);
Node* revers_stack(Node* stack);
Node* popback(Node* New);
type peak_type(Node* New);
type peak_priority(Node* New);
double calculate(Node* stack);
