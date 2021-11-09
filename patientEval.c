/* /////////////////////////////////////////////////////////////////////////////
///////////////////Patient Evaluation and eligibility checker//////////////////
/////////////////////By Soubhag Gopi///////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

#include "main.h"

/*******************************************************************************
 * Adding patient
*******************************************************************************/

int addPatient(patient_t patientList[], int *count)
{
    /* Limits character string */
    char typeString[6];
    
    /*Notifies user Max patient size has been reached */
    while(*count == MAX_PATIENT_SIZE)
    {
        printf("\nMax patient list size has been reached,\n"
               "unable to add new patient entry.\n");
        return 1;
    };

    do
    {
        /* Start of eligibility checker */
        printf("Have you consumed alcohol within the past 48 hours?" 
            " (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.bloodAC = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }   
    }while(1);
    
    do
    {
        printf("Are you low in iron? (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.bloodID = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }   
    }while(1);

    do
    {
        printf("Have you had a tattoo in the last 4 months?"
            " (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.tattoo = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }    
    }while(1);

    do
    {
        printf("Did you live in the UK for 6 months or more between 1980 and"
            " 1996? (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.madcow = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }   
    }while(1);

    do 
    {
        printf("Do you have a heart condition?" 
            " (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.heartcondition = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }   
    }while(1);

    do
    {
        printf("Are you pregnant or recently given birth?"
            " (Type 0 for no and 1 for yes): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].eligibility.pregnancy = atoi (typeString);
            break;
        }
        else if(typeString[0] == '1')
        {
            /* Notifies user they are ineligible */
            printf("Unfortunately you are ineligible to donate blood.\n");
            return 0;
        }    
        else
        {
            /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1.\n");
        }   
    }while(1);

    /* End of eligibility checker */

    do
    {
        /* Start of storing patient information */
        printf("What is your blood type? (Letters only): ");
        fgets(patientList[*count].bloodType.bloodtype, MAX_BLOOD_SIZE, stdin);
        /* Calculates string length */
        int len = strlen (patientList[*count].bloodType.bloodtype);
        if (patientList[*count].bloodType.bloodtype[len-1] == '\n')
        {
            patientList[*count].bloodType.bloodtype[len-1] = '\0';
        }
        /* Compares input to acceptable characters */
        if ((strcmp(patientList[*count].bloodType.bloodtype, "AB") == 0) ||
            (strcmp(patientList[*count].bloodType.bloodtype, "A") == 0) ||
            (strcmp(patientList[*count].bloodType.bloodtype, "B") == 0) ||
            (strcmp(patientList[*count].bloodType.bloodtype, "O") == 0))
        {
            /* breaks loop and moves onto next question */
            break;
        }
        else
        {
            /* Notifies users of acceptable inputs (case sensitive) */
            printf("Enter either A, AB, B, O\n");
        }
    }while(1);

    do
    {
        printf("Is your blood type positive or negative"
            " (0 for negative and 1 for positive): ");
        fgets(typeString, 3, stdin);
        if (typeString[0] == '1' || typeString[0] == '0')
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].bloodType.bloodRh = atoi (typeString);
            break;
        }
        else
        /* Notifies users of acceptable inputs */
            printf("Enter either 0 or 1\n");
    }while(1);

    printf("Enter first name: ");
    fgets(patientList[*count].name.firstname, MAX_NAME_SIZE, stdin);
    /* Calculates string length */
    int len = strlen (patientList[*count].name.firstname);
    if (patientList[*count].name.firstname[len-1] == '\n')
    {
        patientList[*count].name.firstname[len-1] = '\0';
    }
    else 
    {
        while (getchar() != '\n')
        {
            getchar();
        }
    }
    
    
    printf("Enter middle name (Leave blank if you do not have one): ");
    fgets(patientList[*count].name.middlename, MAX_NAME_SIZE, stdin);
    /* Calculates string length */
    len = strlen (patientList[*count].name.middlename);
    if (patientList[*count].name.middlename[len-1] == '\n')
    {
        patientList[*count].name.middlename[len-1] = '\0';
    }
    else 
    {
        while (getchar() != '\n')
        {
            getchar();
        }
    }
    printf("Enter last name: ");
    fgets(patientList[*count].name.lastname, MAX_NAME_SIZE, stdin);
    /* Calculates string length */
    len = strlen (patientList[*count].name.lastname);
    if (patientList[*count].name.lastname[len-1] == '\n')
    {
        patientList[*count].name.lastname[len-1] = '\0';
    }
    else 
    {
        while (getchar() != '\n')
        {
            getchar();
        }
    }

    do 
    {
        printf("Enter birthday: day>");
        fgets(typeString, 6, stdin);
        /* Range of acceptable inputs */
        if (atoi (typeString)>=1 && atoi (typeString)<=31)
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].birthday.day = atoi (typeString);
            break;
        }
        else
        /* Notifies users of acceptable inputs */
            printf("Day should be an integer between 1 and 31.\n");
    }while(1);

    do
    {
        printf("Enter birthday: month>");
        fgets(typeString, 6, stdin);
        /* Range of acceptable inputs */
        if (atoi (typeString)>= 1 && atoi (typeString)<=12)
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].birthday.month = atoi (typeString);
            break;
        }
        else
        /* Notifies users of acceptable inputs */
            printf("Month should be an integer between 1 and 12.\n");
    }while(1);

    do
    {
        printf("Enter birthday: year>");
        fgets(typeString, 6, stdin);
        /* Range of acceptable inputs */
        if (atoi (typeString)>= 1900 && atoi (typeString)<=2003)
        {
            /* Converts string to integer and breaks loop */
            patientList[*count].birthday.year = atoi (typeString);
            break;
        }
        else
        /* Notifies users of acceptable inputs */
            printf("Year should be an integer between 1900 and 2003.\n");
    }while(1);

    /* Adds patient to database */
    (*count)+= 1;

    /* returns to menu */
    return 1;
}
