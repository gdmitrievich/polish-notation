#include "parser.h"

#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

namespace polish_notation::parser {
using std::string;

using polish_notation::data_structures::queue::Queue;
using polish_notation::token::Token;

string getLineWithoutSpaces(const string& line) {
    auto stn = std::string::npos;

    if (line.empty() || line.find_first_not_of(" ", 0) == stn)
        return string();

    string newLine;
    size_t l {}, r {};
    do {
        l = r;
        l = line.find_first_not_of(" ", l);
        r = line.find_first_of(" ", l + 1);
        if (l != stn)
            newLine.append(line.substr(l, r - l));
    } while (r != stn && l != stn);

    return newLine;
}

bool trySetTokenQueueFromStr(Queue<Token>& tokenQueue, const string& str) {
    bool state = true;
    const char* cStr = str.c_str();
    int indent {};
    Token token(Token::Id::x);
    while (*cStr && state) {
        indent = trySetTokenFromStr(token, cStr);
        if (indent != -1) {
            cStr += indent;
            tokenQueue.enqueue(token);
        } else {
            state = false;
        }
    }

    return state;
}

int trySetTokenFromStr(Token& token, const char* str) {
    if (!str)
        return -1;

    int indent {};
    if (isdigit(*str)) {
        double n {};
        indent = setNumberFromStr(n, str);
        token = Token(n);
    } else if (!strncmp(str, "x", 1)) {
        indent = 1;
        token.id = Token::Id::x;
    } else if (!strncmp(str, "+", 1)) {
        indent = 1;
        token = Token(Token::Id::plus, Token::Priority::plus);
    } else if (!strncmp(str, "-", 1)) {
        indent = 1;
        token = Token(Token::Id::minus, Token::Priority::minus);
    } else if (!strncmp(str, "*", 1)) {
        indent = 1;
        token = Token(Token::Id::mult, Token::Priority::mult);
    } else if (!strncmp(str, "/", 1)) {
        indent = 1;
        token = Token(Token::Id::div, Token::Priority::div);
    } else if (!strncmp(str, "(", 1)) {
        indent = 1;
        token = Token(Token::Id::lBrace);
    } else if (!strncmp(str, ")", 1)) {
        indent = 1;
        token = Token(Token::Id::rBrace);
    } else if (!strncmp(str, "sin", 3)) {
        indent = 3;
        token = Token(Token::Id::sin);
    } else if (!strncmp(str, "cos", 3)) {
        indent = 3;
        token = Token(Token::Id::cos);
    } else if (!strncmp(str, "tan", 3)) {
        indent = 3;
        token = Token(Token::Id::tan);
    } else if (!strncmp(str, "ctg", 3)) {
        indent = 3;
        token = Token(Token::Id::ctg);
    } else if (!strncmp(str, "sqrt", 4)) {
        indent = 4;
        token = Token(Token::Id::sqrt);
    } else if (!strncmp(str, "ln", 2)) {
        indent = 2;
        token = Token(Token::Id::ln);
    } else {
        indent = -1;
    }

    return indent;
}

int setNumberFromStr(double& number, const char* str) {
    if (!str)
        return 0.;

    size_t intPartLen = getLenOfNumberStr(str);
    const int DOT_LEN = 1;
    size_t fractPartOffset = intPartLen + DOT_LEN;
    size_t fractPartLen {};
    if (hasFractPart(str, intPartLen))
        fractPartLen = getLenOfNumberStr(str + fractPartOffset);

    size_t len = intPartLen + (fractPartLen != 0 ? fractPartLen + DOT_LEN : 0);
    number = convertStrPartToDouble(str, len);

    return len;
}

bool hasFractPart(const char* str, size_t intPartLen) {
    return str[intPartLen] == '.' && isdigit(str[intPartLen + 1]);
}

size_t getLenOfNumberStr(const char* str) {
    if (!str)
        return 0;

    const char* INT_CHARS = "0123456789";
    return strspn(str, INT_CHARS);
}

double convertStrPartToDouble(const char* str, size_t count) {
    if (!str)
        return 0.;

    if (count == (size_t) -1)
        count = strlen(str);

    double n {};
    size_t intPartLen = getLenOfNumberStr(str);
    n = convertStrPartToInt(str, intPartLen);
    if (intPartLen != count) {
        const char* fractPartStr = str + intPartLen + 1;
        size_t fractPartLen = getLenOfNumberStr(fractPartStr);
        n += convertStrPartToInt(fractPartStr, fractPartLen) /
             pow(10, fractPartLen);
    }

    return n;
}

int convertStrPartToInt(const char* str, size_t count) {
    if (!str)
        return 0;

    if (count == (size_t) -1)
        count = strlen(str);

    int n {};
    int power {};
    int digit {};
    while (count > 0) {
        digit = str[count - 1] - '0';
        n += digit * pow(10, power++);
        --count;
    }

    return n;
}
} // namespace polish_notation::parser