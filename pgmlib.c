#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef PPMLIB_H
#include "include/ppmlib.h"
#endif

/*******************************
  int RetVals get_PGM_2(char *file_path, PGM *pgm)
 * @return -2	=> can't open the file, or the file doesn't exist
 *	    -1	=> The file format is not P5
 *	    1	=> a PGM obtained
 *******************************/
int get_PGM_2(char *file_path, PGM *pgm)
{
    /************************************
     * Get: file
    ************************************/
    FILE *fp;

    if ( (fp = fopen( file_path, "rb" ))==NULL ){
        printf("The file doesn't exist, or can't open: %s\n", file_path);

        return -2;

    }

    /************************************
     * Read: header
    ************************************/
    //log
    printf("[%s:%d] pgm file => Reading header...\n", base_name(__FILE__), __LINE__);

    
    int res_i;
    
    //REF pass pointer http://www.geekpage.jp/programming/c/func-pointer-arg.php
    res_i = get_PGM(fp, pgm);
//    enum RetVals res = get_PGM(fp, &pgm);

    if (res_i == 1) {	// pgm => obtained

//    	char *tmp_msg = "[%s:%d] pgm => obtained\n";

	printf("[%s:%d] pgm => obtained\n",
			base_name(__FILE__), __LINE__);

	fclose(fp);

	return 1;

    } else {

	    printf("[%s:%d] file format => not P5\n", __FILE__, __LINE__);

	    fclose(fp);

	    return -1;

    }

}//enum RetVals get_PGMHeader(FILE* fp)

/*******************************
 int RetVals get_PGM(FILE* fp, PGM *pgm)
 * @return -1 =>  The file format is not P5
 *	    1 => PGM obtained
 *******************************/
int get_PGM(FILE* fp, PGM *pgm)
{
    char buffer[MAX_BUFFERSIZE];  /* �f�[�^�ǂݍ��ݗp��ƕϐ� */
    int max_gray; /* �ő�K���l */
    int x, y; /* ���[�v�ϐ� */

    int i, j;

//    gray grays[];

//    PGM pgm;

	/************************************
	 * Read: header
	************************************/


    fgets( buffer, MAX_BUFFERSIZE, fp );
    if ( buffer[0] != 'P' || buffer[1] != '5' ){
//        printf("File format => not P5 (given=%c%c)\n", buffer[0], buffer[1]);
//        printf( "File format => not P5 (given=%s)\n", buffer );
//        printf("File format => not P5 (given=%c%c)\n", buffer[0], buffer[1]);
//        exit(1);
//    	return NULL;
    	return -1;

    }

    //log
    printf("[%s:%d] whie loop => starting...\n", base_name(__FILE__), __LINE__);

    
    // file name
    while ( 1 ){
		fgets( buffer, MAX_BUFFERSIZE, fp );
		if ( buffer[0] = '#' ) {

			pgm->file_name = (char *) malloc (sizeof(char) * (strlen(buffer) + 1));
//			file_name = (char *) malloc (sizeof(char) * (strlen(buffer) + 1));

			sscanf( buffer, "#%s", pgm->file_name );
//			sscanf( buffer, "#%s", file_name );

			break;

		}

	}//while ( 1 )

    x = 0; y = 0;

    while ( x == 0 || y == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d %d", &x, &y );
    }

    max_gray = 0;
    while ( max_gray == 0 ){
        fgets( buffer, MAX_BUFFERSIZE, fp );
        if ( buffer[0] != '#' )
            sscanf( buffer, "%d", &max_gray );
    }

    /* Display the parameters */
//    printf( "pixels(x) = %d, pixels(y) = %d\n", x, y );
//    printf( "max brightness = %d\n",max_gray );

    /************************************
	 * read: grays
	************************************/
    pgm->grays = (gray *) malloc (sizeof(gray) * ((x * y) + 1));
//    pgm->grays = (gray *) malloc (sizeof(gray) * (x + 1));

    int pos = 0;

    for (i = 0; i < y; ++i) {

    	for (j = 0; j < x; ++j) {

			pgm->grays[pos] = (unsigned char)fgetc( fp );

			pos ++;
	//    	pgm->grays[i] = (unsigned char)fgetc( fp );
	//    	grays[i] = (unsigned char)fgetc( fp );

		}



	}


    /************************************
	 * PGM
	************************************/
    pgm->x = x;
    pgm->y = y;
    pgm->max_gray = max_gray;

//    pgm->grays = grays;	// invalid use of flexible array member
//    *(pgm->grays) = grays;	// assignment makes integer from pointer without a cast
//    &(pgm->grays) = grays;	// invalid lvalue in assignment

//    pgm.x = x;
//    pgm.y = y;
//    pgm.max_gray = max_gray;

//    return pgm;
    return 1;

}//enum RetVals get_PGMHeader(FILE* fp)
