/*
 * FL_API_G2.h
 *
 *  Created on: 12 May 2022
 *      Author: yassi
 */

#ifndef INC_FL_API_G2_H_
#define INC_FL_API_G2_H_






#define CLEARSCREEN_COMMAND 1
#define BITMAP_COMMAND 3
#define CIRCKEL_COMMAND 4
#define LINE_RECT_COMMAND 6
#define TEXT_COMMAND 7



void API_Getcommand(void);
extern void API_Getcommand(void);

void API_Command_Data(UI_t commando, int counter);



#endif /* INC_FL_API_G2_H_ */


