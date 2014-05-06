/* 
 * File:   main.c
 * Author: IwabuchiK
 *
 * Created on 2014/05/06, 13:25
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef LIB_H
#include "lib.h"
#endif

/*
 * 
 */
int main(int argc, char** argv) {

    console_textColor = 10;
    
//    enum concol b;
    concol a = green;
    
    printf("concol a => %d\n", a);
    
    printf("done\n");
    
    return (EXIT_SUCCESS);
}

