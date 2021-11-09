/* /////////////////////////////////////////////////////////////////////////////
///////////////////////Assignment 3 Group# 3: general fct header////////////////
///////////////////////////////By Tasman France/////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

/*------------------------------------------------------------------------------
/Required Header Files//////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

/*including allowed standard libraries*/
#include <stdio.h>  /*printf, fopen, fclose, fgets*/
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*including custom header files*/
#include "encryption.h"     /*encrypt, decrypt*/
#include "splashScreen.h"   /*splashScreen*/
#include "main.h"

/*------------------------------------------------------------------------------
/Function Prototypes////////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

#define MAX_PATIENT_SIZE 50
#define MAX_NAME_SIZE 10
#define MAX_BLOOD_SIZE 4
#define MAX_FILENAME_LEN 20
#define DATABASE_FILENAME "donors"
#define SORTED_FILENAME "donorsByBloodType"

/*------------------------------------------------------------------------------
/Function Prototypes////////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

void displayPatient(patient_t patient[], int* numPatient_p);
void printMenu(int mode);
int manageMenuSelection(int *debug, int *count, patient_t patientList[],
patient_t sortedPatients[], const char filename[]);
void waitEnter(int buffer);
