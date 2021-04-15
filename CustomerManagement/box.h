#ifndef __MENU_H__
#define __MENU_H__

#define MAX_SIZE_MENU_STRING 100

#include "customer.h"

static char strings_main[][MAX_SIZE_MENU_STRING] = {
	"���� �޴�",
	"�޴��� �������ּ���.",
	"1. �մ� ���� ���",
	"2. �մ� ���� ��ȸ",
	"3. �մ� ���� ����",
	"4. �մ� ���� ����",
	"5. ���� ����",
	"6. ���α׷� ����",
	-1
};
static char strings_inquiry[][MAX_SIZE_MENU_STRING] = {
	"��ȸ �޴�",
	"�޴��� �������ּ���.",
	"1. ��ü �մ� ���� ��ȸ",
	"2. �̸����� �մ� ���� ��ȸ",
	"3. ���� �޴��� �̵�",
	-1
};
static char strings_inquiry_sort[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� ������ �������ּ���.",
	"1. ù �湮",
	"2. �̸�",
	"3. ����",
	"4. �����",
	"5. �ֱٱ��Žð�",
	"6. ���� �޴��� �̵�",
	-1
};
static char strings_inquiry_order[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� ������ �������ּ���.",
	"1. ��������",
	"2. ��������",
	"3. ���� �޴��� �̵�",
	-1
};
static char strings_inquiry_term[][MAX_SIZE_MENU_STRING] = {
	"",
	"�ֱٱ��Žð� ���� ��ȸ �Ⱓ�� �������ּ���.",
	"1. ��ü �Ⱓ",
	"2. ���� �Է�",
	"3. ���� �޴��� �̵�",
	-1
};
static char strings_sales[][MAX_SIZE_MENU_STRING] = {
	"���� �޴�",
	"�޴��� �������ּ���.",
	"1. �մ� ����",
	"2. �Ǹ�",
	"3. ȭ��� ����",
	"4. ���� �޴��� �̵�",
	-1
};
static char strings_sales_info[][MAX_SIZE_MENU_STRING] = {
		"",
		"",
		"",
		"",
		-1
};
static char strings_sales_sell[][MAX_SIZE_MENU_STRING] = {
	"�Ǹ�",
	"�޴��� �������ּ���.",
	"1. ���� �߰�",
	"2. ���� ����",
	"3. ����",
	"4. ���� �޴��� �̵�",
	-1
};
static char strings_food_board[][MAX_SIZE_MENU_STRING] = {
	"�޴���",
	"",
	"1. ������ 3,000��",
	"2. Ƣ��   1,500��",
	"3. ����   3,000��",
	"4. ���   2,500��",
	-1
};
static char strings_popular_food[][MAX_SIZE_MENU_STRING] = {
	"�α� �޴�",
	"",
	"",
	-1
};
static char strings_order_food_list[][MAX_SIZE_MENU_STRING] = {
		"�ֹ��� ���� ���",
		"",
		"",
		"",
		"",
		"",
		-1
};
static char strings_choice_not_found[][MAX_SIZE_MENU_STRING] = {
	"", 
	"�Է��Ͻ� ������ �´� �������� �����ϴ�.", 
	"",
	-1
};
static char strings_customer_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"�Է��Ͻ� ������ �´� �մ��� �����ϴ�.",
	"",
	-1
};
static char strings_food_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"�Է��Ͻ� ������ �´� ������ �����ϴ�.",
	"",
	-1
};
static char strings_added_food_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"�߰��� ������ ���� ������ �� �����ϴ�.",
	"",
	-1
};
static char strings_current_food_count_exceed[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� ������ ������ �ʰ��Ͽ� ������ �� �����ϴ�.",
	"",
	-1
};
static char strings_inform_input_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� �մ��� �������ּ���.",
	"",
	-1
};
static char strings_input_name[][MAX_SIZE_MENU_STRING] = {
	"",
	"�̸��� �Է����ּ���.",
	"",
	-1
};
static char strings_input_age[][MAX_SIZE_MENU_STRING] = {
	"",
	"���̸� �Է����ּ���.",
	"",
	-1
};
static char strings_input_number[][MAX_SIZE_MENU_STRING] = {
	"",
	"��ȣ�� �Է����ּ���.",
	"",
	-1
};
static char strings_input_food_id[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� ��ȣ�� �Է����ּ���.",
	"",
	-1
};
static char strings_input_food_count[][MAX_SIZE_MENU_STRING] = {
	"",
	"���� ������ �Է����ּ���.",
	"",
	-1
};
static char strings_input_latest_purchase_term[][MAX_SIZE_MENU_STRING] = {
	"",
	"�ֱ� �� �������� ��ȸ�� ������ �Է����ּ���.",
	"",
	-1
};
static char failure_load_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� �ҷ����� ����",
	"",
	-1
};
static char success_load_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� �ҷ����� ����",
	"",
	-1
};
static char failure_save_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};
static char success_save_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};
static char failure_register_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ��� ����",
	"",
	-1
};
static char success_register_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ��� ����",
	"",
	-1
};
static char failure_update_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};
static char success_update_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};
static char failure_delete_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};
static char success_delete_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"�մ� ���� ���� ����",
	"",
	-1
};

int get_size_strings(char(*strings)[MAX_SIZE_MENU_STRING]);
int get_max_size_string(char(*strings)[MAX_SIZE_MENU_STRING], int size_strings);
void show_box_top(char* string, int size);
void show_box_bottom(int size);
void show_box_description(char* string, int size);
void show_box_choice(char* string, int size);
void show_box_line(int size);
void show_box_blank_line(int size);
void show_box(char(*strings)[MAX_SIZE_MENU_STRING]);
void show_box_changed(char(*strings)[MAX_SIZE_MENU_STRING], char* title, char* description);

#endif
