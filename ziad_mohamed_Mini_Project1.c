#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include "struct_engine.h"
struct engine current_engine; //global struct

/*1) i don't check on initial values because in the video uploaded by MT , the printed engine initial values weren't checked on
so i decided to make all the initial values not trigger the sensors*/

/*2)when speed gets to 30 and temp increases by (5/4) +1 to above the threshold i make temp 20 because of the temp sensor
 same for engine temp to 125*/
int main(void) {
	while(1) // ends only when current_engine.x==c
	{	engine_init();
		engine_options();
		if(current_engine.x=='a')
		{	puts("Turn on the vehicle engine\n"); //prints choice
			while(1) //ends only current_engine.y==a
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
#if(WITH_ENGINE_TEMP_CONTROLLER==1)
				else if(current_engine.y=='d')
				{
					receive_engine_temperature();
					check_engine_temp();
				}
#endif
				else
				{
					puts("Invalid option , Please choose again"); //retake input if it was invalid
					continue;
				}
				if(current_engine.c!='o' && current_engine.c!='O') //checks temp if i did not check on it already (to turn off ac or temp controller if speed was previously 30)
																   // and if my speed is not 30 (i switched to another speed)
				{
					if(current_engine.y!='c') //if i did not check on temp already
						check_temp();
#if(WITH_ENGINE_TEMP_CONTROLLER==1)
					if(current_engine.y!='d') //if i did not check on engine temp already
						check_engine_temp();
#endif
				}
				engine_display(); //displays engine conditions
				current_engine.c='\0'; //to reset traffic colour to make conditions in line 46 work correctly (i did not turn to 30km/hr recently)
			}
		}
		else if(current_engine.x=='b')
			puts("Turn off the vehicle engine\n");	//prints choice
		else if(current_engine.x=='c')
		{
			puts("Quit the system");	//end program
			return 0;
		}
		else
		{
			puts("Invalid option , Please choose again"); //retake input if it was invalid
			continue;
		}

	}

}
