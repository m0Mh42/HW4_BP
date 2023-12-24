#include <gtest/gtest.h>
#include "../include/concatenate_string.h"

TEST(ConcatStringTest, Test1) {
    char* str1 = "Rick";
    char* str2 = "Novak";
    char* res = concatenate_and_manipulate(str1, str2);
    EXPECT_STREQ(res, "Rick_Novak");
}

TEST(ConcatStringTest, Test2) {
    char* str1 = "Matthew";
    char* str2 = "Perry";
    char* res = concatenate_and_manipulate(str1, str2);
    EXPECT_STREQ(res, "Matthew_Perry");
}