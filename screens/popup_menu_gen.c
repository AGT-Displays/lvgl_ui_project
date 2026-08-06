/**
 * @file popup_menu_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "popup_menu_gen.h"
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

lv_obj_t * popup_menu_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_plus_btn;
    static lv_style_t style_icon_pill;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_plus_btn);
            lv_style_set_width(&style_plus_btn, 64);
            lv_style_set_height(&style_plus_btn, 64);
            lv_style_set_radius(&style_plus_btn, 180);
            lv_style_set_bg_opa(&style_plus_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_plus_btn, 0);

            lv_style_init(&style_icon_pill);
            lv_style_set_width(&style_icon_pill, 480);
            lv_style_set_height(&style_icon_pill, 64);
            lv_style_set_bg_color(&style_icon_pill, COL_CARD);
            lv_style_set_bg_opa(&style_icon_pill, (255 * 100 / 100));
            lv_style_set_radius(&style_icon_pill, 180);
            lv_style_set_border_width(&style_icon_pill, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (popup_menu == NULL) popup_menu = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = popup_menu;
        lv_obj_set_name_static(lv_obj_0, "popup_menu_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "Menu popup", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_style_pad_row(lv_obj_1, 28, 0);
        lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_2, lv_pct(100));
        lv_obj_set_height(lv_obj_2, 72);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
        lv_obj_set_align(lv_obj_3, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_obj_3, 60);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_obj_3, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_3, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_opa(lv_obj_3, 0, 0);
        lv_obj_set_style_border_width(lv_obj_3, 0, 0);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_3);
        lv_obj_set_flex_flow(lv_obj_4, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_4, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_pad_left(lv_obj_4, 76, 0);
        lv_obj_set_style_pad_right(lv_obj_4, 24, 0);
        lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_4, &style_icon_pill, 0);
        lv_obj_bind_flag_if_not_eq(lv_obj_4, &subject_expanded_row, LV_OBJ_FLAG_HIDDEN, 1);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_0, "");
        lv_obj_set_flag(lv_label_0, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_0, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_0, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_1, "");
        lv_obj_set_flag(lv_label_1, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_1, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_1, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_1, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_2 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_flag(lv_label_2, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_2, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_2, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_3, "");
        lv_obj_set_flag(lv_label_3, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_3, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_3, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_3, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_3);
        lv_obj_set_align(lv_button_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_flag(lv_button_0, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_0, COL_BLUE, 0);
        lv_obj_add_style(lv_button_0, &style_plus_btn, 0);
        lv_obj_t * lv_label_4 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_4, "");
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_4, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_4, icon_32, 0);

        lv_obj_add_event_cb(lv_button_0, popup_toggle_row_cb, LV_EVENT_CLICKED, "1");

        lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_5, lv_pct(100));
        lv_obj_set_height(lv_obj_5, 72);
        lv_obj_set_style_bg_opa(lv_obj_5, 0, 0);
        lv_obj_set_style_border_width(lv_obj_5, 0, 0);
        lv_obj_set_flag(lv_obj_5, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_5);
        lv_obj_set_align(lv_obj_6, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(lv_obj_6, -60);
        lv_obj_set_flag(lv_obj_6, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_obj_6, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_6, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_opa(lv_obj_6, 0, 0);
        lv_obj_set_style_border_width(lv_obj_6, 0, 0);
        lv_obj_set_flag(lv_obj_6, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_6);
        lv_obj_set_flex_flow(lv_obj_7, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_7, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_7, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_pad_left(lv_obj_7, 24, 0);
        lv_obj_set_style_pad_right(lv_obj_7, 76, 0);
        lv_obj_set_flag(lv_obj_7, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_7, &style_icon_pill, 0);
        lv_obj_bind_flag_if_not_eq(lv_obj_7, &subject_expanded_row, LV_OBJ_FLAG_HIDDEN, 2);
        lv_obj_t * lv_label_5 = lv_label_create(lv_obj_7);
        lv_label_set_text(lv_label_5, "");
        lv_obj_set_flag(lv_label_5, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_5, COL_PURPLE, 0);
        lv_obj_set_style_text_font(lv_label_5, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_5, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_6 = lv_label_create(lv_obj_7);
        lv_label_set_text(lv_label_6, "");
        lv_obj_set_flag(lv_label_6, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_6, COL_PURPLE, 0);
        lv_obj_set_style_text_font(lv_label_6, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_6, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_7 = lv_label_create(lv_obj_7);
        lv_label_set_text(lv_label_7, "");
        lv_obj_set_flag(lv_label_7, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_7, COL_PURPLE, 0);
        lv_obj_set_style_text_font(lv_label_7, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_7, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_8 = lv_label_create(lv_obj_7);
        lv_label_set_text(lv_label_8, "");
        lv_obj_set_flag(lv_label_8, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_8, COL_PURPLE, 0);
        lv_obj_set_style_text_font(lv_label_8, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_8, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_6);
        lv_obj_set_align(lv_button_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_flag(lv_button_1, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_1, COL_PURPLE, 0);
        lv_obj_add_style(lv_button_1, &style_plus_btn, 0);
        lv_obj_t * lv_label_9 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_9, "");
        lv_obj_set_align(lv_label_9, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_9, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_9, icon_32, 0);

        lv_obj_add_event_cb(lv_button_1, popup_toggle_row_cb, LV_EVENT_CLICKED, "2");

        lv_obj_t * lv_obj_8 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_8, lv_pct(100));
        lv_obj_set_height(lv_obj_8, 72);
        lv_obj_set_style_bg_opa(lv_obj_8, 0, 0);
        lv_obj_set_style_border_width(lv_obj_8, 0, 0);
        lv_obj_set_flag(lv_obj_8, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_9 = lv_obj_create(lv_obj_8);
        lv_obj_set_align(lv_obj_9, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_obj_9, 60);
        lv_obj_set_flag(lv_obj_9, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_obj_9, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_9, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_opa(lv_obj_9, 0, 0);
        lv_obj_set_style_border_width(lv_obj_9, 0, 0);
        lv_obj_set_flag(lv_obj_9, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_10 = lv_obj_create(lv_obj_9);
        lv_obj_set_flex_flow(lv_obj_10, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_10, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_10, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_pad_left(lv_obj_10, 76, 0);
        lv_obj_set_style_pad_right(lv_obj_10, 24, 0);
        lv_obj_set_flag(lv_obj_10, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_10, &style_icon_pill, 0);
        lv_obj_bind_flag_if_not_eq(lv_obj_10, &subject_expanded_row, LV_OBJ_FLAG_HIDDEN, 3);
        lv_obj_t * lv_label_10 = lv_label_create(lv_obj_10);
        lv_label_set_text(lv_label_10, "");
        lv_obj_set_flag(lv_label_10, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_10, COL_YELLOW, 0);
        lv_obj_set_style_text_font(lv_label_10, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_10, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_11 = lv_label_create(lv_obj_10);
        lv_label_set_text(lv_label_11, "");
        lv_obj_set_flag(lv_label_11, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_11, COL_YELLOW, 0);
        lv_obj_set_style_text_font(lv_label_11, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_11, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_12 = lv_label_create(lv_obj_10);
        lv_label_set_text(lv_label_12, "");
        lv_obj_set_flag(lv_label_12, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_12, COL_YELLOW, 0);
        lv_obj_set_style_text_font(lv_label_12, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_12, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_label_13 = lv_label_create(lv_obj_10);
        lv_label_set_text(lv_label_13, "");
        lv_obj_set_flag(lv_label_13, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_style_text_color(lv_label_13, COL_YELLOW, 0);
        lv_obj_set_style_text_font(lv_label_13, icon_32, 0);
        lv_obj_add_subject_set_int_event(lv_label_13, &subject_expanded_row, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_9);
        lv_obj_set_align(lv_button_2, LV_ALIGN_LEFT_MID);
        lv_obj_set_flag(lv_button_2, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(lv_button_2, COL_YELLOW, 0);
        lv_obj_add_style(lv_button_2, &style_plus_btn, 0);
        lv_obj_t * lv_label_14 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_14, "");
        lv_obj_set_align(lv_label_14, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_14, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_14, icon_32, 0);

        lv_obj_add_event_cb(lv_button_2, popup_toggle_row_cb, LV_EVENT_CLICKED, "3");

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

