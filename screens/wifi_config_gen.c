/**
 * @file wifi_config_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "wifi_config_gen.h"
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

lv_obj_t * wifi_config_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_mode_btn;
    static lv_style_t style_mode_btn_active;
    static lv_style_t style_right_panel;
    static lv_style_t style_field_input;
    static lv_style_t style_divider;
    static lv_style_t style_qr_placeholder;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_mode_btn);
            lv_style_set_width(&style_mode_btn, 200);
            lv_style_set_height(&style_mode_btn, 64);
            lv_style_set_radius(&style_mode_btn, 14);
            lv_style_set_bg_opa(&style_mode_btn, (255 * 100 / 100));
            lv_style_set_border_width(&style_mode_btn, 0);

            lv_style_init(&style_mode_btn_active);
            lv_style_set_outline_width(&style_mode_btn_active, 3);
            lv_style_set_outline_opa(&style_mode_btn_active, (255 * 80 / 100));

            lv_style_init(&style_right_panel);
            lv_style_set_bg_color(&style_right_panel, COL_CARD);
            lv_style_set_bg_opa(&style_right_panel, (255 * 100 / 100));
            lv_style_set_radius(&style_right_panel, RADIUS_CARD);
            lv_style_set_border_width(&style_right_panel, 0);
            lv_style_set_pad_all(&style_right_panel, 10);

            lv_style_init(&style_field_input);
            lv_style_set_bg_color(&style_field_input, COL_BG);
            lv_style_set_bg_opa(&style_field_input, (255 * 100 / 100));
            lv_style_set_radius(&style_field_input, 10);
            lv_style_set_border_width(&style_field_input, 0);
            lv_style_set_width(&style_field_input, lv_pct(100));
            lv_style_set_height(&style_field_input, 34);
            lv_style_set_text_color(&style_field_input, COL_TEXT);

            lv_style_init(&style_divider);
            lv_style_set_bg_color(&style_divider, COL_TEXT_DIM);
            lv_style_set_bg_opa(&style_divider, (255 * 40 / 100));
            lv_style_set_border_width(&style_divider, 0);
            lv_style_set_height(&style_divider, 1);
            lv_style_set_width(&style_divider, lv_pct(100));

            lv_style_init(&style_qr_placeholder);
            lv_style_set_bg_color(&style_qr_placeholder, lv_color_hex(0xffffff));
            lv_style_set_bg_opa(&style_qr_placeholder, (255 * 100 / 100));
            lv_style_set_radius(&style_qr_placeholder, 8);
            lv_style_set_border_width(&style_qr_placeholder, 0);
            lv_style_set_width(&style_qr_placeholder, 110);
            lv_style_set_height(&style_qr_placeholder, 110);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (wifi_config == NULL) wifi_config = lv_obj_create(NULL);
        lv_obj_t * lv_obj_0 = wifi_config;
        lv_obj_set_name_static(lv_obj_0, "wifi_config_#");
        lv_obj_set_width(lv_obj_0, lv_pct(100));
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_screen_bg, 0);
        header_create(lv_obj_0, "Configuração de rede", "");

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_flex_grow(lv_obj_1, 1);
        lv_obj_set_style_bg_opa(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_hor(lv_obj_1, 20, 0);
        lv_obj_set_style_pad_column(lv_obj_1, 20, 0);
        lv_obj_set_style_pad_bottom(lv_obj_1, 8, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_set_width(lv_obj_2, LV_SIZE_CONTENT);
        lv_obj_set_height(lv_obj_2, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_2, 0, 0);
        lv_obj_set_style_border_width(lv_obj_2, 0, 0);
        lv_obj_set_style_pad_row(lv_obj_2, 16, 0);
        lv_obj_set_style_flex_main_place(lv_obj_2, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_2, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_0, COL_BLUE, 0);
        lv_obj_add_style(lv_button_0, &style_mode_btn, 0);
        lv_obj_add_style(lv_button_0, &style_mode_btn_active, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_0, &subject_wifi_mode, LV_STATE_CHECKED, 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "Rede manual");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(lv_label_0, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_0, text_16, 0);

        lv_obj_add_subject_set_int_event(lv_button_0, &subject_wifi_mode, LV_EVENT_CLICKED, 0);

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_2);
        lv_obj_set_style_bg_color(lv_button_1, COL_YELLOW, 0);
        lv_obj_add_style(lv_button_1, &style_mode_btn, 0);
        lv_obj_add_style(lv_button_1, &style_mode_btn_active, LV_STATE_CHECKED);
        lv_obj_bind_state_if_eq(lv_button_1, &subject_wifi_mode, LV_STATE_CHECKED, 1);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "Rede de compart. de chaves");
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_width(lv_label_1, 170);
        lv_label_set_long_mode(lv_label_1, LV_LABEL_LONG_MODE_WRAP);
        lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_style_text_color(lv_label_1, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_1, text_14, 0);

        lv_obj_add_subject_set_int_event(lv_button_1, &subject_wifi_mode, LV_EVENT_CLICKED, 1);

        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
        lv_obj_set_flex_grow(lv_obj_3, 1);
        lv_obj_set_height(lv_obj_3, lv_pct(100));
        lv_obj_set_flex_flow(lv_obj_3, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_3, 6, 0);
        lv_obj_set_style_flex_main_place(lv_obj_3, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_flag(lv_obj_3, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_add_style(lv_obj_3, &style_right_panel, 0);
        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_3);
        lv_obj_set_width(lv_obj_4, lv_pct(100));
        lv_obj_set_height(lv_obj_4, 190);
        lv_obj_set_flex_flow(lv_obj_4, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(lv_obj_4, 0, 0);
        lv_obj_set_style_border_width(lv_obj_4, 0, 0);
        lv_obj_set_style_pad_row(lv_obj_4, 6, 0);
        lv_obj_set_flag(lv_obj_4, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_bind_flag_if_not_eq(lv_obj_4, &subject_wifi_mode, LV_OBJ_FLAG_HIDDEN, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_2, "Nome da rede:");
        lv_obj_set_style_text_color(lv_label_2, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_2, text_14, 0);

        lv_obj_t * wifi_ssid_ta = lv_textarea_create(lv_obj_4);
        lv_obj_set_name(wifi_ssid_ta, "wifi_ssid_ta");
        lv_textarea_set_one_line(wifi_ssid_ta, true);
        lv_textarea_set_placeholder_text(wifi_ssid_ta, "SSID");
        lv_obj_add_style(wifi_ssid_ta, &style_field_input, 0);
        lv_obj_add_event_cb(wifi_ssid_ta, wifi_field_focus_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_3, "Senha:");
        lv_obj_set_style_text_color(lv_label_3, COL_TEXT, 0);
        lv_obj_set_style_text_font(lv_label_3, text_14, 0);

        lv_obj_t * wifi_pass_ta = lv_textarea_create(lv_obj_4);
        lv_obj_set_name(wifi_pass_ta, "wifi_pass_ta");
        lv_textarea_set_one_line(wifi_pass_ta, true);
        lv_textarea_set_password_mode(wifi_pass_ta, true);
        lv_textarea_set_placeholder_text(wifi_pass_ta, "Senha");
        lv_obj_add_style(wifi_pass_ta, &style_field_input, 0);
        lv_obj_add_event_cb(wifi_pass_ta, wifi_field_focus_cb, LV_EVENT_CLICKED, NULL);

        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_4);
        lv_obj_set_width(lv_button_2, 160);
        lv_obj_set_height(lv_button_2, 32);
        lv_obj_set_style_bg_color(lv_button_2, COL_BLUE, 0);
        lv_obj_add_style(lv_button_2, &style_pill_btn, 0);
        lv_obj_add_style(lv_button_2, &style_pill_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_4 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_4, "Iniciar");
        lv_obj_set_align(lv_label_4, LV_ALIGN_CENTER);

        lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_3);
        lv_obj_set_width(lv_obj_5, lv_pct(100));
        lv_obj_set_height(lv_obj_5, 190);
        lv_obj_set_style_bg_opa(lv_obj_5, 0, 0);
        lv_obj_set_style_border_width(lv_obj_5, 0, 0);
        lv_obj_set_flag(lv_obj_5, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_bind_flag_if_not_eq(lv_obj_5, &subject_wifi_mode, LV_OBJ_FLAG_HIDDEN, 1);
        lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_5);
        lv_obj_set_align(lv_obj_6, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_obj_6, -28);
        lv_obj_set_flag(lv_obj_6, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_add_style(lv_obj_6, &style_qr_placeholder, 0);

        lv_obj_t * lv_button_3 = lv_button_create(lv_obj_5);
        lv_obj_set_align(lv_button_3, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_button_3, 67);
        lv_obj_set_flag(lv_button_3, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_width(lv_button_3, 340);
        lv_obj_set_height(lv_button_3, 32);
        lv_obj_set_style_bg_color(lv_button_3, COL_BLUE, 0);
        lv_obj_add_style(lv_button_3, &style_pill_btn, 0);
        lv_obj_add_style(lv_button_3, &style_pill_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_5 = lv_label_create(lv_button_3);
        lv_label_set_text(lv_label_5, "Iniciar uma rede de compart. de chaves");
        lv_obj_set_align(lv_label_5, LV_ALIGN_CENTER);
        lv_obj_set_width(lv_label_5, 308);
        lv_label_set_long_mode(lv_label_5, LV_LABEL_LONG_MODE_WRAP);
        lv_obj_set_style_text_align(lv_label_5, LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_set_style_text_font(lv_label_5, text_14, 0);

        lv_obj_t * lv_obj_7 = lv_obj_create(lv_obj_3);
        lv_obj_add_style(lv_obj_7, &style_divider, 0);

        lv_obj_t * lv_label_6 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_6, "MAC:");
        lv_obj_set_style_text_color(lv_label_6, COL_TEXT_DIM, 0);
        lv_obj_set_style_text_font(lv_label_6, text_14, 0);

        lv_obj_t * lv_label_7 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_7, "Versão:");
        lv_obj_set_style_text_color(lv_label_7, COL_TEXT_DIM, 0);
        lv_obj_set_style_text_font(lv_label_7, text_14, 0);

        bottom_nav_create(lv_obj_0);

        lv_obj_t * wifi_kb = lv_keyboard_create(lv_obj_0);
        lv_obj_set_name(wifi_kb, "wifi_kb");
        lv_obj_set_width(wifi_kb, lv_pct(100));
        lv_obj_set_height(wifi_kb, 200);
        lv_obj_set_align(wifi_kb, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_flag(wifi_kb, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_keyboard_set_mode(wifi_kb, LV_KEYBOARD_MODE_TEXT_LOWER);
        lv_obj_bind_flag_if_eq(wifi_kb, &subject_wifi_kb_visible, LV_OBJ_FLAG_HIDDEN, 0);
        lv_obj_add_subject_set_int_event(wifi_kb, &subject_wifi_kb_visible, LV_EVENT_READY, 0);
        lv_obj_add_subject_set_int_event(wifi_kb, &subject_wifi_kb_visible, LV_EVENT_CANCEL, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

