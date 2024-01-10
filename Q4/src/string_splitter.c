#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **splitString(const char *input, char delimiter, int *substringCount)
{
    int count = 1;
    char delimiters[] = {delimiter, 0};

    // counting words
    const char *tmp = input;
    while (tmp = strstr(tmp, delimiters))
    {
        count++;
        tmp++;
    }

    // copying input
    char *copy;
    size_t input_len = strlen(input) + 1;
    copy = (char *)malloc(input_len * sizeof(char));
    strcpy(copy, input);

    char **split;
    split = (char **)malloc(count * sizeof(char *));

    // finding words
    char *ptr = copy;
    for (int i = 0; i < count; i++)
    {
        char *p = strpbrk(ptr, delimiters);
        if (p != NULL)
            *p = 0; // null terminating for strcpy
        char *ret = ptr;
        size_t ret_len = strlen(ret) + 1;
        split[i] = (char *)malloc(ret_len * sizeof(char));
        strcpy(split[i], ret);
        ptr = ++p; // continuing word search after the null termination
    }

    *substringCount = count;
    free(copy);
    return split;
}

// free memory
void freeSubstrings(char **substrings, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(substrings[i]);
    }
    free(substrings);
}
