#ifndef USER_OPERATIONS_H
#define USER_OPERATIONS_H

void read_backup_file(char ***stored_data, int *size, const char *backup_file_name);
void write_backup_file(char **stored_data, int size, const char *backup_file_name);
void show_users(char **stored_data, int size);
void new_user(char ***stored_data, int *size, const char *user_name, const char *email, const char *password);
void delete_user(char ***stored_data, int *size, const char *user_name);
void email_cnt(char **stored_data, int size);
void end_program(char ***stored_data, int size);
void format_username(char **name);

#endif // USER_OPERATIONS_H