/******************************************************************
This is to certify that this project is my own work, based on my
personal efforts in studying and applying the concepts learned. I
have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and
debugged by my own efforts. I further certify that I have not copied
in part or whole or otherwise plagiarized the work of other students
and/or persons.
NONO, Alec Marx Gabriel Belen , DLSU ID# 12413704
******************************************************************/

#include <stdio.h>

#define SRESET    "\e[0m"
#define SBOLD     "\e[39;49;1m"
#define SNORMAL   "\e[39;49m"
#define SBLACK    "\e[1;38;5;16m"
#define SBROWN    "\e[1;38;5;130m"
#define SRED      "\e[1;38;5;196m"
#define SORANGE   "\e[1;38;5;208m"
#define SYELLOW   "\e[1;38;5;226m"
#define SGREEN    "\e[1;38;5;46m"
#define SBLUE     "\e[1;38;5;21m"
#define SVIOLET   "\e[1;38;5;93m"
#define SGRAY     "\e[1;38;5;102m"
#define SWHITE    "\e[1;38;5;255m"
#define SGOLD     "\e[1;38;5;178m"
#define SSILVER   "\e[1;38;5;246m"

void welcomeLine(){

    printf("%s _ _ _     _                   \n", SBOLD);
    printf("| | | |___| |___ ___ _____ ___ \n");
    printf("| | | | -_| |  _| . |     | -_|\n");
    printf("|_____|___|_|___|___|_|_|_|___|%s\n", SNORMAL);
    printf("%18s\n", "To The");
    printf("%sResistor Color Code Calculator! %s \n\n", SBOLD, SRESET);

    printf("%19s\n", "Legend:");
    printf("%10s%20s\n","Color", "Key Assignment");

    printf("%s%10s%s%16s\n", SBLACK, "black", SRESET, "B or b");
    printf("%s%10s%s%16s\n", SBROWN, "brown", SRESET, "N or n");
    printf("%s%9s%s%17s\n", SRED, "red", SRESET, "R or r");
    printf("%s%11s%s%15s\n", SORANGE, "orange", SRESET, "O or o");
    printf("%s%11s%s%15s\n", SYELLOW, "yellow", SRESET, "Y or y");
    printf("%s%10s%s%16s\n", SGREEN, "green", SRESET, "G or g");
    printf("%s%10s%s%16s\n", SBLUE, "blue", SRESET, "E or e");
    printf("%s%11s%s%15s\n", SVIOLET, "violet", SRESET, "V or v");
    printf("%s%10s%s%16s\n", SGRAY, "gray", SRESET, "A or a");
    printf("%s%10s%s%16s\n", SWHITE, "white", SRESET, "W or w");
    printf("%s%10s%s%16s\n", SGOLD, "gold", SRESET, "D or d");
    printf("%s%11s%s%15s\n", SSILVER, "silver", SRESET, "S or s");
    printf("%11s%15s\n\n", "No Band", "Z or z");

}

void askMode(int *pFormat){

    do
    {
        printf("What type of mode: Per-line? [0] or One-liner? [1]\t");
        scanf("%d",pFormat);

    if (*pFormat != 0 && *pFormat != 1)
    {
        printf("Invalid input. Please enter 0 or 1. \n");
    }

    } while (*pFormat != 0 && *pFormat != 1);
    
}

void oneLineInput(char *cBand1, char *cBand2, 
                  char *cBand3, char *cBand4, 
                  char *cBand5, char *cBand6)
{
    printf("Enter the color bands; use commas as separators:\n");
    scanf(" %c,%c,%c,%c,%c,%c", 
            cBand1, cBand2, 
            cBand3, cBand4, 
            cBand5, cBand6);

    printf("Entered bands: %c,%c,%c,%c,%c,%c\n", 
                            *cBand1, *cBand2, 
                            *cBand3, *cBand4, 
                            *cBand5, *cBand6);
}

void perLineInput(char *cBand1, char *cBand2, 
                  char *cBand3, char *cBand4, 
                  char *cBand5, char *cBand6)
{

    printf("Enter the color bands\n");
    printf("1st band: ");
    scanf(" %c", cBand1);
    printf("2nd band: ");
    scanf(" %c", cBand2);
    printf("3rd band: ");
    scanf(" %c", cBand3);
    printf("4th band: ");
    scanf(" %c", cBand4);
    printf("5th band: ");
    scanf(" %c", cBand5);
    printf("6th band: ");
    scanf(" %c", cBand6);

    printf("Entered bands: %c,%c,%c,%c,%c,%c", 
                        *cBand1, *cBand2, 
                        *cBand3, *cBand4, 
                        *cBand5, *cBand6);
}

int main(){

    char cBand1, cBand2, 
         cBand3, cBand4, 
         cBand5, cBand6;

    int nFormat;

    welcomeLine();

    askMode(&nFormat);

    if(nFormat == 0)
    {
        perLineInput(&cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
        
    }
    else if (nFormat == 1)
    {
        oneLineInput(&cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
    
    return 0;
}