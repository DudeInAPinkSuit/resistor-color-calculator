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
#define SGRAY     "\e[1;38;5;246m"
#define SWHITE    "\e[1;38;5;255m"
#define SGOLD     "\e[1;38;5;178m"
#define SSILVER   "\e[1;38;5;102m"

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



int main(){

    welcomeLine();

   




    return 0;
}