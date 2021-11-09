/*******************************************************************************
 * Author: Group 03
 * Date: 31/10/2021
 * Purpose: This header file defines all the main functions that the blood
 * donation system requires
*******************************************************************************/

/*******************************************************************************
* List of standard libraries used
*******************************************************************************/

#include <stdio.h> /*printf, scanf, fgets, fopen, fclose, fprintf, fscanf, */
#include <string.h> /*strcmp, strlen*/
#include <stdlib.h> /*malloc, free, atoi*/
#include <math.h> /**/

/*******************************************************************************
* List of preprocessing directives
*******************************************************************************/

#define MAX_PATIENT_SIZE 50
#define MAX_NAME_SIZE 10
#define MAX_BLOOD_SIZE 4

#define MAX_FILENAME_LEN 20
#define DATABASE_FILENAME "donors"

/*******************************************************************************
* List of structs
*******************************************************************************/
struct date
{
    int day;
    int month;
    int year;
};
typedef struct date date_t;

struct eligibility
{
    int bloodAC;
    int bloodID;
    int tattoo;
    int madcow;
    int heartcondition;
    int pregnancy;
};
typedef struct eligibility eligibility_t;

struct bloodType    /*we can change to a char array with size 2*/
{
    char bloodtype[MAX_BLOOD_SIZE];
    int bloodRh;
};
typedef struct bloodType bloodType_t;

struct name
{
    char firstname[MAX_NAME_SIZE];
    char middlename[MAX_NAME_SIZE];
    char lastname[MAX_NAME_SIZE];
};
typedef struct name name_t;

struct patient 
{
    name_t name;
    date_t birthday;
    eligibility_t eligibility;
    bloodType_t bloodType;
};
typedef struct patient patient_t;

/*******************************************************************************
* Function Prototypes
*******************************************************************************/

int addPatient(patient_t patientList[], int *count);
void sortPatients(patient_t patients[], patient_t sortedPatients[],
const char filename[], int* numPatients_p, int *debug);
int savePatientsToFile(const patient_t patients[], const char filename[],
const int* numPatients_p, int *debug);
int readPatientsFromFile(const char filename[], patient_t patients[],
int* numPatients_p, int *debug);
void searchForDonor(const patient_t patients[], const int* numPatients_p,
int *debug);
