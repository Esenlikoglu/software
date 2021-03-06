/*
 * LL_API_G2.h
 *
 *  Created on: 12 May 2022'
 *
 * 	The variables of the API-Logic-Layer are defined in this header file
 * 	In This file, certain functions will be externed  to the use of the other C-files
 *
 */


#include "main.h"


//Variables for the choosing process

#define TXT 0
#define LINE 1
#define RECTANGLE 2
#define BITMAP 3
#define CLEARSCREEN 4

//Variables for filling the array

#define ARRAY_FIRST_lOCATION 1
#define ARRAY_SECOND_lOCATION 2
#define ARRAY_THIRD_lOCATION 3
#define ARRAY_FOURTH_lOCATION 4
#define ARRAY_FIFTH_lOCATION 5
#define ARRAY_SIXTH_lOCATION 6
#define ARRAY_SEVENTH_lOCATION 7

#define LINE_TEXT 4

//Variables for array sizes
#define SIZE_TYPE 1024
#define ARRAY_SIZE 10

#define INDEX_COLOR 12


//Logic-Layer function headers
void show_errno(const char *err_info);


void API_In_DrawLine(UI_t apidata);
//Logic-Layer externed function
extern void API_In_DrawLine(UI_t apidata);

void API_In_DrawRectangle(UI_t apidata);
//Logic-Layer externed function
extern void API_In_DrawRectangle(UI_t apidata);

void API_In_DrawText(UI_t apidata);
//Logic-Layer externed function
extern void API_In_DrawText(UI_t apidata);

void API_In_DrawCirckel(UI_t apidata);
//Logic-Layer externed function
extern void API_In_DrawCirckel(UI_t apidata);

void API_In_Bitmap(UI_t apidata);
//Logic-Layer externed function
extern void API_In_DrawCirckel(UI_t apidata);

//Logic-Layer function headers
void Seperate_line(void);
void Seperate_Rectangle(void);
void Seperate_Circkel(void);
void Seperate_Text(void);
void Seperate_Bitmap(void);
void Seperate_Clearscreen(void);
int API_ReLi_Sep(void);

//s: custom error message
//
//Output: custom error message followed by colon, space, and implementation-defined error message

void perror(const char *s);



//errnum: error code
//
//Output: pointer to the implementation-defined error message string
char* strerror(int errnum);
