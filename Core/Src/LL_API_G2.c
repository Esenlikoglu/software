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
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <errno.h>
/* USER CODE END Includes */



////s: custom error message
////
////Output: custom error message followed by colon, space, and implementation-defined error message

char errnum;

void API_In_DrawLine(UI_t commando)
{
	if(commando.x_1 == 0 ){
		errno = ERANGE;
		show_errno(errnum);
	}

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



