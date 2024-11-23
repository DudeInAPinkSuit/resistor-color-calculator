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

/*
    Description:  Resistor Color Calculator
    Programmed by: Nono, Alec Marx Gabriel B.
    Last modified: November 18, 2024
    Version: v1.16
    [Acknowledgements: Stack Overflow, w3schools, YouTube, GitHub]
*/

#include <stdio.h>

// constants for colored text
#define SRESET     "\e[0m"
#define SBOLD      "\e[39;49;1m"
#define SWHITEBOLD "\e[1;38;5;255m"
#define SREDBOLD   "\e[1;38;5;196m"

#define SBLACK    "\e[1;38;5;16;48;5;15mblack\e[39;0m"
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

/*
    Welcome lines with proper formatting; shows Key Legend
    Precondition: Program has just started
*/

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

    printf("%37s%16s\n", SBLACK, "B or b");
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
/*
    Asks the format of user input
    Precondition: welcomeLine() has already been called
    @param pFormat is used to store the state of the chosen mode
*/
void askMode(char *pFormat)
{
    do{
        printf("Per-line mode [0] or One-liner mode [1]\t: ");
        scanf(" %c%*[^\n]",pFormat);

        if (*pFormat != '0' && *pFormat != '1'){
            printf("%sInvalid input. Please enter 0 or 1.%s \n", SREDBOLD, SRESET);
        }

    } while (*pFormat != '0' && *pFormat != '1');
}

/*
    Prints the user-entered bands
    Precondition: the characters used to represent the bands have been entered by the user
    @param nValid used to store the state of the validity of user input
    @param pBand1 used to check the band within the variable
    @param pBand2 used to check the band within the variable
    @param pBand3 used to check the band within the variable
    @param pBand4 used to check the band within the variable
    @param pBand5 used to check the band within the variable
    @param pBand6 used to check the band within the variable
*/

void enteredBands(int *nValid, char *pBand1, char *pBand2, 
                  char *pBand3, char *pBand4, 
                  char *pBand5, char *pBand6)
{
    printf("Entered bands: ");

    char* pBand = pBand1;

    for(int i = 0; i <= 5; i++){

        switch (*pBand){
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
/*
    Acquires the bands given through user input within a single line separated by commas
    Precondition: askMode() loop has already been exited
    @param nValid used to store the state of the validity of user input
    @param pBand1 used to store the inputted character by the user
    @param pBand2 used to store the inputted character by the user
    @param pBand3 used to store the inputted character by the user
    @param pBand4 used to store the inputted character by the user
    @param pBand5 used to store the inputted character by the user
    @param pBand6 used to store the inputted character by the user
*/
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
/* 
    Acquires the bands given through user input one by one
    Precondition: askMode() loop has already been exited; input mode has been decided
    @param nValid used to store the state of the validity of user input
    @param pBand1 used to store the inputted character by the user
    @param pBand2 used to store the inputted character by the user
    @param pBand3 used to store the inputted character by the user
    @param pBand4 used to store the inputted character by the user
    @param pBand5 used to store the inputted character by the user
    @param pBand6 used to store the inputted character by the user
*/
void perLineInput(int *nValid, char *pBand1, char *pBand2, 
                  char *pBand3, char *pBand4, 
                  char *pBand5, char *pBand6)
{
    printf("Enter the color bands\n");
    printf("1st band: ");
    scanf(" %c%*[^\n]", pBand1);
    printf("2nd band: ");
    scanf(" %c%*[^\n]", pBand2);
    printf("3rd band: ");
    scanf(" %c%*[^\n]", pBand3);
    printf("4th band: ");
    scanf(" %c%*[^\n]", pBand4);
    printf("5th band: ");
    scanf(" %c%*[^\n]", pBand5);
    printf("6th band: ");
    scanf(" %c%*[^\n]", pBand6);

    enteredBands(nValid, pBand1, pBand2, 
                 pBand3, pBand4, 
                 pBand5, pBand6);
}
/*
    Computes for the significant digits of the resistance
    Precondition: Either perLineInput() or oneLineInput()
                  have been called
    @param pValid used to store the state of the validity of user input
    @param pBand1 used to store the inputted character by the user
    @param nDigits identifies the number of significant 
           digits in a specific resistor
    @return the significant digits of the resistance value
            is returned
*/
int compute1stDigits(char *pBand1, int *pValid, int nDigits)
{

    int nDigit3 = 0;
    int nDigit2 = 0;
    int nDigit1 = 0;

    int *pDigit = &nDigit1;
    char *pBand = pBand1;

    for(int i = 0; i < nDigits; i++){

        switch (*pBand){
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
                printf("%sInvalid input for 1st, 2nd or 3rd digit!%s\n", SREDBOLD, SRESET);    
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

/*
    Computes for the resistance value
    Precondition: The significant digits of the resistance
                  have been computed and stored in a
                  variable in main()
    @param nDigit123 used as the significant digits
    @param pBand used to determine multiplier value
    @return the complete resistance value is returned
*/

float computeResistorVal(int nDigit123, char *pBand)
{
    float fMultiplier;

    switch (*pBand){
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
/*
    Computes for the resistor's tolerance
    Precondition: 3rd or 4th variable contain a
                  character corresponding to a band
    @param pBand used to determine multiplier value
           which is then calculated
    @return a tolerance value is returned
*/
float computeTolerance(char *pBand)
{

    switch (*pBand){
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
/*
    Computes for the temperature coefficient
    Precondition: 6th variable contains a valid 
                  band that isn't set to 'No Band'
    @param pBand used to determine temperature
           coefficient value which is then 
           calculated
    @return a tolerance value is returned
*/
int computeTempCoefficient(char *pBand)
{

    switch (*pBand){
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
/*
    Computes for the lower bound of the resistance
    Precondition: resistance value and tolerance have
                  been computed already
    @param fResistorVal used as a baseline in calculating lower bound
    @param fTolerance used to calculate the deviation in 
           resistance accuracy
    @return a lower bound value is returned
*/
float rangeLowerBound(float fResistorVal, float fTolerance)
{
    return fResistorVal - (fResistorVal * fTolerance);
}
/*
    Computes for the upper bound of the resistance
    Precondition: resistance value and tolerance have
                  been computed already
    @param fResistorVal used as a baseline in calculating upper bound
    @param fTolerance used to calculate the deviation in 
           resistance accuracy
    @return an upper bound value is returned
*/
float rangeUpperBound(float fResistorVal, float fTolerance)
{
    return fResistorVal + (fResistorVal * fTolerance);
}
/*
    Prints pre-formatted output without temperature coefficient
    Precondition: resistance value and tolerance have
                  been computed already;
                  rangeUpperBound() & rangeLowerBound
                  have been declared
    @param fResistorVal used to print out the value
    @param fTolerance used to print out the value
    @param pValid used to store the state of the validity of user input
*/
void output(float fResistorVal, float fTolerance, int *pValid)
{

    if((fTolerance != 0) && (fResistorVal != 0)){

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
        // Warning for resistors above 1000000 ohms
        if(fResistorVal > 1000000){
            printf("%sWarning! This value is above 100 Mega-ohms. No Practical Application! %s\n",
                    SREDBOLD,
                    SRESET);
            *pValid = 0;
        } 

    }
    else if ((fTolerance == 0) && (fResistorVal == 0)){
        printf("%sInvalid Multiplier and Tolerance Band!%s\n", SREDBOLD, SRESET); 
        *pValid = 0;
    }
    else if (fResistorVal == 0){
        printf("%sInvalid Multiplier Band!%s\n", SREDBOLD, SRESET);
        *pValid = 0;
    }
    else{
        printf("%sAn error has occurred%s", SREDBOLD, SRESET);
        *pValid = 0;
    }

}
/*
    Prints temperature coefficient value for 6 band 
    Precondition: resistance value and tolerance have
                  been computed and printed already;
    @param nTempCoefficient used to print out the value
                            and checks if value exists
*/
void sixBandOutput(int nTempCoefficient)
{

    if ((nTempCoefficient == 0)){
        printf("%sInvalid Temperature Coefficient Value%s\n", SREDBOLD, SRESET);
    }
    else{
        printf("The temperature coefficient is %s%dppm/K%s\n", 
                SWHITEBOLD,
                nTempCoefficient,
                SRESET);
    }

}

int main()
{

    // initializes variables for storing characters with corresponding bands
    char cBand1, cBand2, 
         cBand3, cBand4, 
         cBand5, cBand6;

    int nDigit123; // stores the significant digits of the resistance
    float fResistorVal; // stores final stores resistance value
    float fTolerance; // stores tolerance
    int nTempCoefficient = 0; // stores temperature coefficient; 0 by default

    char cFormat; // stores either 1 or 0; for the format of user input
    int nValid = 1; // stores either 1 or 0; checks the validity of the program flow

    welcomeLine(); // shows welcome text

    askMode(&cFormat); // asks for input mode


    // executes the corresponding input mode 
    if(cFormat == '0'){

        perLineInput(&nValid, &cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
    else if (cFormat == '1'){

        oneLineInput(&nValid, &cBand1, &cBand2, 
                     &cBand3, &cBand4, 
                     &cBand5, &cBand6);
    }
 
    if(nValid == 0){
        printf("%sPlease use a valid input%s", SREDBOLD, SRESET);
    }
    else{
        // flow if only 4 bands
        if((cBand5 == 'Z' || cBand5 == 'z') && 
           (cBand6 == 'Z' || cBand6 == 'z')){

            nDigit123 = compute1stDigits(&cBand1, &nValid, 2);
            fResistorVal = computeResistorVal(nDigit123, &cBand3);
            fTolerance = computeTolerance(&cBand4);

            output(fResistorVal, fTolerance, &nValid);
        }
        // flow if only 5 bands
        else if((cBand6 == 'Z') || (cBand6 == 'z')){

            nDigit123 = compute1stDigits(&cBand1, &nValid, 3);
            fResistorVal = computeResistorVal(nDigit123, &cBand4);
            fTolerance = computeTolerance(&cBand5);

            output(fResistorVal, fTolerance, &nValid);
        }
        // flow if there are 6 bands
        else{

            nDigit123 = compute1stDigits(&cBand1, &nValid, 3);
            fResistorVal = computeResistorVal(nDigit123, &cBand4);
            fTolerance = computeTolerance(&cBand5);
            nTempCoefficient = computeTempCoefficient(&cBand6);

            output(fResistorVal, fTolerance, &nValid);
            if(nValid)
                sixBandOutput(nTempCoefficient);
        }
    }

    return 0;
}

