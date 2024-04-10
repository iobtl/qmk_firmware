// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_pointing_device.md
// Auto enables mouse layer when mouse is in use
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

// Index of mouse layer
#define AUTO_MOUSE_DEFAULT_LAYER 4

// Time layer remains active after activation (default 650ms)
#define AUTO_MOUSE_TIME 500

#define TAPPING_TERM 150

// TODO: not needed? already have custom userspace impl.
// #define QUICK_TAP_TERM 100

// If another key is tapped while a key is currently being held, activates the held behavior instantly.
#define PERMISSIVE_HOLD

#define BILATERAL_COMBINATIONS

// Suppresses modifiers during periods of active typing.
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 150

// Define only one of the two below, but not both.
// Read here for details: https://github.com/sadekbaroudi/qmk_firmware/tree/master/keyboards/fingerpunch#layer-lighting

// #define FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE
