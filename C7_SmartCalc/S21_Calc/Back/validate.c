#include "validate.h"

int validate_str(char *str) {
  int len = strlen(str);
  char new_str[len];
  int answer = ERROR;
  int i = 0, t = 0;
  // удаляем пробелы
  while (i < len) {
    if (str[i] == ' ')
      i++;
    else
      new_str[t++] = str[i++];
  }
  new_str[t] = '\0';
  answer = check_symbol(new_str);
  if (answer) answer = examination(new_str);
  return answer;
}

// проврека строки на символы
int check_symbol(char *str) {
  int answer = OK;
  int len = strlen(str);
  for (int i = 0; i < len && answer; i++) {
    if (strchr(".0123456789+-x*/()^", str[i]) == NULL &&
        !search_trig(str, &i) && !modd(str, &i))
      answer = ERROR;
  }
  return answer;
}
int modd(char *str, int *i) {
  int t = *i;
  int result = ERROR;
  if (strncmp(str + t, "mod", 3) == 0) {
    *i += 2;
    result = OK;
  }
  return result;
}

int examination(char *str) {
  int result = OK;
  int point = 0;
  int open_bracket = 0;
  int clouse_bracket = 0;
  int len = strlen(str);
  for (int i = 0; i < len && result; i++) {
    if (strchr("0123456789", str[i]) != NULL) {
      if (strchr("0123456789*/+-^.m)", str[i + 1]) == NULL) result = ERROR;
    } else if (strchr(".", str[i]) != NULL) {
      if (strchr("0123456789", str[i + 1]) == NULL || point ||
          strchr("0123456789", str[i - 1]) == NULL || i == 0)
        result = ERROR;
      point = 1;
    } else if (strchr("x", str[i]) != NULL) {
      if (strchr("*/+-^m)", str[i + 1]) == NULL) {
        result = ERROR;
      }
    } else if (strchr("+-*/^", str[i]) != NULL) {
      point = 0;
      if (strchr("0123456789sctalmx(", str[i + 1]) == NULL || (i + 1 >= len))
        result = ERROR;
    } else if (strchr("x", str[i]) != NULL) {
      if (strchr("*/+-^.m)", str[i + 1]) == NULL) result = ERROR;
    } else if (strchr("(", str[i]) != NULL) {
      open_bracket++;
      if (strchr("0123456789(+-cstalmx", str[i + 1]) == NULL) result = ERROR;
    } else if (strchr(")", str[i]) != NULL) {
      clouse_bracket++;
      if (strchr(")+-*/^", str[i + 1]) == NULL)
        result = ERROR;
      else if (i + 1 == len)
        result = OK;
    } else if (strchr("^", str[i]) != NULL) {
      if (strchr("0123456789(+-ctsalx", str[i + 1]) == NULL) result = ERROR;
    } else if (strncmp(str + i, "mod", 3) == 0) {
      i += 3;
      if (strchr("0123456789(+-cstalx", str[i]) == NULL || i == len)
        result = ERROR;

    } else if (search_trig(str, &i) == OK) {
      if (i + 1 >= len || strchr(")", str[i + 1]) != NULL)
        result = ERROR;
      else {
        i++;
        result = search_in_trig(str, &i, &result);
        i--;
      }
    }
  }
  if (open_bracket != clouse_bracket) result = ERROR;
  return result;
}

int search_in_trig(char *str, int *i, int *result) {
  int point = 0;
  int clouse_bracket = 0;
  int open_bracket = 1;
  int len = strlen(str);
  for (int t = 0; open_bracket != clouse_bracket && *result; (*i)++, t++) {
    if (strchr("0123456789", str[*i]) != NULL) {
      if (strchr("0123456789*/+-^.m)", str[*i + 1]) == NULL) *result = ERROR;
    } else if (strchr(".", str[*i]) != NULL) {
      if (strchr("0123456789", str[*i + 1]) == NULL || point ||
          strchr("0123456789", str[*i - 1]) == NULL || t == 0)
        *result = ERROR;
      point = 1;
    } else if (strchr("+-*/^", str[*i]) != NULL) {
      point = 0;
      if (strchr("0123456789cstalmx(", str[*i + 1]) == NULL || (*i + 1 >= len))
        *result = ERROR;
    } else if (strchr("x", str[*i]) != NULL) {
      if (strchr("*/+-^m)", str[*i + 1]) == NULL) {
        *result = ERROR;
      }
    } else if (strchr("(", str[*i]) != NULL) {
      open_bracket++;
      if (strchr("0123456789(+-cstalx", str[*i + 1]) == NULL) *result = ERROR;
    } else if (strchr(")", str[*i]) != NULL) {
      clouse_bracket++;
      if (strchr(")+-*/^", str[*i + 1]) == NULL)
        *result = ERROR;
      else if (*i + 1 == len)
        *result = OK;
    } else if (strchr("^", str[*i]) != NULL) {
      if (strchr("0123456789(+-cstalx", str[*i + 1]) == NULL) *result = ERROR;
    } else if (strncmp(str + (*i), "mod", 3) == 0) {
      *i += 3;
      if (strchr("0123456789(+-cstalx", str[*i]) == NULL) *result = ERROR;
    } else if (strchr("csta", str[*i]) != NULL && search_trig(str, i) == OK) {
      if (*i + 1 >= len)
        *result = ERROR;
      else {
        (*i)++;
        *result = search_in_trig(str, i, result);
        (*i)--;
      }
    }
  }
  return *result;
}

int search_trig(char *str, int *i) {
  int t = *i;
  int result = ERROR;
  if ((strncmp(str + t, "cos(", 4) == 0) ||
      (strncmp(str + t, "sin(", 4) == 0) ||
      (strncmp(str + t, "tan(", 4) == 0) ||
      (strncmp(str + t, "log(", 4) == 0)) {
    *i += 3;
    result = OK;
  } else if ((strncmp(str + t, "acos(", 5) == 0) ||
             (strncmp(str + t, "asin(", 5) == 0) ||
             (strncmp(str + t, "atan(", 5) == 0) ||
             (strncmp(str + t, "sqrt(", 5) == 0)) {
    *i += 4;
    result = OK;
  } else if (strncmp(str + t, "ln(", 3) == 0) {
    *i += 2;
    result = OK;
  }
  return result;
}
