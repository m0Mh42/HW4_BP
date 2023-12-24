#include <gtest/gtest.h>
#include "../include/user_operations.h"

// Test 1
TEST(UserOperations, TEST1) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output =
        "Amir_Jahanshahi\n"
        "Saharnaz_Eslami\n"
        "Bardia_Sahami\n"
        "Pouya_Sharifi\n"
        "Reza_Shahariari\n"
        "Mehrdad_Aflakparast\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
}

// Test 2

TEST(UserOperations, TEST2) {
    const char *backup_file_name = "test_backup.txt";
    const char *backup_content =
        "Lincoln_Huffman L.Huffman@gmail.com 12344321\n"
        "GALE_David gdavid1991@yahoo.com 12344321\n"
        "Danielle_Willis WILLISSS@gmail.com 12344321\n"
        "brian_smith b.3.smith@hotmail.com 12344321\n";

    FILE *backup_file = fopen(backup_file_name, "w");
    ASSERT_TRUE(backup_file != nullptr);
    fprintf(backup_file, "%s", backup_content);
    fclose(backup_file);


    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);


    testing::internal::CaptureStdout();
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output =
        "Lincoln_Huffman\n"
        "Gale_David\n"
        "Danielle_Willis\n"
        "Brian_Smith\n";
    ASSERT_EQ(output, expected_output);


    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
    remove(backup_file_name);
} 

// Test 3
TEST(UserOperations, TEST3) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "ALI_REZAEI";
    const char *password = "12344321";
    const char *email = "ali_rezaei@aut.ac.ir";
    new_user(&stored_data, &size, user_name, email, password);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output = "New user added!\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
}


// Test 4
TEST(UserOperations, TEST4) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "ALI_REZAEI";
    const char *password = "12344321";
    const char *email = "ali_rezaei@aut.ac.ir";
    new_user(&stored_data, &size, user_name, email, password);
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output = 
        "New user added!\n"
        "Amir_Jahanshahi\n"
        "Saharnaz_Eslami\n"
        "Bardia_Sahami\n"
        "Pouya_Sharifi\n"
        "Reza_Shahariari\n"
        "Mehrdad_Aflakparast\n"
        "Ali_Rezaei\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
}

// Test 5
TEST(UserOperations, TEST5) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "Amir_Jahanshahi";
    const char *password = "12344321";
    const char *email = "a_j@aut.ac.ir";
    new_user(&stored_data, &size, user_name, email, password);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output = "User already exists!\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);

}


// Test 6
TEST(UserOperations, TEST6) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "Amir_Jahanshahi";
    const char *password = "12344321";
    const char *email = "a_j@aut.ac.ir";
    new_user(&stored_data, &size, user_name, email, password);
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected_output = 
        "User already exists!\n"
        "Amir_Jahanshahi\n"
        "Saharnaz_Eslami\n"
        "Bardia_Sahami\n"
        "Pouya_Sharifi\n"
        "Reza_Shahariari\n"
        "Mehrdad_Aflakparast\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);

}

// Test 7
TEST(UserOperations, TEST7) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    // FILE *backup_file = fopen(backup_file_name, "r"); TBD
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "Amir_Jahanshahi";
    delete_user(&stored_data, &size, user_name);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "User deleted!\n";
    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
}

// Test 8
TEST(UserOperations, TEST8) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "Amir_Jahanshahi";
    delete_user(&stored_data, &size, user_name);
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = 
        "User deleted!\n"
        "Saharnaz_Eslami\n"
        "Bardia_Sahami\n"
        "Pouya_Sharifi\n"
        "Reza_Shahariari\n"
        "Mehrdad_Aflakparast\n";


    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);

}

// Test 9
TEST(UserOperations, TEST9) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    const char *user_name = "Ali_Rezaei";
    delete_user(&stored_data, &size, user_name);
    show_users(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = 
        "User not found!\n"
        "Amir_Jahanshahi\n"
        "Saharnaz_Eslami\n"
        "Bardia_Sahami\n"
        "Pouya_Sharifi\n"
        "Reza_Shahariari\n"
        "Mehrdad_Aflakparast\n";

    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);

}

// Test 10
TEST(UserOperations, TEST10) {
    const char *backup_file_name = "resources/HW4_Datasets.txt";
    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);

    testing::internal::CaptureStdout();
    email_cnt(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = 
    "Yahoo: 2\n"
    "Gmail: 2\n"
    "AUT: 1\n"
    "Hotmail: 1\n"
    "Others: 0\n";

    ASSERT_EQ(output, expected_output);

    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
}

// Test 11
TEST(UserOperations, TEST11) {
    const char *backup_file_name = "test_backup.txt";
    const char *backup_content =
        "Lincoln_Huffman L.Huffman@gmail.com 12344321\n"
        "GALE_David gdavid1991@yahoo.com 12344321\n"
        "Danielle_Willis WILLISSS@gmail.com 12344321\n"
        "brian_smith b.3.smith@outlook.com 12344321\n";

    FILE *backup_file = fopen(backup_file_name, "w");
    ASSERT_TRUE(backup_file != nullptr);
    fprintf(backup_file, "%s", backup_content);
    fclose(backup_file);


    char **stored_data;
    int size = 0;
    read_backup_file(&stored_data, &size, backup_file_name);


    testing::internal::CaptureStdout();
    email_cnt(stored_data, size);
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = 
    "Yahoo: 1\n"
    "Gmail: 2\n"
    "AUT: 0\n"
    "Hotmail: 0\n"
    "Others: 1\n";
    ASSERT_EQ(output, expected_output);


    for (int i = 0; i < size; ++i) {
        free(stored_data[i]);
    }
    free(stored_data);
    remove(backup_file_name);
} 
