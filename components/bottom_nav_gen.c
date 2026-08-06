/**
 * @file bottom_nav_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bottom_nav_gen.h"
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

lv_obj_t * bottom_nav_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dot_btn;
    static lv_style_t style_dot_btn_pressed;
    static lv_style_t style_nav_divider;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_dot_btn);
            lv_style_set_radius(&style_dot_btn, 180);
            lv_style_set_width(&style_dot_btn, 70);
            lv_style_set_height(&style_dot_btn, 70);
            lv_style_set_bg_opa(&style_dot_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_dot_btn, 0);
            lv_style_set_shadow_width(&style_dot_btn, 0);

            lv_style_init(&style_dot_btn_pressed);
            lv_style_set_transform_width(&style_dot_btn_pressed, -6);
            lv_style_set_transform_height(&style_dot_btn_pressed, -6);

            lv_style_init(&style_nav_divider);
            lv_style_set_bg_color(&style_nav_divider, COL_TEXT_DIM);
            lv_style_set_bg_opa(&style_nav_divider, (255 * 40 / 100));
            lv_style_set_border_width(&style_nav_divider, 0);
            lv_style_set_height(&style_nav_divider, 1);
            lv_style_set_width(&style_nav_divider, lv_pct(100));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "bottom_nav_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, 96);
        lv_obj_set_align(lv_obj_0, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
        lv_obj_set_style_border_width(lv_obj_0, 0, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 10, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_add_style(lv_obj_1, &style_nav_divider, 0);

        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_2, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_2, 1);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_set_align(lv_button_0, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_0, -274);
        lv_obj_set_flag(lv_button_0, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_0, COL_PURPLE, 0);
        lv_obj_add_style(lv_button_0, &style_dot_btn, 0);
        lv_obj_add_style(lv_button_0, &style_dot_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_24, 0);

        lv_obj_add_screen_load_event(lv_button_0, LV_EVENT_CLICKED, number_input, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_set_align(lv_button_1, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_1, -137);
        lv_obj_set_flag(lv_button_1, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_1, COL_RED, 0);
        lv_obj_add_style(lv_button_1, &style_dot_btn, 0);
        lv_obj_add_style(lv_button_1, &style_dot_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, icon_24, 0);

        lv_obj_add_screen_load_event(lv_button_1, LV_EVENT_CLICKED, animation, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_2);
        lv_obj_set_align(lv_button_2, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_2, 0);
        lv_obj_set_flag(lv_button_2, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_2, COL_TEAL, 0);
        lv_obj_add_style(lv_button_2, &style_dot_btn, 0);
        lv_obj_add_style(lv_button_2, &style_dot_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_2, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_24, 0);

        lv_obj_add_screen_load_event(lv_button_2, LV_EVENT_CLICKED, icon_cycle, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_button_3 = lv_button_create(lv_obj_2);
        lv_obj_set_align(lv_button_3, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_3, 137);
        lv_obj_set_flag(lv_button_3, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_3, COL_BLUE, 0);
        lv_obj_add_style(lv_button_3, &style_dot_btn, 0);
        lv_obj_add_style(lv_button_3, &style_dot_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_3 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_3, "");
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_3, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_3, icon_24, 0);

        lv_obj_add_screen_load_event(lv_button_3, LV_EVENT_CLICKED, popup_menu, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_button_4 = lv_button_create(lv_obj_2);
        lv_obj_set_align(lv_button_4, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_4, 274);
        lv_obj_set_flag(lv_button_4, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_4, COL_GREEN, 0);
        lv_obj_add_style(lv_button_4, &style_dot_btn, 0);
        lv_obj_add_style(lv_button_4, &style_dot_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_4 = lv_label_create(lv_button_4);
        lv_label_set_text(lv_label_4, "");
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_4, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_4, icon_24, 0);

        lv_obj_add_screen_load_event(lv_button_4, LV_EVENT_CLICKED, text_entry, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

