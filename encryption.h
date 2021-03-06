/* /////////////////////////////////////////////////////////////////////////////
///////////////////////Assignment 3 Group# 3: encryption header/////////////////
///////////////////////////////By Tasman France/////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

/*------------------------------------------------------------------------------
/Required Header Files//////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

#include <stdio.h>  /*printf, fopen, fclose, fgetc, fputs*/
#include <string.h>
#include <stdlib.h> /*malloc*/
#include <math.h>

/*------------------------------------------------------------------------------
/Defined Constants//////////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

#define MAX_FILE_NAME_SIZE 20
#define MAX_FILE_SIZE 5800    /*allows for [MAX_FILE_SIZE/~58] patients*/

/*------------------------------------------------------------------------------
/Function Prototypes////////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

void encrypt(const char fileName[], int* debugMode);
int oddEvenCheck(int value);
void decrypt(const char fileName[], int* debugMode);
