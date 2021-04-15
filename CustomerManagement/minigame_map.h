#ifndef __MINIGAME_MAP_H__
#define __MINIGAME_MAP_H__

int*** maps;
int map_size;
int* row_sizes;
int* col_sizes;

void load_minigame_map();
int** get_map_rb(int index, int *row_size, int *col_size);
int** get_random_map_rb(int* row_size, int* col_size);
void unload_minigame_map();

#endif
