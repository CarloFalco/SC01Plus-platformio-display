// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image5 = lv_img_create(ui_Screen1);
    lv_img_set_src(ui_Image5, &ui_img_1478022232);
    lv_obj_set_width(ui_Image5, LV_SIZE_CONTENT);   /// 427
    lv_obj_set_height(ui_Image5, LV_SIZE_CONTENT);    /// 320
    lv_obj_set_x(ui_Image5, 8);
    lv_obj_set_y(ui_Image5, -6);
    lv_obj_set_align(ui_Image5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_Image5, 300);

    ui_Button1 = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_Button1, 156);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, lv_pct(-24));
    lv_obj_set_y(ui_Button1, lv_pct(-6));
    lv_obj_set_align(ui_Button1, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Button");

}
