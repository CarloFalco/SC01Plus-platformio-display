// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_comp.h"
#include "ui_comp_hook.h"
#include "ui_events.h"

void BallBounce_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
void ui_event_Screen1(lv_event_t * e);
extern lv_obj_t * ui_Screen1;
void ui_event_Panel3(lv_event_t * e);
extern lv_obj_t * ui_Panel3;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Label2;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Label4;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Label3;
// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
void ui_event_Screen2(lv_event_t * e);
extern lv_obj_t * ui_Screen2;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Label5;
// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
void ui_event_Screen3(lv_event_t * e);
extern lv_obj_t * ui_Screen3;
void ui_event_Panel4(lv_event_t * e);
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Panel5;
// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
void ui_event_Screen4(lv_event_t * e);
extern lv_obj_t * ui_Screen4;
extern lv_obj_t * ui_Panel6;
extern lv_obj_t * ui_nomeComp;
extern lv_obj_t * ui_item2;
extern lv_obj_t * ui_item3;
extern lv_obj_t * ui_item4;
extern lv_obj_t * ui_item5;
void ui_event_Panel7(lv_event_t * e);
extern lv_obj_t * ui_Panel7;
extern lv_obj_t * ui_Bar1;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Label6;
void ui_event_Panel8(lv_event_t * e);
extern lv_obj_t * ui_Panel8;
void ui_event_Image2(lv_event_t * e);
extern lv_obj_t * ui_Image2;
// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
void ui_event_Screen5(lv_event_t * e);
extern lv_obj_t * ui_Screen5;
extern lv_obj_t * ui_Keyboard1;
extern lv_obj_t * ui_TextArea1;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_stopwatch_201x256_png);    // assets/stopwatch.201x256.png
LV_IMG_DECLARE(ui_img_919423605);    // assets/settings-svgrepo-com (1).png






void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
