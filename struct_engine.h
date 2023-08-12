#ifndef STRUCT_ENGINE_H_
#define STRUCT_ENGINE_H_
#define WITH_ENGINE_TEMP_CONTROLLER 1 //determines if engine temperature and controller are used
									  //according to that certain lines are compiled if its value is 1
struct engine{ //structure containing all the conditions of the engine
	char x;    //represents the choice made by user in engine_options function
	char y;    //represents the choice made by user in engine_turn_on_options function
	char c;    //traffic light colour
	int speed;
	float room_temperature;
	char *ac_state;
	char *engine_state;
#if (WITH_ENGINE_TEMP_CONTROLLER==1)
	float temperature;
	char *temp_controller;
#endif
};

#endif
