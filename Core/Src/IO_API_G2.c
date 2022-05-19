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

	// Create two integers dx,sx
	//dx will contain absolute subtraction of the x coordinates
	//sx will compare the coordinenates and will return a valid value
     int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;


 	// Create two integers dx,sx
 	//dy will contain absolute subtraction of the x coordinates
 	//sy will compare the coordinenates and will return a valid value
     int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;

     /* error value e_xy */
     int err = dx+dy, e2;

     for(;;){
    	 /* loop for setting pixels on in between x0 and x1 and y0 and y1 */
    	 UB_VGA_SetPixel(x0,y0,COLOR);
        if (x0==x1 && y0==y1) break;
       // variable for turning the error handlers on
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
	// recall function line to draw a rectangle
	// plotLine recalls four times with four different locations
	// complete a rectangle
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
	// create variable for the radius
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */
   do {
	   // Turn the pixels from a different start en end location.
	   // each location will start and end at a different locations
	   // from an r(radius) distance from his starting point
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
void API_bitmap(uint16_t x_bitmap, uint16_t y_bitmap)
{
// create two counters
	uint16_t x,y;

// create variable to go through bitmap array
	int i=0;
// loop array y
	for(y=0;y<119;y++)
	{
// loop array x
	  for(x=0;x<119;x++)
	  {
//	set pixels on counter i from array bitmap
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
// create counters
	int i,j,k,l;

// remember the last location of the previous letter
	int x_old=x;

// pointer to select which letter
	const char* letter;

// variable to select the right width of the chosen letter
	char width;

// get the input size from tekst to size
	int size = strlen(tekst);

// for loop to put 'size' long letters on screen
	for (i=0; i<size;i++)
	{
	// Get the right letter with the pointer letter
	// and the right width from the bitmap.h
	// it has -32 because the letters start from 32
		letter = Arial_32_addr[tekst[i]-32];
		width  = Arial_32_width[tekst[i]-32];
		// for loop to draw 4 times 1 byte ( 4*8 = Arial_32 )
		for (j=0; j < 4; j++)
		{
			// for loop to start drawing the pixels on the right width
			for (k=0; k<width; k++)
			{
				// for loop to go through the byte
				for(l=0; l<8;l ++)
				{
					// go through array one by one
					if((letter[j*width+k]>>l)&0x01)
					{
						// set pixels on the right position x_old and length.
						 UB_VGA_SetPixel (x+x_old + k, y+ j*8+l, kleur);

					}

				}
			}
		// x_old shifts for next letter
		}x_old += 5 +k;
	}
}

