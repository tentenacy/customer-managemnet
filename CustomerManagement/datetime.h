#ifndef __DATETIME_H__
#define __DATETIME_H__

#define MAX_SIZE_STRING_DATETIME 20

char current_datetime[MAX_SIZE_STRING_DATETIME];

void update_datetime();
int string_to_integer(char* string);
void string_to_datetime(char* string_datetime, int* year, int* month, int* day, int* hour, int* minute, int* seconds);
void sub_month_from_datetime(char* dst, char* string_datetime, int month);
int string_datetime_comparison(char* str_dt1, char* str_dt2);

#endif