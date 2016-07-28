#include <pebble.h>
#include "contacts.h"

Window *momContact, *dadContact;
TextLayer *momName, *dadName, *momNumber, *dadNumber;

void momContact_load(Window *window){
	momName = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(momName, GColorClear);
 	text_layer_set_text_color(momName, GColorBlack);
	text_layer_set_font(momName, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(momName, GTextAlignmentCenter);
	text_layer_set_text(momName, "Mobile Number: (123)456-7890");
	layer_add_child(window_get_root_layer(momContact), text_layer_get_layer(momName));
	
	momNumber = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(momNumber, GColorClear);
 	text_layer_set_text_color(momNumber, GColorBlack);
	text_layer_set_font(momNumber, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(momNumber, GTextAlignmentCenter);
	text_layer_set_text(momNumber, "Mom");
	layer_add_child(window_get_root_layer(momContact), text_layer_get_layer(momNumber));
}

void momContact_unload(Window *window){
	text_layer_destroy(momName);
	text_layer_destroy(momNumber);
}

void momContact_create(){
	momContact = window_create();
	window_set_window_handlers(momContact, (WindowHandlers) {
    .load = momContact_load,
    .unload = momContact_unload
 	});
	window_set_background_color(momContact, GColorWhite);
}

void momContact_destroy(){
	window_destroy(momContact);
}

Window *get_momContact(){
	return momContact;
}

void dadContact_load(Window *window){
	dadName = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(dadName, GColorClear);
 	text_layer_set_text_color(dadName, GColorBlack);
	text_layer_set_font(dadName, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(dadName, GTextAlignmentCenter);
	text_layer_set_text(dadName, "Dad");
	layer_add_child(window_get_root_layer(dadContact), text_layer_get_layer(dadName));
	
	dadNumber = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(dadNumber, GColorClear);
 	text_layer_set_text_color(dadNumber, GColorBlack);
	text_layer_set_font(dadNumber, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(dadNumber, GTextAlignmentCenter);
	text_layer_set_text(dadNumber, "Mom");
	layer_add_child(window_get_root_layer(dadContact), text_layer_get_layer(dadNumber));
}

void dadContact_unload(Window *window){
	text_layer_destroy(dadName);
	text_layer_destroy(dadNumber);
}

void dadContact_create(){
	dadContact = window_create();
	window_set_window_handlers(dadContact, (WindowHandlers) {
    .load = dadContact_load,
    .unload = dadContact_unload
 	});
	window_set_background_color(dadContact, GColorWhite);
}

void dadContact_destroy(){
	window_destroy(dadContact);
}

Window *get_dadContact(){
	return dadContact;
}