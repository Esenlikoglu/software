/*
 * IO_API_G2.h
 *
 *  Created on: 12 May 2022'
 *
 * 	The variables of the IO-Front-Layer are defined in this header file
 * 	In This file, certain functions will be externed  to the use of the other C-files
 *
 */

#ifndef INC_IO_API_G2_H_
#define INC_IO_API_G2_H_

//Front-Layer function headers
void plotLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint8_t COLOR);
// Front-Layer externed function
extern void plotLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint8_t COLOR);

//Front-Layer function headers
void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR);
// Front-Layer externed function
extern void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR);

//Front-Layer function headers
void plotCircle(uint16_t xm, uint16_t ym, int r,uint8_t COLOR);
// Front-Layer externed function
extern void plotCircle(uint16_t xm, uint16_t ym, int r,uint8_t COLOR);

//Front-Layer function headers
void API_text(int x,int y, char kleur, char tekst[]);
// Front-Layer externed function
extern void API_text(int x,int y, char kleur, char tekst[]);

//Front-Layer function headers
void API_bitmap(uint16_t x_bitmap, uint16_t y_bitmap);
// Front-Layer externed function
extern void API_bitmap(uint16_t x_bitmap, uint16_t y_bitmap);

#endif /* INC_IO_API_G2_H_ */
