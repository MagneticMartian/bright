#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>

static const char* BACKLIGHT_FILE = "/sys/class/backlight/intel_backlight/brightness";
static const int MAX_BRIGHT = 500;
static const int INC_BRIGHT = 50;
static const int DEC_BRIGHT = -50;
