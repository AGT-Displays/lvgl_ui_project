/**
 * @file brightness_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "brightness_gen.h"
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

lv_obj_t * brightness_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bright_card;
    static lv_style_t style_bright_card_checked;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_bright_card);
            lv_style_set_width(&style_bright_card, 150);
            lv_style_set_height(&style_bright_card, 170);
            lv_style_set_radius(&style_bright_card, RADIUS_CARD);
            lv_style_set_bg_opa(&style_bright_card, (255 * 100 / 100));
            lv_style_set_border_width(&style_bright_card, 0);

            lv_style_init(&style_bright_card_checked);
            lv_style_set_bg_color(&style_bright_card_checked, COL_BLUE);
            lv_style_set_bg_grad_color(&style_bright_card_checked, lv_color_hex(0x1c6fd0));
            lv_style_set_bg_grad_dir(&style_bright_card_checked, LV_GRAD_DIR_VER);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (brightness == NULL) brightness = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = brightness;
        lv_obj_set_name_static(lv_obj_0, "brightness_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "Brilho", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_align(lv_obj_2, LV_ALIGN_CENTER);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_obj_2, lv_pct(100));
        lv_obj_set_height(lv_obj_2, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_style_pad_hor(lv_obj_2, 20, 0);
        lv_obj_set_style_pad_column(lv_obj_2, 16, 0);
        lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_0, COL_CARD_LIGHT, 0);
        lv_obj_add_style(lv_button_0, &style_bright_card, 0);
        lv_obj_add_style(lv_button_0, &style_bright_card_checked, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_0, &subject_brightness, LV_STATE_CHECKED, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "0");
        lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, text_14, 0);

        lv_obj_t * lv_label_1 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_1, "");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, icon_32, 0);

        lv_obj_add_subject_set_int_event(lv_button_0, &subject_brightness, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_1, COL_CARD_LIGHT, 0);
        lv_obj_add_style(lv_button_1, &style_bright_card, 0);
        lv_obj_add_style(lv_button_1, &style_bright_card_checked, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_1, &subject_brightness, LV_STATE_CHECKED, 30);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_2, "30");
        lv_obj_set_align(lv_label_2, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_style_text_color(lv_label_2, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_2, text_14, 0);

        lv_obj_t * lv_label_3 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_3, "");
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_3, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_3, icon_32, 0);

        lv_obj_add_subject_set_int_event(lv_button_1, &subject_brightness, LV_EVENT_CLICKED, 30);

        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_2, COL_CARD_LIGHT, 0);
        lv_obj_add_style(lv_button_2, &style_bright_card, 0);
        lv_obj_add_style(lv_button_2, &style_bright_card_checked, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_2, &subject_brightness, LV_STATE_CHECKED, 70);
        lv_obj_t * lv_label_4 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_4, "70");
        lv_obj_set_align(lv_label_4, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_style_text_color(lv_label_4, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_4, text_14, 0);

        lv_obj_t * lv_label_5 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_5, "");
        lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_5, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_5, icon_32, 0);

        lv_obj_add_subject_set_int_event(lv_button_2, &subject_brightness, LV_EVENT_CLICKED, 70);

        lv_obj_t * lv_button_3 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_3, COL_CARD_LIGHT, 0);
        lv_obj_add_style(lv_button_3, &style_bright_card, 0);
        lv_obj_add_style(lv_button_3, &style_bright_card_checked, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_3, &subject_brightness, LV_STATE_CHECKED, 100);
        lv_obj_t * lv_label_6 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_6, "100");
        lv_obj_set_align(lv_label_6, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_style_text_color(lv_label_6, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_6, text_14, 0);

        lv_obj_t * lv_label_7 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_7, "");
        lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_7, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_7, icon_32, 0);

        lv_obj_add_subject_set_int_event(lv_button_3, &subject_brightness, LV_EVENT_CLICKED, 100);

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

