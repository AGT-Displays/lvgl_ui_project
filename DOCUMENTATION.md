# LVGL Kiosk UI — Project Documentation

A full LVGL v9.5.0 XML-based UI for an 800×480 kiosk touchscreen, built in LVGL Pro
Editor v2.0.0 from a set of static prototype images. This document covers the
project's structure, the reasoning behind its non-obvious decisions, and the
recurring bugs/gotchas that came up while matching the UI to the prototypes —
mainly so the *why* behind the code isn't lost.

## Table of contents

1. [Toolchain](#toolchain)
2. [Project structure](#project-structure)
3. [Global resources (`globals.xml`)](#global-resources-globalsxml)
4. [Shared components](#shared-components)
5. [Screens](#screens)
6. [C callbacks (`src/ui_callbacks.c`)](#c-callbacks-srcui_callbacksc)
7. [Recurring bugs and hard-won lessons](#recurring-bugs-and-hard-won-lessons)
8. [Known gaps / not implemented](#known-gaps--not-implemented)

---

## Toolchain

Built and previewed with:

- **LVGL Pro Editor v2.0.0** — authors/validates the XML, drives the live preview,
  exports the `*_gen.c` / `*_gen.h` files.
- **Emscripten (emsdk)** — compiles the `sim/` target to run in a browser for a
  full, real (non-Editor-preview) build check.
- **Ninja + CMake + Git** — the actual build tools underneath, installed via
  `winget install Kitware.CMake Ninja-build.Ninja Git.Git`.

The project has two build paths that need to agree:

- The **Editor's own live preview**, which is more lenient (some invalid
  attributes only warn instead of failing).
- The **real compiled build** (`sim/` via CMake/Ninja, or Emscripten), which is
  the actual source of truth — several bugs in this project only surfaced here,
  never in the live preview (see [Recurring bugs](#recurring-bugs-and-hard-won-lessons)).

`src/ui_callbacks.h` guards its LVGL include with:

```c
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif
```

because the Editor's internal preview build and the external `sim/` CMake build
define that macro differently — matching the Editor's own generated headers'
pattern was the fix.

## Project structure

```
globals.xml              Shared colors, styles, fonts, subjects (see below)
screens/                 One <screen> XML per top-level page, plus its *_gen.c/.h
components/              Reusable <component> XML (header bar, bottom nav, ...)
src/ui_callbacks.c/.h    Hand-written C event callbacks referenced from XML
fonts/                   Source TTF/WOFF files + generated font data (*_data.c)
prototype/               Reference mockup images the UI was built to match
sim/                     Standalone CMake/Emscripten simulator target
```

Every `*.xml` file has a matching Editor-generated `*_gen.c` / `*_gen.h` — those
are build output, not hand-edited.

## Global resources (`globals.xml`)

### Colors

A small fixed palette, each accent color paired with a `_dark` pressed-state
variant: `col_bg`, `col_card`, `col_card_light`, `col_text`, `col_text_dim`,
`col_purple`, `col_teal`, `col_red`, `col_blue`, `col_green`, `col_yellow` (+
`_dark` variants). Two shared radii: `radius_card` (18px) and `radius_pill` (24px).

### Shared styles

- `style_screen_bg` — every screen's background (`col_bg`, `pad_all=0`,
  `border_width=0`).
- `style_card` — the standard rounded card look used across dashboard tiles.
- `style_header_pill`, `style_header_title` — the shared top-bar pill.
- `style_nav_icon_btn(_pressed)` — small circular icon buttons (header, main_menu).
- `style_pill_btn(_pressed)` — rounded action-button pills (Iniciar, etc).

### Subjects (reactive state)

| Subject | Type | Used by |
|---|---|---|
| `subject_numval` | int | number_input value |
| `subject_kb_visible` | int | number_input keypad overlay |
| `subject_current_icon` | int | icon_cycle selection |
| `subject_expanded_row` | int | popup_menu — which row's pill is open (0/1/2/3) |
| `subject_wifi_mode` | int | wifi_config — manual vs shared-key |
| `subject_wifi_kb_visible` | int | wifi_config keyboard overlay |
| `subject_brightness` | int | brightness screen selection |
| `subject_anim_playing` | int | animation screen play/stop state |
| `subject_text_kb_visible` | int | text_entry keyboard overlay |
| `subject_entry_text` | string | text_entry committed text |

Bindings on these subjects (`bind_flag_if_eq`, `bind_state_if_eq`, ...) drive
almost all conditional visibility in the project declaratively, with C only
brought in where the logic couldn't be expressed that way (see the callbacks
section).

### Fonts

Two families, both custom-registered rather than relying on LVGL's built-ins —
see [the font gotcha](#lv_font_montserrat_xx-isnt-reachable-from-xml) for why.

- **`text_14` … `text_128`** — real text/numbers, from the bundled Montserrat
  TTFs (`Regular` / `Medium` / `SemiBold` depending on weight needed), covering
  `0x20-0xFF` so Portuguese accents (ã, ç, á, é, í, ó, ú, °, ...) render.
- **`icon_14` … `icon_48`** — icon glyphs, from
  `fonts/FontAwesome5-Solid+Brands+Regular.woff` (LVGL's own published subset).
  Each size only pulls in the exact codepoints actually used at that size (via
  the `symbols` attribute), to keep each generated font small — this list has
  been extended incrementally all session whenever a new icon was needed at an
  existing size.

## Shared components

### `components/header.xml`

The top bar used by every screen **except** `main_menu` (which has its own
custom top row). A rounded pill on the left (icon + title, both passed as
`<api>` props), a circular Home button on the right that always
`screen_load_event`s back to `main_menu`.

### `components/bottom_nav.xml`

The footer nav present on every screen: a thin divider line, then 5 circular
buttons that jump to the 5 feature screens. Notable design choices, both driven
by bugs (see below): the divider + button row are a plain column, and **each
button is individually pinned** with `align="center"` + `ignore_layout="true"`
+ a fixed `x` offset (`-274, -137, 0, 137, 274`) rather than laid out via
`flex_flow="row"` — flex distribution inside this component proved unreliable
enough (see [gotchas](#recurring-bugs-and-hard-won-lessons)) that explicit
positions were the only way to get pixel-perfect, clip-free placement.

### `components/animation_preview.xml`

The teal preview panel + Play/Stop buttons for `screens/animation.xml`. The
dot's slide animation is driven by a plain C `lv_anim_t`
(`anim_play_dot_cb` / `anim_stop_dot_cb`) rather than a declarative
`<animations>` block — this installed Editor's validator rejects every
attribute LVGL's own docs describe for `<animation>`, so that feature isn't
usable here. Pulled into its own `<component>` because `<animations>` (were it
usable) is only valid inside `<component>`/`<widget>`, not directly in a
`<screen>`.

## Screens

| Screen | Purpose |
|---|---|
| `main_menu.xml` | Home screen: wifi/numeric shortcut cards, decorative temp/weather cards, its own top icon row |
| `wifi_config.xml` | Manual SSID/password form or shared-key QR view, picked by a mode toggle; on-screen keyboard for both text fields |
| `number_input.xml` | Big value display with up/down steppers, or a numeric keypad panel |
| `brightness.xml` | 4 selectable brightness-level cards |
| `icon_cycle.xml` | 4 buttons swap which icon shows in a center panel |
| `popup_menu.xml` | 3 expandable rows, each a "+" button revealing a pill of icons; only one open at a time |
| `text_entry.xml` | Tap a text panel to reveal a textarea + full keyboard |
| `animation.xml` | Play/Stop-controlled placeholder animation (see `animation_preview` above) |

### `main_menu.xml`

No shared header — has its own top row: a left icon (reserved for replaying a
startup animation once that asset exists; currently unwired rather than
pointing somewhere incorrect) and a brightness shortcut. Below that, 3 columns:

- **Column 1** — wifi card (→ `wifi_config`) stacked over a numeric card
  (→ `number_input`), each `flex_grow="1"` within a column wrapper.
- **Column 2** — decorative temperature card. Its arc + label + media-button
  row are positioned with `align="center"` + `ignore_layout` + fixed `y`
  offsets rather than flex, because flex cross-axis centering inside this
  card was unreliable (see gotchas). The media-button row also needed
  `overflow_visible="true"` and generous sizing so the buttons' press-state
  visuals don't get clipped by the row's own bounds.
- **Column 3** — decorative weather card (temp/condition/city), purely
  informative.

### `wifi_config.xml`

Left column: two mode-select buttons bound to `subject_wifi_mode`
(`bind_state_if_eq` for the "checked"/lit look). Right: a card whose content
swaps between a manual SSID/password form and a shared-key QR placeholder
(`bind_flag_if_not_eq`), both given the **same fixed height** so the shared
MAC/Versão footer underneath always lands at the same Y regardless of which
mode is active. Both textareas are wired to one shared `<lv_keyboard>` overlay
(`wifi_kb`) that slides up from the bottom; `wifi_field_focus_cb` retargets it
to whichever field was tapped via `lv_keyboard_set_textarea()`, since XML can
only bind a keyboard's textarea once at creation. Password masking comes for
free from `password_mode="true"` on that field.

### `number_input.xml`

Left: a value card with up/down stepper buttons (`subject_increment_event`,
clamped 0–99), tap the card to reveal a keypad panel on the right
(`subject_kb_visible`). The keypad's custom "Confirma/Cancela" keymap is
installed once in C (`setup_number_keypad_cb`) since `lv_keyboard`'s XML API
has no `map` attribute; `number_keypad_key_cb` intercepts those two keys
(everything else — digits, backspace — goes through the keyboard's own default
handling). Every size in this screen (button dimensions, card size, font,
gaps) was tuned against the *exact* pixel budget of its container, confirmed
via the Editor's inspector gizmo rather than assumed — see
[gotchas](#recurring-bugs-and-hard-won-lessons).

### `brightness.xml`

4 selectable cards bound to `subject_brightness` via one `bind_state_if_eq`
per card (checked = lit blue gradient). The row is centered with
`align="center"` + `ignore_layout` on a wrapper rather than flex
`cross_place`, for the same reliability reason as everywhere else.

### `icon_cycle.xml`

Two 2-button columns (left/right) each set `subject_current_icon`; a center
panel overlays one label per icon, each shown only while the subject matches
its value (`bind_flag_if_not_eq`).

### `popup_menu.xml`

3 rows, each a "+" button that reveals a pill of 4 icons. Only one row may be
open at a time via a single shared subject, `subject_expanded_row`
(0 = none, 1/2/3 = that row). Opening a closed row (closing whatever else was
open) and re-tapping an already-open row's "+" (closing it) both require
comparing against the subject's *current* value — logic the declarative
`subject_set_int_event` / `subject_toggle_event` primitives can't express (they
only set or flip unconditionally) — hence `popup_toggle_row_cb` in C. Tapping
any icon *inside* an open pill collapses it via a plain declarative
`subject_set_int_event(..., value=0)`, since closing doesn't need to know which
row was open.

The button+pill pairs use `align` + `ignore_layout` so each keeps its own fixed
position regardless of whether its sibling pill is currently hidden — relying
on flex order alone made the "+" button jump around whenever the pill
collapsed out of the layout.

### `text_entry.xml`

A committed-text panel (shown while collapsed) swaps for a textarea + keyboard
overlay (`subject_text_kb_visible`). `text_entry_confirm_cb` fires on the
keyboard's Enter key, copying the draft into `subject_entry_text`; Esc/Cancel
needs no C — the XML just hides the overlay without touching the committed text.

### `animation.xml`

No real animation frame assets were supplied, so Play/Stop drive a placeholder
dot sliding across a panel (see `animation_preview` above). Once real frames
exist, the placeholder dot can be swapped for an `lv_animimg` driven by the
same two buttons.

## C callbacks (`src/ui_callbacks.c`)

Every callback exists because the same logic genuinely couldn't be expressed
in declarative XML — not as a stylistic choice. Summary:

| Callback | Fires on | Why C was needed |
|---|---|---|
| `anim_play_dot_cb` / `anim_stop_dot_cb` | Play/Stop buttons | `<animations>` block rejected by this Editor's validator despite matching LVGL's docs |
| `setup_number_keypad_cb` | number_input screen load | `lv_keyboard`'s XML API has no `map` attribute for custom keymaps |
| `number_keypad_key_cb` | numeric keypad key press | Needs to intercept two non-standard key strings ("Confirma"/"Cancela") mid-stream |
| `text_entry_confirm_cb` | text keyboard Enter | Copies draft text into the committed subject on confirm only |
| `wifi_field_focus_cb` | SSID/password field tap | `lv_keyboard`'s `textarea` binding is fixed at creation; retargeting needs `lv_keyboard_set_textarea()` |
| `popup_toggle_row_cb` | popup_menu "+" buttons | Needs to branch on the shared subject's *current* value (open/close/switch), which plain set/toggle events can't do |

## Recurring bugs and hard-won lessons

These cost the most back-and-forth this session, roughly in the order they
were discovered. Recorded here so they don't get re-litigated from scratch.

### A plain `<lv_obj>` with no width/height does not size to content

`lv_obj_class`'s `width_def`/`height_def` is `LV_DPI_DEF` (~100px), **not**
content-sizing. Any wrapper `<lv_obj>` needs an explicit `width`/`height`
(`"content"` or a pixel value) or it silently clips whatever's inside it to a
~100px box. This caused real clipping bugs (e.g. wifi_config's form panels)
before being root-caused.

### `lv_font_montserrat_XX` isn't reachable from XML

The Editor doesn't expose LVGL's built-in fonts under their real C names from
hand-written XML (`montserrat_18` ≠ `lv_font_montserrat_18` — the former only
silently falls back to the default font in the *live preview*, and hard-fails
("use of undeclared identifier") in a real compiled build). Fixed by
registering custom fonts from source TTF/WOFF files in `globals.xml` instead —
see [Fonts](#fonts) above.

### `<animation>` / `lv_keyboard.map` / `lv_textarea.max_length` aren't real XML attributes here

All three are documented LVGL features that this installed Editor's XML
validator rejects as "Unknown attribute." All three were moved to plain C
(`event_cb` callbacks) instead of the declarative form the docs describe.

### Flex cross-axis centering is unreliable in this Editor/LVGL build

Repeatedly, `style_flex_cross_place="center"` (and `style_flex_main_place`
used for vertical centering in a column) resolved noticeably off-center or
inconsistently — main_menu's red card contents, its media-button row,
wifi_config's QR/button pair, and the brightness card row all hit this. The
**fix that worked every time**: drop flex for that element and use
`align="center"` + `ignore_layout="true"` + a manually computed fixed
offset instead. This became the default approach for any tricky centering in
this project, applied proactively rather than re-discovered each time.

### `flex_flow` set only inside a `<style>` doesn't enable flex layout

A `flex_flow="row"` declared purely inside a shared `<style>` block never
actually switches an `lv_obj` onto the flex layout engine — only the widget's
own **inline** `flex_flow` attribute does that. Symptom: children all stacking
at `(0,0)` instead of laying out (first hit in `popup_menu`'s icon pills).

### Default theme padding/border sneaks in unless explicitly zeroed

Any plain `lv_obj` lacking explicit `border_width="0"` shows a visible
default-theme border even with `bg_opa="0"` — repeatedly mistaken for
unwanted "framing" around content (top bars, media-button rows, whole content
columns). Screen/component root `<view>` elements also silently eat vertical
space from **default `pad_row`** between their flex children unless given
`style_pad_row="0"` explicitly — this was missing from every screen except
`main_menu` for most of the session, and became the actual root cause of
`animation.xml`'s bottom-nav-pushed-off-screen bug once the preview panel grew
tall enough to expose it. **All screens now have this set.**

### `LV_OBJ_FLAG_OVERFLOW_VISIBLE` only extends a container's *own* ext-draw-size, not just any child overflow

Setting `overflow_visible="true"` on a tight-fitting row didn't stop its
children's press-state visuals from clipping, because that flag only expands
the clip region by the *container's own* ext-draw-size (its own shadow/outline
needs), which is 0 for a plain transparent row — it doesn't automatically make
room for a child's effects. The reliable fix ended up being simply **sizing
the container with real margin** around its content, not relying on the flag.

### The Editor's inspector: W/H readings are reliable, X/Y are not

The Properties panel's X/Y fields show the *unset default* position-override
value (always 0), never the true resolved flex-computed screen position — this
was confirmed via `wifi_config`'s arc (`x=0,y=0` shown, but visually not at the
origin). Its **W/H** fields (and the drag-handle "gizmo" WxH readout shown
while an element is selected) *are* trustworthy, and became the standard way
to get hard numbers before sizing anything tightly — see the `number_input`
and `bottom_nav` sagas, both eventually solved only after getting an exact
gizmo reading instead of guessing.

### Components are opaque to the inspector once instantiated

Selecting a `<component>` instance in a screen (e.g. `bottom_nav`) shows its
own outer box, but you cannot drill into its internal children from that
context — confirmed directly by the Editor's behavior during the `bottom_nav`
clipping investigation. Diagnosing internals requires opening the component's
own XML file (or its isolated preview) directly.

### Manual edits via the Editor's drag UI can corrupt icon text

Dragging/resizing elements by hand in the Editor was observed to mangle raw
UTF-8 private-use-area characters into double-encoded mojibake (confirmed at
the byte level once: original UTF-8 for U+F021 got reinterpreted as
Windows-1252 and re-encoded, producing garbled bytes). **Always use `&#N;`
numeric XML entities** for icon codepoints instead of pasting literal
characters — entities are plain ASCII and immune to this.

### When in doubt, don't guess twice in a row

Several bugs (main_menu's red card centering, number_input's button clipping,
bottom_nav's clipping) took multiple wrong guesses before being solved. The
pattern that consistently worked: after one failed guess, **stop guessing and
get hard evidence** — an inspector screenshot with the specific element
selected, its gizmo W×H, or a pixel-level crop/zoom of the actual screenshot —
rather than continuing to adjust numbers blind.

## Known gaps / not implemented

- **`main_menu`'s top-left icon button** is unwired. It's meant to replay a
  startup animation, but no such asset was ever provided in the prototype
  folder.
- **`animation.xml`** uses a placeholder sliding dot instead of the
  prototype's cyclist animation — no real frame assets were provided. Once
  frames exist, swap the dot for an `lv_animimg` driven by the same Play/Stop
  buttons.
- **wifi_config's "Iniciar" buttons** don't actually attempt a network
  connection — this is a UI-only kiosk mockup with no networking backend.
