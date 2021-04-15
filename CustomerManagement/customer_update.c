#include "customer.h"
#include "customer_helper.h"
#include "custom_input.h"
#include "custom_output.h"
#include "box.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void update_customer(int mid, char* name, int age, char* number, int expenditure, char* latest_purchase_time, Customer* cus) {
	strcpy(cus[mid].name, name);
	cus[mid].age = age;
	strcpy(cus[mid].number, number);
	cus[mid].expenditure = expenditure;
	strcpy(cus[mid].latest_purchase_time, latest_purchase_time);
}

void update_customer_user_input(Customer* cus) {
	char name[MAX_SIZE_STRING_CUSTOMER];
	int mid = get_mid_by_name(name, STATUS_UPDATE, cus);
	int uid = cus[mid].uid;
	if (mid == -1) {
		show_box(strings_customer_not_found);
		printf("\n");
		return;
	}
	char* title = (char*)malloc(MAX_SIZE_MENU_STRING * sizeof(char));
	sprintf(title, "%d번 %s 손님 정보 수정", uid, name);
	char me_name[MAX_SIZE_STRING_CUSTOMER];
	int me_age;
	char me_number[MAX_SIZE_STRING_CUSTOMER];
	input_informations(me_name, &me_age, me_number, title);
	update_customer(mid, me_name, me_age, me_number, cus[mid].expenditure, cus[mid].latest_purchase_time, cus);
	free(title);

	char buffer[128];
	int n_line = 0;
	FILE* fcus;
	FILE* temp_fcus;
	if (fopen_s(&fcus, "customer.txt", "r") == 0 && fopen_s(&temp_fcus, "temp.txt", "w") == 0) {
		while (fgets(buffer, 128, fcus) != NULL) {
			if (++n_line == cus[mid].uid) {
				fprintf(temp_fcus, "%d %d %s %d %s %s\n", cus[mid].uid, 0, cus[mid].name, cus[mid].age, cus[mid].number, cus[mid].latest_purchase_time);
			}
			else {
				fputs(buffer, temp_fcus);
			}
		}
		fclose(fcus);
		fclose(temp_fcus);
		remove("customer.txt");
		rename("temp.txt", "customer.txt");
		show_box(success_update_customer);
		printf("\n");
	}
	else {
		show_box(failure_update_customer);
		printf("\n");
	}
}

int update_customer_expenditure(int mid, int* count_food, int current_expenditure, Customer* cus) {
	int i;
	for (i = 0; i < MAX_SIZE_FOOD; i++) {
		count_sold_food[i] += count_food[i];
	}
	sales += current_expenditure;
	update_customer(mid, cus[mid].name, cus[mid].age, cus[mid].number, cus[mid].expenditure + current_expenditure, current_datetime, cus);
	char buffer[128];
	int n_line = 0;
	FILE* fcus;
	FILE* temp_fcus;
	if (fopen_s(&fcus, "customer.txt", "r") == 0 && fopen_s(&temp_fcus, "temp.txt", "w") == 0) {
		while (fgets(buffer, 128, fcus) != NULL) {
			if (++n_line == cus[mid].uid) {
				fprintf(temp_fcus, "%d %d %s %d %s %s\n", cus[mid].uid, 0, cus[mid].name, cus[mid].age, cus[mid].number, cus[mid].latest_purchase_time);
			}
			else {
				fputs(buffer, temp_fcus);
			}
		}
		fclose(fcus);
		fclose(temp_fcus);
		remove("customer.txt");
		rename("temp.txt", "customer.txt");
		return 1;
	}
	else {
		return 0;
	}
}

int update_history_purchase(int mid, int* count_food, Customer* cus) {
	FILE* fhist;
	if (fopen_s(&fhist, "history_purchase.txt", "a") == 0) {
		fprintf(fhist, "%d %d %d %d %d %d %s\n", cus[mid].uid, mid, count_food[0], count_food[1], count_food[2], count_food[3], current_datetime);
		fclose(fhist);
		return 1;
	}
	else {
		return 0;
	}
}