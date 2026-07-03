#ifndef DISPLAY_H
#define DISPLAY_H
#include "config.h"

Block parse_logo(const char* path);
Block render(Block logo, Block info);

#endif