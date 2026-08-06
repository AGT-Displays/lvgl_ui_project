/**
 * @file lvgl_ui_project_gen.h
 */

#ifndef LVGL_UI_PROJECT_GEN_H
#define LVGL_UI_PROJECT_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void lvgl_ui_project_set_target(uint32_t target);
uint32_t lvgl_ui_project_get_target(void);
bool lvgl_ui_project_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define LVGL_UI_PROJECT_TARGET_UNDEFINED  (0 << 1)
#define LVGL_UI_PROJECT_TARGET_TARGET1    (1 << 1)
#define LVGL_UI_PROJECT_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef LVGL_UI_PROJECT_COMPILE_TARGET
#define LVGL_UI_PROJECT_COMPILE_TARGET LVGL_UI_PROJECT_TARGET_ALL
#endif

#define LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(target) (LVGL_UI_PROJECT_COMPILE_TARGET & (target) ? 1 : 0)

/**
 * Screen background
 */
#define COL_BG lv_color_hex(0x12142a)
/**
 * Card / panel background
 */
#define COL_CARD lv_color_hex(0x1c1f3a)
/**
 * Lighter card / pressed panel
 */
#define COL_CARD_LIGHT lv_color_hex(0x262a4d)
/**
 * Primary text
 */
#define COL_TEXT lv_color_hex(0xffffff)
/**
 * Secondary text
 */
#define COL_TEXT_DIM lv_color_hex(0x9aa0c0)
/**
 * Purple accent (wordart / wifi)
 */
#define COL_PURPLE lv_color_hex(0x8b5cf6)
/**
 * Purple pressed
 */
#define COL_PURPLE_DARK lv_color_hex(0x6d28d9)
/**
 * Teal accent (numeric / icons)
 */
#define COL_TEAL lv_color_hex(0x14b8a6)
/**
 * Teal pressed
 */
#define COL_TEAL_DARK lv_color_hex(0x0f9488)
/**
 * Red/pink accent (temp / animation)
 */
#define COL_RED lv_color_hex(0xef5170)
/**
 * Red pressed
 */
#define COL_RED_DARK lv_color_hex(0xc23955)
/**
 * Blue accent (weather / popup / wifi)
 */
#define COL_BLUE lv_color_hex(0x3aa0f3)
/**
 * Blue pressed
 */
#define COL_BLUE_DARK lv_color_hex(0x2680cc)
/**
 * Green accent (keyboard / confirm)
 */
#define COL_GREEN lv_color_hex(0x22c55e)
/**
 * Green pressed
 */
#define COL_GREEN_DARK lv_color_hex(0x18a34c)
/**
 * Yellow accent (shared key / manual)
 */
#define COL_YELLOW lv_color_hex(0xf4b740)
/**
 * Yellow pressed
 */
#define COL_YELLOW_DARK lv_color_hex(0xd39c2c)
/**
 * Standard card corner radius
 */
#define RADIUS_CARD 18
/**
 * Pill / header corner radius
 */
#define RADIUS_PILL 24


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

extern lv_obj_t * animation;
extern lv_obj_t * brightness;
extern lv_obj_t * icon_cycle;
extern lv_obj_t * main_menu;
extern lv_obj_t * number_input;
extern lv_obj_t * popup_menu;
extern lv_obj_t * text_entry;
extern lv_obj_t * wifi_config;

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_screen_bg;
extern lv_style_t style_card;
extern lv_style_t style_header_pill;
extern lv_style_t style_header_title;
extern lv_style_t style_nav_icon_btn;
extern lv_style_t style_nav_icon_btn_pressed;
extern lv_style_t style_value_text;
extern lv_style_t style_label_dim;
extern lv_style_t style_pill_btn;
extern lv_style_t style_pill_btn_pressed;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * text_14;
extern lv_font_t * text_16;
extern lv_font_t * text_18;
extern lv_font_t * text_20;
extern lv_font_t * text_32;
extern lv_font_t * text_48;
extern lv_font_t * text_64;
extern lv_font_t * text_80;
extern lv_font_t * text_96;
extern lv_font_t * text_128;
extern lv_font_t * icon_14;
extern lv_font_t * icon_18;
extern lv_font_t * icon_20;
extern lv_font_t * icon_24;
extern lv_font_t * icon_32;
extern lv_font_t * icon_48;


/*----------------
 * Images
 *----------------*/



/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_numval;
extern lv_subject_t subject_kb_visible;
extern lv_subject_t subject_current_icon;
extern lv_subject_t subject_expanded_row;
extern lv_subject_t subject_wifi_mode;
extern lv_subject_t subject_wifi_kb_visible;
extern lv_subject_t subject_brightness;
extern lv_subject_t subject_anim_playing;
extern lv_subject_t subject_text_kb_visible;
extern lv_subject_t subject_entry_text;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void anim_play_dot_cb(lv_event_t * e);
void anim_stop_dot_cb(lv_event_t * e);
void number_keypad_key_cb(lv_event_t * e);
void setup_number_keypad_cb(lv_event_t * e);
void popup_toggle_row_cb(lv_event_t * e);
void text_entry_confirm_cb(lv_event_t * e);
void wifi_field_focus_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void lvgl_ui_project_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/animation_preview_gen.h"
#include "components/bottom_nav_gen.h"
#include "components/header_gen.h"
#include "screens/animation_gen.h"
#include "screens/brightness_gen.h"
#include "screens/icon_cycle_gen.h"
#include "screens/main_menu_gen.h"
#include "screens/number_input_gen.h"
#include "screens/popup_menu_gen.h"
#include "screens/text_entry_gen.h"
#include "screens/wifi_config_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_UI_PROJECT_GEN_H*/