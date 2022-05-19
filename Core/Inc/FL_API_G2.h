/*
 * FL_API_G2.h
 *
 *  Created on: 12 May 2022'
 *
 * 	The variables of the API-Front-Layer are defined in this header file
 * 	In This file, certain functions will be externed  to the use of the other C-files
 *
 */

#ifndef INC_FL_API_G2_H_
#define INC_FL_API_G2_H_


//Variables for the choosing process
#define CLEARSCREEN_COMMAND 1
#define BITMAP_COMMAND 		2
#define CIRCKEL_COMMAND		4
#define LINE_RECT_COMMAND 	6
#define TEXT_COMMAND 		7


//Front-Layer function headers
void API_Getcommand(void);
// Front-Layer externed function
extern void API_Getcommand(void);

//Front-Layer function headers
void API_Command_Data(UI_t commando, int counter);



#endif /* INC_FL_API_G2_H_ */


