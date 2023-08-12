#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include "struct_engine.h"
struct engine current_engine;
//i don't check on initial values because in the video , the printed engine initial values weren't checked on
//so i decided to make all the initial values not trigger the sensors
int main(void) {
	while(1)
	{	engine_init();
		engine_options();
		if(current_engine.x=='a')
		{	puts("Turn on the vehicle engine\n"); //prints choice
			while(1)
			{								//each if contains 2 functions one for receiving inputs
				engine_turn_on_options();   // from user and the other is for checking the sensors
				if(current_engine.y=='a')
					break;
				else if(current_engine.y=='b')
				{
					receive_traffic_light();
					check_traffic();
					check_temp();			//if speed was previously 30 and it now changed i'll need to check temperature
#if(WITH_ENGINE_TEMP_CONTROLLER==1)
					check_engine_temp();
#endif
				}
				else if(current_engine.y=='c')
				{
					receive_room_temperature();
					check_temp();
				}
#if(WITH_ENGINE_TEMP_CONTROLLER==1)
				else if(current_engine.y=='d')
				{
					receive_engine_temperature();
					check_engine_temp();
				}
#endif
				check_speed(); //checks if speed is 30 and does its code
				engine_display(); //displays engine conditions
			}
		}
		else if(current_engine.x=='b')
			puts("Turn off the vehicle engine\n");	//prints choice
		else if(current_engine.x=='c')
		{
			puts("Quit the system");	//end program
			return 0;
		}
	}

}
