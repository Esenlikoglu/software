/**
  ******************************************************************************
  * @file           : IO_API_G2.c
  * @brief          : IO_layer body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 Groep_2.
  *
  *
  * This file includes all the necessary functions of the IO-Front-Layer
  * The file contains 5 functions
  *
  ******************************************************************************
  */

#include "main.h"
#include "IO_API_G2.h"
#include "bitmap.h"


/**
  * @Brief Plot the line according to the given arguments
  * @Param uint16_t x0  Begin x-coordinate
  * @Param uint16_t y0	Begin y-coordinate
  * @Param uint16_t x1	End x-coordinate
  * @Param uint16_t y1  End y-coordinate
  * @Param uint8_t COLOR line color
  * @Note The functions will generate a line using a mathematical equation
  * @Retval None
  */

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


/**
  * @Brief Plot the rectangle according to the given arguments
  * @Param uint16_t xp  	Begin x-coordinate
  * @Param uint16_t p0		Begin y-coordinate
  * @Param uint16_t width	width of th rectangle
  * @Param uint16_t length  length of the rectangle
  * @Param uint8_t COLOR    rectangle color
  * @Note The functions will generate a rectangle using a mathematical equation
  * @Retval None
  */
void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR)
{
	plotLine(xp,yp,xp,yp+length,COLOR);
	plotLine(xp,yp,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp,yp+length,COLOR);

}

/**
  * @Brief Plot the circle according to the given arguments
  * @Param uint16_t xm 		x-coordinate
  * @Param uint16_t ym	    y-coordinate
  * @Param int r	   		radius of th circle
  * @Param uint8_t color	length of the circle
  * @Note The functions will generate a circle using a mathematical equation
  * @Retval None
  */
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

/**
  * @Brief Plot a bitmap according to the given arguments
  * @Param uint16_t x_bitmap	x coordinate
  * @Param uint16_t 	y_bitmap    y coordinate
  * @Note The functions will generate a bitmap
  * @Retval None
  */
void API_bitmap(uint16_t x_bitmap, uint16_t y_bitmap){
uint16_t x,y;
int i=0;


	for(y=0;y<119;y++)
	{
	  for(x=0;x<119;x++)
	  {

		  UB_VGA_SetPixel (x+x_bitmap,y+y_bitmap,(uint8_t)HU_Utrecht_logo[i]);
		  i++;
	  }


}
}


/**
  * @Brief Plot text according to the given arguments
  * @Param int x 		x coordinate
  * @Param char kleur	color
  * @Param char tekst   text
  * @Note The functions will generate the input text
  * @Retval None
  */
void API_text(int x,int y, char kleur, char tekst[])
{
int i,j,k,l;
int x_old=x;
const char* letter;
char width;
int size = strlen(tekst);
for (i=0; i<size;i++)
	{
		letter = Arial_32_addr[tekst[i]-32];
		width  = Arial_32_width[tekst[i]-32];

		for (j=0; j < 4; j++)
		{
			for (k=0; k<width; k++)
			{
				for(l=0; l<8;l ++)
				{
					if((letter[j*width+k]>>l)&0x01)
					{
						 UB_VGA_SetPixel (x+x_old + k, y+ j*8+l, kleur);

					}

				}
			}
		}x_old += 5 +k;
	}
}

