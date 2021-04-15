#include "custom_output.h"
#include "customer_helper.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_form_customer() {
	printf("┌----------┬------------┬------┬---------------------┬---------------------┬---------------------┐ \n");
	printf("│ 고유번호 │ 이름       │ 나이 │ 전화번호            │ 지출액              │ 최근구매시간        │ \n");
	printf("├----------┼------------┼------┼---------------------┼---------------------┼---------------------┤ \n");
}

void show_customer(int mid, Customer* cus) {
	printf("│ %-8d │ %-10s │ %-4d │ %-19s │ %-19d │ %-19s │\n", cus[mid].uid, cus[mid].name, cus[mid].age, cus[mid].number, cus[mid].expenditure, cus[mid].latest_purchase_time);
}

void show_all_customer(Customer* cus, int sort, int order, int latest_purchase_term) {
	Customer* ccus = (Customer*)malloc(sizeof(Customer) * (size_customer + 1));
	memcpy(ccus, cus, sizeof(Customer) * (size_customer + 1));
	int i;
	int j;
	int i_lpt_empty;
	int j_lpt_empty;
	// bubble sort
	for (i = 0; i < size_customer - 1; i++) {
		for (j = i + 1; j < size_customer; j++) {
			switch (sort) {
			case SORT_BY_FIRST:
				if (order == ASCENDING && ccus[i].uid > ccus[j].uid) {
					swap_customer(ccus + i, ccus + j);
				}
				else if (order == DESCENDING && ccus[i].uid < ccus[j].uid) {
					swap_customer(ccus + i, ccus + j);
				}
				break;
			case SORT_BY_NAME:
				if (order == ASCENDING && strcmp(ccus[i].name, ccus[j].name) > 0) {
					swap_customer(ccus + i, ccus + j);
				}
				else if (order == DESCENDING && strcmp(ccus[i].name, ccus[j].name) < 0) {
					swap_customer(ccus + i, ccus + j);
				}
				break;
			case SORT_BY_AGE:
				if (order == ASCENDING && ccus[i].age > ccus[j].age) {
					swap_customer(ccus + i, ccus + j);
				}
				else if (order == DESCENDING && ccus[i].age < ccus[j].age) {
					swap_customer(ccus + i, ccus + j);
				}
				break;
			case SORT_BY_EXPENDITURE:
				if (order == ASCENDING && ccus[i].expenditure > ccus[j].expenditure) {
					swap_customer(ccus + i, ccus + j);
				}
				else if (order == DESCENDING && ccus[i].expenditure < ccus[j].expenditure) {
					swap_customer(ccus + i, ccus + j);
				}
				break;
			case SORT_BY_LPT:
				i_lpt_empty = strcmp(ccus[i].latest_purchase_time, "-") == 0 ? 1 : 0;
				j_lpt_empty = strcmp(ccus[j].latest_purchase_time, "-") == 0 ? 1 : 0;
				if (i_lpt_empty && !j_lpt_empty) {
					swap_customer(ccus + i, ccus + j);
					break;
				}
				if (!i_lpt_empty && !j_lpt_empty) {
					if (order == ASCENDING && string_datetime_comparison(ccus[i].latest_purchase_time, ccus[j].latest_purchase_time) > 0) {
						swap_customer(ccus + i, ccus + j);
					}
					else if (order == DESCENDING && string_datetime_comparison(ccus[i].latest_purchase_time, ccus[j].latest_purchase_time) < 0) {
						swap_customer(ccus + i, ccus + j);
					}
				}
				break;
			}
		}
	}
	print_form_customer();
	char sub[MAX_SIZE_STRING_CUSTOMER];
	int count_print = 0;
	int index_print[MAX_SIZE_CUSTOMER];
	update_datetime();
	for (i = 0; i < size_customer; i++) {
		if (latest_purchase_term != -1) {
			if (strcmp(ccus[i].latest_purchase_time, "-") == 0) {
				continue;
			}
			sub_month_from_datetime(sub, current_datetime, latest_purchase_term);
			if (string_datetime_comparison(ccus[i].latest_purchase_time, sub) <= 0) {
				continue;
			}
		}
		index_print[count_print++] = i;
	}
	for (i = 0; i < count_print; i++) {
		show_customer(index_print[i], ccus);
		if (i == count_print - 1) {
			printf("└----------┴------------┴------┴---------------------┴---------------------┴---------------------┘  \n");
			break;
		}
		printf("├----------┼------------┼------┼---------------------┼---------------------┼---------------------┤ \n");
	}
	if (count_print == 0 || size_customer == 0) {
		printf("└----------┴------------┴------┴---------------------┴---------------------┴---------------------┘ \n");
	}
	printf("\n");
	free(ccus);
}

void show_customers_by_name(char* name, int latest_purchase_term, Customer* cus) {
	int i = 0;
	char sub[MAX_SIZE_STRING_CUSTOMER];
	int count_print = 0;
	int index_print[MAX_SIZE_CUSTOMER];
	update_datetime();
	for (i = 0; i < size_customer; i++) {
		if (latest_purchase_term != -1) {
			if (strcmp(cus[i].latest_purchase_time, "-") == 0) {
				continue;
			}
			sub_month_from_datetime(sub, current_datetime, latest_purchase_term);
			if (string_datetime_comparison(cus[i].latest_purchase_time, sub) <= 0) {
				continue;
			}
		}
		if (strcmp(cus[i].name, name) == 0) {
			index_print[count_print++] = i;
		}
	}
	print_form_customer();
	for (i = 0; i < count_print; i++) {
		show_customer(index_print[i], cus);
		if (i == count_print - 1) {
			printf("└----------┴------------┴------┴---------------------┴---------------------┴---------------------┘  \n");
			break;
		}
		printf("├----------┼------------┼------┼---------------------┼---------------------┼---------------------┤ \n");
	}
	if (count_print == 0 || size_customer == 0) {
		printf("└----------┴------------┴------┴---------------------┴---------------------┴---------------------┘  \n");
	}
	printf("\n");
}

void show_receipt(int* count_food) {
	int i;
	int sum_of_price = 0;
	printf("┌─────────────────── <<영수증>>───────────────────┐\n");
	printf("│                                                 │\n");
	printf("│ 메뉴                 수량                  금액 │\n");
	printf("│                                                 │\n");
	printf("├─────────────────────────────────────────────────┤\n");
	printf("│                                                 │\n");
	for (i = 0; i < MAX_SIZE_FOOD; i++) {
		if (count_food[i] == 0) {
			continue;
		}
		sum_of_price += count_food[i] * PRICE_FOOD[i];
		printf("│ %-6s        ", NAME_FOOD[i]);
		printf("%9d개       ", count_food[i]);
		printf("%13d원 │", count_food[i] * PRICE_FOOD[i]);
		printf("\n");
	}
	printf("│                                                 │\n");
	printf("│                        합 계: %15d원 │\n", sum_of_price);
	printf("│                                                 │\n");
	printf("└─────────────────────────────────────────────────┘\n");
	return;
}