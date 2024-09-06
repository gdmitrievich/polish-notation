#include "../../../src/parser/parser.h"

#include <gtest/gtest.h>

using namespace polish_notation::parser;
using std::string;

// getLineWithoutSpaces tests.
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

// setNumberFromStr tests.
TEST(SetNumberFromStrTests, PassNullptrStr) {
    const char* src = nullptr;
    double expectedNumber = 0.;
    int expectedIndent = 0;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassEmptyStr) {
    const char* src = "";
    double expectedNumber = 0.;
    int expectedIndent = 0;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithIntegerDigit) {
    const char* src = "5";
    double expectedNumber = 5.;
    int expectedIndent = 1;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithIntegerDigits) {
    const char* src = "555";
    double expectedNumber = 555.;
    int expectedIndent = 3;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithIntegerDigitsInTheBeginning) {
    const char* src = "555abc";
    double expectedNumber = 555.;
    int expectedIndent = 3;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithDoubleNumber) {
    const char* src = "5.5";
    double expectedNumber = 5.5;
    int expectedIndent = 3;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithTwoFractionParts) {
    const char* src = "55.5.55";
    double expectedNumber = 55.5;
    int expectedIndent = 4;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithNonDigitsAtTheEnd) {
    const char* src = "55.55abc";
    double expectedNumber = 55.55;
    int expectedIndent = 5;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

TEST(SetNumberFromStrTests, PassLineWithNumberWithTheroesAtTheBeginning) {
    const char* src = "005.005abc";
    double expectedNumber = 5.005;
    int expectedIndent = 7;
    double result {};

    int indent = setNumberFromStr(result, src);

    EXPECT_EQ(result, expectedNumber);
    EXPECT_EQ(indent, expectedIndent);
}

// convertStrPartToDouble tests.
TEST(ConvertStrPartToDoubleTests, PassNullptrStr) {
    const char* src = nullptr;
    double expected = 0.;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassEmptyLine) {
    const char* src = "";
    double expected = 0.;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithOnlyIntegerDigits) {
    const char* src = "555";
    double expected = 555.;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithOnlyDoubleDigits) {
    const char* src = "555.55";
    double expected = 555.55;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithOneDigitInIntPart) {
    const char* src = "0.555";
    double expected = 0.555;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithOneDigitInFractPart) {
    const char* src = "555.5";
    double expected = 555.5;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithTheroesAtTheFractPart) {
    const char* src = "5.000";
    double expected = 5.;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithTheroesInIntAndFractPart) {
    const char* src = "0.0";
    double expected = 0.;

    double result = convertStrPartToDouble(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithDigitsAndSymbolsAtTheBeginning) {
    const char* src = "abc555.55";
    double expected = 555.55;

    double result = convertStrPartToDouble(src + 3);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests, PassLineWithDigitsAndSymbolsAtTheEnd) {
    const char* src = "555.5cba";
    double expected = 555.5;

    double result = convertStrPartToDouble(src, 5);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToDoubleTests,
     PassLineWithDigitsAndSymbolsAtTheBeginningAndTheEnd) {
    const char* src = "abc555.555cba";
    double expected = 555.555;

    double result = convertStrPartToDouble(src + 3, 7);

    EXPECT_EQ(result, expected);
}

// convertStrPartToInt tests.
TEST(ConvertStrPartToIntTests, PassNullptrStr) {
    const char* src = nullptr;
    int expected = 0;

    int result = convertStrPartToInt(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests, PassEmptyLine) {
    const char* src = "";
    int expected = 0;

    int result = convertStrPartToInt(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests, PassLineWithOnlyDigits) {
    const char* src = "555";
    int expected = 555;

    int result = convertStrPartToInt(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests, PassLineWithTheroesAtTheBeginning) {
    const char* src = "005";
    int expected = 5;

    int result = convertStrPartToInt(src);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests, PassLineWithDigitsAndSymbolsAtTheBeginning) {
    const char* src = "abc555";
    int expected = 555;

    int result = convertStrPartToInt(src + 3);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests, PassLineWithDigitsAndSymbolsAtTheEnd) {
    const char* src = "555cba";
    int expected = 555;

    int result = convertStrPartToInt(src, 3);

    EXPECT_EQ(result, expected);
}

TEST(ConvertStrPartToIntTests,
     PassLineWithDigitsAndSymbolsAtTheBeginningAndTheEnd) {
    const char* src = "abc555cba";
    int expected = 555;

    int result = convertStrPartToInt(src + 3, 3);

    EXPECT_EQ(result, expected);
}