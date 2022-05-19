/**
  ******************************************************************************
  * @file           : LL_API_G2.c
  * @brief          : Logic_layer body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 Groep_2.
  *
  *
  * This file includes all the necessary functions of the API-Logic-Layer
  * The file contains 12 functions
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "LL_API_G2.h"
#include "IO_API_G2.h"
#include "main.h"
/* Private includes ----------------------------------------------------------*/


/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <errno.h>
/* USER CODE END Includes */





const char* errnum;


/**
  * @brief Functions plot a line with the given arguments.
  * @param UI_t apidata
  * @note  Gives an error if the arguments are zero
  * @retval None
  */
void API_In_DrawLine(UI_t apidata)
{
	//Checks if the arguments in the struct are equal to zero
	if(apidata.x_1 == 0 || apidata.y_1 == 0 || apidata.x_2 == 0|| apidata.y_2 == 0|| apidata.kleur== 0)
	{
	//Gives an error when the arguments in the struct are zero
			errno = ERANGE;
			show_errno(errnum);
	}
	//Else jumps in the function that will plot a line
	else plotLine(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.y_2,apidata.kleur);
}

/**
  * @brief Functions plot a rectangle with the given arguments.
  * @param UI_t apidata
  * @note  Gives an error if the arguments are zero
  * @retval None
  */
void API_In_DrawRectangle(UI_t apidata)
{
	//Jumps into function that will plot a rectangle
	plotRect(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.y_2,apidata.kleur);
}

/**
  * @brief Functions plot a circle with the given arguments.
  * @param UI_t apidata
  * @note  Gives an error if the arguments are zero
  * @retval None
  */

void API_In_DrawCirckel(UI_t apidata)
{
	//Jumps into function that will plot a circle
	plotCircle(apidata.x_1,apidata.y_1 , apidata.x_2, apidata.kleur);
}

/**
  * @brief Functions plot text with the given arguments.
  * @param UI_t apidata
  * @note  Gives an error if the arguments are zero
  * @retval None
  */
void API_In_DrawText(UI_t apidata)
{
	//Jumps into a function that will plot text
	API_text(apidata.x,apidata.y,apidata.text_kleur,apidata.tekst);
}

void API_In_Bitmap(UI_t apidata)
{

	 API_bitmap(apidata.x_1, apidata.y_1);
	 }

/**
  * @brief Functions that will switch between different kind of erorrs
  * @param const char *err_info
  * @note  Functions will print error in the terminal
  * @retval None
  */

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


/**
  * @brief Checks if the command is a line or a rectangle
  * @param void
  * @note  Returns 1 if line, 2 if rectangle
  * @retval None
  */

int API_ReLi_Sep(void)
{
	int cmp;
	char comp_line[LINE_TEXT];

	//Loops the input buffer and passes the characters into another array
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



/**
  * @brief Seperate the buffer of a line-command using comma as delimiter
  * @param void
  * @note  Fills the variables in the struct
  * @retval None
  */

void Seperate_line(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	// comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		//Passing the value to an array
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.dikte = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);


	 //Jumps into the function that will draw a line
	 API_In_DrawLine(commando);

}

/**
  * @brief Seperate the buffer of a rectangle-command using comma as delimiter
  * @param void
  * @note  Fills the variables in the struct
  * @retval None
  */


void Seperate_Rectangle(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	// comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		//Passing the value to an array
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}


	//Fills the struct
	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.gevuld = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);

	//Jumps into the function that will draw a rectangle
	API_In_DrawRectangle(commando);


}



/**
  * @brief Seperate the buffer of a circkel-command using comma as delimiter
  * @param void
  * @note  Fills the variables in the struct
  * @retval None
  */

void Seperate_Circkel(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	// comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		//Passing the value to an array
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}


	//Fills the struct
	commando.x_1 = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y_1 = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.x_2 = (uint16_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	commando.y_2 = (uint16_t)atoi(aryvul[ARRAY_FOURTH_lOCATION]);
	commando.kleur = (uint8_t)atoi(aryvul[ARRAY_FIFTH_lOCATION]);
	commando.gevuld = (uint8_t)atoi(aryvul[ARRAY_SIXTH_lOCATION]);

	//Jumps into the function that will draw a circle
	API_In_DrawCirckel(commando);


}



/**
  * @brief Seperate the buffer of a text-command using comma as delimiter
  * @param void
  * @note  Fills the variables in the struct
  * @retval None
  */


void Seperate_Text(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	//Comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		//Passing the value to an array
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	commando.x = (uint16_t)atoi(aryvul[ARRAY_FIRST_lOCATION]);
	commando.y = (uint16_t)atoi(aryvul[ARRAY_SECOND_lOCATION]);
	commando.text_kleur = (uint8_t)atoi(aryvul[ARRAY_THIRD_lOCATION]);
	strncpy(commando.tekst, aryvul[ARRAY_FOURTH_lOCATION] , sizeof(commando.x_1));

	//Jumps into the function that will draw text
	API_In_DrawText(commando);


}



/**
  * @brief Seperate the buffer of a Bitmap-command using comma as delimiter
  * @param void
  * @note  Fills the variables in the struct
  * @retval None
  */

void Seperate_Bitmap(void)
{
	int i = 0;
	char* aryvul[ARRAY_SIZE]={0};

	//Comma is delimiter
	char * token = strtok(input.line_rx_buffer, ",");

	//Fills an array with the seperated tokens
	while( token != NULL )
	{
		//Passing the value to an array
		aryvul[i]= token;
		i++;
		token = strtok(NULL, ",");
	}

	//Fills the struct
	// memcpy(&commando.nr, &aryvul[ARRAY_FIRST_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.x_1, &aryvul[ARRAY_SECOND_lOCATION] , sizeof(commando.x_1));
	 memcpy(&commando.y_1, &aryvul[ARRAY_THIRD_lOCATION] , sizeof(commando.x_1));

	 //Jumps into the function that will draw a bitmap
	 API_In_Bitmap(commando);

}



/**
  * @brief Seperate the buffer of a Clearscreen-command using comma as delimiter
  * @param void
  * @note  Shifting the index of the input-buffer-array, reset the screen color
  * @retval None
  */

void Seperate_Clearscreen(void)
{
	int  i;
	char temp;
	int pos = INDEX_COLOR;

	//Shifting the input index
	while(pos)
	{
		temp = input.line_rx_buffer[0];
		for(i = 0; i < 1024 - 1; i++)
			input.line_rx_buffer[i] = input.line_rx_buffer[i + 1];

		input.line_rx_buffer[1024 - 1] = temp;
		pos--;
	}

	//Reset the screen color
	if(strncmp(input.line_rx_buffer, "rood", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_RED);
	else if(strncmp(input.line_rx_buffer, "zwart", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_BLACK);
	else if(strncmp(input.line_rx_buffer, "groen", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_GREEN);
	else if(strncmp(input.line_rx_buffer, "wit", sizeof(input.line_rx_buffer)) == 0) UB_VGA_FillScreen(VGA_COL_WHITE);
	else UB_VGA_FillScreen(VGA_COL_BLUE);
}


