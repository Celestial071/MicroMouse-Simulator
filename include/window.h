#ifndef _WINDOW_H
#define _WINDOW_H
//library inclusion
#pragma once

#include "algorithm.h"

void window(const int screenWidth, const int screenHeight);
void drawMap(const char *map);
int getindexStart(const char *buffer);
int getWidth(const char *buffer);
#endif