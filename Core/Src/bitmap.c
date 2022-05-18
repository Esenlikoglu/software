#include "text.h"
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "bitmap.h"





void API_bitmap(void){
uint16_t x,y;
int i=0;


	for(y=0;y<32;y++)
	{
	  for(x=0;x<24;x++)
	  {
//		  UB_VGA_SetPixel (x,y,(uint8_t)Arial_32_96[i]);
//		  UB_VGA_SetPixel (x,y,0XFF);
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

