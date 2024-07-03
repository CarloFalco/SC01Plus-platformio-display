#ifndef DISPLAYFCN_H
#define DISPLAYFCN_H

#include <lvgl.h>
#include <LovyanGFX.hpp>
#include "Arduino.h"
#include "ui_events.h"

extern int number;


void increase_number(lv_event_t * e);
void reset_number(lv_event_t * e);

#endif