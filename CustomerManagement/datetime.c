#include "datetime.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

void update_datetime() {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(current_datetime, "%d-%d-%d %d:%d:%d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int string_to_integer(char* string) {
	int i;
	int j;
	int res = 0;
	for (i = strlen(string) - 1, j = 1; i >= 0; i--, j *= 10) {
		res += (string[i] - '0') * j;
	}
	return res;
}

void string_to_datetime(char* string_datetime, int* year, int* month, int* day, int* hour, int* minute, int* seconds) {
	char copy[20];
	char date[11];
	char time[9];
	char* p;
	strcpy(copy, string_datetime);
	p = strtok(copy, " ");
	strcpy(date, p);
	p = strtok(NULL, " ");
	strcpy(time, p);

	p = strtok(date, "-");  *year = string_to_integer(p);
	p = strtok(NULL, "-");  *month = string_to_integer(p);
	p = strtok(NULL, "-");	*day = string_to_integer(p);
	p = strtok(time, ":");	*hour = string_to_integer(p);
	p = strtok(NULL, ":");	*minute = string_to_integer(p);
	p = strtok(NULL, ":");	*seconds = string_to_integer(p);
}

void sub_month_from_datetime(char* dst, char* string_datetime, int month) {
	char res[20];
	int dt[6];
	string_to_datetime(string_datetime, &dt[0], &dt[1], &dt[2], &dt[3], &dt[4], &dt[5]);
	while (1) {
		if (dt[1] - month <= 0) {
			month -= dt[1];
			dt[0] -= 1;
			dt[1] = 12;
		}
		else {
			dt[1] -= month;
			break;
		}
	}
	sprintf(res, "%d-%d-%d %d:%d:%d", dt[0], dt[1], dt[2], dt[3], dt[4], dt[5]);
	strcpy(dst, res);
}

// 연습겸 strcmp를 사용하지 않고 다른 방법으로 접근해보았다.
int string_datetime_comparison(char* str_dt1, char* str_dt2) {
	int dt1[6];
	int dt2[6];
	string_to_datetime(str_dt1, &dt1[0], &dt1[1], &dt1[2], &dt1[3], &dt1[4], &dt1[5]);
	string_to_datetime(str_dt2, &dt2[0], &dt2[1], &dt2[2], &dt2[3], &dt2[4], &dt2[5]);
	int date1 = dt1[0] * 10000 + dt1[1] * 100 + dt1[2];
	int time1 = dt1[3] * 10000 + dt1[4] * 100 + dt1[5];
	int date2 = dt2[0] * 10000 + dt2[1] * 100 + dt2[2];
	int time2 = dt2[3] * 10000 + dt2[4] * 100 + dt2[5];
	if (date1 > date2) {
		return 1;
	}
	else if (date1 == date2) {
		if (time1 > time2) {
			return 1;
		}
		else if (time1 == time2) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}
