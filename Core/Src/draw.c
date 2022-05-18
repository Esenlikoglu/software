/*
 * draw.c
 *
 *  Created on: 3 mei 2022
 *      Author: eesen
 */

#include "main.h"

void plotLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1,uint8_t COLOR)
{
     int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
     int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
     int err = dx+dy, e2; /* error value e_xy */

     for(;;){  /* loop */
    	 UB_VGA_SetPixel(x0,y0,COLOR);
        if (x0==x1 && y0==y1) break;
        e2 = 2*err;
        if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
    }
}


void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR, uint16_t fill)
{
	int y1;
	if(fill==FALSE)
	{
	plotLine(xp,yp,xp,yp+length,COLOR);
	plotLine(xp,yp,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp,yp+length,COLOR);
	} else
	{
	y1 =yp;
		for(y1=yp; y1<(yp+length); y1++)
		{
			plotLine(xp,yp+(y1-yp),xp+width,yp+(y1-yp),COLOR);
		}
	}
}

void plotCircle(uint16_t xm, uint16_t ym, int r,uint8_t COLOR)
{
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */
   do {
	   UB_VGA_SetPixel(xm-x, ym+y,COLOR); /*   I. Quadrant */
	   UB_VGA_SetPixel(xm-y, ym-x,COLOR); /*  II. Quadrant */
	   UB_VGA_SetPixel(xm+x, ym-y,COLOR); /* III. Quadrant */
	   UB_VGA_SetPixel(xm+y, ym+x,COLOR); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}
