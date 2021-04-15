#include "customer.h"
#include "custom_input.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "box.h"

void register_customer(int uid, char* name, int age, char* number, int expenditure, char* latest_purchase_time, Customer* cus) {
	cus[size_customer].uid = uid;
	cus[size_customer].expenditure = expenditure;
	strcpy(cus[size_customer].name, name);
	cus[size_customer].age = age;
	strcpy(cus[size_customer].number, number);
	strcpy(cus[size_customer].latest_purchase_time, latest_purchase_time);
	size_customer += 1;
}

void register_customer_user_input(Customer * cus) {
	char me_name[MAX_SIZE_STRING_CUSTOMER];
	int me_age;
	char me_number[MAX_SIZE_STRING_CUSTOMER];
	input_informations(me_name, &me_age, me_number, "손님 정보 등록");
	uid_customer += 1;
	register_customer(uid_customer, me_name, me_age, me_number, 0, "-", cus);
	FILE* fcus;
	if (fopen_s(&fcus, "customer.txt", "a") == 0) {
		fprintf(fcus, "%d %d %s %d %s %s\n", uid_customer, 0, me_name, me_age, me_number, "-");
		fclose(fcus);
		show_box(success_register_customer);
		printf("\n");
	}
	else {
		show_box(failure_register_customer);
		printf("\n");
	}
}

void load_customer(Customer * cus) {
	int i;
	FILE* fcus = NULL;
	FILE* fhist = NULL;
	if (fopen_s(&fcus, "customer.txt", "r") == 0 && fopen_s(&fhist, "history_purchase.txt", "r") == 0) {
		// customer.txt
		int cus_uid;
		int cus_deleted;
		char cus_name[MAX_SIZE_STRING_CUSTOMER];
		int cus_age;
		char cus_number[MAX_SIZE_STRING_CUSTOMER];
		char cus_latest_purchase_time[MAX_SIZE_STRING_DATETIME];

		// history_purchase.txt
		int hist_uid;
		int hist_mid;
		int hist_count_food[MAX_SIZE_FOOD];
		char hist_purchase_time[MAX_SIZE_STRING_DATETIME];

		// scanf는 기본적으로 공백을 입력받지 못한다.
		// %[^\n]을 사용하면 \n을 제외한 모든 문자를 입력받을 수 있다.
		// \n을 입력받으면 입력이 종료된다.
		while (fscanf(fcus, "%d %d %s %d %s %[^\n]", &cus_uid, &cus_deleted, cus_name, &cus_age, cus_number, cus_latest_purchase_time) != EOF) {
			if (cus_deleted == 0) {
				register_customer(cus_uid, cus_name, cus_age, cus_number, 0, cus_latest_purchase_time, cus);
			}
			uid_customer = cus_uid;
		}
		fclose(fcus);

		int expenditure;
		while (fscanf(fhist, "%d %d %d %d %d %d %[^\n]", &hist_uid, &hist_mid, &hist_count_food[0], &hist_count_food[1], &hist_count_food[2], &hist_count_food[3], hist_purchase_time) != EOF) {
			expenditure = 0;
			for (i = 0; i < MAX_SIZE_FOOD; i++) {
				expenditure += hist_count_food[i] * PRICE_FOOD[i];
				count_sold_food[i] += hist_count_food[i];
			}
			sales += expenditure;
			if (hist_mid != -1) {
				cus[hist_mid].expenditure += expenditure;
			}
		}
		fclose(fhist);

		show_box(success_load_customer);
		printf("\n");
	}
	else {
		show_box(failure_load_customer);
		printf("\n");
	}
}