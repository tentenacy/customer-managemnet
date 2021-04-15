#ifndef __CUSTOM_OUTPUT_H__
#define __CUSTOM_OUTPUT_H__

#include "customer.h"
#include "sales.h"

enum { SORT_BY_FIRST = 1, SORT_BY_NAME, SORT_BY_AGE, SORT_BY_EXPENDITURE, SORT_BY_LPT };
enum { ASCENDING = 1, DESCENDING };

void print_form_customer();
void show_customer(int mid, Customer * cus);
void show_all_customer(Customer * cus, int sort, int order, int latest_purchase_term);
void show_customers_by_name(char* name, int latest_purchase_term, Customer* cus);
void show_receipt(int* count_food);

#endif
