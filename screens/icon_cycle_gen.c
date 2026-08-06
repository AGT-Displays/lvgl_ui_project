/**
 * @file icon_cycle_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_cycle_gen.h"
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

lv_obj_t * icon_cycle_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_icon_btn;
    static lv_style_t style_center_panel;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_icon_btn);
            lv_style_set_width(&style_icon_btn, 170);
            lv_style_set_height(&style_icon_btn, 56);
            lv_style_set_radius(&style_icon_btn, RADIUS_PILL);
            lv_style_set_bg_opa(&style_icon_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_icon_btn, 0);

            lv_style_init(&style_center_panel);
            lv_style_set_width(&style_center_panel, 180);
            lv_style_set_height(&style_center_panel, 180);
            lv_style_set_bg_color(&style_center_panel, COL_CARD);
            lv_style_set_bg_opa(&style_center_panel, (255 * 100 / 100));
            lv_style_set_radius(&style_center_panel, RADIUS_CARD);
            lv_style_set_border_width(&style_center_panel, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (icon_cycle == NULL) icon_cycle = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = icon_cycle;
        lv_obj_set_name_static(lv_obj_0, "icon_cycle_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "Ícones variáveis", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_2, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_2, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_2, 24, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_0, COL_GREEN, 0);
        lv_obj_add_style(lv_button_0, &style_icon_btn, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "ICON 1");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, text_16, 0);

        lv_obj_add_subject_set_int_event(lv_button_0, &subject_current_icon, LV_EVENT_CLICKED, 1);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_1, COL_BLUE, 0);
        lv_obj_add_style(lv_button_1, &style_icon_btn, 0);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "ICON 2");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, text_16, 0);

        lv_obj_add_subject_set_int_event(lv_button_1, &subject_current_icon, LV_EVENT_CLICKED, 2);

        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
        lv_obj_set_align(lv_obj_3, LV_ALIGN_CENTER);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_3, &style_center_panel, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_2, "");
        lv_obj_set_align(lv_label_2, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_2, COL_TEAL, 0);
        lv_obj_set_style_text_font(lv_label_2, icon_48, 0);
        lv_obj_bind_flag_if_not_eq(lv_label_2, &subject_current_icon, LV_OBJ_FLAG_HIDDEN, 1);

        lv_obj_t * lv_label_3 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_3, "");
        lv_obj_set_align(lv_label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_3, COL_BLUE, 0);
        lv_obj_set_style_text_font(lv_label_3, icon_48, 0);
        lv_obj_bind_flag_if_not_eq(lv_label_3, &subject_current_icon, LV_OBJ_FLAG_HIDDEN, 2);

        lv_obj_t * lv_label_4 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_4, "");
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_4, COL_PURPLE, 0);
        lv_obj_set_style_text_font(lv_label_4, icon_48, 0);
        lv_obj_bind_flag_if_not_eq(lv_label_4, &subject_current_icon, LV_OBJ_FLAG_HIDDEN, 3);

        lv_obj_t * lv_label_5 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_5, "");
        lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_5, COL_RED, 0);
        lv_obj_set_style_text_font(lv_label_5, icon_48, 0);
        lv_obj_bind_flag_if_not_eq(lv_label_5, &subject_current_icon, LV_OBJ_FLAG_HIDDEN, 4);

        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_4, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_4, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_4, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_4, 0, 0);
        lv_obj_set_style_border_width(lv_obj_4, 0, 0);
        lv_obj_set_style_flex_main_place(lv_obj_4, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_4, 24, 0);
        lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_4);
        lv_obj_set_style_bg_color(lv_button_2, COL_PURPLE, 0);
        lv_obj_add_style(lv_button_2, &style_icon_btn, 0);
        lv_obj_t * lv_label_6 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_6, "ICON 3");
        lv_obj_set_align(lv_label_6, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_6, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_6, text_16, 0);

        lv_obj_add_subject_set_int_event(lv_button_2, &subject_current_icon, LV_EVENT_CLICKED, 3);

        lv_obj_t * lv_button_3 = lv_button_create(lv_obj_4);
        lv_obj_set_style_bg_color(lv_button_3, COL_RED, 0);
        lv_obj_add_style(lv_button_3, &style_icon_btn, 0);
        lv_obj_t * lv_label_7 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_7, "ICON 4");
        lv_obj_set_align(lv_label_7, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_7, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_7, text_16, 0);

        lv_obj_add_subject_set_int_event(lv_button_3, &subject_current_icon, LV_EVENT_CLICKED, 4);

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

