#ifndef STRING_SPLITTER_H
#define STRING_SPLITTER_H

char** splitString(const char *input, char delimiter, int *substringCount);
void freeSubstrings(char **substrings, int count);

#endif
