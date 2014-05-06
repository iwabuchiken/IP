/* 
 * File:   lib.h
 * Author: IwabuchiK
 *
 * Created on 2014/05/06, 13:26
 */

#ifndef LIB_H
#define	LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef WIN_H
#define WIN_H
#include <windows.h>
#endif

///////////////////////////////////////////////////////

// Global variables

///////////////////////////////////////////////////////
unsigned short int console_textColor;
unsigned short int console_backgroundColor;

///////////////////////////////////////////////////////

// Enum

///////////////////////////////////////////////////////
//enum concol
typedef enum
{
	black=0,
	dark_blue=1,
	dark_green=2,
	dark_aqua,dark_cyan=3,
	dark_red=4,
	dark_purple=5,dark_pink=5,dark_magenta=5,
	dark_yellow=6,
	dark_white=7,
	gray=8,
	blue=9,
	green=10,
	aqua=11,cyan=11,
	red=12,
	purple=13,pink=13,magenta=13,
	yellow=14,
	white=15
} concol;



#ifdef	__cplusplus
}
#endif

#endif	/* LIB_H */

