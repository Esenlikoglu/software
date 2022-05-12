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


	// HAl wants a memory location to store the charachter it receives from the UART
	// We will pass it an array, but we will not use it. We declare our own variable in the interupt handler
	// See stm32f4xx_it.c
	//HAL_UART_Receive_IT(&huart2, input.byte_buffer_rx, BYTE_BUFLEN);

	strcpy(commando.type, input.line_rx_buffer);


	if( strcmp(commando.type, "lijn") == 0 )
			 {
				 printf("voer in de data met een comma daartussen\n\n");
					printf(" x, y, x’, y’, kleur, dikte\n");
				// printf("het is lijn\n");
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

			 for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;

}




