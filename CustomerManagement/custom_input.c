#include "custom_input.h"
#include "box.h"
#include <stdio.h>

void input_integer(int* n) {
	printf(" >> ");
	scanf("%d", n);
}

// 이름 입력
void input_string(char* str) {
	printf(" >> "); 
	scanf("%s", str);
}

// 정보 입력 - 나이, 전화번호
void input_informations(char* name, int* age, char* number, char* title) {
	show_box_changed(strings_input_name, title, "");
	input_string(name);
	printf("\n");
	show_box_changed(strings_input_age, title, "");
	input_integer(age);
	printf("\n");
	show_box_changed(strings_input_number, title, "");
	input_string(number);
	printf("\n");
}
