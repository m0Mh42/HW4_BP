#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/user_operations.h"

// #define MAX_USER_DATA_LENGTH 100

void read_backup_file(char ***stored_data, int *size, const char *backup_file_name) {
    // Open the file

    // Count the number of users in the file


    // Rewind the file to the beginning


    // Allocate memory for stored_data


    // Read user data from the file
}
void show_users(char **stored_data, int size) {
    // Extract the user name from the stored data

    // Capitalize the first letter of each word in the user name

    // Print the formatted user name

}

void new_user(char ***stored_data, int *size, const char *user_name, const char *email, const char *password) {
    // Check if the user already exists


    // Allocate memory for the new user data


    // Format the new user data


    // Resize the stored_data array


    // Add the new user data

}

void delete_user(char ***stored_data, int *size, const char *user_name) {
    // Free memory for the deleted user data


    // Shift the remaining users to fill the gap


    // Resize the stored_data array
}

void email_cnt(char **stored_data, int size) {
    // Code here
}


void end_program(char ***stored_data, int size) {
    // Code Here
}