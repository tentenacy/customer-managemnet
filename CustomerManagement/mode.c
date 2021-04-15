#include "mode.h"
#include "box.h"
#include "sales.h"
#include "minigame_manager.h"
#include "custom_input.h"
#include "custom_output.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

void main_mode(Customer* cus) {
	while (1) {
		int choice_main = 0;
		show_box(strings_main);
		input_integer(&choice_main);
		printf("\n");
		system("cls");
		switch (choice_main) {
		case 1:
			register_customer_user_input(cus);
			break;

		case 2:
			inquiry_mode(cus);
			break;

		case 3:
			update_customer_user_input(cus);
			break;

		case 4:
			delete_customer(cus);
			break;

		case 5:
			sales_mode(cus);
			break;

		case 6:
			return;

		default:
			show_box(strings_choice_not_found);
			printf("\n");

		}
	}
	return;
}


int inquiry_term_mode(Customer* cus, int* choice_term, char* title) {
	int term;
	while (1) {
		show_box_changed(strings_inquiry_term, title, "");
		input_integer(choice_term);
		printf("\n");
		switch (*choice_term) {
		case 1:
			return -1;

		case 2:
			show_box_changed(strings_input_latest_purchase_term, title, "");
			input_integer(&term);
			printf("\n");
			return term;

		case 3:
			*choice_term = 0;
			return 0;

		default:
			show_box(strings_choice_not_found);
			printf("\n");
		}
	}
	return 0;
}

int inquiry_order_mode(Customer* cus, int* choice_order, char* title) {
	while (1) {
		show_box_changed(strings_inquiry_order, title, "");
		input_integer(choice_order);
		printf("\n");
		switch (*choice_order) {
		case 1:
		case 2:
			return 1;

		case 3:
			*choice_order = 0;
			return 0;

		default:
			show_box(strings_choice_not_found);
			printf("\n");
		}
	}
	return 0;
}

int inquiry_sort_mode(Customer* cus, int* choice_sort, char* title) {
	while (1) {
		show_box_changed(strings_inquiry_sort, title, "");
		input_integer(choice_sort);
		printf("\n");
		switch (*choice_sort) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return 1;

		case 6:
			*choice_sort = 0;
			return 0;

		default:
			show_box(strings_choice_not_found);
			printf("\n");
		}
	}
	return 0;
}

void inquiry_mode(Customer* cus) {
	int showed;
	while (1) {
		int choice_inquiry = 0;
		int choice_sort;
		int choice_order;
		int choice_term;
		show_box(strings_inquiry);
		input_integer(&choice_inquiry);
		printf("\n");
		system("cls");
		showed = 0;
		switch (choice_inquiry) {
		case 1:
			while (showed == 0 && inquiry_sort_mode(cus, &choice_sort, "전체 손님 정보 조회") == 1) {
				while (showed == 0 && inquiry_order_mode(cus, &choice_order, "전체 손님 정보 조회") == 1) {
					while (showed == 0) {
						choice_term = inquiry_term_mode(cus, &choice_term, "전체 손님 정보 조회");
						if (choice_term == 0) {
							break;
						}
						show_all_customer(cus, choice_sort, choice_order, choice_term);
						showed = 1;
					}
				}
			}
			
			break;

		case 2:
			show_box_changed(strings_input_name, "이름으로 손님 정보 조회", "");
			char name[MAX_SIZE_STRING_CUSTOMER];
			input_string(name);
			printf("\n");

			while (showed == 0) {
				choice_term = inquiry_term_mode(cus, &choice_term, "이름으로 손님 정보 조회");
				if (choice_term == 0) {
					break;
				}
				show_customers_by_name(name, choice_term, cus);
				showed = 1;
			}

			break;

		case 3:
			return;

		default:
			show_box(strings_choice_not_found);
			printf("\n");

		}
	}
	return;
}

void sales_sell_mode(int mid, Customer* cus) {
	int i;
	int choice = 0;
	int ordered = 0;
	int sum_price = 0;
	int count_food[MAX_SIZE_FOOD] = {0};
	while (1)
	{
		ordered = 0;
		char(*strings_order_food)[MAX_SIZE_MENU_STRING] = (char(*)[MAX_SIZE_MENU_STRING])malloc(MAX_SIZE_FOOD * MAX_SIZE_MENU_STRING * sizeof(char));
		for (i = 0; i < MAX_SIZE_FOOD; i++) {
			if (count_food[i] == 0) {
				memcpy(strings_order_food_list[i + 2], "", sizeof(char));
				continue;
			}
			ordered = 1;
			sprintf(strings_order_food[i], "%s %d개", NAME_FOOD[i], count_food[i]);
			memcpy(strings_order_food_list[i + 2], strings_order_food[i], sizeof(char) * (strlen(strings_order_food[i]) + 1));
		}
		free(strings_order_food);
		if (ordered == 0) {
			memcpy(strings_order_food_list[1], "없음", sizeof(char) * (strlen("없음") + 1));
		}
		show_box(strings_order_food_list);
		printf("\n");
		if (ordered == 0) {
			memcpy(strings_order_food_list[1], "", sizeof(char));
		}
		show_box(strings_sales_sell);
		input_integer(&choice);
		printf("\n");
		system("cls");
		switch (choice) {
		case 1:
			sum_price += add_food(count_food);
			system("cls");
			break;

		case 2:
			show_box(strings_order_food_list);
			printf("\n");
			sum_price -= delete_food(count_food);
			system("cls");
			break;

		case 3:
			if (sum_price == 0) {
				show_box(strings_added_food_not_found);
				printf("\n");
				continue;
			}
			update_datetime();
			if (update_customer_expenditure(mid, count_food, sum_price, cus) == 1 && update_history_purchase(mid, count_food, cus) == 1) {
				show_box(success_save_customer);
				printf("\n");
			}
			else {
				show_box(failure_delete_customer);
				printf("\n");
			}
			show_receipt(count_food);
			printf("\n");

		case 4:
			return;

		default:
			show_box(strings_choice_not_found);
		}
	}
	return;
}

void sales_mode(Customer* cus) {
	int mid = -1;
	while (1) {
		int choice_sales = 0;
		show_sales_informations(mid, cus);
		show_box(strings_sales);
		input_integer(&choice_sales);
		printf("\n");
		system("cls");
		switch (choice_sales) {
		case 1:
			mid = select_customer(cus);
			if (mid != -1) {
				system("cls");
			}
			break;

		case 2:
			if (mid == -1) {
				show_box(strings_inform_input_customer);
				printf("\n");
				break;
			}

			sales_sell_mode(mid, cus);
			break;

		case 3:
			play_restaurant_restroom();
			break;

		case 4:
			return;

		default:
			show_box(strings_choice_not_found);
			printf("\n");

		}
	}
	return;
}
