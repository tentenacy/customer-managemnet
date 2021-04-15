#include "minigame_map.h"
#include <stdlib.h>
#include <stdio.h>

void load_minigame_map() {
	srand(time(NULL));
	int i;
	int j;
	int k;
	FILE* fp = NULL;
	if(fopen_s(&fp, "rr_map.txt", "r") == 0) {
		fscanf(fp, "%d", &map_size);
		row_sizes = (int*)malloc(sizeof(int) * map_size);
		col_sizes = (int*)malloc(sizeof(int) * map_size);
		maps = (int***)malloc(sizeof(int**) * map_size);
		for (k = 0; k < map_size; k++) {
			fscanf(fp, "%d", &row_sizes[k]);
			fscanf(fp, "%d", &col_sizes[k]);
			maps[k] = (int**)malloc(sizeof(int*) * row_sizes[k]);
			for (i = 0; i < row_sizes[k]; i++) {
				maps[k][i] = (int*)malloc(sizeof(int) * col_sizes[k]);
				for (j = 0; j < col_sizes[k]; j++) {
					fscanf(fp, "%d", &maps[k][i][j]);
				}
			}
		}
		fclose(fp);
	}
}

int** get_map_rb(int index, int* row_size, int* col_size) {
	int i;
	int j;
	*row_size = row_sizes[index];
	*col_size = col_sizes[index];
	return maps[index];
}

int** get_random_map_rb(int* row_size, int* col_size) {
	return get_map_rb(rand() % map_size, row_size, col_size);
}

void unload_minigame_map() {
	int i;
	int k;
	for (k = 0; k < map_size; k++) {
		for (i = 0; i < row_sizes[k]; i++) {
			free(maps[k][i]);
		}
	}
	for (k = 0; k < map_size; k++) {
		free(maps[k]);
	}
	free(maps);
	free(row_sizes);
	free(col_sizes);
}