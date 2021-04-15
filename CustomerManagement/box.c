#include "box.h"
#include "custom_input.h"
#include "custom_output.h"
#include "sales.h"
#include "minigame_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_size_strings(char (*strings)[MAX_SIZE_MENU_STRING]) {
	int size_strings = 0;
	int i = 0;
	while (strings[i++][0] != -1) {
		size_strings += 1;
	}
	return size_strings;
}

int get_max_size_string(char (*strings)[MAX_SIZE_MENU_STRING], int size_strings) {
	int max_size = -1;
	int i;
	for (i = 0; i < size_strings; i++) {
		int size = strlen(strings[i]);
		if (max_size < size) {
			max_size = size;
		}
	}
	return max_size + 8;
}

void show_box_top(char* string, int size) {
	int i;
	int index_start = size / 2 - strlen(string) / 2 - 3;
	for (i = 0; i < size;) {
		if (i == index_start && strcmp(string, "") != 0) {
			printf(" <<%s>>", string);
			i += strlen(string) + 5;
			continue;
		}

		if (i == 0) {
			printf("┌");
		}
		else if (i == size - 1) {
			printf("┐");
		}
		else {
			printf("─");
		}
		i += 1;
	}
	printf("\n");
}

void show_box_bottom(int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0) {
			printf("└");
		}
		else if (i == size - 1) {
			printf("┘");
		}
		else {
			printf("─");
		}
	}
	printf("\n");
}

void show_box_description(char* string, int size) {
	int i;
	int index = size / 2 - strlen(string) / 2;
	for (i = 0; i < size;) {
		if (i == index) {
			printf("%s", string);
			i += strlen(string);
			continue;
		}

		if (i == 0 || i == size - 1) {
			printf("│");
		}
		else {
			printf(" ");
		}
		i += 1;
	}
	printf("\n");
}

void show_box_choice(char* string, int size) {
	int i;
	for (i = 0; i < size;) {
		if (i == 0) {
			printf("│");
		}
		else if (i == size - 1) {
			printf("│");
		}
		else if (i == 3) {
			printf("%s", string);
			i += strlen(string);
			continue;
		}
		else {
			printf(" ");
		}
		i += 1;
	}
	printf("\n");
}

void show_box_line(int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0) {
			printf("├");
		}
		else if (i == size - 1) {
			printf("┤");
		}
		else {
			printf("─");
		}
	}
	printf("\n");
}

void show_box_blank_line(int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (i == 0 || i == size - 1) {
			printf("│");
		}
		else {
			printf(" ");
		}
	}
	printf("\n");
}

void show_box(char (*strings)[MAX_SIZE_MENU_STRING]) {
	int size_strings = get_size_strings(strings);
	int size = get_max_size_string(strings, size_strings);
	int divided = 0;
	int i;

	show_box_top(strings[0], size);
	show_box_blank_line(size);
	if (strcmp(strings[1], "") != 0) {
		show_box_description(strings[1], size);
	}
	for (i = 2; i < size_strings; i++) {
		if (strcmp(strings[i], "") == 0) {
			continue;
		}
		if (strcmp(strings[1], "") != 0 && divided == 0) {
			show_box_blank_line(size);
			show_box_line(size);
			show_box_blank_line(size);
			divided = 1;
		}
		show_box_choice(strings[i], size);
	}
	show_box_blank_line(size);
	show_box_bottom(size);
	return;
}

void show_box_changed(char (*strings)[MAX_SIZE_MENU_STRING], char* title, char* description) {
	int i;
	int size_strings = get_size_strings(strings);
	char (*copied_strings)[MAX_SIZE_MENU_STRING] = (char(*)[MAX_SIZE_MENU_STRING])malloc(sizeof(char) * (size_strings + 1) * MAX_SIZE_MENU_STRING);
	for (i = 0; i < size_strings; i++) {
		memcpy(copied_strings[i], strings[i], sizeof(char) * (strlen(strings[i]) + 1));
	}
	copied_strings[size_strings][0] = -1;
	// strings의 복사 배열을 만들어야 한다.
	if (strcmp(title, "") != 0) {
		memcpy(copied_strings[0], title, sizeof(char) * (strlen(title) + 1));
	}
	if (strcmp(description, "") != 0) {
		memcpy(copied_strings[1], description, sizeof(char) * (strlen(description) + 1));
	}
	show_box(copied_strings);
	free(copied_strings);
	return;
}