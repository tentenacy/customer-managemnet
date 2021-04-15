#include "sales.h"
#include "customer_helper.h"
#include "box.h"
#include "custom_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_popular_menu() {
	int i;
	int max = count_sold_food[0];
	int max_index = 0;
	for (i = 1; i < MAX_SIZE_FOOD; i++) {
		if (max < count_sold_food[i]) {
			max = count_sold_food[i];
			max_index = i;
		}
	}
	show_box_changed(strings_popular_food, "", NAME_FOOD[max_index]);
	return;
}

void show_sales_informations(int mid, Customer * cus) {
	int i = 0;
	char* string_sales = (char*)malloc(MAX_SIZE_MENU_STRING * sizeof(char));
	char* string_current_customer = (char*)malloc(MAX_SIZE_MENU_STRING * sizeof(char));
	if (mid == -1) {
		sprintf(string_sales, "매출: %d원", sales);
		memcpy(string_current_customer, "현재 손님: 없음", strlen("현재 손님: 없음") + 1);
	}
	else {
		sprintf(string_sales, "매출: %d원", sales);
		sprintf(string_current_customer, "현재 손님: %s(%d번)", cus[mid].name, cus[mid].uid);
	}
	
	memcpy(strings_sales_info[2], string_sales, sizeof(char) * (strlen(string_sales) + 1));
	memcpy(strings_sales_info[3], string_current_customer, sizeof(char) * (strlen(string_current_customer) + 1));
	show_box(strings_sales_info);
	printf("\n");
	free(string_sales);
	free(string_current_customer);
	return;
}

int select_customer(Customer * cus) {
	char name[MAX_SIZE_STRING_CUSTOMER];
	int mid = get_mid_by_name(name, STATUS_SELECT, cus);
	if(mid == -1) {
		show_box(strings_customer_not_found);
		printf("\n");
	}
	return mid;
}

int add_food(int* count_food) {
	int id = 0;
	int count = 0;
	int price = 0;
	while (1) {
		show_box(strings_food_board);
		printf("\n");
		show_popular_menu();
		printf("\n");
		show_box_changed(strings_input_food_id, "음식 추가", "");
		input_integer(&id); id -= 1;
		printf("\n");
		if (id < 0 || id >= MAX_SIZE_FOOD) {
			show_box(strings_food_not_found);
			printf("\n");
			continue;
		}
		show_box_changed(strings_input_food_count, "음식 추가", "");
		input_integer(&count);
		printf("\n");
		count_food[id] += count;
		price = count * PRICE_FOOD[id];
		return price;
	}
	return price;
}

int delete_food(int* count_food) {
	int id = 0;
	int count = 0;
	int price = 0;
	while (1) {
		show_box(strings_food_board);
		printf("\n");
		show_popular_menu();
		printf("\n");
		show_box_changed(strings_input_food_id, "음식 삭제", "");
		input_integer(&id); id -= 1;
		printf("\n");
		if (id < 0 || id >= MAX_SIZE_FOOD) {
			show_box(strings_food_not_found);
			printf("\n");
			continue;
		}
		show_box_changed(strings_input_food_count, "음식 삭제", "");
		input_integer(&count);
		printf("\n");
		if (count_food[id] - count < 0) {
			show_box(strings_current_food_count_exceed);
			printf("\n");
			continue;
		}
		count_food[id] -= count;
		price = count * PRICE_FOOD[id];
		return price;
	}
	return price;
}