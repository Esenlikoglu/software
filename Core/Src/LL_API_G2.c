/*
 * LL_API_G2.c
 *
 *  Created on: 12 May 2022
 *      Author: Sahag
 */


#include <errno.h>
#include "LL_API_G2.h"

void errorno_test (void)
{
	printf("errno value: %d\n",errno);

}

void show_errno(void)
{
    const char *err_info = "unknown error";
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
  //  fputs(err_info, stdout);
   // puts(" occurred");
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
//
//
////errnum: error code
////
////Output: pointer to the implementation-defined error message string
//char* strerror(int errnum)
//{
//	return errno;
//}
