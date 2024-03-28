#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum exam { ERROR, OK };
int search_trig(char *str, int *i);
int search_in_trig(char *str, int *i, int *result);
int examination(char *str);
int validate_str(char *str);
int check_symbol(char *str);
int modd(char *str, int *i);
