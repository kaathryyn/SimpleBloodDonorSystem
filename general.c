/* /////////////////////////////////////////////////////////////////////////////
///////////////////////Assignment 3 Group# 3: general fct source////////////////
///////////////////////////////By Tasman France/////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

#include "general.h"

/*------------------------------------------------------------------------------
/Function Definitions///////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
-FUNCTION:displays current patients saved in the database
================================================================================
-INPUTS:
    -patients[] array
    -memory address of the number of patients
-OUTPUTS:
    -none
------------------------------------------------------------------------------*/
void displayPatient(patient_t patients[], int* numPatients_p)
{
    int i;
    char valuePN;

    if(*numPatients_p != 0)
    {
        printf("\n\nPatient list:\n"
             "__________________________________  ____________  ____________\n"
             "|Firstname |Middlename|Surname   |  |Birthdate |  |Bloodtype |\n"
             "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ~~~~~~~~~~~~  ~~~~~~~~~~~~\n"
               );
               /*list header*/
        
        for(i=0 ; i<*numPatients_p ; i++)  /*patient print loop, continues
                                            until i == donor list size*/
        {
            if(patients[i].bloodType.bloodRh == 0){valuePN = '-';}
            else if(patients[i].bloodType.bloodRh == 1){valuePN = '+';}    
            printf("|%-10s|%-10s|%-10s|  |%02d-%02d-%d|  |%6s%-4c|\n"
            "----------------------------------  ------------  ------------\n",
            patients[i].name.firstname,
            patients[i].name.middlename,
            patients[i].name.lastname,
            patients[i].birthday.day,
            patients[i].birthday.month,
            patients[i].birthday.year,
            patients[i].bloodType.bloodtype,
            valuePN);
        }
    }

    else
    {
        printf("\nThere are no patients currently saved in the database.\n");
    }
}

/*------------------------------------------------------------------------------
-FUNCTION:prints the option menu for the user to select a function
================================================================================
-INPUTS:
    -mode selection (either first bootup or user/system polled for menu/help)
-OUTPUTS:
    -none
------------------------------------------------------------------------------*/

void printMenu(int mode)
{
    if(mode == 0)   /*first boot (first menu occurence)*/
    {
        printf("\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|            Welcome to Blood Donation System 1.1            |\n"
           "|                                                            |\n"
           "|                         Main Menu                          |\n"
           "|                         ---------                          |\n"
           "|                Type 'help' for more options                |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "| Please enter your desired operation from the list,         |\n"
           "| followed by the [enter] key:                               |\n"
           "|                                                            |\n"
           "|       1. Add donor                                         |\n"
           "|       2. Delete last donor                                 |\n"
           "|       3. Display donor list                                |\n"
           "|       4. Select donor                                      |\n"
           "|       5. Export donor list as file                         |\n"
           "|       6. Import donor list from file                       |\n"
           "|       7. Sort donors and save as file                      |\n"
           "|       8. Exit program and encrypt donor list               |\n"
           "|                                                            |\n"
           "|                                                            |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "Selection>>> ");
    }
    else if(mode == 1)  /*user/sys polled for menu (repeated menu occurence)*/
    {
        printf("\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|                         Main Menu                          |\n"
           "|                         ---------                          |\n"
           "|                Type 'help' for more options                |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|       1. Add donor                                         |\n"
           "|                                                            |\n"
           "|       2. Delete last donor                                 |\n"
           "|                                                            |\n"
           "|       3. Display donor list                                |\n"
           "|                                                            |\n"
           "|       4. Select donor                                      |\n"
           "|                                                            |\n"
           "|       5. Export donor list as file                         |\n"
           "|                                                            |\n"
           "|       6. Import donor list from file                       |\n"
           "|                                                            |\n"
           "|       7. Sort donors and save as file                      |\n"
           "|                                                            |\n"
           "|       8. Exit program and encrypt donor list               |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "Selection>>> ");
    }
    else if(mode == 2)  /*user polled for help menu*/
    {
        printf("\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|                         Help Menu                          |\n"
           "|                         ---------                          |\n"
           "|                   Type 'menu' to go back                   |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|                                                            |\n"
           "|Choosing a task:                                            |\n"
           "|   Typing a value from 1 to 8 and hitting the [enter] key   |\n"
           "|   will access the corresponding operation listed in the    |\n"
           "|   menu next to the value you entered.                      |\n"
           "|                                                            |\n"
           "|Extra options:                                              |\n"
           "|   Type 'help' to return to this dialogue box.              |\n"
           "|                                                            |\n"
           "|   Type 'debug' to access additional error messages and     |\n"
           "|   information on current operations.                       |\n"
           "|                                                            |\n"
           "|   Type 'menu' in order to return to the main menu          |\n"
           "|                                                            |\n"
           "|                                                            |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "Selection>>> ");
    }
}

/*------------------------------------------------------------------------------
-FUNCTION:activates different functions depending on users choice from the menu
================================================================================
-INPUTS:
    -memory address of debug flag
    -memory address of the number of patients
    -patientList[] array
    -sortedPatients[] array
    -character array containing file name
-OUTPUTS:
    -exit flag
------------------------------------------------------------------------------*/
int manageMenuSelection(int *debug, int *count,
patient_t patientList[], patient_t sortedPatients[], const char filename[])
{
    char userSelection[7];
    int loopFlag = 1;

    fgets(userSelection, 7, stdin);

    if((userSelection[0] == '1')&&
       (userSelection[2] == '\0'))  /*call funct addPatient()*/
    {
        addPatient(patientList, count);
    }
    else if((userSelection[0] == '2')&&
            (userSelection[2] == '\0')) /*user removes last donor*/
    {
        if(*count != 0) /*if there are patients saved*/
        {
            *count -= 1;
            printf("Last donor sucessfully removed.\n");
        }
        else if(*count == 0)    /*no patients present*/
        {
            printf("No donors removed. List is currently empty.\n");
        }
    }
    else if((userSelection[0] == '3')&&
            (userSelection[2] == '\0')) /*call funct displayList()*/
    {
        displayPatient(patientList, count);
        waitEnter(1);    /*waits for [enter] key to be pressed*/
    }
    else if((userSelection[0] == '4')&&
            (userSelection[2] == '\0')) /*call funct selectPatient()*/
    {
        searchForDonor(patientList, count, debug);
        waitEnter(2);    /*waits for [enter] key to be pressed*/
    }
    else if((userSelection[0] == '5')&&
            (userSelection[2] == '\0')) /*call funct exportPatient()*/
    {
        savePatientsToFile(patientList, filename, count, debug);
    }
    else if((userSelection[0] == '6')&&
            (userSelection[2] == '\0')) /*call funct importPatient()*/
    {
        readPatientsFromFile(filename, patientList, count, debug);
    }
    else if((userSelection[0] == '7')&&
            (userSelection[2] == '\0')) /*save sorted patient list*/
    {
        sortPatients(patientList, sortedPatients, filename, count, debug);
    }
    else if((userSelection[0] == '8')&&
            (userSelection[2] == '\0')) /*return exit flag(HIGH)*/
    {
        loopFlag = 0;   /*do not reprint main menu*/
        return 1;
    }
    else if((userSelection[0] == 'm')&& /*user polls for menu*/
            (userSelection[1] == 'e')&&
            (userSelection[2] == 'n')&&
            (userSelection[3] == 'u')&&
            (userSelection[5] == '\0'))
    {
        printMenu(1);   /*prints shortened menu*/
        loopFlag = 0;   /*do not reprint main menu*/
    }
    else if((userSelection[0] == 'l')&& /*egg*/
            (userSelection[1] == 'o')&&
            (userSelection[2] == 'l')&&
            (userSelection[4] == '\0'))
    {
        printf("Hello World\n"
               "Please bleed on-screen right now. Thanks. :^)\n");
               /*easter egg referencing inside joke in team*/
        waitEnter(1);    /*waits for [enter] key to be pressed*/
    }
    else if((userSelection[0] == 'd')&& /*user polls for debug mode*/
            (userSelection[1] == 'e')&&
            (userSelection[2] == 'b')&&
            (userSelection[3] == 'u')&&
            (userSelection[4] == 'g')&&
            (userSelection[6] == '\0'))
    {
        printf("Debug mode activated,\n"
               "all processes/related error messages will be displayed\n");
        *debug = 1; /*set debug flag HIGH*/
        waitEnter(1);    /*waits for [enter] key to be pressed*/
    }
    else if((userSelection[0] == 'h')&& /*user polls for help*/
            (userSelection[1] == 'e')&&
            (userSelection[2] == 'l')&&
            (userSelection[3] == 'p')&&
            (userSelection[5] == '\0'))
    {
        printMenu(2);   /*prints help menu with extended options*/
        loopFlag = 0;   /*do not reprint main menu*/
    }
    else    /*improper user input*/
    {
        printf("\nIncorrect choice.\n"
               "Please enter a valid selection,\n"
               "or type 'menu' to see your options again.\n>>>");
               loopFlag = 0;
    }

    while(loopFlag == 1)
    {
        printMenu(1);   /*prints selection menu*/
        loopFlag = 0;
    }
    return 0;   /*return exit flag(LOW)*/
}

/*------------------------------------------------------------------------------
-FUNCTION:pauses function until the user presses the [enter] key (buffer) times
================================================================================
-INPUTS:
    -an integer value for the amount of [enter] key presses to wait for
-OUTPUTS:
    -none
------------------------------------------------------------------------------*/

void waitEnter(int buffer)
{
    printf("\n\nPress the [enter] key to continue...");
    if(buffer == 1) /*wait for 1 newline*/
    {
        while(getchar()!='\n')  /*waits until getchar returns newline char*/
        {
            getchar();
        }
    }

    if(buffer == 2) /*wait for 2 newlines*/
    {
        while(getchar()!='\n')  /*waits until getchar returns newline (1st)*/
        {
            getchar();
        }
        while(getchar()!='\n')  /*waits until getchar returns newline (2nd)*/
        {
            getchar();
        }
    }
    printf("\n\n");
}
