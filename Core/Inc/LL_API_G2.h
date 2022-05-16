/*
 * LL_API_G2.h
 *
 *  Created on: 12 May 2022
 *      Author: Sahag
 */




//enum api_error
//{
//	E_SUCCESS			 =  0,
//	E_INVALID_INPUT		 = -1,
//	E_SENSOR_NOT_FOUND	 = -2,
//	E_READ_TIME_OUT		 = -3,
//
//};




//s: custom error message
//
//Output: custom error message followed by colon, space, and implementation-defined error message

void perror(const char *s);



//errnum: error code
//
//Output: pointer to the implementation-defined error message string
char* strerror(int errnum);