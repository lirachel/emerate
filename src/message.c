#include <pebble.h>
#include "message.h"

Window *message, *changeMessage;
TextLayer *messageLayer, *diffMessage;

void message_load(Window *window){
	messageLayer = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(messageLayer, GColorClear);
 	text_layer_set_text_color(messageLayer, GColorBlack);
	text_layer_set_font(messageLayer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(messageLayer, GTextAlignmentCenter);
	text_layer_set_text(messageLayer, "DEFAULT TEXT");
	layer_add_child(window_get_root_layer(message), text_layer_get_layer(messageLayer));
}

void message_unload(Window *window){
	text_layer_destroy(messageLayer);
}

void message_create(){
	message = window_create();
	window_set_window_handlers(message, (WindowHandlers) {
    .load = message_load,
    .unload = message_unload
 	});
	window_set_background_color(message, GColorWhite);
}

void message_destroy(){
	window_destroy(message);
}

Window *get_message(){
	return message;
}

void changeMessage_load(Window *window){
	diffMessage = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(diffMessage, GColorClear);
 	text_layer_set_text_color(diffMessage, GColorBlack);
	text_layer_set_font(diffMessage, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(diffMessage, GTextAlignmentCenter);
	text_layer_set_text(diffMessage, "Write a different text: ");
	layer_add_child(window_get_root_layer(changeMessage), text_layer_get_layer(diffMessage));
}

void changeMessage_unload(Window *window){
	text_layer_destroy(diffMessage);
}

void changeMessage_create(){
	changeMessage = window_create();
	window_set_window_handlers(changeMessage, (WindowHandlers) {
    .load = changeMessage_load,
    .unload = changeMessage_unload
 	});
	window_set_background_color(changeMessage, GColorWhite);
}

void changeMessage_destroy(){
	window_destroy(changeMessage);
}

Window *get_changeMessage(){
	return changeMessage;
}