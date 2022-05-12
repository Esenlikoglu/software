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

int commacounter;

#define SIZE_TYPE 1024


int beginx;


void Commacounter(UI_t commando)
{
	int i;
  for(i=0; i<SIZE_TYPE; i++)
  {
	 // commando.type[i] = input.line_rx_buffer[i];
	  if (input.line_rx_buffer[i] == ',')
	  {
		  commacounter ++;
		  break;
	  }

  }
}

//void linedecoder(UI_t commando)
//{
//	switch(commacounter)
//	{
//	   case 1:
//		   strcpy(commando.x_1, input.line_rx_buffer);
//		   printf("1\n");
//		   break;
//	   case 2:
//		   strcpy(commando.y_1, input.line_rx_buffer);
//		   printf("2\n");
//		   break;
//	   case 3:
//		   strcpy(commando.x_2, input.line_rx_buffer);
//		   printf("3\n");
//		   break;
//	   case 4:
//		   strcpy(commando.y_2, input.line_rx_buffer);
//		   printf("4\n");
//		   break;
//	   case 5:
//		   strcpy(commando.kleur, input.line_rx_buffer);
//		   printf("5\n");
//		   break;
//	   case 6:
//		   strcpy(commando.kleur, input.line_rx_buffer);
//		   printf("6\n");
//		   break;
//	   case 7:
//		   strcpy(commando.dikte, input.line_rx_buffer);
//		   printf("7\n");
//		   break;
//	   default:
//		   printf("Ik zit in de default");
//	 }
//}

void API_Getcommand(UI_t commando)
{
	int i;

	// Reset some stuff
	input.byte_buffer_rx[0] = 0;
	input.char_counter = 0;
	input.command_execute_flag = FALSE;

	Commacounter(commando);
	//copy the buffer into the struct
	strcpy(commando.type, input.line_rx_buffer);

    //Comparing the string in the struct with certain strings
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
				 printf("Ongeldig commando \t\n");
			 }


			 //clear the buffer
			 for(i = 0; i < LINE_BUFLEN; i++) input.line_rx_buffer[i] = 0;

}









//	int i=0;
//
//	if(input.line_rx_buffer[i] == ',')
//	{
//		commacounter++;
//		printf("ik tel de commacounter nu op\n");
//	}
//	   i++;
//
////	switch(input.line_rx_buffer[i])
////	{
////		case ',':
////			commacounter++;
//// 			i++;
//// 			linedecoder(commando);
//// 			printf("ik tel de commacounter nu op\n");
//// 			break;
////		default:
////			printf("ik tel de i nu op\n");
////			i++;
////			break;
////	}
