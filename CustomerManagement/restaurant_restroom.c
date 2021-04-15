#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include "restaurant_restroom.h"
#include "minigame_map.h"

void show_map() {
	int i;
	int j;
	for (i = 0; i < map_row_size; i++) {
		for (j = 0; j < map_col_size; j++) {
			if (map[i][j] == 0) {
				printf("  ");
			}
			else if (map[i][j] == 1) {
				printf("¡á");
			}
			else if (map[i][j] == 2) {
				printf("¡Ù");
			}
			else if (map[i][j] == 3) {
				printf("¡Ú");
			}
		}
		printf("\n");
	}
}

int set_direction(int pressed_key) {
	int changed_direction = 0;
	switch (pressed_key) {
	case KEY_UP:
		changed_direction = 0;
		break;

	case KEY_DOWN:
		changed_direction = 1;
		break;

	case KEY_LEFT:
		changed_direction = 2;
		break;

	case KEY_RIGHT:
		changed_direction = 3;
		break;

	default:
		break;
	}
	return changed_direction;
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int move(int* pos_x, int* pos_y, int direction) {
	int next_pos_x = *pos_x + diff_direction[direction][0];
	int next_pos_y = *pos_y + diff_direction[direction][1];
	if (map[next_pos_y][next_pos_x / 2] == 1) return 0;
	gotoxy(*pos_x, *pos_y);
	printf("  ");
	*pos_x = next_pos_x;
	*pos_y = next_pos_y;
	gotoxy(*pos_x, *pos_y);
	printf("¡Ü");
	return 1;
}

void init_restaurant_bathroom(int pos_x, int pos_y) {
	int** temp;
	temp = get_random_map_rb(&map_row_size, &map_col_size);
	map = (int**)malloc(sizeof(int*) * map_row_size);
	int i;
	for (i = 0; i < map_row_size; i++) {
		map[i] = (int*)malloc(sizeof(int) * map_col_size);
		memcpy(map[i], temp[i], sizeof(int) * map_col_size);
	}
	//map = get_rb_map(3, &map_row_size, &map_col_size);
	int src[DIRECTION_SIZE][2] = {
		{0, -1}, // up
		{0, 1}, // down
		{-2, 0}, // left
		{2, 0} // right
	};
	memcpy(diff_direction, src, sizeof(diff_direction));
	show_map();
	gotoxy(pos_x, pos_y);
	printf("¡Ü");
}

void destroy_restaurant_bathroom() {
	int i;
	for (i = 0; i < map_row_size; i++) {
		free(map[i]);
	}
	free(map);
}