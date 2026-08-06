/**
 * @file main_menu_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "main_menu_gen.h"
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

lv_obj_t * main_menu_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_temp_arc_bg;
    static lv_style_t style_temp_arc_ind;
    static lv_style_t style_temp_arc_knob;
    static lv_style_t style_mini_round_btn;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_temp_arc_bg);
            lv_style_set_arc_color(&style_temp_arc_bg, lv_color_hex(0xffffff));
            lv_style_set_arc_opa(&style_temp_arc_bg, (255 * 60 / 100));
            lv_style_set_arc_width(&style_temp_arc_bg, 10);
            lv_style_set_arc_rounded(&style_temp_arc_bg, true);

            lv_style_init(&style_temp_arc_ind);
            lv_style_set_arc_color(&style_temp_arc_ind, lv_color_hex(0xffe08a));
            lv_style_set_arc_width(&style_temp_arc_ind, 10);
            lv_style_set_arc_rounded(&style_temp_arc_ind, true);

            lv_style_init(&style_temp_arc_knob);
            lv_style_set_bg_color(&style_temp_arc_knob, lv_color_hex(0xffe08a));
            lv_style_set_bg_opa(&style_temp_arc_knob, (255 * 100 / 100));
            lv_style_set_border_width(&style_temp_arc_knob, 0);

            lv_style_init(&style_mini_round_btn);
            lv_style_set_radius(&style_mini_round_btn, 180);
            lv_style_set_bg_color(&style_mini_round_btn, COL_CARD_LIGHT);
            lv_style_set_bg_opa(&style_mini_round_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_mini_round_btn, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (main_menu == NULL) main_menu = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = main_menu;
        lv_obj_set_name_static(lv_obj_0, "main_menu_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_height(lv_obj_1, 72);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_scrollbar_mode(lv_obj_1, LV_SCROLLBAR_MODE_OFF);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_1);
        lv_obj_set_width(lv_button_0, 44);
        lv_obj_set_height(lv_button_0, 44);
        lv_obj_set_style_bg_color(lv_button_0, COL_CARD, 0);
        lv_obj_add_style(lv_button_0, &style_nav_icon_btn, 0);
        lv_obj_add_style(lv_button_0, &style_nav_icon_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_18, 0);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_1);
        lv_obj_set_width(lv_button_1, 44);
        lv_obj_set_height(lv_button_1, 44);
        lv_obj_set_style_bg_color(lv_button_1, COL_CARD, 0);
        lv_obj_add_style(lv_button_1, &style_nav_icon_btn, 0);
        lv_obj_add_style(lv_button_1, &style_nav_icon_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "BRT");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_1, COL_YELLOW, 0);
        lv_obj_set_style_text_font(lv_label_1, text_14, 0);

        lv_obj_add_screen_load_event(lv_button_1, LV_EVENT_CLICKED, brightness, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_2, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_2, 1);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_hor(lv_obj_2, 20, 0);
        lv_obj_set_style_pad_column(lv_obj_2, 16, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
        lv_obj_set_flex_grow(lv_obj_3, 1);
        lv_obj_set_height(lv_obj_3, lv_pct(100));
        lv_obj_set_style_bg_opa(lv_obj_3, 0, 0);
        lv_obj_set_style_border_width(lv_obj_3, 0, 0);
        lv_obj_set_style_pad_all(lv_obj_3, 0, 0);
        lv_obj_set_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_3, 16, 0);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_3);
        lv_obj_set_flex_grow(lv_button_2, 1);
        lv_obj_set_width(lv_button_2, lv_pct(100));
        lv_obj_set_style_bg_color(lv_button_2, COL_PURPLE, 0);
        lv_obj_add_style(lv_button_2, &style_card, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_2, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_32, 0);

        lv_obj_add_screen_load_event(lv_button_2, LV_EVENT_CLICKED, wifi_config, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_button_3 = lv_button_create(lv_obj_3);
        lv_obj_set_flex_grow(lv_button_3, 1);
        lv_obj_set_width(lv_button_3, lv_pct(100));
        lv_obj_set_style_bg_color(lv_button_3, COL_TEAL, 0);
        lv_obj_add_style(lv_button_3, &style_card, 0);
        lv_obj_t * lv_label_3 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_3, "123");
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_3, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_3, text_32, 0);

        lv_obj_add_screen_load_event(lv_button_3, LV_EVENT_CLICKED, number_input, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_2);
        lv_obj_set_flex_grow(lv_obj_4, 1);
        lv_obj_set_height(lv_obj_4, lv_pct(100));
        lv_obj_set_style_bg_color(lv_obj_4, COL_RED, 0);
        lv_obj_set_style_bg_opa(lv_obj_4, (255 * 100 / 100), 0);
        lv_obj_set_style_border_width(lv_obj_4, 0, 0);
        lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_scrollbar_mode(lv_obj_4, LV_SCROLLBAR_MODE_OFF);
        lv_obj_add_style(lv_obj_4, &style_card, 0);
        lv_obj_t * lv_arc_0 = lv_arc_create(lv_obj_4);
        lv_obj_set_align(lv_arc_0, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_arc_0, -45);
        lv_obj_set_flag(lv_arc_0, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_arc_0, 120);
        lv_obj_set_height(lv_arc_0, 120);
        lv_arc_set_min_value(lv_arc_0, 0);
        lv_arc_set_max_value(lv_arc_0, 40);
        lv_arc_set_value(lv_arc_0, 20);
        lv_arc_set_bg_start_angle(lv_arc_0, 120);
        lv_arc_set_bg_end_angle(lv_arc_0, 60);
        lv_obj_add_style(lv_arc_0, &style_temp_arc_bg, LV_PART_MAIN);
        lv_obj_add_style(lv_arc_0, &style_temp_arc_ind, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_0, &style_temp_arc_knob, LV_PART_KNOB);
        lv_obj_t * lv_label_4 = lv_label_create(lv_arc_0);
        lv_label_set_text(lv_label_4, "20°C");
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_4, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_4, text_18, 0);

        lv_obj_t * lv_label_5 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_5, "Temperatura do quarto");
        lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_label_5, 34);
        lv_obj_set_flag(lv_label_5, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_text_color(lv_label_5, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_5, text_14, 0);

        lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_4);
        lv_obj_set_align(lv_obj_5, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_obj_5, 79);
        lv_obj_set_flag(lv_obj_5, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_flag(lv_obj_5, LV_OBJ_FLAG_OVERFLOW_VISIBLE, true);
        lv_obj_set_width(lv_obj_5, 180);
        lv_obj_set_height(lv_obj_5, 76);
        lv_obj_set_style_bg_opa(lv_obj_5, 0, 0);
        lv_obj_set_style_border_width(lv_obj_5, 0, 0);
        lv_obj_set_style_pad_all(lv_obj_5, 0, 0);
        lv_obj_set_flag(lv_obj_5, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_4 = lv_button_create(lv_obj_5);
        lv_obj_set_align(lv_button_4, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_4, -54);
        lv_obj_set_flag(lv_button_4, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_button_4, 36);
        lv_obj_set_height(lv_button_4, 36);
        lv_obj_add_style(lv_button_4, &style_mini_round_btn, 0);
        lv_obj_t * lv_label_6 = lv_label_create(lv_button_4);
        lv_label_set_text(lv_label_6, "");
        lv_obj_set_align(lv_label_6, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_6, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_6, icon_14, 0);

        lv_obj_t * lv_button_5 = lv_button_create(lv_obj_5);
        lv_obj_set_align(lv_button_5, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_5, 0);
        lv_obj_set_flag(lv_button_5, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_button_5, 44);
        lv_obj_set_height(lv_button_5, 44);
        lv_obj_add_style(lv_button_5, &style_mini_round_btn, 0);
        lv_obj_t * lv_label_7 = lv_label_create(lv_button_5);
        lv_label_set_text(lv_label_7, "");
        lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_7, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_7, icon_18, 0);

        lv_obj_t * lv_button_6 = lv_button_create(lv_obj_5);
        lv_obj_set_align(lv_button_6, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_button_6, 54);
        lv_obj_set_flag(lv_button_6, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_button_6, 36);
        lv_obj_set_height(lv_button_6, 36);
        lv_obj_add_style(lv_button_6, &style_mini_round_btn, 0);
        lv_obj_t * lv_label_8 = lv_label_create(lv_button_6);
        lv_label_set_text(lv_label_8, "");
        lv_obj_set_align(lv_label_8, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_8, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_8, icon_14, 0);

        lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_2);
        lv_obj_set_flex_grow(lv_obj_6, 1);
        lv_obj_set_height(lv_obj_6, lv_pct(100));
        lv_obj_set_style_bg_color(lv_obj_6, COL_BLUE, 0);
        lv_obj_set_style_bg_opa(lv_obj_6, (255 * 100 / 100), 0);
        lv_obj_set_style_border_width(lv_obj_6, 0, 0);
        lv_obj_set_flex_flow(lv_obj_6, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_6, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_6, 4, 0);
        lv_obj_set_flag(lv_obj_6, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_6, &style_card, 0);
        lv_obj_t * lv_label_9 = lv_label_create(lv_obj_6);
        lv_label_set_text(lv_label_9, "12°");
        lv_obj_set_style_text_color(lv_label_9, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_9, text_32, 0);

        lv_obj_t * lv_label_10 = lv_label_create(lv_obj_6);
        lv_label_set_text(lv_label_10, "Neve");
        lv_obj_set_style_text_color(lv_label_10, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_10, text_18, 0);

        lv_obj_t * lv_label_11 = lv_label_create(lv_obj_6);
        lv_label_set_text(lv_label_11, "Chengdu");
        lv_obj_set_style_text_color(lv_label_11, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_11, text_14, 0);

        bottom_nav_create(lv_obj_0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

