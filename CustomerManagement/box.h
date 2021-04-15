#ifndef __MENU_H__
#define __MENU_H__

#define MAX_SIZE_MENU_STRING 100

#include "customer.h"

static char strings_main[][MAX_SIZE_MENU_STRING] = {
	"메인 메뉴",
	"메뉴를 선택해주세요.",
	"1. 손님 정보 등록",
	"2. 손님 정보 조회",
	"3. 손님 정보 수정",
	"4. 손님 정보 삭제",
	"5. 영업 시작",
	"6. 프로그램 종료",
	-1
};
static char strings_inquiry[][MAX_SIZE_MENU_STRING] = {
	"조회 메뉴",
	"메뉴를 선택해주세요.",
	"1. 전체 손님 정보 조회",
	"2. 이름으로 손님 정보 조회",
	"3. 이전 메뉴로 이동",
	-1
};
static char strings_inquiry_sort[][MAX_SIZE_MENU_STRING] = {
	"",
	"정렬 기준을 선택해주세요.",
	"1. 첫 방문",
	"2. 이름",
	"3. 나이",
	"4. 지출액",
	"5. 최근구매시간",
	"6. 이전 메뉴로 이동",
	-1
};
static char strings_inquiry_order[][MAX_SIZE_MENU_STRING] = {
	"",
	"정렬 순서를 선택해주세요.",
	"1. 오름차순",
	"2. 내림차순",
	"3. 이전 메뉴로 이동",
	-1
};
static char strings_inquiry_term[][MAX_SIZE_MENU_STRING] = {
	"",
	"최근구매시간 기준 조회 기간을 선택해주세요.",
	"1. 전체 기간",
	"2. 직접 입력",
	"3. 이전 메뉴로 이동",
	-1
};
static char strings_sales[][MAX_SIZE_MENU_STRING] = {
	"영업 메뉴",
	"메뉴를 선택해주세요.",
	"1. 손님 선택",
	"2. 판매",
	"3. 화장실 가기",
	"4. 이전 메뉴로 이동",
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
	"판매",
	"메뉴를 선택해주세요.",
	"1. 음식 추가",
	"2. 음식 삭제",
	"3. 결제",
	"4. 이전 메뉴로 이동",
	-1
};
static char strings_food_board[][MAX_SIZE_MENU_STRING] = {
	"메뉴판",
	"",
	"1. 떡볶이 3,000원",
	"2. 튀김   1,500원",
	"3. 순대   3,000원",
	"4. 김밥   2,500원",
	-1
};
static char strings_popular_food[][MAX_SIZE_MENU_STRING] = {
	"인기 메뉴",
	"",
	"",
	-1
};
static char strings_order_food_list[][MAX_SIZE_MENU_STRING] = {
		"주문할 음식 목록",
		"",
		"",
		"",
		"",
		"",
		-1
};
static char strings_choice_not_found[][MAX_SIZE_MENU_STRING] = {
	"", 
	"입력하신 정보에 맞는 선택지가 없습니다.", 
	"",
	-1
};
static char strings_customer_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"입력하신 정보에 맞는 손님이 없습니다.",
	"",
	-1
};
static char strings_food_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"입력하신 정보에 맞는 음식이 없습니다.",
	"",
	-1
};
static char strings_added_food_not_found[][MAX_SIZE_MENU_STRING] = {
	"",
	"추가한 음식이 없어 결제할 수 없습니다.",
	"",
	-1
};
static char strings_current_food_count_exceed[][MAX_SIZE_MENU_STRING] = {
	"",
	"현재 음식의 수량을 초과하여 삭제할 수 없습니다.",
	"",
	-1
};
static char strings_inform_input_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"먼저 손님을 선택해주세요.",
	"",
	-1
};
static char strings_input_name[][MAX_SIZE_MENU_STRING] = {
	"",
	"이름을 입력해주세요.",
	"",
	-1
};
static char strings_input_age[][MAX_SIZE_MENU_STRING] = {
	"",
	"나이를 입력해주세요.",
	"",
	-1
};
static char strings_input_number[][MAX_SIZE_MENU_STRING] = {
	"",
	"번호를 입력해주세요.",
	"",
	-1
};
static char strings_input_food_id[][MAX_SIZE_MENU_STRING] = {
	"",
	"음식 번호를 입력해주세요.",
	"",
	-1
};
static char strings_input_food_count[][MAX_SIZE_MENU_STRING] = {
	"",
	"음식 수량을 입력해주세요.",
	"",
	-1
};
static char strings_input_latest_purchase_term[][MAX_SIZE_MENU_STRING] = {
	"",
	"최근 몇 개월까지 조회할 것인지 입력해주세요.",
	"",
	-1
};
static char failure_load_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 불러오기 실패",
	"",
	-1
};
static char success_load_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 불러오기 성공",
	"",
	-1
};
static char failure_save_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 저장 실패",
	"",
	-1
};
static char success_save_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 저장 성공",
	"",
	-1
};
static char failure_register_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 등록 실패",
	"",
	-1
};
static char success_register_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 등록 성공",
	"",
	-1
};
static char failure_update_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 수정 실패",
	"",
	-1
};
static char success_update_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 수정 성공",
	"",
	-1
};
static char failure_delete_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 삭제 실패",
	"",
	-1
};
static char success_delete_customer[][MAX_SIZE_MENU_STRING] = {
	"",
	"손님 정보 삭제 성공",
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
