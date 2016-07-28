#include <pebble.h>
#include "send.h"

Window *send;
TextLayer *sendLayer;

void send_load(Window *window){
	sendLayer = text_layer_create(GRect(0, 0, 144, 168));
	text_layer_set_background_color(sendLayer, GColorClear);
 	text_layer_set_text_color(sendLayer, GColorBlack);
	text_layer_set_font(sendLayer, fonts_get_system_font(FONT_KEY_GOTHIC_18));
	text_layer_set_text_alignment(sendLayer, GTextAlignmentCenter);
	text_layer_set_text(sendLayer, "Text sent!");
	layer_add_child(window_get_root_layer(send), text_layer_get_layer(sendLayer));
}

void send_unload(Window *window){
	text_layer_destroy(sendLayer);
}

void send_create(){
	send = window_create();
	window_set_window_handlers(send, (WindowHandlers) {
    .load = send_load,
    .unload = send_unload
 	});
	window_set_background_color(send, GColorWhite);
}

void send_destroy(){
	window_destroy(send);
}

Window *get_send(){
	return send;
}