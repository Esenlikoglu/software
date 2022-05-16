/*
 * LL_API_G2.c
 *
 *  Created on: 12 May 2022
 *      Author: Sahag
 */

#include <stdio.h>
#include <errno.h>
#include "LL_API_G2.h"




void show_errno(const char *err_info)
{

    err_info = "unknown error";
    switch (errno) {
    case EDOM:
        err_info = "domain error";
        break;
    case EILSEQ:
        err_info = "illegal sequence";
        break;
    case ERANGE:
        err_info = "pole or range error";
        break;
    case 0:
        err_info = "no error";
    }
    printf("ERROR: %s \n" ,err_info);
}


////s: custom error message
////
////Output: custom error message followed by colon, space, and implementation-defined error message
//
//void perror(const char *s)
//{
//
//
//
//}



////errnum: error code
////
////Output: pointer to the implementation-defined error message string
//char* strerror(int errnum)
//{
//
//	errnum = 3;
//
//	return errno;
//}

