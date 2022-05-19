/*
 * IO_API_G2.h
 *
 *  Created on: 18 May 2022
 *      Author: Sahag
 */

#ifndef INC_IO_API_G2_H_
#define INC_IO_API_G2_H_


void plotLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint8_t COLOR);
extern void plotLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint8_t COLOR);

void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR);
extern void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR);


void plotCircle(uint16_t xm, uint16_t ym, int r,uint8_t COLOR);
extern void plotCircle(uint16_t xm, uint16_t ym, int r,uint8_t COLOR);

void API_text(int x,int y, char kleur, char tekst[]);
extern void API_text(int x,int y, char kleur, char tekst[]);

#endif /* INC_IO_API_G2_H_ */
