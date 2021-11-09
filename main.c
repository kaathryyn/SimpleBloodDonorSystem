/* /////////////////////////////////////////////////////////////////////////////
//////////////////////////////Assignment_3 Group_3/////////////////////////////
///////////////////////////////////Main file////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

/*------------------------------------------------------------------------------
/Required Header Files//////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

/*including custom header files*/
#include "general.h"

/*------------------------------------------------------------------------------
/Instructions for making main.out///////////////////////////////////////////////
------------------------------------------------------------------------------*/

/*
Run these commands in the terminal
to get and run the main.out file
    ~~~~~~~~~~~~~~~~~~~~~~~~~
    |    1.) make clean     |
    |                       |
    |    2.) make main.out  |
    |                       |
    |    3.) ./main.out     |
    ~~~~~~~~~~~~~~~~~~~~~~~~~
*/

/*------------------------------------------------------------------------------
/Main Function//////////////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

int main(void)
{
    patient_t patientList[MAX_PATIENT_SIZE], sortedPatients[MAX_PATIENT_SIZE];
    int numPatient = 0, exit = 0, debug = 0;    /*list size & flag variables*/
    char filename[MAX_FILENAME_LEN] = DATABASE_FILENAME;

    splashScreen(1); /*prints company splash screen*/
    waitEnter(1);    /*waits until [enter] key pressed*/

    decrypt(filename, &debug);  /*decrypts donor list if available*/
    readPatientsFromFile(filename, patientList, &numPatient, &debug);
    /*imports donor list if available after decryption*/

    printMenu(0);   /*prints main menu*/

    while(exit != 1)    /*cont' loop until 'exit program' chosen*/
    {
        exit = manageMenuSelection(&debug, &numPatient, patientList,
        sortedPatients, filename);  /*function selection script*/
    }

    if(exit == 1)   /*program exited*/
    {
        printf("Thank you for choosing to use our product,\n");
        if(debug == 1)
        {
            printf("Boo!\n\n");
            /*spoopy endcard*/
        }
        if(debug == 0)
        {
            printf("have a nice day!\n\n");
            /*farewell endcard*/
        }
        printf("\n\nPress the [enter] key to exit...");
        while(getchar()!='\n')
        {
            getchar();
        }
    }
    encrypt(filename, &debug);  /*re-encrypt donor list*/

    return 0;
}
