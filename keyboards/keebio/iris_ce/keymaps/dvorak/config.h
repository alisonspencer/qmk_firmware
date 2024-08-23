/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/


#undef DEBOUNCE
#define DEBOUNCE 20


#undef TAPPING_TERM
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
#define TAPPING_TOGGLE 2


#define LAYER_LOCK_IDLE_TIMEOUT 60000  // Turn off after 60 seconds.


#define COMBO_TERM 200
#define COMBO_STRICT_TIMER


#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 300  // how long before oneshot times out
#define ONESHOT_TAP_TOGGLE 2 // how many taps before oneshot toggle is triggered


#define SELECT_WORD_TIMEOUT 2000  // When idle, clear state after 2 seconds.

// #define PERMISSIVE_HOLD



#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_TIMEOUT 60000  // 60s timeout in milliseconds

#define BACKLIGHT_LEVELS 6  // number of levels your backlight will have (maximum 31 excluding off)
#define BACKLIGHT_BREATHING  // enables backlight breathing
#define BREATHING_PERIOD 15
#define RGBLIGHT_LAYERS



#define USB_SUSPEND_WAKEUP_DELAY 0


#define TRI_LAYER_LOWER_LAYER 4
#define TRI_LAYER_UPPER_LAYER 6
#define TRI_LAYER_ADJUST_LAYER 11





