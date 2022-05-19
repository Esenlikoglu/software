/*
 * FL_API_G2.c
 *
 *  Created on: 12 May 2022
 *      Author: yassi
 */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */


//#include <stdio.h>
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "FL_API_G2.h"
#include "LL_API_G2.h"

UI_t commando;


//--------------------------------------------------------------
//
//--------------------------------------------------------------

void API_Getcommand(void)
{
	int i;
	int commacounter;

	// Reset some stuff
	input.byte_buffer_rx[0] = 0;
	input.char_counter = 0;
	input.command_execute_flag = FALSE;

	//Loop in the buffer
    for (i=0;i<LINE_BUFLEN;i++)
    {
    	//Checks if there is a comma in the buffer
        if(input.line_rx_buffer[i] == ',')
        {
        	//Counts the amount of comma's
        	commacounter++;
        }
    }
    API_Command_Data(commando,commacounter);
    fflush(stdin);

	//clear the buffer
	for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;
	commacounter = 0;


}

//--------------------------------------------------------------
// Switching the amount of comma's and jumps into a certain function
//--------------------------------------------------------------

void API_Command_Data(UI_t commando,int counter)
{
	if (counter == LINE_RECT_COMMAND )
	{
		if (API_ReLi_Sep() == LINE) Seperate_line();
	    if (API_ReLi_Sep() == RECTANGLE) Seperate_Rectangle();
	}
	else if(counter==TEXT_COMMAND) Seperate_Text();
	else if(counter==CIRCKEL_COMMAND) Seperate_Circkel();
	else if(counter==BITMAP_COMMAND) Seperate_Bitmap();
	else if(counter==CLEARSCREEN_COMMAND) Seperate_Clearscreen();
}








