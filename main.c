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

#ifndef PPMLIB_H
#include "include/ppmlib.h"
#endif




/*
 * 
 */
/*******************************
 prototypes 
 *******************************/
void set_Root(void);
void on_Destroy(void);

void _main_RGB(char **);
void _main_SrcFile(char **);
void _main_DstDir(char **);

void _test_FileSep(void);
void _test_BaseName(void);
void _test_ConsoleColor(void);
void _test_IntTypePointer(void);
void _test_Realpath(void);
void _test_MkDir(void);

void _main_DstFile(char **);
void _main_GetPGM(void);

void _main_Conv_PGM2PPM(void);

//////////////////////////////////////////

// Gloval variables

//////////////////////////////////////////
char *ROOT;

char *IMAGE_ROOT_SRC;
char *IMAGE_FILE_SRC;

char *IMAGE_ROOT_DST;
char *IMAGE_FILE_DST;

int * RGB[3];

PGM *PGM_src;
PPM *PPM_dst;

//pixval pval;

int main(int argc, char** argv) {

    ///////////////////////////////////////////////////////

    // Setup

    ///////////////////////////////////////////////////////
    consolColor_Init();
    
    set_Root();

    /*******************************
     Function variables
     *******************************/
    int len;	// used in malloc()
    
    
//    _test_Realpath();
//    _test_MkDir();
    
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
//    int * rgb_vals[3];
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
    _main_RGB(argv);
    
    /////////////////////////////////////

    // Opt: source file

    /////////////////////////////////////
    _main_SrcFile(argv);

    /*******************************
         Get: IMAGE_ROOT_DST
     *******************************/
    _main_DstDir(argv);
    
    /*******************************
     Validate: IMAGE_FILE_DST
     *******************************/
    _main_DstFile(argv);
	    
    /*******************************
     Get: PGM instance
     *******************************/
    _main_GetPGM();
//    PGM_src = (PGM *) malloc(sizeof(PGM) * 1);
//    
//    res_i = get_PGM_2(IMAGE_FILE_SRC, PGM_src);
//    
//    //log
//    printf("[%s:%d] get_PGM_2 => %d\n", base_name(__FILE__), __LINE__, res_i);

    /*******************************
     * Convert: PGM to PPM
     *******************************/
    _main_Conv_PGM2PPM();
//    PPM_dst = (PPM *) malloc(sizeof(PPM) * 1);
//    
//    conv_PGM2PPM(PGM_src, PPM_dst);
//    
//    //log
//    printf("[%s:%d] PPM_dst->max_brightness => %d\n",
//	    base_name(__FILE__), __LINE__, PPM_dst->max_brightness);

    
    
	    
    /*******************************
     Tests
    *******************************/
//	_test_IntTypePointer();
	
    printf("done\n");
    
    on_Destroy();
    
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

void _main_RGB(char **argv)
{
    int res_i;
    int flag_RGV;
    
    int i;  // counter
    
     res_i = _opt_RGB(argv, RGB);
//    res_i = _opt_RGB(argv, rgb_vals);

//	//log
//	printf("[%s:%d] res => %d\n", base_name(__FILE__), __LINE__, res_i);

	// Set: flag for RGV
    flag_RGV = res_i;

    if (res_i == 1) {

	    //log
	    printf("\n");

	    char rgb_message[20];

	    sprintf(rgb_message, "rgb => %d,%d,%d",
					    RGB[0],
					    RGB[1],
					    RGB[2]
					    );

	    consolColor_Change(black, white);

	    //log
	    printf("[%s:%d] rgb set (%s)\n", base_name(__FILE__), __LINE__, rgb_message);

	    consolColor_Reset();

	    //log
	    printf("\n");

    } else {

	    //log
	    printf("[%s:%d] rgb_vals => not obtained\n", base_name(__FILE__), __LINE__);

	    for (i = 0; i < 3; ++i) {

		    *(RGB[i]) = 100;
//			rgb_vals[i] = 100;

	    }

	    //log
	    printf("[%s:%d] rgb_vals => Set to default(=100)\n",
			    base_name(__FILE__), __LINE__);

    }//if (res_   
}

void _main_SrcFile(char **argv)
{
    int len;
    int res_i;
    
    char *fpath_src_m = _opt_Src_File(argv, ROOT);
//    fpath_src = _opt_Src_File(argv, ROOT);
//    fpath_src = _opt_Src_File(argv, dir_name(__FILE__));

    consolColor_Change(black, white);
    //log
    printf("\n[%s:%d] fpath_src => %s\n\n", base_name(__FILE__), __LINE__, fpath_src_m);

    // Copy to IMAGE_FILE_SRC
    char *sep = get_FileSep_Str();
    
    len = strlen(fpath_src_m);
    
    IMAGE_FILE_SRC = (char *) malloc(sizeof(char) * (len + 1));
    
    strcpy(IMAGE_FILE_SRC, fpath_src_m);
    
    *(IMAGE_FILE_SRC + len) = '\0';
    
    //log
    printf("[%s:%d] IMAGE_FILE_SRC => %s\n", base_name(__FILE__), __LINE__, IMAGE_FILE_SRC);

    consolColor_Reset();

    free(sep);
    
    /*******************************
     Validate: source file, path
     *******************************/
    /*******************************
	Set: IMAGE_ROOT_SRC
     *******************************/
    char *tmp = dir_name(fpath_src_m);
    
    if (tmp != NULL) {
	
//	//log
//	printf("[%s:%d] tmp => != NULL (=%s)\n", base_name(__FILE__), __LINE__, tmp);

	
	int len = strlen(tmp);
	
	IMAGE_ROOT_SRC = (char *) malloc(sizeof(char) * (len + 1));
	
	strcpy(IMAGE_ROOT_SRC, tmp);
	
	*(IMAGE_ROOT_SRC + len) = '\0';
	
	consolColor_Change(black, white);
	
	//log
	printf("[%s:%d] IMAGE_ROOT_SRC set => %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_SRC);
	
	consolColor_Reset();
	
    } else {
	
	//log
	printf("[%s:%d] tmp =>  NULL\n", base_name(__FILE__), __LINE__);
	
	int len = strlen(ROOT);
	
	IMAGE_ROOT_SRC = (char *) malloc(sizeof(char) * (len + 1));
	
	strcpy(IMAGE_ROOT_SRC, tmp);
	
	*(IMAGE_ROOT_SRC + len) = '\0';
	
	//log
	printf("[%s:%d] IMAGE_ROOT_SRC set => %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_SRC);

    }
    
    consolColor_Reset();

    /*******************************
	Validate: IMAGE_ROOT_SRC => exists?
     *******************************/
    res_i = dirExists(IMAGE_ROOT_SRC);
    
    //log
    printf("[%s:%d] dirExists => %d\n", base_name(__FILE__), __LINE__, res_i);
    
    // If IMAGE_ROOT_SRC doesn't exist
    //	=> show message, and exit the program
    if (res_i != 1) {
	
	consolColor_Change(black, red);
	
	//log
	printf("[%s:%d] IMAGE_ROOT_SRC => doesn't exist: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_SRC);
	
	//log
	printf("[%s:%d] Sorry. Program quits. Thank you\n", base_name(__FILE__), __LINE__);
	
	consolColor_Reset();
	
	exit(-1);

    }

    /*******************************
	Validate: source pgm file => exists?
     *******************************/
    res_i = fileExists(fpath_src_m);
    
    //log
    printf("[%s:%d] fileExists => %d\n", base_name(__FILE__), __LINE__, res_i);

    // If source pgm file doesn't exist
    //	=> show message, and exit the program
    if (res_i != 1) {
	
	consolColor_Change(black, red);
	
	//log
	printf("[%s:%d] source pgm file => doesn't exist: %s\n",
		base_name(__FILE__), __LINE__, fpath_src_m);
	
	//log
	printf("[%s:%d] Sorry. Program quits. Thank you\n", base_name(__FILE__), __LINE__);
	
	consolColor_Reset();
	
	exit(-1);

    }//if (res_i != 1)
        
}//void _main_SrcFile(char **, char *)

void _main_DstDir(char **argv)
{
    int res_i;
    
    IMAGE_FILE_DST = _opt_Dst_File(argv, ROOT, IMAGE_FILE_SRC);
    
    if (IMAGE_FILE_DST == NULL) {

	consolColor_Change(black, red);

	//log
	printf("[%s:%d] IMAGE_FILE_DST => NULL\n", base_name(__FILE__), __LINE__);
	printf("[%s:%d] Sorry. Program quits.\n", base_name(__FILE__), __LINE__);

	consolColor_Reset();
	
	exit(-1);
	
    }

    
//    consolColor_Change(black, white);
    
    //log
    printf("[%s:%d] IMAGE_FILE_DST => %s\n", base_name(__FILE__), __LINE__, IMAGE_FILE_DST);

//    consolColor_Reset();
    
    /*******************************
	Validate: IMAGE_ROOT_DST => exists?
     *******************************/
    IMAGE_ROOT_DST = dir_name(IMAGE_FILE_DST);
//    char *dname_dst_m = dir_name(IMAGE_FILE_DST);
    
    if (IMAGE_ROOT_DST == NULL) {

	consolColor_Change(black, red);

	//log
	printf("[%s:%d] IMAGE_ROOT_DST => NULL\n", base_name(__FILE__), __LINE__);
	printf("[%s:%d] Sorry. Program quits.\n", base_name(__FILE__), __LINE__);

	consolColor_Reset();
	
	exit(-1);
	
    }
    
//    //log
//    printf("[%s:%d] IMAGE_ROOT_DST => %s\n", base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);

    // validate
    res_i = dirExists(IMAGE_ROOT_DST);
    
    if (res_i != 1) {	// IMAGE_ROOT_DST => doesn't exist

	consolColor_Change(black, red);

	//log
	printf("[%s:%d] IMAGE_ROOT_DST => doesn't exist: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);
	
	consolColor_Reset();
	
	res_i = _opt_ForceCreate_RootDst(argv);
	
	if (res_i == 1) {   // "-f" option => set

	    //log
	    printf("[%s:%d] '-f' option is set. Creating the dst dir...\n",
		    base_name(__FILE__), __LINE__);
	    
	    res_i = mkdir(IMAGE_ROOT_DST);
	    
	    //log
	    printf("[%s:%d] mkdir() => %d\n", base_name(__FILE__), __LINE__, res_i);
	    
	    if (res_i == 0) {

		//log
		printf("[%s:%d] Dst dir => created: %s\n",
			base_name(__FILE__), __LINE__,IMAGE_ROOT_DST);
		
		consolColor_Change(black, white);

		//log
		printf("[%s:%d] IMAGE_ROOT_DST => set: %s\n",
			base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);

		consolColor_Reset();


	    } else if (res_i == EEXIST) {
		
		//log
		printf("[%s:%d] Dst dir already exists: %s\n",
			base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);
		
	    } else {
		
		consolColor_Change(black, red);
		
		//log
		printf("[%s:%d] Can't create dst dir: %s\n",
			base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);
		
		printf("[%s:%d] Sorry. Program quits.\n",
			
			base_name(__FILE__), __LINE__);
		
		consolColor_Reset();
	    
		exit(-1);

	    }
	    
	} else {    //if (res_i == 1)   // "-f" option => not set
	    
	    consolColor_Change(black, red);
	    
	    printf("[%s:%d] '-f' option is not set. Dst dir won't be created.\n",
		base_name(__FILE__), __LINE__);
	    
	    printf("[%s:%d] Sorry. Program quits.\n",
		base_name(__FILE__), __LINE__);
	    
	    consolColor_Reset();
	    
	    exit(-1);
	    
	}//if (res_i == 1)   // "-f" option
	
    } else {// if (res_i != 1)	// IMAGE_ROOT_DST => exists
	
	//log
	printf("[%s:%d] IMAGE_ROOT_DST => exists: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);
	
	consolColor_Change(black, white);

	//log
	printf("[%s:%d] IMAGE_ROOT_DST: set => %s\n",
		base_name(__FILE__), __LINE__, IMAGE_ROOT_DST);

	consolColor_Reset();

    }// if (res_i != 1)


//    free(dname_dst_m);
    
    /*******************************
	Validate: dst pgm file => exists?
     *******************************/
        
}//_main_DstDir(char **argv)

void _main_DstFile(char **argv)
{
    int res_i;
    
    /*******************************
     Validate: IMAGE_FILE_DST is NULL?
     *******************************/
    if (IMAGE_FILE_DST == NULL) {

	consolColor_Change(black, red);

	//log
	printf("[%s:%d] IMAGE_FILE_DST => NULL\n", base_name(__FILE__), __LINE__);
	printf("[%s:%d] Sorry. The program quits\n", base_name(__FILE__), __LINE__);

	consolColor_Reset();
	
	exit(-1);
	
    }
    
    /*******************************
     File => exists?
     *******************************/
    res_i = fileExists(IMAGE_FILE_DST);
    
    if (res_i == 1) {	// the file exists
	
	res_i = _opt_OverWrite_DstFile(argv);
	
	if (res_i == 1) {   // "-ff" option given

	    //log
	    printf("[%s:%d] Dst file exists. '-ff' option given. "
		    "The file will be overwritten\n",
		    base_name(__FILE__), __LINE__);

	} else {//  if (res_i == 1) {   // "-ff" option not given
	    
	    consolColor_Change(black, red);

	    //log
	    printf("[%s:%d] Dst file exists. '-ff' option not given."
		    " Can't use the dst file. The program quits.\n",
		    base_name(__FILE__), __LINE__);

	    consolColor_Reset();
	    
	    exit(-1);
	    
	}//if (res_i == 1) {   // "-ff" option

	
    } else {//if (res_i == 1) {	// the file exists
	
	//log
	printf("[%s:%d] Dst file => doesn't exist. Wil be created: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_FILE_DST);
	
    }//if (res_i == 1) {	// the file exists

    consolColor_Change(black, white);

    //log
    printf("[%s:%d] IMAGE_FILE_DST => set: %s\n",
	    base_name(__FILE__), __LINE__, IMAGE_FILE_DST);

    consolColor_Reset();
    
}//void _main_DstFile(char **argv)

void _main_GetPGM()
{
    int res_i;
    
    PGM_src = (PGM *) malloc(sizeof(PGM) * 1);
    
    res_i = get_PGM_2(IMAGE_FILE_SRC, PGM_src);
    
    //log
    printf("[%s:%d] get_PGM_2 => %d\n", base_name(__FILE__), __LINE__, res_i);
    
    // result
    if (res_i == -2) {
	
	consolColor_Change(black, red);

	//log
	printf("[%s:%d] The file doesn't exist, or can't open: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_FILE_SRC);
	
	//log
	printf("[%s:%d] Sorry. The program quits\n", base_name(__FILE__), __LINE__);

	consolColor_Reset();
	
	exit(-1);
    
    } else if (res_i == -1) {
	
	consolColor_Change(black, red);

	//log
	printf("[%s:%d] The file format is not P5: %s\n",
		base_name(__FILE__), __LINE__, IMAGE_FILE_SRC);
	
	//log
	printf("[%s:%d] Sorry. The program quits\n", base_name(__FILE__), __LINE__);

	consolColor_Reset();
	
	exit(-1);
    
    } else {
	
	consolColor_Change(black, white);

	//log
	printf("[%s:%d] PGM => obtained: filename=%s\n",
		base_name(__FILE__), __LINE__, PGM_src->file_name);

	consolColor_Reset();
	
    }

    
}

void on_Destroy(void)
{
    free(ROOT);

    free(IMAGE_ROOT_SRC);
    free(IMAGE_FILE_SRC);

    free(IMAGE_ROOT_DST);
    free(IMAGE_FILE_DST);

    free(RGB);
//int * RGB[3];

    if (!PGM_src) {

	free(PGM_src);
	
    }
    
    //log
    if (!PPM_dst) {
//    if (PPM_dst == NULL) {

	free(PPM_dst);
//	//log
//	printf("[%s:%d] PPM_dst => NULL\n", base_name(__FILE__), __LINE__);

    }

//    printf("[%s:%d] PPM_dst => %s\n", base_name(__FILE__), __LINE__, PPM_dst);

//    free(PPM_dst);
    
}

void _main_Conv_PGM2PPM(void)
{
    PPM_dst = (PPM *) malloc(sizeof(PPM) * 1);
    
    conv_PGM2PPM(PGM_src, PPM_dst);
    
    consolColor_Change(black, white);
	
    printf("[%s:%d] PPM_dst->max_brightness => %d\n",
	    base_name(__FILE__), __LINE__, PPM_dst->max_brightness);
    
    consolColor_Reset();    //log
    
}
