#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

char** splitString(const char *input, char delimiter, int *substringCount) {
    // Hint 1: Count delimiters to determine substring count.
    // Hint 2: extract and allocate memory for each substring.


    // Sample Case 1:
    // Input: "One;Two;Three;Four", delimiter = ';', substringCount points to an integer
    // Expected Output: ["One", "Two", "Three", "Four"]
    // After execution, *substringCount should be updated to 4

    // Sample Case 2:
    // Input: "SingleString", delimiter = ',', substringCount points to an integer
    // Expected Output: ["SingleString"]
    // After execution, *substringCount should be updated to 1

}

void freeSubstrings(char **substrings, int count) {
    // Hint: Free each substring, then free the substring array.

    // Sample Case:
    // Input: Array of substrings ["Hello", "World", "Test"], count = 3
    // Operation: Frees memory for each substring and then the array itself

}


