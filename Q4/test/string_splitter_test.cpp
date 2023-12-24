#include <gtest/gtest.h>
#include "../include/string_splitter.h"

TEST(StringSplitterTest, SplitString) {
    int count;
    char **result = splitString("Hello,World,Test", ',', &count);
    EXPECT_EQ(count, 3);
    EXPECT_STREQ(result[0], "Hello");
    EXPECT_STREQ(result[1], "World");
    EXPECT_STREQ(result[2], "Test");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, NoDelimiter) {
    int count;
    char **result = splitString("HelloWorld", ',', &count);
    EXPECT_EQ(count, 1);
    EXPECT_STREQ(result[0], "HelloWorld");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithMultipleDelimiters) {
    int count;
    char **result = splitString("Hello,,World,,Test", ',', &count);
    EXPECT_EQ(count, 5);
    EXPECT_STREQ(result[0], "Hello");
    EXPECT_STREQ(result[1], "");
    EXPECT_STREQ(result[2], "World");
    EXPECT_STREQ(result[3], "");
    EXPECT_STREQ(result[4], "Test");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithDelimiterAtStart) {
    int count;
    char **result = splitString(",Hello,World,Test", ',', &count);
    EXPECT_EQ(count, 4);
    EXPECT_STREQ(result[0], "");
    EXPECT_STREQ(result[1], "Hello");
    EXPECT_STREQ(result[2], "World");
    EXPECT_STREQ(result[3], "Test");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithDelimiterAtEnd) {
    int count;
    char **result = splitString("Hello,World,Test,", ',', &count);
    EXPECT_EQ(count, 4);
    EXPECT_STREQ(result[0], "Hello");
    EXPECT_STREQ(result[1], "World");
    EXPECT_STREQ(result[2], "Test");
    EXPECT_STREQ(result[3], "");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitEmptyString) {
    int count;
    char **result = splitString("", ',', &count);
    EXPECT_EQ(count, 1);
    EXPECT_STREQ(result[0], "");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringAllDelimiters) {
    int count;
    char **result = splitString(",,,", ',', &count);
    EXPECT_EQ(count, 4);
    for (int i = 0; i < count; ++i) {
        EXPECT_STREQ(result[i], "");
    }
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithMixedDelimiters) {
    int count;
    char **result = splitString("Apple;Orange-Banana/Grape", '-', &count);
    EXPECT_EQ(count, 2);
    EXPECT_STREQ(result[0], "Apple;Orange");
    EXPECT_STREQ(result[1], "Banana/Grape");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithWordsAndSpaces) {
    int count;
    char **result = splitString("One Two Three", ' ', &count);
    EXPECT_EQ(count, 3);
    EXPECT_STREQ(result[0], "One");
    EXPECT_STREQ(result[1], "Two");
    EXPECT_STREQ(result[2], "Three");
    freeSubstrings(result, count);
}

TEST(StringSplitterTest, SplitStringWithNoMatchingDelimiter) {
    int count;
    char **result = splitString("HelloWorld", 'x', &count);
    EXPECT_EQ(count, 1);
    EXPECT_STREQ(result[0], "HelloWorld");
    freeSubstrings(result, count);
}
