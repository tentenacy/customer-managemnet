#include "customer.h"
#include "box.h"
#include "minigame_map.h"
#include "mode.h"
#include "datetime.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Customer cus[MAX_SIZE_CUSTOMER + 1];
	load_minigame_map();
	load_customer(cus);
	main_mode(cus);
	unload_minigame_map();
	return 0;
}
