#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#define MAX_SIZE_CUSTOMER 1000
#define MAX_SIZE_STRING_CUSTOMER 20

enum { STATUS_UPDATE, STATUS_DELETE, STATUS_SELECT };

int uid_customer;
int size_customer;
int sales;

typedef struct _Customer {
	int uid;
	char name[MAX_SIZE_STRING_CUSTOMER];
	int age;
	char number[MAX_SIZE_STRING_CUSTOMER];
	int expenditure;
	char latest_purchase_time[MAX_SIZE_STRING_CUSTOMER];
} Customer;

#include "sales.h"

void register_customer(int uid, char* name, int age, char* number, int expenditure, char* latest_purchase_time, Customer* cus);
void register_customer_user_input(Customer * cus);
void load_customer(Customer * cus);
void update_customer(int mid, char* name, int age, char* number, int expenditure, char* latest_purchase_time, Customer* cus);
void update_customer_user_input(Customer* cus);
int update_customer_expenditure(int mid, int* count_food, int current_expenditure, Customer* cus);
int update_history_purchase(int mid, int* count_food, Customer* cus);
void delete_customer(Customer * cus);

#endif
