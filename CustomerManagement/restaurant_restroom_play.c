#include "minigame_manager.h"
#include "restaurant_restroom.h"
#include "queue_pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

Pair get_target_position(int start_x, int start_y, int* target_distance) {
	int i, j;
	int** distance = (int**)malloc(sizeof(int*) * map_row_size);
	for (i = 0; i < map_row_size; i++) {
		distance[i] = (int*)malloc(sizeof(int) * map_col_size);
		for (j = 0; j < map_col_size; j++) {
			distance[i][j] = -1;
		}
	}
	Queue* queue = new_queue_pair();
	queue->push(make_pair(start_x, start_y), queue);
	distance[start_y][start_x / 2] = 0;
	while (!(queue->empty())) {
		int curr_x = queue->front(queue).first;
		int curr_y = queue->front(queue).second;
		queue->pop(queue);
		for (i = 0; i < 4; i++) {
			int next_x = curr_x + dx[i] * 2;
			int next_y = curr_y + dy[i];
			if (next_y >= 0 && next_y < map_row_size && next_x / 2 >= 0 && next_x / 2 < map_col_size) {
				if (distance[next_y][next_x / 2] == -1 && map[next_y][next_x / 2] != 1) {
					if (map[next_y][next_x / 2] == 2 || map[next_y][next_x / 2] == 3) {
						*target_distance = distance[curr_y][curr_x / 2] + 1;
						for (j = 0; j < map_row_size; j++) {
							free(distance[j]);
						}
						free(distance);
						destroy_queue_pair(queue);
						return make_pair(next_x, next_y);
					}
					distance[next_y][next_x / 2] = distance[curr_y][curr_x / 2] + 1;
					queue->push(make_pair(next_x, next_y), queue);
				}
			}
		}
	}
}

void play_restaurant_restroom()
{
	int curr_pos_x = 1 * 2;
	int curr_pos_y = 1;
	int curr_distance = 0;
	int target_pos_x = 0;
	int target_pos_y = 0;
	int target_distance = 0;
	int curr_direction = 0;
	init_restaurant_bathroom(curr_pos_x, curr_pos_y);
	Pair target_pos = get_target_position(curr_pos_x, curr_pos_y, &target_distance);
	target_pos_x = target_pos.first;
	target_pos_y = target_pos.second;
	while (1) {
		if (_kbhit()) {
			int pressed_key = _getch();
			if (pressed_key == 224) continue;
			if (pressed_key != KEY_UP && pressed_key != KEY_DOWN && pressed_key != KEY_LEFT && pressed_key != KEY_RIGHT) {
				break;
			}
			curr_direction = set_direction(pressed_key);
			if (move(&curr_pos_x, &curr_pos_y, curr_direction) == 0) {
				continue;
			}
			curr_distance += 1;
			/*printf("%d %d %d\n", curr_pos_x / 2, curr_pos_y, curr_distance);
			printf("%d %d %d\n", target_pos_x / 2, target_pos_y, target_distance);*/
			if (curr_pos_x == target_pos_x && curr_pos_y == target_pos_y && curr_distance == target_distance) {
				if (map[curr_pos_y][curr_pos_x / 2] == 3) {
					printf("mission complete\n");
					Sleep(1000);
					break;
				}
				map[curr_pos_y][curr_pos_x / 2] = 0;
				curr_distance = 0;
				Pair target_pos = get_target_position(curr_pos_x, curr_pos_y, &target_distance);
				target_pos_x = target_pos.first;
				target_pos_y = target_pos.second;
			}
			else if (curr_distance >= target_distance) {
				printf("game over\n");
				Sleep(1000);
				break;
			}
		}
	}
	destroy_restaurant_bathroom();
	system("cls");
	return;
}