#include <pebble.h>
#include "messageMenu.h"
#include "message.h"

Window *messageWindow;
MenuLayer *messageMenu;

Window *message, *changeMessage;
TextLayer *messageLayer, *diffMessage;

uint16_t menu_get_num_sections_callback3(MenuLayer *menu_layer, void *data){
	return 1;
}

uint16_t menu_get_num_rows_callback3(MenuLayer *menu_layer, uint16_t section_index, void *data){
	switch(section_index){
		case 0: 
			return 2;
		default:
			return 0;
	}
}


int16_t menu_get_header_height_callback3(MenuLayer *menu_layer, uint16_t section_index, void *data){
    return MENU_CELL_BASIC_HEADER_HEIGHT;
}

void menu_draw_header_callback3(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
	switch(section_index){
		case 0:
			menu_cell_basic_header_draw(ctx, cell_layer, "Message");
			break;
	}
	
}

void menu_draw_row_callback3(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
    switch(cell_index->section){
		case 0:
			switch(cell_index->row){
				case 0:
					menu_cell_basic_draw(ctx, cell_layer, "Message", "", NULL); //last parameter for 20x20 icon if desired
					break;
				case 1:
					menu_cell_basic_draw(ctx, cell_layer, "Change Message", "", NULL); //last parameter for 20x20 icon if desired
					break;
			}
		
	}
}

void menu_select_callback3(MenuLayer *menu_layer, MenuIndex *cell_index, void *data){
	switch(cell_index->row){
		case 0: 
			message_create();
			break;
		case 1:
			changeMessage_create();
			break;
	}
}

void messageWindow_load(Window *window){
	messageMenu = menu_layer_create(GRect(0, 0, 144, 168));
	menu_layer_set_callbacks(messageMenu, NULL, (MenuLayerCallbacks){
        .get_num_sections = menu_get_num_sections_callback3, 
        .get_num_rows = menu_get_num_rows_callback3,
        .get_header_height = menu_get_header_height_callback3,
        .draw_header = menu_draw_header_callback3,
        .draw_row = menu_draw_row_callback3,
        .select_click = menu_select_callback3,
    });

    menu_layer_set_click_config_onto_window(messageMenu, window);

    layer_add_child(window_get_root_layer(messageWindow), menu_layer_get_layer(messageMenu));
}

void messageWindow_unload(Window *window){
	window_destroy(messageWindow);
}

void messageWindow_create(){
	messageWindow = window_create();
	window_set_window_handlers(messageWindow, (WindowHandlers) {
    .load = messageWindow_load,
    .unload = messageWindow_unload
 	});
	window_set_background_color(messageWindow, GColorWhite);
	
	window_stack_push(messageWindow, true);
}

void messageWindow_destroy(){
	window_destroy(messageWindow);
}

Window *get_messageWindow(){
	return messageWindow;
}
