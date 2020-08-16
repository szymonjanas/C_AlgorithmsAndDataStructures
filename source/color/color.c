#include "color.h"

const char *const c_red           = "[0;31m";
const char *const c_red_light     = "[1;31m";
const char *const c_green         = "[0;32m";
const char *const c_green_light    = "[1;32m";
const char *const c_yellow        = "[0;33m";
const char *const c_yellow_light   = "[1;33m";
const char *const c_blue          = "[0;34m";
const char *const c_blue_light     = "[1;34m";
const char *const c_magenta       = "[0;35m";
const char *const c_magenta_light  = "[1;35m";
const char *const c_cyan          = "[0;36m";
const char *const c_cyan_light     = "[1;36m";

static const char *const c_reset         = "[0m";
static const char *const c_esc           = "\033";

char* c_color(const char *const color_name, const char *message)
{
    char * out = (char *) malloc (3 + strlen(color_name) + strlen(message) + strlen(c_reset));
    strcpy(out, c_esc);
    strcat(out, color_name);
    strcat(out, message);
    strcat(out, c_esc);
    strcat(out, c_reset);
    return out;
}
