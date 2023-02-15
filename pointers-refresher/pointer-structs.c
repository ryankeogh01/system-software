#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int year;
  int month;
  int day;
} date;

int main(void) {

  date *today;
  today = (date*)malloc(sizeof(date));

  // the explicit way of accessing fields of our struct
  (*today).day = 15;
  (*today).month = 6;
  (*today).year = 2022;

  printf("the longhand way of displaying date is %d/%d/%d\n", (*today).day, today->month, today->year);

  // the more readable shorthand way of doing it
  today->day = 15;
  today->month = 6;
  today->year = 2023;

  printf("the readable way of displaying date is %d/%d/%d\n", today->day, today->month, today->year);

  free(today);

  return 0;
}