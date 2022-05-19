/**
  ******************************************************************************
  * @file           : FL_API_G2.c
  * @brief          : Front_layer body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 Groep_2.
  *
  *
  * This file includes all the necessary functions of the API-Front-Layer
  * The file contains two functions
  *
  ******************************************************************************
  */


#include "main.h"
#include "FL_API_G2.h"

//Include the header of the logic_layer
#include "LL_API_G2.h"


//Define struct
UI_t commando;


/**
  * @Brief Gets the command buffer and counts the added comma's
  * @Param void
  * @Note the function will reset after every enter command
  * @Retval None
  */

void API_Getcommand(void)
{
	//Initialize counters
	int i, commactr;

	// Reset the uart receive buffer index 0
	input.byte_buffer_rx[0] = 0;
	//Reset the characters counter
	input.char_counter = 0;
	//Reset the flag
	input.command_execute_flag = FALSE;

	//Loop in the buffer
    for (i=0;i<LINE_BUFLEN;i++)
    {
    	//Checks if there is a comma in the buffer
        if(input.line_rx_buffer[i] == ',')
        {
        	//Counts the amount of comma's
        	commactr++;
        }
    }

    //Execute function with a stuct and a counter
    API_Command_Data(commando,commactr);
    //Flushing the array
    fflush(stdin);

	//Clear the buffer
	for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;
	//Reset the counter
	commactr = 0;


}

/**
  * @brief Compares the amount of comma's and jumps into a certain function
  * @param UI_t commando, int counter
  * @note  Function gives error when counter is not equal to any command
  * @retval None
  */

void API_Command_Data(UI_t commando,int counter)
{
	//Checks if counter is equal to the amount of commas of the line/rectangle command
	if (counter == LINE_RECT_COMMAND )
	{
		// If the input command is equal to "lijn",
		// the functions will jump into the Seperate_Line function
		if (API_ReLi_Sep() == LINE) Seperate_line();
		// If the input command is equal to "rechthoek",
		// the functions will jump into the Seperate_Rectangle function
	    if (API_ReLi_Sep() == RECTANGLE) Seperate_Rectangle();
	}

	//Checks if counter is equal to the amount of commas of the Text command
	else if(counter==TEXT_COMMAND) Seperate_Text();
	//Checks if counter is equal to the amount of commas of the Circle command
	else if(counter==CIRCKEL_COMMAND) Seperate_Circkel();
	//Checks if counter is equal to the amount of commas of the Bitmap command
	else if(counter==BITMAP_COMMAND) Seperate_Bitmap();
	//Checks if counter is equal to the amount of commas of the Clearscreen command
	else if(counter==CLEARSCREEN_COMMAND) Seperate_Clearscreen();

	// else ERROR
}








