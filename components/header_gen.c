/**
 * @file header_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "header_gen.h"
#include "../lvgl_ui_project.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * header_create(lv_obj_t * parent, const char * title, const char * icon)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "header_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, 64);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
        lv_obj_set_style_border_width(lv_obj_0, 0, 0);
        lv_obj_set_style_pad_hor(lv_obj_0, 20, 0);
        lv_obj_set_style_pad_top(lv_obj_0, 16, 0);
        lv_obj_set_style_pad_bottom(lv_obj_0, 0, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_height(lv_obj_1, 44);
        lv_obj_set_style_flex_cross_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_column(lv_obj_1, 10, 0);
        lv_obj_set_style_pad_hor(lv_obj_1, 18, 0);
        lv_obj_add_style(lv_obj_1, &style_header_pill, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
        lv_label_set_text(lv_label_0, icon);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_18, 0);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
        lv_label_set_text(lv_label_1, title);
        lv_obj_add_style(lv_label_1, &style_header_title, 0);

        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
        lv_obj_set_width(lv_button_0, 44);
        lv_obj_set_height(lv_button_0, 44);
        lv_obj_set_align(lv_button_0, LV_ALIGN_RIGHT_MID);
        lv_obj_set_style_bg_color(lv_button_0, COL_CARD, 0);
        lv_obj_add_style(lv_button_0, &style_nav_icon_btn, 0);
        lv_obj_add_style(lv_button_0, &style_nav_icon_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_2, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_18, 0);

        lv_obj_add_screen_load_event(lv_button_0, LV_EVENT_CLICKED, main_menu, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

