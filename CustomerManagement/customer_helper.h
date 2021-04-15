#ifndef __CUSTOMER_HELPER_H__
#define __CUSTOMER_HELPER_H__


#include "customer.h"

void swap_customer(Customer* u, Customer* v);
int get_count_customer(char * name, Customer * cus);
int get_mid_by_uid(int uid, Customer * cus);
int get_mid_by_name(char* name, int status, Customer* cus);

#endif
