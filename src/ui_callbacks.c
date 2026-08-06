/**
 * @file ui_callbacks.c
 *
 * See ui_callbacks.h. The subjects below are declared in globals.xml; the
 * Editor's C export creates each as a global `lv_subject_t` with this exact
 * name, so they can be reached here with a plain extern instead of guessing
 * the exported project's header name.
 */
#include "ui_callbacks.h"
#include <stdlib.h>

extern lv_subject_t subject_numval;
extern lv_subject_t subject_kb_visible;
extern lv_subject_t subject_entry_text;
extern lv_subject_t subject_text_kb_visible;
extern lv_subject_t subject_wifi_kb_visible;
extern lv_subject_t subject_expanded_row;

#define ANIM_DOT_MIN_X (-140)
#define ANIM_DOT_MAX_X (140)
#define ANIM_DOT_DURATION 1200

void anim_play_dot_cb(lv_event_t * e)
{
    const char * dot_name = (const char *)lv_event_get_user_data(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    lv_obj_t * screen = lv_obj_get_screen(btn);
    lv_obj_t * dot = lv_obj_find_by_name(screen, dot_name);
    if(dot == NULL) return;

    lv_anim_delete(dot, NULL);
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, dot);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&a, ANIM_DOT_MIN_X, ANIM_DOT_MAX_X);
    lv_anim_set_duration(&a, ANIM_DOT_DURATION);
    lv_anim_start(&a);
}

void anim_stop_dot_cb(lv_event_t * e)
{
    const char * dot_name = (const char *)lv_event_get_user_data(e);
    lv_obj_t * btn = lv_event_get_target_obj(e);
    lv_obj_t * screen = lv_obj_get_screen(btn);
    lv_obj_t * dot = lv_obj_find_by_name(screen, dot_name);
    if(dot == NULL) return;

    lv_anim_delete(dot, NULL);
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, dot);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);
    lv_anim_set_values(&a, lv_obj_get_x(dot), ANIM_DOT_MIN_X);
    lv_anim_set_duration(&a, ANIM_DOT_DURATION);
    lv_anim_start(&a);
}

void setup_number_keypad_cb(lv_event_t * e)
{
    static const char * numval_kb_map[] = {
        "1", "2", "3", "\n",
        "4", "5", "6", "\n",
        "7", "8", "9", "\n",
        ".", "0", LV_SYMBOL_BACKSPACE, "\n",
        "Confirma", "Cancela", ""
    };
    static const lv_buttonmatrix_ctrl_t numval_kb_ctrl[] = {
        1, 1, 1,
        1, 1, 1,
        1, 1, 1,
        1, 1, 1,
        LV_BUTTONMATRIX_CTRL_WIDTH_2, LV_BUTTONMATRIX_CTRL_WIDTH_2
    };

    const char * kb_name = (const char *)lv_event_get_user_data(e);
    lv_obj_t * screen = lv_event_get_target_obj(e);
    lv_obj_t * kb = lv_obj_find_by_name(screen, kb_name);
    if(kb == NULL) return;

    lv_keyboard_set_map(kb, LV_KEYBOARD_MODE_USER_1, numval_kb_map, numval_kb_ctrl);
    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_USER_1);

    /* max_length isn't an XML attribute lv_textarea's parser exposes, so it
     * has to be set here in C instead - caps typing at 2 digits (0-99) up
     * front, rather than only clamping after Confirma is pressed. */
    lv_obj_t * ta = lv_obj_find_by_name(screen, "numval_ta");
    if(ta != NULL) lv_textarea_set_max_length(ta, 2);
}

void number_keypad_key_cb(lv_event_t * e)
{
    lv_obj_t * kb = lv_event_get_target_obj(e);
    uint32_t btn_id = lv_buttonmatrix_get_selected_button(kb);
    if(btn_id == LV_BUTTONMATRIX_BUTTON_NONE) return;

    const char * txt = lv_buttonmatrix_get_button_text(kb, btn_id);
    if(txt == NULL) return;

    const char * ta_name = (const char *)lv_event_get_user_data(e);
    lv_obj_t * screen = lv_obj_get_screen(kb);
    lv_obj_t * ta = lv_obj_find_by_name(screen, ta_name);

    if(lv_strcmp(txt, "Confirma") == 0) {
        if(ta != NULL) {
            int32_t value = (int32_t)atoi(lv_textarea_get_text(ta));
            if(value < 0) value = 0;
            if(value > 99) value = 99;
            lv_subject_set_int(&subject_numval, value);
            lv_textarea_set_text(ta, "");
        }
        lv_subject_set_int(&subject_kb_visible, 0);
    }
    else if(lv_strcmp(txt, "Cancela") == 0) {
        if(ta != NULL) lv_textarea_set_text(ta, "");
        lv_subject_set_int(&subject_kb_visible, 0);
    }
}

void text_entry_confirm_cb(lv_event_t * e)
{
    const char * ta_name = (const char *)lv_event_get_user_data(e);
    lv_obj_t * kb = lv_event_get_target_obj(e);
    lv_obj_t * screen = lv_obj_get_screen(kb);
    lv_obj_t * ta = lv_obj_find_by_name(screen, ta_name);
    if(ta == NULL) return;

    lv_subject_copy_string(&subject_entry_text, lv_textarea_get_text(ta));
    lv_subject_set_int(&subject_text_kb_visible, 0);
    lv_textarea_set_text(ta, "");
}

void wifi_field_focus_cb(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target_obj(e);
    lv_obj_t * screen = lv_obj_get_screen(ta);
    lv_obj_t * kb = lv_obj_find_by_name(screen, "wifi_kb");
    if(kb == NULL) return;

    lv_keyboard_set_textarea(kb, ta);
    lv_subject_set_int(&subject_wifi_kb_visible, 1);
}

void popup_toggle_row_cb(lv_event_t * e)
{
    const char * row_str = (const char *)lv_event_get_user_data(e);
    int32_t row = (int32_t)atoi(row_str);

    int32_t current = lv_subject_get_int(&subject_expanded_row);
    lv_subject_set_int(&subject_expanded_row, current == row ? 0 : row);
}
