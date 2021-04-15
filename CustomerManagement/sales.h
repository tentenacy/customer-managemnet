#ifndef __SALES_H__
#define __SALES_H__

#include "customer.h"

#define MAX_SIZE_FOOD 4
#define MAX_SIZE_STRING_FOOD 10

static char NAME_FOOD[MAX_SIZE_FOOD][MAX_SIZE_STRING_FOOD] = {
	"¶±ººÀÌ",
	"Æ¢±è",
	"¼ø´ë",
	"±è¹ä"
};

static int PRICE_FOOD[MAX_SIZE_FOOD] = {
	3000,
	1500,
	3000,
	2500
};

int count_sold_food[MAX_SIZE_FOOD];

void show_popular_menu();
void show_sales_informations(int mid, Customer * cus);
int select_customer(Customer * cus);
int add_food(int* count_food);
int delete_food(int* count_food);

#endif
