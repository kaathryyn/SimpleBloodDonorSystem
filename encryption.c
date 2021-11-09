/* /////////////////////////////////////////////////////////////////////////////
///////////////////////Assignment 3 Group# 3: encryption source/////////////////
///////////////////////////////By Tasman France/////////////////////////////////
///////////////////////////////////////////////////////////////////////////// */

/*------------------------------------------------------------------------------
/Required Header Files//////////////////////////////////////////////////////////
------------------------------------------------------------------------------*/

#include "encryption.h"

/*------------------------------------------------------------------------------
-FUNCTION:encrypts a text file
================================================================================
-INPUTS:
    -character array containing file name
    -memory location of debug flag
-OUTPUTS:
    -none
------------------------------------------------------------------------------*/

void encrypt(const char fileName[], int* debugMode)
{
    int iter, fileSize=0;
    char ch;
    unsigned int charStorage[MAX_FILE_SIZE];

    FILE* file_p = NULL;    /*setting up file pointer*/
    file_p = (FILE*) malloc(sizeof(char)*MAX_FILE_SIZE);

    file_p = fopen(fileName, "r");

    if(*debugMode == 1)
    {
        printf("\n\nInput filename: %s\n", fileName);
    }

    if(file_p == NULL)  /*doesnt point to file*/
    {
        printf("File read error.\n");
        if(*debugMode == 1)
        {
            printf("Encryption file pointer returned NULL character.\n");
        }
        return;
    }

    for(ch = fgetc(file_p), iter = 0 ; ch!=EOF&&
    iter<MAX_FILE_SIZE ; ch = fgetc(file_p), iter++)
    /*saving contents of file to char ch[]*/
    {
        charStorage[iter] = ch;
        fileSize++; /*keeping track of file size in characters*/
    }

    fclose(file_p); /*closing file*/
    file_p = NULL;
    
    if(*debugMode == 1) /*if in debugmode, display file details*/
    {
        printf("\n\nContents of input file for encryption:\n---\n");
        for(iter=0 ; iter<=fileSize ; iter++)
        {
            printf("%c", charStorage[iter]);
        }
        
        printf("\n---\nCharacter ASCII decimal values\n---\n");

        for(iter=0 ; iter<=fileSize ; iter++)
        {
            printf("%d", charStorage[iter]);
        }
        printf("\n---\nEnd of file contents.\n");
        printf("\n\nFile size (#characters): %d\n", fileSize);
    }

    if(oddEvenCheck(fileSize) == 1) /*i.e. even number of characters*/
    {
        if(*debugMode == 1)
        {
            printf("\n\nEven number of charaters, shifting by +finalValue\n");
        }
        for(iter=0 ; iter<fileSize-2 ; iter++)  /*even, :. shift char by +10*/
        {
            charStorage[iter]+=charStorage[fileSize-1];
        }
    }

    else if(oddEvenCheck(fileSize) == 0)    /*i.e. odd number of characters*/
    {
        if(*debugMode == 1)
        {
            printf("\n\nOdd number of characters, shifting by -finalValue\n");
        }
        for(iter=0 ; iter<fileSize-2 ; iter++)  /*odd, :. shift char by -10*/
        {
            charStorage[iter]-=charStorage[fileSize-1];
        }
    }

    if(*debugMode == 1)
    {
        printf("\n\nContents of output encrypted file:\n---\n");
        for(iter=0 ; iter<=fileSize ; iter++)
        {
            printf("%c", charStorage[iter]);
        }
        
        printf("\n---\nCharacter ASCII decimal values\n---\n");

        for(iter=0 ; iter<=fileSize ; iter++)
        {
            printf("%d", charStorage[iter]);
        }
        printf("\n---\nEnd of file contents.\n");
    }

    file_p = (FILE*) malloc(sizeof(FILE*));

    file_p = fopen(fileName, "w");

    if(*debugMode == 1)
    {
        printf("\n\nOutput filename: %s\n", fileName);
    }

    if(file_p == NULL)
    {
        printf("File read error.\n");
        if(*debugMode == 1)
        {
            printf("Encryption file pointer returned NULL character.\n");
        }
    }
    for(iter=0 ; iter<fileSize ; iter++)
    {
        fputc(charStorage[iter], file_p);
    }

    fclose(file_p);
    file_p = NULL;
}

/*------------------------------------------------------------------------------
-FUNCTION:
================================================================================
-INPUTS:
    -character array containing file name
    -memory location of debug flag
-OUTPUTS:
    -none
------------------------------------------------------------------------------*/

void decrypt(const char fileName[], int* debugMode)
{
    int iter, fileSize=0;
    char ch;
    unsigned int charStorage[MAX_FILE_SIZE];
    
    FILE* file_p = NULL;    /*setting up file pointer*/
    file_p = (FILE*) malloc(sizeof(char)*MAX_FILE_SIZE);

    file_p = fopen(fileName, "r");

    if(file_p == NULL)
    {
        if(*debugMode == 1)
        {
            printf("File read error.\n"
                   "Decryption file pointer returned NULL character.\n");
        }
        return;
    }

    if(*debugMode == 1)
    {
        printf("\n\nInput filename: %s\n", fileName);
    }

    for(ch = fgetc(file_p), iter = 0 ; ch!=EOF&&
    iter<MAX_FILE_SIZE ; ch = fgetc(file_p), iter++)
    /*saving contents of file to char ch[]*/
    {
        charStorage[iter] = ch;
        fileSize++; /*keeping track of file size in characters*/
    }

    fclose(file_p);
    file_p = NULL;
    
    if(*debugMode == 1)
    {
        printf("\n\nContents of input file for Decryption:\n---\n");
        for(iter=0 ; iter<fileSize ; iter++)
        {
            printf("%c", charStorage[iter]);
        }
        
        printf("\n---\nCharacter ASCII decimal values\n---\n");

        for(iter=0 ; iter<fileSize ; iter++)
        {
            printf("%d", charStorage[iter]);
        }
        printf("\n---\nEnd of file contents.\n");

        printf("\n\nfilesize(characters): %d\n", fileSize);
    }

    if(oddEvenCheck(fileSize) == 1)
    /*i.e. even number of characters, :. reduce by 10*/
    {
        if(*debugMode == 1)
        {
            printf("\n\nEven number of charaters\n");
        }
        for(iter=0 ; iter<fileSize-2 ; iter++)
        {
            charStorage[iter]-=charStorage[fileSize-1];
        }
    }

    else if(oddEvenCheck(fileSize) == 0)
    /*i.e. odd number of characters, :. increase by 10*/
    {
        if(*debugMode == 1)
        {
            printf("\n\nOdd number of characters\n");
        }
        for(iter=0 ; iter<fileSize-2 ; iter++)
        {
            charStorage[iter]+=charStorage[fileSize-1];
        }
    }

    file_p = (FILE*) malloc(sizeof(FILE*));

    file_p = fopen(fileName, "w");

    if(*debugMode == 1)
    {
        printf("\n\nOutput filename: %s\n", fileName);
    }

    if(file_p == NULL)
    {
        printf("File read error.\n");
        if(*debugMode == 1)
        {
            printf("Decryption file pointer returned NULL character.\n");
        }
    }
    for(iter=0 ; iter<fileSize ; iter++)
    {
        fputc(charStorage[iter], file_p);
    }

    fclose(file_p);
    file_p = NULL;

    if(*debugMode == 1)
    {
        printf("\n\nContents of output Decrypted file:\n---\n");
        for(iter=0 ; iter<fileSize ; iter++)
        {
            printf("%c", charStorage[iter]);
        }
        
        printf("\n---\nCharacter ASCII decimal values\n---\n");

        for(iter=0 ; iter<fileSize ; iter++)
        {
            printf("%d", charStorage[iter]);
        }
        printf("\n---\nEnd of file contents.\n");
    }

}

/*------------------------------------------------------------------------------
-FUNCTION:checks if a value is odd or even and returns a value
================================================================================
-INPUTS:
    -an integer to be checked
-OUTPUTS:
    -returns a value depending on whether or not it is odd or even
    EVEN-->1
    ODD -->0
------------------------------------------------------------------------------*/

int oddEvenCheck(int value) /*returns a 1 when value is even, 0 when odd*/
{
    if(value%2 == 0)    /*if no remainder when /2, value even*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
