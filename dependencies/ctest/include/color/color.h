#ifndef C_TERMINAL_COLOR
#define C_TERMINAL_COLOR

#include <string.h>
#include <stdlib.h>

extern const char *const c_red;
extern const char *const c_red_light;
extern const char *const c_green;
extern const char *const c_green_light;
extern const char *const c_yellow;
extern const char *const c_yellow_light;
extern const char *const c_blue;
extern const char *const c_blue_light;
extern const char *const c_magenta;
extern const char *const c_magenta_light;
extern const char *const c_cyan;
extern const char *const c_cyan_light;

char* c_color(const char *const color_name, const char *message);

#endif
