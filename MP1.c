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
#define SBLACK    "\e[1;38;5;16mblack\e[39;0m"
#define SBROWN    "\e[1;38;5;130mbrown\e[39;0m"
#define SRED      "\e[1;38;5;196mred\e[39;0m"
#define SORANGE   "\e[1;38;5;208morange\e[39;0m"
#define SYELLOW   "\e[1;38;5;226myellow\e[39;0m"
#define SGREEN    "\e[1;38;5;46mgreen\e[39;0m"
#define SBLUE     "\e[1;38;5;21mblue\e[39;0m"
#define SVIOLET   "\e[1;38;5;93mviolet\e[39;0m"
#define SGRAY     "\e[1;38;5;102mgray\e[39;0m"
#define SWHITE    "\e[1;38;5;255mwhite\e[39;0m"
#define SGOLD     "\e[1;38;5;178mgold\e[39;0m"
#define SSILVER   "\e[1;38;5;246msilver\e[39;0m"

void welcomeLine(){

    printf("%s _ _ _     _                   \n", SBOLD);
    printf("| | | |___| |___ ___ _____ ___ \n");
    printf("| | | | -_| |  _| . |     | -_|\n");
    printf("|_____|___|_|___|___|_|_|_|___|%s\n", SRESET);
    printf("%18s\n", "To The");
    printf("%sResistor Color Code Calculator! %s \n\n", SBOLD, SRESET);

    printf("%19s\n", "Legend:");
    printf("%10s%20s\n","Color", "Key Assignment");

    printf("%29s%16s\n", SBLACK, "B or b");
    printf("%30s%16s\n", SBROWN, "N or n");
    printf("%29s%17s\n", SRED,  "R or r");
    printf("%31s%15s\n", SORANGE,  "O or o");
    printf("%31s%15s\n", SYELLOW,  "Y or y");
    printf("%29s%16s\n", SGREEN,  "G or g");
    printf("%29s%16s\n", SBLUE,  "E or e");
    printf("%30s%15s\n", SVIOLET,  "V or v");
    printf("%30s%16s\n", SGRAY,  "A or a");
    printf("%30s%16s\n", SWHITE,  "W or w");
    printf("%30s%16s\n", SGOLD,  "D or d");
    printf("%31s%15s\n", SSILVER,  "S or s");
    printf("%11s%15s\n\n", "No Band", "Z or z");

}

void askMode(char *pFormat){

    do
    {
        printf("Per-line mode [0] or One-liner mode [1]\t: ");
        scanf(" %c",pFormat);

    if (*pFormat != '0' && *pFormat != '1')
    {
        printf("Invalid input. Please enter 0 or 1. \n");
    }

    } while (*pFormat != '0' && *pFormat != '1');
    
}


void enteredBands(char *cBand1, char *cBand2, 
                  char *cBand3, char *cBand4, 
                  char *cBand5, char *cBand6)
{

    printf("Entered bands: ");

    char* pBand = cBand1;

    for(int i = 0; i <= 5; i++){

        switch (*pBand)
        {
        case 'B': case 'b':
            printf("%s", SBLACK);
            break;
        case 'N': case 'n':
            printf("%s", SBROWN);
            break;
        case 'R': case 'r':
            printf("%s", SRED);
            break;
        case 'O': case 'o':
            printf("%s", SORANGE);
            break;
        case 'Y': case 'y':
            printf("%s", SYELLOW);
            break;
        case 'G': case 'g':
            printf("%s", SGREEN);
            break;
        case 'E': case 'e':
            printf("%s", SBLUE);
            break;
        case 'V': case 'v':
            printf("%s", SVIOLET);
            break;
        case 'A': case 'a':
            printf("%s", SGRAY);
            break;
        case 'W': case 'w':
            printf("%s", SWHITE);
            break;
        case 'D': case 'd':
            printf("%s", SGOLD);
            break;
        case 'S': case 's':
            printf("%s", SSILVER);
            break;
        case 'Z': case 'z':
            printf("No Band");
            break;
        default:
            printf("Invalid");
            break;
        }
        if (i != 5){
             printf(", ");
        }

        pBand--;
    }

}

void oneLineInput(char *cBand1, char *cBand2, 
                  char *cBand3, char *cBand4, 
                  char *cBand5, char *cBand6)
{
    printf("Enter the 6 color bands; use commas as separators:\n");
    scanf(" %c,%c,%c,%c,%c,%c", 
            cBand1, cBand2, 
            cBand3, cBand4, 
            cBand5, cBand6);

    enteredBands(cBand1, cBand2, 
                 cBand3, cBand4, 
                 cBand5, cBand6);


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

    enteredBands(cBand1, cBand2, 
                 cBand3, cBand4, 
                 cBand5, cBand6);
}

int main(){

    char cBand1, cBand2, 
         cBand3, cBand4, 
         cBand5, cBand6;

    char cFormat;

    welcomeLine();

    askMode(&cFormat);

    if(cFormat == '0')
    {
        perLineInput(&cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
    else if (cFormat == '1')
    {
        oneLineInput(&cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
    
    return 0;
}

