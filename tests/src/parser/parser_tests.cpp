#include "../../../src/parser/parser.h"

#include <gtest/gtest.h>

using namespace polish_notation::parser;
using std::string;

TEST(GetLineWithoutSpacesTests, PassEmptyLine) {
    string src("");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, src);
    EXPECT_EQ(result.size(), 0);
}

TEST(GetLineWithoutSpacesTests, PassLineWithoutSpaces) {
    string src("line_without_spaces");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, src);
}

TEST(GetLineWithoutSpacesTests, PassLineOnlyWithSpaces) {
    string src("   ");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result.empty(), true);
}

TEST(GetLineWithoutSpacesTests, PassLineStartsWithSpaces) {
    string src("   line");
    string expected("line");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, expected);
}

TEST(GetLineWithoutSpacesTests, PassLineEndsWithSpaces) {
    string src("line    ");
    string expected("line");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, expected);
}

TEST(GetLineWithoutSpacesTests, PassLineWithSingleSpacesBetweenWords) {
    string src("it's a line with single spaces");
    string expected("it'salinewithsinglespaces");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, expected);
}

TEST(GetLineWithoutSpacesTests,
     PassLineWithSpacesAtTheStartAndEndAndBetweenWords) {
    string src("    it's    a line   with single spaces   ");
    string expected("it'salinewithsinglespaces");

    string result = getLineWithoutSpaces(src);

    EXPECT_EQ(result, expected);
}