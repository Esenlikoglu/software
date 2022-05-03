#ifndef _IMGLIB_0
#define _IMGLIB_0

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <math.h>
#include <sys/queue.h>
#include "main.h"

typedef unsigned char color_component;
typedef color_component pixel[3];
typedef struct {
    unsigned int width;
    unsigned int height;
    pixel * buf;
} image_t;
typedef image_t * image;

image alloc_img(unsigned int width, unsigned int height);
void free_img(image);
void fill_img(image img,
        color_component r,
        color_component g,
        color_component b );
void put_pixel_unsafe(
       	image img,
        unsigned int x,
        unsigned int y,
        color_component r,
        color_component g,
        color_component b );
void put_pixel_clip(
       	image img,
        unsigned int x,
        unsigned int y,
        color_component r,
        color_component g,
        color_component b );
#define GET_PIXEL(IMG, X, Y) (IMG->buf[ ((Y) * IMG->width + (X)) ])
#endif
image alloc_img(unsigned int width, unsigned int height)
{
    image img;
    img = malloc(sizeof(image_t));
    img->buf = malloc(width * height * sizeof(pixel));
    img->width = width;
    img->height = height;
    return img;
}

void free_img(image img)
{
    free(img->buf);
    free(img);
}

void fill_img(
        image img,
        color_component r,
        color_component g,
        color_component b )
{
    unsigned int i, n;
    n = img->width * img->height;
    for (i=0; i < n; ++i)
    {
        img->buf[i][0] = r;
        img->buf[i][1] = g;
        img->buf[i][2] = b;
    }
}

void put_pixel_unsafe(
       	image img,
        unsigned int x,
        unsigned int y,
        color_component r,
        color_component g,
        color_component b )
{
    unsigned int ofs;
    ofs = (y * img->width) + x;
    img->buf[ofs][0] = r;
    img->buf[ofs][1] = g;
    img->buf[ofs][2] = b;
}

void put_pixel_clip(
       	image img,
        unsigned int x,
        unsigned int y,
        color_component r,
        color_component g,
        color_component b )
{
    if (x < img->width && y < img->height)
      put_pixel_unsafe(img, x, y, r, g, b);
}
