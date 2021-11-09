/*//////////////////////////////////////////////////////////////////////////////
//////////////////////////////Assignment 3 Group# 3/////////////////////////////
//////////////////////////////File System Function//////////////////////////////
//////////////////////////////////////////////////////////////////////////////*/

#include "main.h"

/*******************************************************************************
 * This function sorts out the list donors based on their bloodtype and saves
 * each donor and their information to a new file.
 * inputs:
 * - patient_t patients[]: the patients currently in the db
 * - patient_t sortedPatients[]: copy of patients array
 * - char filename[]: name of file which data will be saved to
 * - int* numPatients_p: pointer to the count of patients in the db
 * - int *debug: flag that determines whether program is in DEBUG_MODE or not
 * outputs:
 * - none
*******************************************************************************/
void sortPatients(patient_t patients[], patient_t sortedPatients[],
const char filename[], int* numPatients_p, int *debug)
{
	int iter, next;
	patient_t temp; /*Placeholder for moving donor*/

    /*DEBUG MODE: display total number of donors*/
    if(*debug == 1)
    {   
        printf("Total number of donors in database: ");
    }

    /*Copying patients to new sortedPatients array*/
    for (iter = 0; iter < *numPatients_p; iter++)
    {
        sortedPatients[iter] = patients[iter];
    }
    
    /*DEBUG MODE: display total number of donors*/
    if(*debug == 1)
    {
        printf("%d\n", iter);
    }

    /*Iterating and comparing donors for sorting*/
	for (iter = 0; iter < *numPatients_p; iter++)
	{
		for (next = iter + 1; next < *numPatients_p; next++)
		{   
            /*DEBUG MODE: displays bloodtype to show why donors swapped*/
            if (*debug == 1)
            {
                printf("%s's blood type = %s%c\n",
                sortedPatients[iter].name.firstname,
                sortedPatients[iter].bloodType.bloodtype,
                sortedPatients[iter].bloodType.bloodRh);

                printf("%s's blood type = %s%c\n",
                sortedPatients[next].name.firstname,
                sortedPatients[next].bloodType.bloodtype,
                sortedPatients[next].bloodType.bloodRh);

                if(strcmp(
                sortedPatients[iter].bloodType.bloodtype,
                sortedPatients[next].bloodType.bloodtype) > 0)
                {
                    printf("Swapping...\n\n");
                }
                else
                {
                    printf("Already in order - Not swapping.\n\n");
                }
            }

            /*Sorted by blood type: A, AB, B, O*/
			if(strcmp(
                sortedPatients[iter].bloodType.bloodtype,
                sortedPatients[next].bloodType.bloodtype) > 0)
			{   
                /*Bubble sort to alter array*/
				temp = sortedPatients[next];
                sortedPatients[next] = sortedPatients[iter];
                sortedPatients[iter] = temp;
			}
		}
	}

	/*Saves sorted donors to new file*/
    printf("Donors sorted.\n");
	savePatientsToFile(sortedPatients, filename, numPatients_p, debug);
}

/*******************************************************************************
 * This function saves the patients/donors in the database to a file
 * inputs:
 * - char filename[]: the name of file which is being read from
 * - patient_t patients[]: the system's database of current donors
 * - int* numPatients_p: a pointer to the number of patients in the database
 * - int *debug: flag that determines whether program is in DEBUG_MODE or not
 * outputs:
 * - 1 or 0: 
 *   --> 1 = file has been saved
 *   --> 0 = file error/file cannot be saved
*******************************************************************************/
int savePatientsToFile(const patient_t patients[], const char filename[],
const int* numPatients_p, int *debug)
{	
	int iter;

    if (*numPatients_p == 0)
    {
        printf("No patients currently in the database.");
        return 0;
    }

    /*Allocating memory to file pointer*/
    FILE* file_p = NULL;
    file_p =(FILE*) malloc(sizeof(FILE*));

	file_p = fopen(filename, "w");
	if (file_p == NULL)
	{
		printf("Unable to open file.\n");
		return 0;
	}

    if(*debug == 1)
    {   
        printf("Total number of donors in database: %d\n", *numPatients_p);
    }
    
    /*File Header*/
    fprintf(file_p,"First_Name  Mid_Name   Last_Name  ");
	fprintf(file_p,"D.O.B       Blood_Type\n");

    /*Add patients[iter].priority when implemented*/
	for (iter = 0; iter < *numPatients_p; iter++)
	{
        fprintf(file_p, "%-11s %-10s %-10s %02d-%02d-%d %5s %d\n",
		patients[iter].name.firstname,
        patients[iter].name.middlename,
		patients[iter].name.lastname,
		patients[iter].birthday.day,
        patients[iter].birthday.month,
		patients[iter].birthday.year,
        patients[iter].bloodType.bloodtype,
		patients[iter].bloodType.bloodRh);
	}

    fclose(file_p);
    file_p = NULL;

    printf("Success. Donors have been saved to file.\n");
    return 1;
}

/*******************************************************************************
 * This function reads a list of donors from an existing file
 * inputs:
 * - char filename[]: the name of file which is being read from
 * - patient_t patients[]: the system's database of current donors
 * - int* numPatients_p: a pointer to the number of patients in the database
 * - int *debug: flag that determines whether program is in DEBUG_MODE or not
 * outputs:
 * - 1 or 0: 
 *   --> 1 = file has been saved
 *   --> 0 = file error/file cannot be saved
*******************************************************************************/
int readPatientsFromFile(const char filename[], patient_t patients[],
int* numPatients_p, int *debug)
{
	int iter;	
	/*Resetting number of patiens to zero*/
	*numPatients_p = 0;

	FILE* file_p = fopen(filename, "r");
	if (file_p == NULL)
	{
		printf("Unable to open file.\n");
		return 0;
	}

    /*Skips header of the file*/
    fscanf(file_p, "%*[^\n]\n");

	for (iter = 0; iter < MAX_PATIENT_SIZE; iter++)
	{	
		/*If all fields have been entered, will increase patient count by 1*/
		if(fscanf(file_p, "%s %s %s %d-%d-%d %s %d",
		patients[iter].name.firstname,
        patients[iter].name.middlename,
		patients[iter].name.lastname,
        &patients[iter].birthday.day,
        &patients[iter].birthday.month,
        &patients[iter].birthday.year,
        patients[iter].bloodType.bloodtype,
        &patients[iter].bloodType.bloodRh) == 8)
		{
			(*numPatients_p)++;
		}
	}

    /*DEBUG MODE: displaying the number of patients added to database*/
    if (*debug == 1)
    {
        printf("Number of patients added to database: %d", *numPatients_p);
    }

	fclose(file_p);
    file_p = NULL;

	printf("Donors have been added to database.\n");
	return 1;
}
/*******************************************************************************
 * This function searches for a donor based on the user's input
 * inputs:
 * - patient_t patients[]: the system's database of current donors
 * - int* numPatients_p: a pointer to the number of patients in the database
 * - int *debug: flag that determines whether program is in DEBUG_MODE or not
 * outputs:
 * - none
*******************************************************************************/
void searchForDonor(const patient_t patients[], const int* numPatients_p,
int *debug)
{   
    /*Creates new array of patients for patients that match input*/
    patient_t found[MAX_PATIENT_SIZE];

    int searchType, iter, match = 0;
    char valuePN;
    
    /*Prompt to get search type from user*/
    printf("Please input a 0 or 1 for search type\n"
            "(0 - first & last name, 1 - bloodType): ");
    scanf("%d", &searchType);

    if (searchType == 0)
    {
        /*When search type is based on name*/
        char firstName[MAX_NAME_SIZE];
        char lastName[MAX_NAME_SIZE];

	    printf("Please enter the first name of the donor: ");
	    scanf("%s", firstName);

        printf("Please enter the last name of the donor: ");
	    scanf("%s", lastName);

        for (iter = 0; iter < *numPatients_p; iter++)
        {
            if ((strcmp(patients[iter].name.firstname, firstName) == 0) &&
            (strcmp(patients[iter].name.lastname, lastName) == 0))
            {   
                /*Adds matched patient to found array*/
                found[match] = patients[iter];
                
                /*DEBUG MODE: displays the match found */
                if(*debug == 1)
                {
                    printf("\nMatch: %d\n", (match + 1));
                    printf("Specified first name: %s\n", firstName);
                    printf("Specified last name: %s\n", lastName);
                    printf("Database first name: %s\n",
                    found[match].name.firstname);
                    printf("Database last name: %s\n\n",
                    found[match].name.lastname);
                }

                match++;
            }
        }
    }
    else
    {   
        /*When search type is based on blood type*/
        char inputBloodType[MAX_BLOOD_SIZE];
        printf("Please enter the desired blood type: ");
        scanf("%s", inputBloodType);

        for (iter = 0; iter < *numPatients_p; iter++)
        {
            if (strcmp(patients[iter].bloodType.bloodtype,
                inputBloodType) == 0)
            {
                /*If match found, adding donor to new array*/
                found[match] = patients[iter];

                /*DEBUG MODE: displays the match found*/
                if(*debug == 1)
                {
                    printf("\n\nMatch: %d\n", (match + 1));
                    printf("%s's blood type [%s] matches specified "
                    "blood type [%s].\n\n",
                    found[match].name.firstname,
                    found[match].bloodType.bloodtype,
                    inputBloodType);
                }

                match++;
            }
        }
    }

    /*DEBUG MODE: displays total matches found*/
    if(*debug == 1)
    {
        printf("Total matches found: %d\n", match);
    }

    /*When at least 1 match has been found, will print results in cmd*/
    if (match > 0) 
    {
        /*Column Header*/
        printf("\n\nMatching Donors:\n"
             "__________________________________  ____________  ____________\n"
             "|Firstname |Middlename|Surname   |  |Birthdate |  |Bloodtype |\n"
             "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  ~~~~~~~~~~~~  ~~~~~~~~~~~~\n"
             );

        for (iter = 0; iter < match; iter++)
	    {   
            /*Replacing number value of Rh to +ve or -ve symbols*/
		    if(patients[iter].bloodType.bloodRh == 0){valuePN = '-';}
            else if(patients[iter].bloodType.bloodRh == 1){valuePN = '+';}    

            printf("|%-10s|%-10s|%-10s|  |%02d-%02d-%d|  |%5s%-5c|\n"
            "----------------------------------  ------------  ------------\n",
		    found[iter].name.firstname,
            found[iter].name.middlename,
		    found[iter].name.lastname,
		    found[iter].birthday.day,
            found[iter].birthday.month,
		    found[iter].birthday.year,
            found[iter].bloodType.bloodtype,
		    valuePN);
	    }
    }
    else
    {   
        /*Error message when no matches found*/
        printf("Error - No entries match your input.\n");
    }
}

