#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include "struct_engine.h"

int main(void) {
	while(1)
	{	engine_init();
		engine_options();
		if(current_engine.x=='a')
		{	puts("Turn on the vehicle engine\n");
			while(1)
			{								//each if contains 2 functions one for receiving inputs
				engine_turn_on_options();   // from user and the other is for checking the sensors
				if(current_engine.y=='a')
					break;
				else if(current_engine.y=='b')
				{
					receive_traffic_light();
					check_traffic();
				}
				else if(current_engine.y=='c')
				{
					receive_room_temperature();
					check_temp();
				}
				else if(current_engine.y=='d')
				{
					receive_engine_temperature();
					check_engine_temp();
				}
				check_speed(); //keeps checking if speed is 30 and increase the temp if it is each time
				engine_display();
			}
		}
		else if(current_engine.x=='b')
			puts("Turn off the vehicle engine\n");
		else if(current_engine.x=='c')
		{
			puts("Quit the system");
			return 0;
		}
	}

}
