#include <stdio.h>
#include "struct_engine.h"
#include "functions.h"
extern struct engine current_engine; //global variable included here
void engine_options()			     //options to do with the engine
{
	puts("a. Turn on the vehicle engine");
	puts("b. Turn off the vehicle engine");
	puts("c. Quit the system");
	fflush(stdout);
	scanf(" %c",&current_engine.x);
}
void engine_turn_on_options()	//choices after turning on the engine
{
	puts("a. Turn off the engine");
	puts("b. Set the traffic light colour.");
	puts("c. Set the room temperature (Temperature Sensor)");
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
	puts("d. Set the engine temperature (Engine Temperature Sensor)");
#endif
	fflush(stdout);
	scanf(" %c",&current_engine.y);
}
void receive_traffic_light()	//input traffic light
{
	puts("Please enter the required colour :");
	fflush(stdout);
	scanf(" %c",&current_engine.c);
}
void receive_room_temperature()		//input room temperature
{
	puts("Please enter the room temperature :");
	fflush(stdout);
	scanf("%f",&current_engine.room_temperature);
}
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
void receive_engine_temperature()	//input engine temperature
{
	puts("Please enter the engine temperature :");
	fflush(stdout);
	scanf("%f",&current_engine.temperature);
}
#endif
void check_temp()	//conditions at certain room temperatures
{
	if(current_engine.room_temperature<10)
	{
		current_engine.ac_state="ON";
		current_engine.room_temperature=20;
	}
	else if(current_engine.room_temperature>30)
	{
		current_engine.ac_state="ON";
		current_engine.room_temperature=20;
	}
	else
		current_engine.ac_state="OFF";
}
void check_traffic()	//conditions at certain traffic colours
{
	if(current_engine.c=='g'||current_engine.c=='G')
		current_engine.speed=100;
	else if(current_engine.c=='o'||current_engine.c=='O')
		current_engine.speed=30;
	else if(current_engine.c=='r'||current_engine.c=='R')
		current_engine.speed=0;
}
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
void check_engine_temp()	//conditions at certain engine temperatures
{
	if(current_engine.temperature<100)
	{
		current_engine.temp_controller="ON";
		current_engine.temperature=125;
	}
	else if(current_engine.temperature>150)
	{
		current_engine.temp_controller="ON";
		current_engine.temperature=125;
	}
	else
		current_engine.temp_controller="OFF";
}
#endif
void check_speed() //changing temperature when speed is 30
{
	if (current_engine.speed==30)
	{
		current_engine.room_temperature=(current_engine.room_temperature*5)/4+1;
		check_temp(); //need to check temperature because i may need to turn on AC to make temp 20
		current_engine.ac_state="ON"; //i'll always have it on despite temperature
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		current_engine.temperature=(current_engine.temperature*5)/4+1;
		check_engine_temp(); //need to check engine temperature as it increases
		current_engine.temp_controller="ON"; //i'll always have it on despite temperature
#endif
	}
}

void engine_init() //initial values that don't trigger any conditions
{
	current_engine.speed=100;
	current_engine.room_temperature=20;
	current_engine.ac_state="OFF";
	current_engine.engine_state="ON";
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
	current_engine.temp_controller="OFF";
	current_engine.temperature=110;
#endif
}
void engine_display() //displays current engine status
{
	printf("Engine is %s\n",current_engine.engine_state);
	printf("AC is %s\n",current_engine.ac_state);
	printf("Vehicle speed is %d km/hr\n",current_engine.speed);
	printf("Room temperature is %d\n",(int)current_engine.room_temperature);
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
	printf("Engine temperature controller is %s\n",current_engine.temp_controller);
	printf("Engine temperature is %d\n\n",(int)current_engine.temperature);
#else
	printf("\n");	//to compensate the new line in line 119
#endif
	fflush(stdout);
}

