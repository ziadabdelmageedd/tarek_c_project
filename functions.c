#include <stdio.h>
#include "struct_engine.h"
#include "functions.h"
void engine_options()
{
	puts("a. Turn on the vehicle engine");
	puts("b. Turn off the vehicle engine");
	puts("c. Quit the system");
	fflush(stdout);
	scanf(" %c",&current_engine.x);
}
void engine_turn_on_options()
{
	puts("a. Turn off the engine");
	puts("b. Set the traffic light colour.");
	puts("c. Set the room temperature (Temperature Sensor)");
	puts("d. Set the engine temperature (Engine Temperature Sensor)");
	fflush(stdout);
	scanf(" %c",&current_engine.y);
}
void receive_traffic_light()
{
	puts("Please enter the required colour :");
	fflush(stdout);
	scanf(" %c",&current_engine.c);
}
void receive_room_temperature()
{
	puts("Please enter the room temperature :");
	fflush(stdout);
	scanf("%f",&current_engine.room_temperature);
}
void receive_engine_temperature()
{
	puts("Please enter the engine temperature :");
	fflush(stdout);
	scanf("%f",&current_engine.temperature);
}
void check_temp()
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
void check_traffic()
{
	if(current_engine.c=='g'||current_engine.c=='G')
		current_engine.speed=100;
	else if(current_engine.c=='o'||current_engine.c=='O')
		current_engine.speed=30;
	else if(current_engine.c=='r'||current_engine.c=='R')
		current_engine.speed=0;
}
void check_engine_temp()
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
void check_speed()
{
	if (current_engine.speed==30)
	{
		current_engine.ac_state="ON";
		current_engine.room_temperature=(current_engine.room_temperature*5)/4+1;
		current_engine.temp_controller="ON";
		current_engine.temperature=(current_engine.temperature*5)/4+1;
		check_temp(); //need to check temperature because i may need to turn on AC here
		check_engine_temp(); //need to check engine temperature as it increases
	}
}

void engine_init() //initial values that don't trigger any conditions
{
	current_engine.speed=100;
	current_engine.room_temperature=20;
	current_engine.temperature=110;
	current_engine.ac_state="OFF";
	current_engine.engine_state="ON";
	current_engine.temp_controller="OFF";
}
void engine_display()
{
	printf("Engine is %s\n",current_engine.engine_state);
	printf("AC is %s\n",current_engine.ac_state);
	printf("Vehicle speed is %d km/hr\n",current_engine.speed);
	printf("Room temperature is %d\n",(int)current_engine.room_temperature);
	printf("Engine temperature controller is %s\n",current_engine.temp_controller);
	printf("Engine temperature is %d\n\n",(int)current_engine.temperature);
	fflush(stdout);
}

