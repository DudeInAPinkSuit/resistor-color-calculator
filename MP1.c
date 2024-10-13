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

// constants for colored text
#define SRESET     "\e[0m"
#define SBOLD      "\e[39;49;1m"
#define SWHITEBOLD "\e[1;38;5;255m"
#define SREDBOLD   "\e[1;38;5;196m"

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

void welcomeLine()
{

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

void askMode(char *pFormat)
{
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

void enteredBands(int *nValid, char *pBand1, char *pBand2, 
                  char *pBand3, char *pBand4, 
                  char *pBand5, char *pBand6)
{
    printf("Entered bands: ");

    char* pBand = pBand1;

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
            *nValid = 0;
            break;
        }
        (i == 5) ? printf("\n") : printf(", ");
        
        pBand--;
    }
}

void oneLineInput(int *nValid, char *pBand1, char *pBand2, 
                  char *pBand3, char *pBand4, 
                  char *pBand5, char *pBand6)
{
    printf("Enter the 6 color bands; use commas as separators (Extra inputs are discarded):\n");
    scanf(" %c,%c,%c,%c,%c,%c", 
            pBand1, pBand2, 
            pBand3, pBand4, 
            pBand5, pBand6);

    enteredBands(nValid, pBand1, pBand2, 
                 pBand3, pBand4, 
                 pBand5, pBand6);
}

void perLineInput(int *nValid, char *pBand1, char *pBand2, 
                  char *pBand3, char *pBand4, 
                  char *pBand5, char *pBand6)
{
    printf("Enter the color bands\n");
    printf("1st band: ");
    scanf(" %c", pBand1);
    printf("2nd band: ");
    scanf(" %c", pBand2);
    printf("3rd band: ");
    scanf(" %c", pBand3);
    printf("4th band: ");
    scanf(" %c", pBand4);
    printf("5th band: ");
    scanf(" %c", pBand5);
    printf("6th band: ");
    scanf(" %c", pBand6);

    enteredBands(nValid, pBand1, pBand2, 
                 pBand3, pBand4, 
                 pBand5, pBand6);
}

int compute1stDigits(char *pBand1, int *pValid, int nDigits)
{
    
    int nDigit3 = 0;
    int nDigit2 = 0;
    int nDigit1 = 0;

    int *pDigit = &nDigit1;
    char *pBand = pBand1;

    for(int i = 0; i < nDigits; i++){

        switch (*pBand)
        {
        case 'B': case 'b':
            *pDigit = 0;
            break;
        case 'N': case 'n':
            *pDigit = 1;
            break;
        case 'R': case 'r':
            *pDigit = 2;
            break;
        case 'O': case 'o':
            *pDigit = 3;
            break;
        case 'Y': case 'y':
            *pDigit = 4;
            break;
        case 'G': case 'g':
            *pDigit = 5;
            break;
        case 'E': case 'e':
            *pDigit = 6;
            break;
        case 'V': case 'v':
            *pDigit = 7;
            break;
        case 'A': case 'a':
            *pDigit = 8;
            break;
        case 'W': case 'w':
            *pDigit = 9;
            break;
        default:
            *pValid = 0;
            if(i == 1){
                printf("Invalid input for 1st, 2nd or 3rd digit!\n");    
            }  
            break;
        }

        // adds 1 to the memory address to iterate to the next variable
        pDigit++;

        // subtracts 1 to the memory address to iterate to the next variable
        pBand--;

    }

    if(nDigits == 2)
    {
        return (nDigit1 * 10) + (nDigit2);
    }
    else if(nDigits == 3)
    {
        return (nDigit1 * 100) + (nDigit2 * 10) + (nDigit3);
    }
    else
    {
        return 0;
    }
}

float computeResistorVal(int nDigit123, char *pBand)
{
    float fMultiplier;

    switch (*pBand)
        {
        case 'B': case 'b':
            fMultiplier = 1;
            break;
        case 'N': case 'n':
            fMultiplier = 10;
            break;
        case 'R': case 'r':
            fMultiplier = 100;
            break;
        case 'O': case 'o':
            fMultiplier = 1000;
            break;
        case 'Y': case 'y':
            fMultiplier = 10000;
            break;
        case 'G': case 'g':
            fMultiplier = 100000;           
            break;
        case 'E': case 'e':
            fMultiplier = 1000000;        
            break;
        case 'D': case 'd':
            fMultiplier = 0.1;
            break;
        case 'S': case 's':
            fMultiplier = 0.01;
            break;
        default:
            fMultiplier = 0;
            break;

    }

    return nDigit123 * fMultiplier;
}

float computeTolerance(char *pBand)
{

    switch (*pBand)
        {
        case 'N': case 'n':
            return 0.01;
            break;
        case 'R': case 'r':
            return 0.02;
            break;
        case 'G': case 'g':
            return 0.005;      
            break;
        case 'E': case 'e':
            return 0.0025; 
            break;
        case 'V': case 'v':
            return 0.0001;     
            break;
        case 'D': case 'd':
            return 0.05; 
            break;
        case 'S': case 's':
            return 0.10; 
            break;
        default:    
            return 0;
            break;
        }
}

int computeTempCoefficient(char *pBand){

    switch (*pBand)
        {
        case 'B': case 'b':
            return 250; 
            break;
        case 'N': case 'n':
            return 100 ;
            break;
        case 'R': case 'r':
            return 50; 
            break;
        case 'O': case 'o':
            return 15; 
            break;
        case 'Y': case 'y':
            return 25; 
            break;
        case 'G': case 'g':
            return 20;            
            break;
        case 'E': case 'e':
            return 10;         
            break;
        case 'V': case 'v':
            return 5;       
            break;
        case 'A': case 'a':
            return 1; 
            break;
        default:
            return 0;
            break;
        }
}

float rangeLowerBound(float fResistorVal, float fTolerance)
{
    return fResistorVal - (fResistorVal * fTolerance);
}

float rangeUpperBound(float fResistorVal, float fTolerance)
{
    return fResistorVal + (fResistorVal * fTolerance);
}

void output(float fResistorVal, int nDigit123, float fTolerance)
{
    if(fResistorVal == 0)
    {
        printf("Invalid Multiplier Band!\n");
    }
    else
    {  
        if(fTolerance == 0)
        {
            printf("Invalid Tolerance Value\n");
        }
        else
        {
            printf("Resistor Value is %s%.2f%s ohms with a tolerance of %s%.2f%%%s\n", 
                    SWHITEBOLD,
                    fResistorVal,
                    SRESET,
                    SWHITEBOLD,
                    fTolerance*100,
                    SRESET);
            printf("Resistance Range Value: %s%.2f%s ohms to %s%.2f%s ohms\n",
                    SWHITEBOLD,
                    rangeLowerBound(fResistorVal, fTolerance),
                    SRESET, 
                    SWHITEBOLD,
                    rangeUpperBound(fResistorVal, fTolerance),
                    SRESET);
            if(fResistorVal > 1000000)
            {
                printf("%sWarning! This value is above 100 Mega-ohms. No Practical Application! %s\n",
                        SREDBOLD,
                        SRESET);
            }
        }
    }
}

void sixBandOutput(int nTempCoefficient){

    if (nTempCoefficient == 0)
    {
        printf("Invalid Temperature Coefficient Value\n");
    }
    else
    {
        printf("The temperature coefficient is %s%dppm/K%s\n", 
                SWHITEBOLD,
                nTempCoefficient,
                SRESET);
    }

}

int main()
{

    char cBand1, cBand2, 
         cBand3, cBand4, 
         cBand5, cBand6;

    int nDigit123;
    float fResistorVal;
    float fTolerance;
    int nTempCoefficient = 0;

    char cFormat;
    int nValid = 1;

    welcomeLine();

    askMode(&cFormat);

    if(cFormat == '0')
    {
        perLineInput(&nValid, &cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
    else if (cFormat == '1')
    {
        oneLineInput(&nValid, &cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }

    if(nValid == 0)
    {
        printf("Please use a valid input");
    }
    else
    {
        // flow if only 4 bands
        if((cBand5 == 'Z' || cBand5 == 'z') && 
            (cBand6 == 'Z' || cBand6 =='z') )
        {
            nDigit123 = compute1stDigits(&cBand1, &nValid, 2);
            fResistorVal = computeResistorVal(nDigit123, &cBand3);
            fTolerance = computeTolerance(&cBand4);

            output(fResistorVal, nDigit123, fTolerance);
        }
        // flow if only 5 bands
        else if((cBand6 == 'Z') || (cBand6 == 'z'))
        {
            nDigit123 = compute1stDigits(&cBand1, &nValid, 3);
            fResistorVal = computeResistorVal(nDigit123, &cBand4);
            fTolerance = computeTolerance(&cBand5);

            output(fResistorVal, nDigit123, fTolerance);
        }
        // flow if there are 6 bands
        else
        {
            nDigit123 = compute1stDigits(&cBand1, &nValid, 3);
            fResistorVal = computeResistorVal(nDigit123, &cBand4);
            fTolerance = computeTolerance(&cBand5);
            nTempCoefficient = computeTempCoefficient(&cBand6);

            output(fResistorVal, nDigit123, fTolerance);
            sixBandOutput(nTempCoefficient);
        }
    }

    return 0;
}

