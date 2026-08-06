/**
 * @file animation_preview_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "animation_preview_gen.h"
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

lv_obj_t * animation_preview_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_preview_panel;
    static lv_style_t style_round_action_btn;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_preview_panel);
            lv_style_set_bg_color(&style_preview_panel, lv_color_hex(0x1c5f66));
            lv_style_set_bg_opa(&style_preview_panel, (255 * 100 / 100));
            lv_style_set_radius(&style_preview_panel, RADIUS_CARD);
            lv_style_set_border_width(&style_preview_panel, 0);

            lv_style_init(&style_round_action_btn);
            lv_style_set_width(&style_round_action_btn, 64);
            lv_style_set_height(&style_round_action_btn, 64);
            lv_style_set_radius(&style_round_action_btn, 180);
            lv_style_set_bg_opa(&style_round_action_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_round_action_btn, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "animation_preview_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
        lv_obj_set_style_border_width(lv_obj_0, 0, 0);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_column(lv_obj_0, 20, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_height(lv_obj_1, 260);
        lv_obj_set_style_flex_main_place(lv_obj_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_scrollbar_mode(lv_obj_1, LV_SCROLLBAR_MODE_OFF);
        lv_obj_add_style(lv_obj_1, &style_preview_panel, 0);
        lv_obj_t * anim_dot = lv_obj_create(lv_obj_1);
        lv_obj_set_name(anim_dot, "anim_dot");
        lv_obj_set_width(anim_dot, 48);
        lv_obj_set_height(anim_dot, 48);
        lv_obj_set_align(anim_dot, LV_ALIGN_CENTER);
        lv_obj_set_style_radius(anim_dot, 180, 0);
        lv_obj_set_style_bg_color(anim_dot, COL_YELLOW, 0);
        lv_obj_set_style_bg_opa(anim_dot, (255 * 100 / 100), 0);
        lv_obj_set_style_border_width(anim_dot, 0, 0);

        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_height(lv_obj_2, 260);
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_2, 20, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_0, COL_GREEN, 0);
        lv_obj_add_style(lv_button_0, &style_round_action_btn, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, icon_24, 0);

        lv_obj_add_event_cb(lv_button_0, anim_play_dot_cb, LV_EVENT_CLICKED, "anim_dot");
        lv_obj_add_subject_set_int_event(lv_button_0, &subject_anim_playing, LV_EVENT_CLICKED, 1);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_1, COL_RED, 0);
        lv_obj_add_style(lv_button_1, &style_round_action_btn, 0);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, icon_24, 0);

        lv_obj_add_event_cb(lv_button_1, anim_stop_dot_cb, LV_EVENT_CLICKED, "anim_dot");
        lv_obj_add_subject_set_int_event(lv_button_1, &subject_anim_playing, LV_EVENT_CLICKED, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

