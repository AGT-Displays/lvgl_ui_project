/**
 * @file number_input_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "number_input_gen.h"
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

lv_obj_t * number_input_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_arrow_btn;
    static lv_style_t style_kb_panel;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_arrow_btn);
            lv_style_set_width(&style_arrow_btn, 160);
            lv_style_set_height(&style_arrow_btn, 30);
            lv_style_set_radius(&style_arrow_btn, 10);
            lv_style_set_bg_color(&style_arrow_btn, COL_CARD);
            lv_style_set_bg_opa(&style_arrow_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_arrow_btn, 0);

            lv_style_init(&style_kb_panel);
            lv_style_set_bg_color(&style_kb_panel, COL_CARD);
            lv_style_set_bg_opa(&style_kb_panel, (255 * 100 / 100));
            lv_style_set_radius(&style_kb_panel, RADIUS_CARD);
            lv_style_set_border_width(&style_kb_panel, 0);
            lv_style_set_pad_all(&style_kb_panel, 10);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (number_input == NULL) number_input = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = number_input;
        lv_obj_set_name_static(lv_obj_0, "number_input_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "WordArt e teclado numérico", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_style_pad_column(lv_obj_1, 20, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_flex_grow(lv_obj_2, 1);
        lv_obj_set_height(lv_obj_2, lv_pct(100));
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_2, 10, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_add_style(lv_button_0, &style_arrow_btn, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_14, 0);

        lv_subject_increment_dsc_t * subject_increment_event_0 = lv_obj_add_subject_increment_event(lv_button_0, &subject_numval, LV_EVENT_CLICKED, 1);
        lv_obj_set_subject_increment_event_min_value(lv_button_0, subject_increment_event_0, 0);
        lv_obj_set_subject_increment_event_max_value(lv_button_0, subject_increment_event_0, 99);

        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_2);
        lv_obj_set_width(lv_obj_3, 350);
        lv_obj_set_height(lv_obj_3, 196);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_bg_color(lv_obj_3, COL_CARD, 0);
        lv_obj_set_style_bg_opa(lv_obj_3, (255 * 100 / 100), 0);
        lv_obj_set_style_border_width(lv_obj_3, 0, 0);
        lv_obj_set_style_radius(lv_obj_3, RADIUS_CARD, 0);
        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_3);
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_label_bind_text(lv_label_1, &subject_numval, NULL);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, text_128, 0);

        lv_obj_add_subject_toggle_event(lv_obj_3, &subject_kb_visible, LV_EVENT_CLICKED);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_add_style(lv_button_1, &style_arrow_btn, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_2, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_14, 0);

        lv_subject_increment_dsc_t * subject_increment_event_1 = lv_obj_add_subject_increment_event(lv_button_1, &subject_numval, LV_EVENT_CLICKED, -1);
        lv_obj_set_subject_increment_event_min_value(lv_button_1, subject_increment_event_1, 0);
        lv_obj_set_subject_increment_event_max_value(lv_button_1, subject_increment_event_1, 99);

        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
        lv_obj_set_flex_grow(lv_obj_4, 1);
        lv_obj_set_height(lv_obj_4, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_4, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_4, 8, 0);
        lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_4, &style_kb_panel, 0);
        lv_obj_bind_flag_if_eq(lv_obj_4, &subject_kb_visible, LV_OBJ_FLAG_HIDDEN, 0);
        lv_obj_t * numval_ta = lv_textarea_create(lv_obj_4);
        lv_obj_set_name(numval_ta, "numval_ta");
        lv_obj_set_width(numval_ta, lv_pct(100));
        lv_obj_set_height(numval_ta, 40);
        lv_textarea_set_one_line(numval_ta, true);
        lv_textarea_set_placeholder_text(numval_ta, "0");

        lv_obj_t * numval_kb = lv_keyboard_create(lv_obj_4);
        lv_obj_set_name(numval_kb, "numval_kb");
        lv_obj_set_width(numval_kb, lv_pct(100));
        lv_obj_set_height(numval_kb, 200);
        lv_keyboard_set_mode(numval_kb, LV_KEYBOARD_MODE_USER_1);
        lv_keyboard_set_textarea(numval_kb, numval_ta);
        lv_obj_add_event_cb(numval_kb, number_keypad_key_cb, LV_EVENT_VALUE_CHANGED, "numval_ta");

        lv_obj_add_event_cb(lv_obj_0, setup_number_keypad_cb, LV_EVENT_SCREEN_LOADED, "numval_kb");
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

