/*
 * FL_API_G2.c
 *
 *  Created on: 12 May 2022
 *      Author: yassi
 */


//#include <stdio.h>
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"





void API_Getcommand(UI_t commando)
{
	int i;

	//for(i = 0; i < LINE_BUFLEN; i++)
		 // input.line_rx_buffer[i] = 0;

	// Reset some stuff
	input.byte_buffer_rx[0] = 0;
	input.char_counter = 0;
	input.command_execute_flag = FALSE;


	//copy the buffer into the struct
	strcpy(commando.type, input.line_rx_buffer);

    //Comparing the struct with certain strings
	if( strcmp(commando.type, "lijn") == 0 )
			 {
				 printf("voer in de data met een comma daartussen\n\n");
				 printf(" x, y, x’, y’, kleur, dikte\n");
			 }

			 else if( strcmp(commando.type, "rechthoek") == 0 )
			 {
				 printf("het is rechthoek\n");
			 }

			 else if( strcmp(commando.type, "tekst") == 0 )
			 {
				  printf("het is tekst\n");
			 }

			 else if( strcmp(commando.type, "bitmap") == 0 )
			 {
				  printf("het is bitmap\n");
			 }

			 else if( strcmp(commando.type, "clearscreen") == 0 )
			 {
				  printf("het is clearscreen\n");
			 }

			 else
			 {
				 printf("Ongeldig commando\n");
			 }

			 //clear the buffer
			 for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;

}




