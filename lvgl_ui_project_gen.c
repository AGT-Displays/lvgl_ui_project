/**
 * @file lvgl_ui_project_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_ui_project_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t lvgl_ui_project_target = LVGL_UI_PROJECT_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * animation = NULL;
lv_obj_t * brightness = NULL;
lv_obj_t * icon_cycle = NULL;
lv_obj_t * main_menu = NULL;
lv_obj_t * number_input = NULL;
lv_obj_t * popup_menu = NULL;
lv_obj_t * text_entry = NULL;
lv_obj_t * wifi_config = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * text_14;
extern lv_font_t text_14_data;
lv_font_t * text_16;
extern lv_font_t text_16_data;
lv_font_t * text_18;
extern lv_font_t text_18_data;
lv_font_t * text_20;
extern lv_font_t text_20_data;
lv_font_t * text_32;
extern lv_font_t text_32_data;
lv_font_t * text_48;
extern lv_font_t text_48_data;
lv_font_t * text_64;
extern lv_font_t text_64_data;
lv_font_t * text_80;
extern lv_font_t text_80_data;
lv_font_t * text_96;
extern lv_font_t text_96_data;
lv_font_t * text_128;
extern lv_font_t text_128_data;
lv_font_t * icon_14;
extern lv_font_t icon_14_data;
lv_font_t * icon_18;
extern lv_font_t icon_18_data;
lv_font_t * icon_20;
extern lv_font_t icon_20_data;
lv_font_t * icon_24;
extern lv_font_t icon_24_data;
lv_font_t * icon_32;
extern lv_font_t icon_32_data;
lv_font_t * icon_48;
extern lv_font_t icon_48_data;

/*----------------
 * Images
 *----------------*/



/*----------------
 * Global styles
 *----------------*/

lv_style_t style_screen_bg;
lv_style_t style_card;
lv_style_t style_header_pill;
lv_style_t style_header_title;
lv_style_t style_nav_icon_btn;
lv_style_t style_nav_icon_btn_pressed;
lv_style_t style_value_text;
lv_style_t style_label_dim;
lv_style_t style_pill_btn;
lv_style_t style_pill_btn_pressed;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_numval;
lv_subject_t subject_kb_visible;
lv_subject_t subject_current_icon;
lv_subject_t subject_expanded_row;
lv_subject_t subject_wifi_mode;
lv_subject_t subject_wifi_kb_visible;
lv_subject_t subject_brightness;
lv_subject_t subject_anim_playing;
lv_subject_t subject_text_kb_visible;
lv_subject_t subject_entry_text;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_ui_project_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
    if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
        if (!text_14) {
            /* text_14 */
            /* get font 'text_14' from a C array */
            text_14 = &text_14_data;

        }
        if (!text_16) {
            /* text_16 */
            /* get font 'text_16' from a C array */
            text_16 = &text_16_data;

        }
        if (!text_18) {
            /* text_18 */
            /* get font 'text_18' from a C array */
            text_18 = &text_18_data;

        }
        if (!text_20) {
            /* text_20 */
            /* get font 'text_20' from a C array */
            text_20 = &text_20_data;

        }
        if (!text_32) {
            /* text_32 */
            /* get font 'text_32' from a C array */
            text_32 = &text_32_data;

        }
        if (!text_48) {
            /* text_48 */
            /* get font 'text_48' from a C array */
            text_48 = &text_48_data;

        }
        if (!text_64) {
            /* text_64 */
            /* get font 'text_64' from a C array */
            text_64 = &text_64_data;

        }
        if (!text_80) {
            /* text_80 */
            /* get font 'text_80' from a C array */
            text_80 = &text_80_data;

        }
        if (!text_96) {
            /* text_96 */
            /* get font 'text_96' from a C array */
            text_96 = &text_96_data;

        }
        if (!text_128) {
            /* text_128 */
            /* get font 'text_128' from a C array */
            text_128 = &text_128_data;

        }
        if (!icon_14) {
            /* icon_14 */
            /* get font 'icon_14' from a C array */
            icon_14 = &icon_14_data;

        }
        if (!icon_18) {
            /* icon_18 */
            /* get font 'icon_18' from a C array */
            icon_18 = &icon_18_data;

        }
        if (!icon_20) {
            /* icon_20 */
            /* get font 'icon_20' from a C array */
            icon_20 = &icon_20_data;

        }
        if (!icon_24) {
            /* icon_24 */
            /* get font 'icon_24' from a C array */
            icon_24 = &icon_24_data;

        }
        if (!icon_32) {
            /* icon_32 */
            /* get font 'icon_32' from a C array */
            icon_32 = &icon_32_data;

        }
        if (!icon_48) {
            /* icon_48 */
            /* get font 'icon_48' from a C array */
            icon_48 = &icon_48_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/



    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_UI_PROJECT_CHECK_COMPILE_TARGET(LVGL_UI_PROJECT_TARGET_ALL)
        if (lvgl_ui_project_check_target(LVGL_UI_PROJECT_TARGET_ALL)) {
            lv_style_init(&style_screen_bg);
            lv_style_set_bg_color(&style_screen_bg, COL_BG);
            lv_style_set_bg_opa(&style_screen_bg, (255 * 100 / 100));
            lv_style_set_pad_all(&style_screen_bg, 0);
            lv_style_set_border_width(&style_screen_bg, 0);
            lv_style_set_radius(&style_screen_bg, 0);

            lv_style_init(&style_card);
            lv_style_set_bg_color(&style_card, COL_CARD);
            lv_style_set_bg_opa(&style_card, (255 * 100 / 100));
            lv_style_set_radius(&style_card, RADIUS_CARD);
            lv_style_set_border_width(&style_card, 0);
            lv_style_set_pad_all(&style_card, 12);

            lv_style_init(&style_header_pill);
            lv_style_set_bg_color(&style_header_pill, COL_CARD);
            lv_style_set_bg_opa(&style_header_pill, (255 * 100 / 100));
            lv_style_set_radius(&style_header_pill, RADIUS_PILL);
            lv_style_set_pad_hor(&style_header_pill, 18);
            lv_style_set_pad_ver(&style_header_pill, 10);
            lv_style_set_border_width(&style_header_pill, 0);

            lv_style_init(&style_header_title);
            lv_style_set_text_color(&style_header_title, COL_TEXT);
            lv_style_set_text_font(&style_header_title, text_18);

            lv_style_init(&style_nav_icon_btn);
            lv_style_set_radius(&style_nav_icon_btn, 180);
            lv_style_set_bg_opa(&style_nav_icon_btn, (255 * 100 / 100));
            lv_style_set_shadow_width(&style_nav_icon_btn, 0);
            lv_style_set_border_width(&style_nav_icon_btn, 0);

            lv_style_init(&style_nav_icon_btn_pressed);
            lv_style_set_transform_width(&style_nav_icon_btn_pressed, -4);
            lv_style_set_transform_height(&style_nav_icon_btn_pressed, -4);

            lv_style_init(&style_value_text);
            lv_style_set_text_color(&style_value_text, COL_TEXT);
            lv_style_set_text_font(&style_value_text, text_48);

            lv_style_init(&style_label_dim);
            lv_style_set_text_color(&style_label_dim, COL_TEXT_DIM);
            lv_style_set_text_font(&style_label_dim, text_14);

            lv_style_init(&style_pill_btn);
            lv_style_set_bg_opa(&style_pill_btn, (255 * 100 / 100));
            lv_style_set_radius(&style_pill_btn, RADIUS_PILL);
            lv_style_set_text_color(&style_pill_btn, COL_TEXT);
            lv_style_set_pad_hor(&style_pill_btn, 16);
            lv_style_set_pad_ver(&style_pill_btn, 10);
            lv_style_set_border_width(&style_pill_btn, 0);

            lv_style_init(&style_pill_btn_pressed);
            lv_style_set_transform_width(&style_pill_btn_pressed, -4);
            lv_style_set_transform_height(&style_pill_btn_pressed, -4);

        }
        #endif
        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_numval, 0);
    lv_subject_init_int(&subject_kb_visible, 0);
    lv_subject_init_int(&subject_current_icon, 1);
    lv_subject_init_int(&subject_expanded_row, 0);
    lv_subject_init_int(&subject_wifi_mode, 0);
    lv_subject_init_int(&subject_wifi_kb_visible, 0);
    lv_subject_init_int(&subject_brightness, 100);
    lv_subject_init_int(&subject_anim_playing, 0);
    lv_subject_init_int(&subject_text_kb_visible, 0);
    static char subject_entry_text_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_entry_text_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_entry_text,
                           subject_entry_text_buf,
                           subject_entry_text_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Tap to enter text"
                          );

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&text_14, "text_14");
    check_font(&text_16, "text_16");
    check_font(&text_18, "text_18");
    check_font(&text_20, "text_20");
    check_font(&text_32, "text_32");
    check_font(&text_48, "text_48");
    check_font(&text_64, "text_64");
    check_font(&text_80, "text_80");
    check_font(&text_96, "text_96");
    check_font(&text_128, "text_128");
    check_font(&icon_14, "icon_14");
    check_font(&icon_18, "icon_18");
    check_font(&icon_20, "icon_20");
    check_font(&icon_24, "icon_24");
    check_font(&icon_32, "icon_32");
    check_font(&icon_48, "icon_48");

    /* Register fonts */
    lv_xml_register_font(NULL, "text_14", text_14);
    lv_xml_register_font(NULL, "text_16", text_16);
    lv_xml_register_font(NULL, "text_18", text_18);
    lv_xml_register_font(NULL, "text_20", text_20);
    lv_xml_register_font(NULL, "text_32", text_32);
    lv_xml_register_font(NULL, "text_48", text_48);
    lv_xml_register_font(NULL, "text_64", text_64);
    lv_xml_register_font(NULL, "text_80", text_80);
    lv_xml_register_font(NULL, "text_96", text_96);
    lv_xml_register_font(NULL, "text_128", text_128);
    lv_xml_register_font(NULL, "icon_14", icon_14);
    lv_xml_register_font(NULL, "icon_18", icon_18);
    lv_xml_register_font(NULL, "icon_20", icon_20);
    lv_xml_register_font(NULL, "icon_24", icon_24);
    lv_xml_register_font(NULL, "icon_32", icon_32);
    lv_xml_register_font(NULL, "icon_48", icon_48);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_numval", &subject_numval);
    lv_xml_register_subject(NULL, "subject_kb_visible", &subject_kb_visible);
    lv_xml_register_subject(NULL, "subject_current_icon", &subject_current_icon);
    lv_xml_register_subject(NULL, "subject_expanded_row", &subject_expanded_row);
    lv_xml_register_subject(NULL, "subject_wifi_mode", &subject_wifi_mode);
    lv_xml_register_subject(NULL, "subject_wifi_kb_visible", &subject_wifi_kb_visible);
    lv_xml_register_subject(NULL, "subject_brightness", &subject_brightness);
    lv_xml_register_subject(NULL, "subject_anim_playing", &subject_anim_playing);
    lv_xml_register_subject(NULL, "subject_text_kb_visible", &subject_text_kb_visible);
    lv_xml_register_subject(NULL, "subject_entry_text", &subject_entry_text);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "anim_play_dot_cb", anim_play_dot_cb);
    lv_xml_register_event_cb(NULL, "anim_stop_dot_cb", anim_stop_dot_cb);
    lv_xml_register_event_cb(NULL, "number_keypad_key_cb", number_keypad_key_cb);
    lv_xml_register_event_cb(NULL, "setup_number_keypad_cb", setup_number_keypad_cb);
    lv_xml_register_event_cb(NULL, "popup_toggle_row_cb", popup_toggle_row_cb);
    lv_xml_register_event_cb(NULL, "text_entry_confirm_cb", text_entry_confirm_cb);
    lv_xml_register_event_cb(NULL, "wifi_field_focus_cb", wifi_field_focus_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    animation = lv_obj_create(NULL);
    brightness = lv_obj_create(NULL);
    icon_cycle = lv_obj_create(NULL);
    main_menu = lv_obj_create(NULL);
    number_input = lv_obj_create(NULL);
    popup_menu = lv_obj_create(NULL);
    text_entry = lv_obj_create(NULL);
    wifi_config = lv_obj_create(NULL);

    animation_create();
    brightness_create();
    icon_cycle_create();
    main_menu_create();
    number_input_create();
    popup_menu_create();
    text_entry_create();
    wifi_config_create();
#endif
}

void lvgl_ui_project_set_target(uint32_t target)
{
    lvgl_ui_project_target = target;
}

uint32_t lvgl_ui_project_get_target(void)
{
    return lvgl_ui_project_target;
}

bool lvgl_ui_project_check_target(uint32_t target)
{
    return (lvgl_ui_project_target & target) ? true : false;
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) anim_play_dot_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("anim_play_dot_cb was called\n");
}
void __attribute__((weak)) anim_stop_dot_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("anim_stop_dot_cb was called\n");
}
void __attribute__((weak)) number_keypad_key_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("number_keypad_key_cb was called\n");
}
void __attribute__((weak)) setup_number_keypad_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("setup_number_keypad_cb was called\n");
}
void __attribute__((weak)) popup_toggle_row_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("popup_toggle_row_cb was called\n");
}
void __attribute__((weak)) text_entry_confirm_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("text_entry_confirm_cb was called\n");
}
void __attribute__((weak)) wifi_field_focus_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("wifi_field_focus_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}