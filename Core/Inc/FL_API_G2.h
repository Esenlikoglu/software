/*
 * FL_API_G2.h
 *
 *  Created on: 12 May 2022
 *      Author: yassi
 */





#ifndef INC_FL_API_G2_H_
#define INC_FL_API_G2_H_



#define TXT 0
#define LINE 1
#define RECTANGLE 2
#define BITMAP 3
#define CLEARSCREEN 4

#define LINE_RECT_COMMAND 6
#define CLEARSCREEN_COMMAND 1
#define BITMAP_COMMAND 3
#define TEXT_COMMAND 7

#define ARRAY_FIRST_lOCATION 1
#define ARRAY_SECOND_lOCATION 2
#define ARRAY_THIRD_lOCATION 3
#define ARRAY_FOURTH_lOCATION 4
#define ARRAY_FIFTH_lOCATION 5
#define ARRAY_SIXTH_lOCATION 6
#define ARRAY_SEVENTH_lOCATION 7



#define LINE_TEXT 4
#define SIZE_TYPE 1024
#define ARRAY_SIZE 10



void API_Getcommand(void);
//extern void API_Getcommand(void);


void API_Command_Data(UI_t commando, int counter);
//extern void API_Command_Data(UI_t commando, int counter);


void Seperate_line(void);
//extern void Seperate_line(void);

void Seperate_Rectangle(void);
//extern void Seperate_Rectangle(void);

void Seperate_Text(void);
//extern void Seperate_Text(void);

void Seperate_Bitmap(void);
//extern void Seperate_Bitmap(void);

void Seperate_Clearscreen(void);
//extern void Seperate_Clearscreen(void);

int API_ReLi_Sep(void);
//extern int API_ReLi_Sep(void);

#endif /* INC_FL_API_G2_H_ */


