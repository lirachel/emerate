#include <pebble.h>
#include "addContact.h"

Window *addContact;
TextLayer *addName, *addNumber;

void addContact_load(Window *window){
	addName = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(addName, GColorClear);
 	text_layer_set_text_color(addName, GColorBlack);
	text_layer_set_font(addName, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(addName, GTextAlignmentCenter);
	text_layer_set_text(addName, "Name: ");
	layer_add_child(window_get_root_layer(addContact), text_layer_get_layer(addName));
	
	addNumber = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(addNumber, GColorClear);
 	text_layer_set_text_color(addNumber, GColorBlack);
	text_layer_set_font(addNumber, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(addNumber, GTextAlignmentCenter);
	text_layer_set_text(addNumber, "Mobile Number: ");
	layer_add_child(window_get_root_layer(addContact), text_layer_get_layer(addNumber));
}

void addContact_unload(Window *window){
	text_layer_destroy(addName);
	text_layer_destroy(addNumber);
}

void addContact_create(){
	addContact = window_create();
	window_set_window_handlers(addContact, (WindowHandlers) {
    .load = addContact_load,
    .unload = addContact_unload
 	});
	window_set_background_color(addContact, GColorWhite);
}

void addContact_destroy(){
	window_destroy(addContact);
}

Window *get_addContact(){
	return addContact;
}