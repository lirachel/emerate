#include <pebble.h>
#include "mainMenu.h"
#include "contactMenu.h"
#include "messageMenu.h"
#include "splashWindow.h"

void launch_main_window(void *data){
	window_stack_push(get_mainWindow(), true);
}

int main(){
	splash_window_create();
	mainWindow_create();
	
	window_stack_push(splash_window_get_window(), true);
	app_timer_register(1500, launch_main_window, NULL);
	
	app_event_loop();
	mainWindow_destroy();
	splash_window_destroy();
}