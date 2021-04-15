#ifndef __MODE_H__
#define __MODE_H__

#include "customer.h"

void main_mode(Customer* cus);
int inquiry_order_mode(Customer* cus, int* choice_order, char* title);
int inquiry_sort_mode(Customer* cus, int* choice_sort, char* title);
void inquiry_mode(Customer* cus);
void sales_sell_mode(int mid, Customer* cus);
void sales_mode(Customer* cus);

#endif
