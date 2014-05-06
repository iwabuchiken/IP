/* 
 * File:   img_lib.h
 * Author: IwabuchiK
 *
 * Created on 2014/05/06, 16:02
 */

#ifndef IMG_LIB_H
#define	IMG_LIB_H

#ifndef LIB_H
#include "lib.h"
#endif

void show_usage(void);

int _opt_RGV(char **, int **);
int validate_RGBStringFormat(char *);
char * _opt_Src_File(char **, char *);

#endif	/* IMG_LIB_H */

