/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : LL_API_G2.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *  Created on: 12 May 2022
  *      Author: Sahag
  * <h2><center>&copy; Copyright (c) 2022 Hogeschool Utrecht.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "LL_API_G2.h"
#include "IO_API_G2.h"
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <errno.h>
/* USER CODE END Includes */



////s: custom error message
////
////Output: custom error message followed by colon, space, and implementation-defined error message

const char* errnum;

void API_In_DrawLine(UI_t apidata)
{
		if(apidata.x_1 == 0 || apidata.y_1 == 0 || apidata.x_2 == 0|| apidata.y_2 == 0|| apidata.kleur== 0)
	{
			errno = ERANGE;
			show_errno(errnum);
		}
	 else plotLine(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.y_2,apidata.kleur);



}

void API_In_DrawRectangle(UI_t apidata)
{


	plotRect(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.y_2,apidata.kleur);
}


void API_In_DrawCirckel(UI_t apidata)
{

	plotCircle(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.kleur);
}



void API_In_DrawText(UI_t apidata)
{
	API_text(apidata.x,apidata.y,apidata.text_kleur,apidata.tekst);
}




void show_errno(const char *err_info)
{

    err_info = "unknown error";
    switch (errno) {
    case EDOM:
        err_info = "domain error";
        break;
    case EILSEQ:
        err_info = "illegal sequence";
        break;
    case ERANGE:
        err_info = "pole or range error";
        break;
    case 0:
        err_info = "no error";
    }
    printf("ERROR: %s \n" ,err_info);
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


	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.dikte = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);


	 //draw line
	 API_In_DrawLine(commando);

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



	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.gevuld = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);

	API_In_DrawRectangle(commando);


}

//--------------------------------------------------------------
// Seperate the buffer of a circkel-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------
void Seperate_Circkel(void)
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



	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.gevuld = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);

	API_In_DrawCirckel(commando);


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
	commando.x = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.text_kleur = (uint8_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	strncpy(commando.tekst, aryvul[ARRAY_FOURTH_lOCATION] , sizeof(commando.x_1));
	//commando.tekst = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);

	API_In_DrawText(commando);


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
	 memcpy(&commando.x_1, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_1, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));

}


//--------------------------------------------------------------
// Seperate the buffer of a Clearscreen-command using comma as delimiter
// Fills the variables in the struct
//--------------------------------------------------------------

void Seperate_Clearscreen(void)
{
	int  i;
	char temp;
	int pos = INDEX_COLOR;


	while(pos)
	{
		temp = input.line_rx_buffer[0];
		for(i = 0; i < 1024 - 1; i++)
			input.line_rx_buffer[i] = input.line_rx_buffer[i + 1];

		input.line_rx_buffer[1024 - 1] = temp;
		pos--;
	}


	if(strncmp(input.line_rx_buffer, "rood", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_RED);
	else if(strncmp(input.line_rx_buffer, "zwart", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_BLACK);
	else if(strncmp(input.line_rx_buffer, "groen", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_GREEN);
	else if(strncmp(input.line_rx_buffer, "wit", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_WHITE);
	else UB_VGA_FillScreen(VGA_COL_BLUE);
}


