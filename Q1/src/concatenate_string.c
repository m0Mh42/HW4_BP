#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for character type functions

char *concatenate_and_manipulate(char *str1, char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char *fullname = (char *)malloc((len1 + len2 + 2) * sizeof(char)); // the + 2 is for "_" and \0

    strcpy(fullname, str1);
    strcat(fullname, "_");
    strcat(fullname, str2);

    return fullname;
}