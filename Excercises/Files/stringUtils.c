#include "stringUtils.h"

char* concatString(char* string1, char* string2)
{
    char* finalString = (char*) malloc(strlen(string1) + strlen(string2) + 1);
    if (finalString == NULL) {
        perror("Error when concatenating strings.");
        exit(1);
    }
    strcpy(finalString, string1);
    strcat(finalString, string2);

    return finalString;
}