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

	//clear the buffer
	for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;
	commacounter = 0;


}

//--------------------------------------------------------------
// Switching the amount of comma's and jumps into a certain function
//--------------------------------------------------------------

void API_Command_Data(UI_t commando,int counter)
{

	switch (counter)
	{
		case CLEARSCREEN_COMMAND:
			Seperate_Clearscreen();
			break;
		case BITMAP_COMMAND:
			Seperate_Bitmap();
			break;
		case LINE_RECT_COMMAND:
			//Since Line command and Rectangle command have the same amount of commas
			//Checks if the returned value is a line or rectangle
			if (API_ReLi_Sep() == LINE) Seperate_line();
		    if (API_ReLi_Sep() == RECTANGLE) Seperate_Rectangle();
			break;
		case TEXT_COMMAND:
			Seperate_Text();
			break;
		default:
			printf("Ik ben niet in de cases gegaan");
			break;
	}

}


//--------------------------------------------------------------
// Check if the command is a line or a rectangle
// Returns 1 if line, 2 if rectangle
//--------------------------------------------------------------
int API_ReLi_Sep(void)
{
	int cmp;
	char comp_line[LINE_TEXT];

	for(int i = 0; i<LINE_TEXT;i++)
	{
		comp_line[i] = input.line_rx_buffer[i];
	}

	//Compare the written command with "lijn" and "rech"
	if (strncmp ( comp_line, "lijn", sizeof(comp_line)) == 0) cmp = LINE;
	if (strncmp ( comp_line, "rech", sizeof(comp_line))== 0) cmp = RECTANGLE;

	//Returns 1 if line, 2 if rectangle
	return cmp;
}


//--------------------------------------------------------------
// Seperate the buffer of a line-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------
void Seperate_line(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	// comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	 memcpy(&commando.x_1, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_1, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.x_2, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_2, &aryvul[ARRAY_FOURTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.kleur, &aryvul[ARRAY_FIFTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.dikte, &aryvul[ARRAY_SIXTH_lOCATION] , sizeof(commando.x_1));
}



//--------------------------------------------------------------
// Seperate the buffer of a rectangle-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------
void Seperate_Rectangle(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	// comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	 memcpy(&commando.x_lup, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_lup, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.breedte, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.hoogte, &aryvul[ARRAY_FOURTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.rect_kleur, &aryvul[ARRAY_FIFTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.gevuld, &aryvul[ARRAY_SIXTH_lOCATION] , sizeof(commando.x_1));

}


//--------------------------------------------------------------
// Seperate the buffer of a text-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------

void Seperate_Text(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	//Comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	 memcpy(&commando.x, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.text_kleur, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.tekst, &aryvul[ARRAY_FOURTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.fontnaam, &aryvul[ARRAY_FIFTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.fontgrootte, &aryvul[ARRAY_SIXTH_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.fontstijl, &aryvul[ARRAY_SEVENTH_lOCATION] , sizeof(commando.x_1));

}

//--------------------------------------------------------------
// Seperate the buffer of a Bitmap-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------

void Seperate_Bitmap(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	//Comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	 memcpy(&commando.nr, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.x_lup_bitmap, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_lup_bitmap, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));
}


//--------------------------------------------------------------
// Seperate the buffer of a Clearscreen-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------

void Seperate_Clearscreen(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	//Comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	memcpy(&commando.color_screen, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
}







