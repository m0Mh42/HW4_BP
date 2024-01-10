#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/user_operations.h"

#define MAX_USER_DATA_LENGTH 100
#define MAX_USERNAME_LENGTH 32

void read_backup_file(char ***stored_data, int *size, const char *backup_file_name)
{
    // open file
    FILE *file;
    file = fopen(backup_file_name, "r");

    if (file == NULL)
    {
        perror("FILE ERROR!\n");
        return;
    }

    // read number of users
    while (feof(file) == 0)
    {
        char user[MAX_USER_DATA_LENGTH];
        fgets(user, MAX_USER_DATA_LENGTH, file);
        if (strcmp(user, "\n") != 0 && feof(file) == 0)
            (*size)++;
    }
    // printf("%d\n", *size);

    // rewind for reading user data
    rewind(file);

    // memory allocation
    *stored_data = (char **)malloc((*size) * sizeof(char *));
    for (int i = 0; i < *size; i++)
    {
        // reading user data
        char user[MAX_USER_DATA_LENGTH];
        fgets(user, MAX_USER_DATA_LENGTH, file);

        // if the line contains a user data
        if (strcmp(user, "\n") != 0)
        {
            size_t userlen = strlen(user);
            user[userlen - 1] = 0; // removing the \n character `fgets` will give

            // allocating enough memory
            (*stored_data)[i] = (char *)malloc((userlen) * sizeof(char)); // userlen is `strlen(user) + 1` so null term. is counted
            strncpy((*stored_data)[i], user, userlen - 1);
        }
    }

    // close file
    int ret = fclose(file);
    if (ret == EOF)
    {
        perror("FILE ERROR!\n");
        return;
    }
}

void write_backup_file(char **stored_data, int size, const char *backup_file_name)
{
    // open file
    FILE *file = fopen(backup_file_name, "w");
    if (file == NULL)
    {
        perror("FILE ERROR!\n");
        return;
    }

    // write users
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s\n", stored_data[i]);
    }

    // close file
    int ret = fclose(file);
    if (ret == EOF)
    {
        perror("FILE ERROR!\n");
        return;
    }
}

void format_username(char **username)
{
    // null checking
    if (strlen(*username) < 1)
        return;

    char delimiters[] = "_ ";
    char local_username[MAX_USERNAME_LENGTH + 1];

    char *tok = strtok(*username, delimiters);

    // firstname
    tok[0] = toupper(tok[0]);
    for (size_t i = 1; i < strlen(tok); i++)
    {
        tok[i] = tolower(tok[i]);
    }

    strcpy(local_username, tok);
    strcat(local_username, "_");

    // lastname
    tok = strtok(NULL, delimiters);
    tok[0] = toupper(tok[0]);
    for (size_t i = 1; i < strlen(tok); i++)
    {
        tok[i] = tolower(tok[i]);
    }

    strcat(local_username, tok);

    strcpy(*username, local_username);
}

void show_users(char **stored_data, int size)
{
    char delimiters[] = " ";
    for (int i = 0; i < size; i++)
    {
        char *username = strtok(stored_data[i], delimiters);
        format_username(&username);
        printf("%s\n", username);
    }
}

void new_user(char ***stored_data, int *size, const char *user_name, const char *email, const char *password)
{
    char delimiters[] = " ";
    size_t user_name_len = strlen(user_name);

    // format username for case check
    char *formatted_user_name;
    formatted_user_name = (char *)malloc((user_name_len + 1) * sizeof(char));
    strcpy(formatted_user_name, user_name);

    // username existence check
    for (int i = 0; i < *size; i++)
    {
        char *stored_username = strtok((*stored_data)[i], delimiters);
        format_username(&stored_username);
        format_username(&formatted_user_name);
        if (strcmp(stored_username, user_name) == 0)
        {
            printf("User already exists!\n");
            return;
        }
    }

    // allocating memory for user
    *stored_data = (char **)realloc((void *)*stored_data, (*size + 1) * sizeof(char *));
    size_t data_len = strlen(user_name) + strlen(email) + strlen(password) + 3; // `+3` is for spaces, line feed and null chars.
    (*stored_data)[(*size)] = (char *)malloc(data_len * sizeof(char));

    // creating user
    char user_data[data_len];
    strcpy(user_data, user_name);
    strcat(user_data, " ");
    strcat(user_data, email);
    strcat(user_data, " ");
    strcat(user_data, password);

    strcpy((*stored_data)[(*size)++], user_data);
    printf("New user added!\n");

    free(formatted_user_name);
}

void delete_user(char ***stored_data, int *size, const char *user_name)
{
    char delimiters[] = " ";

    // format username for case check
    size_t user_name_len = strlen(user_name);
    char *formatted_user_name;
    formatted_user_name = (char *)malloc((user_name_len + 1) * sizeof(char));
    strcpy(formatted_user_name, user_name);

    for (int i = 0; i < *size; i++)
    {
        char *stored_username = strtok((*stored_data)[i], delimiters);
        format_username(&stored_username);
        format_username(&formatted_user_name);

        // if user exists delete user
        if (strcmp(stored_username, user_name) == 0)
        {
            for (int j = i + 1; j < *size; j++)
            {
                // shift users in memory
                memmove((*stored_data)[j - 1], (*stored_data)[j], strlen((*stored_data)[j] + 1));
            }
            free((*stored_data)[--(*size)]);
            *stored_data = (char **)realloc(*stored_data, *size * sizeof(char *));
            printf("User deleted!\n");
            break;
        }
        else
        {
            printf("User not found!\n");
            break;
        }
    }
    free(formatted_user_name);
}

void email_cnt(char **stored_data, int size)
{
    size_t count[5];
    memset(count, 0, 5 * sizeof(size_t));

    // email fix properties
    const size_t email_fix_count = 4;
    const char *email_fixes[] = {"@yahoo.com", "@gmail.com", "@aut.ac.ir", "@hotmail.com"};
    const char *email_names[] = {"Yahoo", "Gmail", "AUT", "Hotmail", "Others"};

    for (int i = 0; i < size; i++)
    {
        for (size_t j = 0; j < email_fix_count; j++)
        {
            // looking over each email and fix
            char *email = strstr(stored_data[i], email_fixes[j]);
            if (email != NULL)
            {
                count[j]++;
                break;
            }
            else if (j == 3)
            {
                count[4]++;
                break;
            }
        }
    }

    for (size_t i = 0; i < email_fix_count + 1; i++)
    {
        printf("%s: %ld\n", email_names[i], count[i]);
    }
}

// free memory
void end_program(char ***stored_data, int size)
{
    for (int i = 0; i < size; i++)
    {
        free((*stored_data)[i]);
    }
    free(*stored_data);
}

void cmdline(char *input, char ***stored_data, int *size)
{
    char *command = strtok(input, " ");
    if (strcmp(command, "showusers"))
    {
        show_users(*stored_data, *size);
    }
    else if (strcmp(command, "newuser"))
    {
        char *username = strtok(NULL, " ");
        if (username == NULL)
        {
            printf("No username input.\n");
            return;
        }

        char *email = strtok(NULL, " ");
        if (email == NULL)
        {
            printf("No email input.\n");
            return;
        }

        char *password = strtok(NULL, " ");
        if (password == NULL)
        {
            printf("No password input.\n");
            return;
        }
        new_user(stored_data, size, username, email, password);
    }
    else if (strcmp(command, "deluser"))
    {
        char *username = strtok(NULL, " ");
        if (username == NULL)
        {
            printf("No username input.\n");
            return;
        }
        delete_user(stored_data, size, username);
    }
    else if (strcmp(command, "emailcnt"))
    {
        email_cnt(*stored_data, *size);
    }
    else
    {
        printf("Unknown command.\n");
        return;
    }
}