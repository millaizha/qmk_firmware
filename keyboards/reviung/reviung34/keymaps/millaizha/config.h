#define TAPPING_TERM 300
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION  
#define NO_ACTION_ONESHOT

#define NO_USB_STARTUP_CHECK
#define NO_MUSIC_MODE

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT