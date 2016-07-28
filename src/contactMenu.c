#include <pebble.h>
#include "contactMenu.h"
#include "contacts.h"
#include "addContact.h"

Window *contactWindow;
MenuLayer *contactMenu;

Window *momContact, *dadContact;
TextLayer *momName, *dadName, *momNumber, *dadNumber;

Window *addContact;
TextLayer *addName, *addNumber;

uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data){
	return 1;
}

uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data){
	switch(section_index){
		case 0: 
			return 3;
		default:
			return 0;
	}
}

int16_t menu_get_header_height_callback(MenuLayer *menu_layer, uint16_t section_index, void *data){
    return MENU_CELL_BASIC_HEADER_HEIGHT;
}

void menu_draw_header_callback(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
	switch(section_index){
		case 0:
			menu_cell_basic_header_draw(ctx, cell_layer, "Contacts");
			break;
	}
	
}

void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
    switch(cell_index->section){
		case 0:
			switch(cell_index->row){
				case 0:
					menu_cell_basic_draw(ctx, cell_layer, "Mom", "", NULL); //last parameter for 20x20 icon if desired
					break;
				case 1:
					menu_cell_basic_draw(ctx, cell_layer, "Dad", "", NULL); //last parameter for 20x20 icon if desired
					break;
				case 2:
					menu_cell_basic_draw(ctx, cell_layer, "Add Contact", "", NULL); //last parameter for 20x20 icon if desired
					break;
			}
		
	}
}

void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data){
	switch(cell_index->row){
		case 0: 
			momContact_create();
			break;
		case 1:
			dadContact_create();
			break;
		case 2:
			addContact_create();
			break;
	}
}

void contactWindow_load(Window *window){
	contactMenu = menu_layer_create(GRect(0, 0, 144, 168));
	menu_layer_set_callbacks(contactMenu, NULL, (MenuLayerCallbacks){
        .get_num_sections = menu_get_num_sections_callback, 
        .get_num_rows = menu_get_num_rows_callback,
        .get_header_height = menu_get_header_height_callback,
        .draw_header = menu_draw_header_callback,
        .draw_row = menu_draw_row_callback,
        .select_click = menu_select_callback,
    });

    menu_layer_set_click_config_onto_window(contactMenu, window);

    layer_add_child(window_get_root_layer(contactWindow), menu_layer_get_layer(contactMenu));
}

void contactWindow_unload(Window *window){
	menu_layer_destroy(contactMenu);
}

void contactWindow_create(){
	contactWindow = window_create();
	window_set_window_handlers(contactWindow, (WindowHandlers) {
    .load = contactWindow_load,
    .unload = contactWindow_unload
 	});
	window_set_background_color(contactWindow, GColorWhite);
}

void contactWindow_destroy(){
	window_destroy(contactWindow);
}

Window *get_contactWindow(){
	return contactWindow;
}