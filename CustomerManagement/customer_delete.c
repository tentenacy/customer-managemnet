#include "customer.h"
#include "customer_helper.h"
#include "custom_input.h"
#include "custom_output.h"
#include "box.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_customer(Customer * cus) {
	char name[MAX_SIZE_STRING_CUSTOMER];
	int i;
	int mid = get_mid_by_name(name, STATUS_DELETE, cus);
	int uid = cus[mid].uid;
	if(mid == -1) {
		show_box(strings_customer_not_found);
		printf("\n");
		return; 
	}
	Customer copy_dcus = cus[mid];
	for(i = mid; i < size_customer; i++) {
		cus[i] = cus[i + 1];
	}
	size_customer -= 1; 
	char buffer[128];
	int n_line;
	FILE* fcus;
	FILE* temp_fcus;
	FILE* fhist;
	FILE* temp_fhist;
	if (fopen_s(&fcus, "customer.txt", "r") == 0 && fopen_s(&temp_fcus, "temp.txt", "w") == 0
		&& fopen_s(&fhist, "history_purchase.txt", "r") == 0 && fopen_s(&temp_fhist, "temp_hist.txt", "w") == 0) {
		n_line = 0;
		while (fgets(buffer, 128, fcus) != NULL) {
			if (++n_line == copy_dcus.uid) {
				fprintf(temp_fcus, "%d %d %s %d %s %s\n", copy_dcus.uid, 1, copy_dcus.name, copy_dcus.age, copy_dcus.number, copy_dcus.latest_purchase_time);
			}
			else {
				fputs(buffer, temp_fcus);
			}
		}
		fclose(fcus);
		fclose(temp_fcus);
		remove("customer.txt");
		rename("temp.txt", "customer.txt");

		int hist_uid;
		int hist_mid;
		int hist_count_food[MAX_SIZE_FOOD];
		char hist_current_datetime[MAX_SIZE_STRING_DATETIME];
		while (fscanf(fhist, "%d %d %d %d %d %d %[^\n]", &hist_uid, &hist_mid, &hist_count_food[0], &hist_count_food[1], &hist_count_food[2], &hist_count_food[3], hist_current_datetime) != EOF) {
			if (hist_mid == mid || hist_mid == -1) {
				fprintf(temp_fhist, "%d %d %d %d %d %d %s\n", hist_uid, -1, hist_count_food[0], hist_count_food[1], hist_count_food[2], hist_count_food[3], hist_current_datetime);
			}
			else if(hist_mid > mid) {
				fprintf(temp_fhist, "%d %d %d %d %d %d %s\n", cus[hist_mid - 1].uid, hist_mid - 1, hist_count_food[0], hist_count_food[1], hist_count_food[2], hist_count_food[3], hist_current_datetime);
			}
			else {
				fprintf(temp_fhist, "%d %d %d %d %d %d %s\n", hist_uid, hist_mid, hist_count_food[0], hist_count_food[1], hist_count_food[2], hist_count_food[3], hist_current_datetime);
			}
		}
		fclose(fhist);
		fclose(temp_fhist);
		remove("history_purchase.txt");
		rename("temp_hist.txt", "history_purchase.txt");

		show_box(success_delete_customer);
		printf("\n");
	}
	else {
		show_box(failure_delete_customer);
		printf("\n");
	}
}
