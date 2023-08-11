#ifndef STRUCT_ENGINE_H_
#define STRUCT_ENGINE_H_

struct engine{ //structure containing all the conditions of the engine
	char x;    //represents the choice made by user in engine_options function
	char y;    //represents the choice made by user in engine_turn_on_options function
	char c;    //traffic light colour
	int speed;
	float room_temperature;
	float temperature;
	char *ac_state;
	char *engine_state;
	char *temp_controller;
}current_engine;

#endif
