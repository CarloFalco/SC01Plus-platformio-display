#include "displayFcn.h"


void increase_number(lv_event_t *e) {
 number = number + 10;
 if (number >= 255) number = 255;
}

void reset_number(lv_event_t *e) {
 number = 105;
}
