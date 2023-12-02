#ifndef _HEADER_PRINTF_H
#define _HEADER_PRINTF_H

/*including used libraries*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits>
#include <stdlib.h>
/*ending including libraries*/

/*initializing and defining needed arguments*/
#define OUT_BUFER_SIZE 1024
#define BUF_End -1
#define NULL_string "(nil)"
#define IN_PARAM {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define convert_LOWER 1
#define convert_UNSIGNED 2
/*ending initializing arguments (MACROS)*/

/*initializing function i need for task 0,1>>printf>.function mudules*/
int print_char(va_list co, PARAM_O *obj);
int print_string_s(va_list co, PARAM_O *obj);
int print_int_i_d(va_list co, PARAM_O *obj);
int print_percent(va_list co, PARAM_O *obj);
int print_S(va_list co, PARAM_O *obj);
/*ending*/

/*initializing struct will be used to git decision*/
/**
* struct members- the used struct
*@unsign: flag for unsigned
*@plus_f: flag for plus
*@space_f: flag for space_t
*@hashtag_f: flag for hashtag
*@zero_f: flag for zero
*@minus_f: flag for minus
*@width_X: the width of text
*@precise: the precision of text
*@h_mod: short integer
*@l_mod: long integer
*/

typedef struct members
{
	unsigned int unsign :1;
	unsigned int plus_f :1;
	unsigned int space_f :1;
	unsigned int hashtag_f :1;
	unsigned int zero_f :1;
	unsigned int minus_f :1;
	unsigned int width_X :1;
	unsigned int precise :1;
	unsigned int h_mod :1;
	unsigned int l_mod :1;
} PARAM_O;
/*end initalizing*/

/*intializing specifiers struct*/
/**
*struct space- struct ro deal with specifires %..
*@space_f: format token
*@f: a pointer to a function deal with specifiers
*/
typedef struct space
{
	char *space_f;
	int (*f)(va_list, PARAM_O *);
} space_t;
/*ending intializing*/

/*initializing Put && PUTCHAR*/
int _puts(char *str);
int _putchar (int c);
/*ending*/

#endif /* _HEADER_PRINTF_H*/

