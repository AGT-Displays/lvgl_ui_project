/**
 * @file text_entry_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "text_entry_gen.h"
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

lv_obj_t * text_entry_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_text_panel;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_text_panel);
            lv_style_set_bg_color(&style_text_panel, COL_CARD);
            lv_style_set_bg_opa(&style_text_panel, (255 * 100 / 100));
            lv_style_set_radius(&style_text_panel, RADIUS_CARD);
            lv_style_set_border_width(&style_text_panel, 0);
            lv_style_set_pad_all(&style_text_panel, 20);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (text_entry == NULL) text_entry = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = text_entry;
        lv_obj_set_name_static(lv_obj_0, "text_entry_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "Entrada de texto", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_style_pad_bottom(lv_obj_1, 8, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_2, lv_pct(100));
        lv_obj_set_height(lv_obj_2, lv_pct(100));
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_2, &style_text_panel, 0);
        lv_obj_bind_flag_if_not_eq(lv_obj_2, &subject_text_kb_visible, LV_OBJ_FLAG_HIDDEN, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_2);
        lv_label_bind_text(lv_label_0, &subject_entry_text, NULL);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, text_20, 0);
        lv_label_set_long_mode(lv_label_0, LV_LABEL_LONG_MODE_WRAP);
        lv_obj_set_width(lv_label_0, lv_pct(100));

        lv_obj_add_subject_set_int_event(lv_obj_2, &subject_text_kb_visible, LV_EVENT_CLICKED, 1);

        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_3, lv_pct(100));
        lv_obj_set_height(lv_obj_3, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_3, 0, 0);
        lv_obj_set_style_border_width(lv_obj_3, 0, 0);
        lv_obj_set_style_pad_row(lv_obj_3, 10, 0);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_bind_flag_if_not_eq(lv_obj_3, &subject_text_kb_visible, LV_OBJ_FLAG_HIDDEN, 1);
        lv_obj_t * entry_ta = lv_textarea_create(lv_obj_3);
        lv_obj_set_name(entry_ta, "entry_ta");
        lv_obj_set_width(entry_ta, lv_pct(100));
        lv_obj_set_height(entry_ta, 56);
        lv_textarea_set_one_line(entry_ta, true);
        lv_textarea_set_placeholder_text(entry_ta, "Type new text...");

        lv_obj_t * entry_kb = lv_keyboard_create(lv_obj_3);
        lv_obj_set_name(entry_kb, "entry_kb");
        lv_obj_set_width(entry_kb, lv_pct(100));
        lv_obj_set_flex_grow(entry_kb, 1);
        lv_keyboard_set_mode(entry_kb, LV_KEYBOARD_MODE_TEXT_LOWER);
        lv_keyboard_set_textarea(entry_kb, entry_ta);
        lv_obj_add_event_cb(entry_kb, text_entry_confirm_cb, LV_EVENT_READY, "entry_ta");
        lv_obj_add_subject_set_int_event(entry_kb, &subject_text_kb_visible, LV_EVENT_CANCEL, 0);

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

