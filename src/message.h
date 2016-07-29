#pragma once
#include <pebble.h>

void message_create();
void message_destroy();
Window *get_message();

void changeMessage_create();
void changeMessage_destroy();
Window *get_changeMessage();