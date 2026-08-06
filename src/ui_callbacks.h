/**
 * @file ui_callbacks.h
 *
 * Hand-written event callbacks referenced from the XML screens by name
 * (via <event_cb callback="..."/>). The Editor's C code export expects these
 * symbols to exist somewhere in the compiled sources; this file is that
 * "somewhere" and is registered as an extra source in user_config.cmake.
 */
#ifndef UI_CALLBACKS_H
#define UI_CALLBACKS_H

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* components/animation_preview.xml: fires on the green Play button's clicked
 * event. Slides the dot (found by the name in user_data) from -140 to +140
 * over 1200ms with a plain lv_anim_t. Used instead of a declarative
 * <animations>/<timeline> because this installed Editor's validator rejects
 * every attribute LVGL's docs describe for <animation>. */
void anim_play_dot_cb(lv_event_t * e);

/* components/animation_preview.xml: fires on the red Stop button's clicked
 * event. Slides the dot (found by the name in user_data) back to -140 from
 * wherever it currently is, over 1200ms. */
void anim_stop_dot_cb(lv_event_t * e);

/* screens/number_input.xml: fires once on trigger="screen_loaded" (the
 * screen object is the event target). lv_keyboard's XML API only exposes
 * mode/popovers/textarea - there's no "map" attribute - so the custom
 * "user_1" keymap (digits + a Confirma/Cancela row) can't be declared in
 * XML and has to be installed here via lv_keyboard_set_map(). Safe to run
 * more than once (e.g. if the screen is loaded again): it just reassigns
 * the same static map. The keyboard is found by the name in user_data. */
void setup_number_keypad_cb(lv_event_t * e);

/* screens/number_input.xml: fires on the numeric keypad's value_changed
 * event (every key press). Only acts on the two custom "Confirma"/"Cancela"
 * keys in the "user_1" map (not reserved LVGL symbol strings, so the
 * keyboard's own default handler doesn't recognize them); every other key
 * (digits, backspace) is left to that default handler untouched. Confirma
 * reads the digits typed into the textarea named by the event's user_data,
 * clamps them into subject_numval; both keys close the keypad panel. */
void number_keypad_key_cb(lv_event_t * e);

/* screens/text_entry.xml: fires on the on-screen keyboard's own Enter/OK key
 * (trigger="ready"). Copies the freshly typed draft text into
 * subject_entry_text and closes the keyboard overlay. Esc (trigger="cancel")
 * needs no C code: the XML closes the overlay declaratively and never
 * touches subject_entry_text, so the old text is left intact. */
void text_entry_confirm_cb(lv_event_t * e);

/* screens/wifi_config.xml: fires on either the SSID or password textarea's
 * clicked event (the textarea itself is the event target). One shared
 * lv_keyboard ("wifi_kb") serves both fields - lv_keyboard's XML "textarea"
 * attribute only binds a fixed target once at creation, so switching which
 * field it edits has to happen here via lv_keyboard_set_textarea(). Typing
 * goes directly into the real SSID/password textarea (no separate draft +
 * commit step like number_input/text_entry use), so Enter/Esc on the
 * keyboard can just hide it declaratively in XML with no C involved. */
void wifi_field_focus_cb(lv_event_t * e);

/* screens/popup_menu.xml: fires on any of the three "+" buttons' clicked
 * event (user_data is that button's row number as a string, "1"/"2"/"3").
 * Only one row's pill may be open at a time, tracked by the single shared
 * subject_expanded_row (0 = none open). Opening a row that isn't already
 * open has to also close whatever else was open, and re-tapping the same
 * row's "+" has to close it instead of doing nothing - both need to compare
 * against the subject's current value first, which plain declarative
 * subject_set_int_event/subject_toggle_event can't express (they can only
 * set or flip unconditionally), hence the small C callback. */
void popup_toggle_row_cb(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*UI_CALLBACKS_H*/
