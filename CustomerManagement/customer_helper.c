#include "customer_helper.h"
#include "box.h"
#include "custom_input.h"
#include "custom_output.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap_customer(Customer* u, Customer* v) {
	Customer* temp = (Customer*)malloc(sizeof(Customer));
	memcpy(temp, u, sizeof(Customer));
	memcpy(u, v, sizeof(Customer));
	memcpy(v, temp, sizeof(Customer));
	free(temp);
	return;
}

int get_count_customer(char * name, Customer * cus) {
	int count = 0;
	int i;
	for(i = 0; i < size_customer; i++) {
		if(!strcmp(cus[i].name, name)) {
			count += 1;
		}
	}
	return count;
}

int get_mid_by_uid(int uid, Customer * cus) {
	int i;
	for(i = 0; i < size_customer; i++) {
		if(cus[i].uid == uid) {
			return i;
		}
	}
	return -1;
}

int get_mid_by_name(char * name, int status, Customer * cus) {
	char* description = "";
	char* title = "";
	if(status == STATUS_UPDATE) {
		description = "������ �մ��� �̸��� �Է����ּ���.";
		title = "�մ� ���� ����";
	} else if(status == STATUS_DELETE) {
		description = "�մ��� �̸��� �Է����ּ���.";
		title = "�մ� ���� ����";
	} else if(status == STATUS_SELECT) {
		description = "�մ��� �̸��� �Է����ּ���.";
		title = "�մ� ����";
	}
	show_box_changed(strings_input_name, title, description);
	input_string(name);
	printf("\n"); 
	int count = get_count_customer(name, cus);
	if(count == 0) {
		return -1; 
	}
	int mid = -1;
	int i;
	if(count == 1) {
		for(i = 0; i < size_customer; i++) {
			if(!strcmp(cus[i].name, name)) {
				mid = i;
				break;
			}
		}
	} else if(count > 1) {
		show_customers_by_name(name, -1, cus);
		int me_uid;
		if (status == STATUS_UPDATE) {
			description = "������ �մ��� ���� ��ȣ�� �Է����ּ���.";
		}
		else if (status == STATUS_DELETE) {
			description = "�մ��� ���� ��ȣ�� �Է����ּ���.";
		}
		else if (status == STATUS_SELECT) {
			description = "�մ��� ���� ��ȣ�� �Է����ּ���.";
		}
		show_box_changed(strings_input_name, title, description);
		input_integer(&me_uid);
		printf("\n");
		for(i = 0; i < size_customer; i++) {
			if(strcmp(cus[i].name, name)) {
				if(me_uid == cus[i].uid) {
					return -1;
				}
			}
		}
		mid = get_mid_by_uid(me_uid, cus);
	}
	return mid;
}
