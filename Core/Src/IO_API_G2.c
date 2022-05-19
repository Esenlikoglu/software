/*
 * draw.c
 *
 *  Created on: 3 mei 2022
 *      Author: eesen
 */

#include "main.h"
#include "IO_API_G2.h"
#include "bitmap.h"

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


void plotRect(uint16_t xp,uint16_t yp,uint16_t width,uint16_t length, uint8_t COLOR)
{
	plotLine(xp,yp,xp,yp+length,COLOR);
	plotLine(xp,yp,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp+width,yp,COLOR);
	plotLine(xp+width,yp+length,xp,yp+length,COLOR);

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


void API_bitmap(uint16_t number, uint16_t x_bitmap, uint16_t y_bitmap){
uint16_t x,y;
int i=0;


	for(y=0;y<32;y++)
	{
	  for(x=0;x<24;x++)
	  {
//		  UB_VGA_SetPixel (x_bitmap,y_bitmap,(uint8_t)Arial_32_96[i]);
//		  UB_VGA_SetPixel (x_bimap,y_bitmap,0XFF);
		  i++;
	  }


}
}

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

