/* 
 * File:   main.c
 * Author: IwabuchiK
 *
 * Created on 2014/05/06, 13:25
 */
#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef LIMITS_H
#include <limits.h>
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#endif

#ifndef LIB_H
#include "include/lib.h"
#endif

#ifndef IMG_LIB_H
#include "include/img_lib.h"
#endif




/*
 * 
 */
/*******************************
 prototypes 
 *******************************/
void set_Root(void);

void _test_FileSep(void);
void _test_BaseName(void);
void _test_ConsoleColor(void);
void _test_IntTypePointer(void);
void _test_Realpath(void);
void _test_MkDir(void);

//////////////////////////////////////////

// Gloval variables

//////////////////////////////////////////
char *ROOT;

int main(int argc, char** argv) {

    ///////////////////////////////////////////////////////

    // Setup

    ///////////////////////////////////////////////////////
    consolColor_Init();
    
    set_Root();

//    _test_Realpath();
    _test_MkDir();
    
    //log
    printf("[%s:%d] argv[0] = %s\n", base_name(__FILE__), __LINE__, argv[0]);

    
    /*******************************
     argv => Exists?
     *******************************/
    if (argc < 2) {

//		int tmp = dark_red;

	consolColor_Change(dark_red, white);
//		consolColor_Change(0x00, 0x07);

	show_usage();

	consolColor_Reset();

//		consolColor_Change(console_backgroundColor, console_textColor);

	return -1;

    }

    /////////////////////////////////////

    // Variables

    /////////////////////////////////////
    int * rgb_vals[3];
//	int ** rgb_vals;

    char *fpath_src;	// source pgm file path
    char *fpath_dst;	// dst ppm file path

    int res_i;	// return value of functions

    int i;		// iterator

    // Flags
    int flag_RGV = 0;

    int flag_Force_CreateDstDir = 0;

    int flag_Force_Overwrite_DstFile = 0;

    // Temp vars
    RetVals res_enum;
    
    /////////////////////////////////////

    // Opt: rgb values

    /////////////////////////////////////
    res_i = _opt_RGB(argv, rgb_vals);

//	//log
//	printf("[%s:%d] res => %d\n", base_name(__FILE__), __LINE__, res_i);

	// Set: flag for RGV
    flag_RGV = res_i;

    if (res_i == 1) {

	    //log
	    printf("\n");

	    char rgb_message[20];

	    sprintf(rgb_message, "rgb => %d,%d,%d",
					    rgb_vals[0],
					    rgb_vals[1],
					    rgb_vals[2]
					    );

	    consolColor_Change(black, white);

	    //log
	    printf("[%s:%d] rgb set (%s)\n", base_name(__FILE__), __LINE__, rgb_message);

	    consolColor_Reset();

//		for (i = 0; i < 3; ++i) {
//
//			//log
//			printf("[%s:%d] rgb[%d] = %d\n",
//					base_name(__FILE__), __LINE__, i, rgb_vals[i]);
//
//		}

	    //log
	    printf("\n");

    } else {

	    //log
	    printf("[%s:%d] rgb_vals => not obtained\n", base_name(__FILE__), __LINE__);

	    for (i = 0; i < 3; ++i) {

		    *(rgb_vals[i]) = 100;
//			rgb_vals[i] = 100;

	    }

	    //log
	    printf("[%s:%d] rgb_vals => Set to default(=100)\n",
			    base_name(__FILE__), __LINE__);

    }//if (res_i == 1)

    /////////////////////////////////////

    // Opt: source file

    /////////////////////////////////////
    //log
    printf("[%s:%d] Calling => _opt_Src_File()\n", base_name(__FILE__), __LINE__);

    //log
//    printf("[%s:%d] __FILE__ => %s\n", base_name(__FILE__), __LINE__, __FILE__);
//
//    printf("[%s:%d] PATH_MAX = %d\n", base_name(__FILE__), __LINE__, PATH_MAX);
//
//    //log
//    printf("[%s:%d] dir_name => %s\n", base_name(__FILE__), __LINE__, dir_name(__FILE__));
////	printf("[%s:%d] dir_name => %s\n", base_name(__FILE__), __LINE__, dirname(__FILE__));

    fpath_src = _opt_Src_File(argv, ROOT);
//    fpath_src = _opt_Src_File(argv, dir_name(__FILE__));

    consolColor_Change(black, white);
    //log
    printf("\n[%s:%d] fpath_src => %s\n\n", base_name(__FILE__), __LINE__, fpath_src);

    consolColor_Reset();

    /*******************************
     Tests
    *******************************/
//	_test_IntTypePointer();
	
	
//    //log
//    printf("[%s:%d] textcolor=%d backcolor=%d\n",
//	    base_name(__FILE__), __LINE__, console_textColor, console_backgroundColor);
    
//    console_textColor = 10;
//    
////    enum concol b;
//    concol a = green;
//    
//    printf("concol a => %d\n", a);
    
//    _test_FileSep();
//    _test_BaseName();
//    _test_ConsoleColor();
    
    printf("done\n");
    
    return (EXIT_SUCCESS);
}

void _test_FileSep(void)
{
     char *file_sep = get_FileSep_Str();
     
     char sep = get_FileSep();
    
    //debug
    printf("file_sep = %s\n", file_sep);
    printf("sep = %c\n", sep);
   
}

void _test_BaseName(void)
{
//    //debug
//    printf("__FILE__ => %s\n", base_name(__FILE__));
    //log
    printf("[%s:%d] __FILE__ =====> %s\n", base_name(__FILE__), __LINE__, base_name(__FILE__));


}

void _test_ConsoleColor(void)
{

    char input[20];
    
    int col = textcolor();
    
    //log
    printf("[%s:%d] col => %d\n", base_name(__FILE__), __LINE__, col);

    //log
    printf("[%s:%d] Start => _test_ConsoleColor\n", base_name(__FILE__), __LINE__);

    
    //log
    printf("[%s:%d] textcolor=%d backcolor=%d\n",
	    base_name(__FILE__), __LINE__, console_textColor, console_backgroundColor);
    
    //log
    printf("[%s:%d] Input please => ", base_name(__FILE__), __LINE__);
    
    consolColor_Change(0, 0x0F);
    
    fgets(input, 10, stdin);
    
    fputs(input, stdout);

    consolColor_Reset();
    
    
//    //log
//    printf("[%s:%d] textcolor=%d backcolor=%d\n",
//	    base_name(__FILE__), __LINE__, console_textColor, console_backgroundColor);
}

void _test_IntTypePointer(void)
{
    int *num = (int *)6;
    
    //log
    printf("[%s:%d] num => %d\n", base_name(__FILE__), __LINE__, num);

}

void _test_Realpath(void)
{
//    char buff[255];
//    getcwd (buff, sizeof (buff));
//    printf ("path=%s\\%s\n", buff, argv[0]);
    
//    FILE *fp;
//    
//    fp = fopen(__FILE__, "r");
//    
//    //log
//    printf("[%s:%d] fp->_base ==> %s\n", base_name(__FILE__), __LINE__, fp->_base); // null
//    printf("[%s:%d] fp->_ptr ==> %s\n", base_name(__FILE__), __LINE__, fp->_ptr); // null
//
//    fclose(fp);
    
    
//    char *symlinkpath = "/tmp/symlink/file";
//    char actualpath [PATH_MAX+1];
//    char *ptr;
//
//
//    ptr = (char *)realpath(symlinkpath, actualpath);
//    
//    //log
//    printf("[%s:%d] actualpath = %s\n", base_name(__FILE__), __LINE__, actualpath);

}

void _test_MkDir(void)
{
    char *dirname = "images";
    
    int res = mkdir(dirname);
    
    //log
    printf("[%s:%d] res => %d\n", base_name(__FILE__), __LINE__, res);

    
}

void set_Root(void)
{
    char *tmp = dir_name(__FILE__);
    
    //log
    printf("[%s:%d] tmp => %s\n", base_name(__FILE__), __LINE__, tmp);
    
    if (tmp == NULL) {

	ROOT = (char *) malloc(sizeof(char) * 2);

	*ROOT = '.';
	*(ROOT + 1) = '\0';
	
	//log
	printf("[%s:%d] ROOT => %s\n", base_name(__FILE__), __LINE__, ROOT);

	
    } else {
    }


}
