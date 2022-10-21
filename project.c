/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [FILE NAME]: Vehicle Control system
 * [AUTHOR]: Afnan Talaat
 * [DESCRIPTION]: This is a vehicle control system which can Turn on/off the vehicle engine, use sensors of the vehicle , control room temperature and engine temperature and control vehicle speed.
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#define WITH_ENGINE_TEMP_CONTROLLER 1 /* to check if this system with engine temperature controller or not */


/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [ENUM NAME]: Air_Condion_State
 * [ENUM DESCRIPTION]: the enum responsible for Air conditioner state ON/OFF
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	AC_OFF , AC_ON
}Air_Conditioner_State;

/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [ENUM NAME]: Engine_Temperature_Controller_State
 * [ENUM DESCRIPTION]: the enum responsible for Engine Temperature Controller State ON/OFF
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	CONTROLLER_OFF , CONTROLLER_ON
}Engine_Temperature_Controller_State;

/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [ENUM NAME]: Engine_State
 * [ENUM DESCRIPTION]: the enum responsible for Engine State ON/OFF
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	ENGINE_OFF , ENGINE_ON
}Engine_State;




/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: Vehicle_SetupRoomTemp
 * [DESCRIPTION]: this function is responsible for set up room temperature
 * [ARGS]:
 [IN] *temp_ptr : store temp of room
 [RETURNS] Air_Conditioner_State : if AC is ON/OFF
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
Air_Conditioner_State Vehicle_SetupRoomTemp(int *temp_ptr)
{
	Air_Conditioner_State state = AC_OFF;
	if(*temp_ptr < 10)
	{
		state = AC_ON;
		*temp_ptr = 20;
	}
	else if(*temp_ptr > 30)
	{
		state = AC_ON;
		*temp_ptr = 20;
	}
	else
	{
		state = AC_OFF;
	}
	return state;
}





/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: Vehicle_CalculateSpeed
 * [DESCRIPTION]: this function is responsible for calculate vehicle speed depend on traffic light
 * [ARGS]:
 [IN] light : store traffic light
 [RETURNS] speed : the vehicle speed after calculate
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
int Vehicle_CalculateSpeed(char light)
{
	int speed;

	if((light == 'G') || (light == 'g')) speed = 100;
	if((light == 'O') || (light == 'o')) speed = 30;
	if((light == 'R') || (light == 'r')) speed = 0;

	return speed;
}



/*--------------------------------------------------------------------------------------------------------------------------------------------------
 * [FUNCTION NAME]: Vehicle_SetupEngineTempController
 * [DESCRIPTION]: this function responsible for set up engine temp controller
 * [ARGS]:
 [IN] temp_ptr: store temp of engine
 [RETURNS] Engine_Temperature_Controller_State: return the state of engine ON/OFF
 -------------------------------------------------------------------------------------------------------------------------------------------------*/
Engine_Temperature_Controller_State Vehicle_SetupEngineTempController(int *temp_ptr)
{
	Engine_Temperature_Controller_State state = CONTROLLER_OFF;
	if(*temp_ptr < 100)
	{
		state = CONTROLLER_ON;
		*temp_ptr= 125;
	}
	else if(*temp_ptr > 150)
	{
		state = CONTROLLER_ON;
		*temp_ptr =125;
	}
	else
	{
		state = CONTROLLER_OFF;
	}
	return state;
}




int main(void)
{
	char user_input;
	char sensors_states;
	char traffic_light;

	/*set initial values of vehicle states*/
	Engine_State Engine = ENGINE_OFF;
	Air_Conditioner_State AC_state = AC_OFF;
	int vehicle_speed =0;
	int temp_room = 35;

	/*check if the system with engine temperature controller to set initial values for it */
#if (WITH_ENGINE_TEMP_CONTROLLER ==1)
	Engine_Temperature_Controller_State engine_temp_control = CONTROLLER_OFF;
	int temp_engine = 90;
#endif

	/*infinite loop to make system run all time*/
	for(;;)
	{
		/*Display system menu to user */
		printf("a. Turn on the Vehicle Engine\n");
		printf("b. Turn off the Vehicle Engine\n");
		printf("c. Quit the System\n");

		/* for printf eclipse issue */
		fflush(0);

		/*get input from user*/
		scanf(" %c",&user_input);

		/*if user input 'c' or 'C' the system should be terminated*/
		if((user_input == 'c') || (user_input == 'C'))
		{
			printf("Quit the System \n ");
			break;
		}
		/*if user input 'b' or 'B' turn off vehicle engine*/
		else if((user_input == 'b') || (user_input == 'B'))
		{
			Engine = ENGINE_OFF;
			printf("Turn off Vehicle Engine \n");
		}

		/*if user input 'a' or 'A' turn on vehicle engine */
		else if((user_input == 'a') || (user_input == 'A'))
		{
			for(;;)
			{
				Engine =  ENGINE_ON; /*turn on vehicle engine */

				/*Display Sensors set menu*/
				printf("a. Turn off the engine\n");
				printf("b. Set the Traffic light color \n");
				printf("c. Set the room temperaure (Temperature Sensor)\n");

#if (WITH_ENGINE_TEMP_CONTROLLER ==1)
				printf("d. Set the engine temperature \n");
#endif
				/* for printf eclipse issue */
				fflush(0);

				/*get sensor state from user*/
				scanf(" %c",&sensors_states);

				/*if user input 'a' or 'A' turn off vehicle engine */
				 if((sensors_states == 'a') || (sensors_states == 'A'))
				 {
					 /*turn of vehicle engine*/
					 Engine = ENGINE_OFF;

					 /*break the inner loop and go to outer loop */
					 break;
				 }

				 /*if user input 'b' or 'B' set traffic light color*/
				 if((sensors_states == 'b') || (sensors_states == 'B'))
				 {
					printf("Enter the required color:\n");
					fflush(0);
					scanf(" %c",&traffic_light);

					vehicle_speed = Vehicle_CalculateSpeed(traffic_light);
				 }

				 /*if user input 'c' or 'C' set room temperature*/
				 if((sensors_states == 'c') || (sensors_states == 'C'))
				 {
					printf("Enter the required room temperature:\n");
					fflush(0);
					scanf("%d",&temp_room);

					/*update AC state and temp room*/
					AC_state= Vehicle_SetupRoomTemp(&temp_room);
				 }


#if (WITH_ENGINE_TEMP_CONTROLLER == 1)
				 /*if user input 'd' or 'D' set engine temperature*/
				 if((sensors_states == 'd') || (sensors_states == 'D'))
				 {
					printf("Enter the required engine temperature:\n");
					fflush(0);
					scanf("%d",&temp_engine);

					/*update engine temp controller state and temp engine */
					engine_temp_control = Vehicle_SetupEngineTempController(&temp_engine);
				 }

#endif
				 if(vehicle_speed == 30)
				 {
					 if(AC_state == AC_OFF)
					 {
						 AC_state = AC_ON;
					 }
					 temp_room = ((temp_room *5) / 4) +1;

#if (WITH_ENGINE_TEMP_CONTROLLER == 1)
				     if(engine_temp_control== CONTROLLER_OFF)
				     {
					    engine_temp_control = CONTROLLER_ON;
				     }
				     temp_engine = ((temp_engine *5) / 4) +1;
#endif
				    }



			/*Display current vehicle state*/

			/*display engine state*/
			if(Engine == ENGINE_OFF)
			{
				printf("Engine is OFF\n");
			}
			else
			{
				printf("Engine is ON\n");
			}

			/*display air conditioner state*/
			if(AC_state == AC_OFF)
			{
				printf("AC is OFF\n");
			}
			else
			{
				printf("AC is ON\n");
			}

			/*display vehicle speed*/
			printf("Vehicle speed: %d km/hr \n",vehicle_speed);

			/*display room temperature*/
			printf("Room Temperature: %d C\n",temp_room);

#if (WITH_ENGINE_TEMP_CONTROLLER == 1)
			/*display engine controller state*/
			if(engine_temp_control ==CONTROLLER_OFF)
			{
				printf("Engine temp controller is OFF\n");

			}
			else
			{
				printf("Engine Temp Controller is ON\n");
			}

			/*display engine temperature*/
			printf("Engine Temperature:%d C\n \n",temp_engine);
#endif
			}
	    }
		else{
			printf("Error please enter valid input\n");
	    }

   }
   return 0;
}
