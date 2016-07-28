#include <pebble.h>
#include "mainMenu.h"

int main(){
	mainWindow_create();
	app_event_loop();
	mainWindow_destroy();
}