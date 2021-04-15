#ifndef __RESTAURANT_RESTROOM_H__
#define __RESTAURANT_RESTROOM_H__

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define DIRECTION_SIZE 4

int diff_direction[DIRECTION_SIZE][2];
int** map;
int map_row_size;
int map_col_size;

void show_map();
int set_direction(int pressed_key);
void gotoxy(int x, int y);
int move(int* pos_x, int* pos_y, int direction);
void init_restaurant_bathroom(int pos_x, int pos_y);
void destroy_restaurant_bathroom();

#endif
