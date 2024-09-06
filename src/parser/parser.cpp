#include "parser.h"

#include <cstddef>
#include <string>
#include <cstring>
#include <cctype>

namespace polish_notation::parser {
using std::string;

using polish_notation::data_structures::queue::Queue;
using polish_notation::token::Token;

string getLineWithoutSpaces(const string& line) {
    auto stn = std::string::npos;

    string newLine;
    if (!line.empty() && line.find_first_not_of(" ", 0) != stn) {
        size_t l {}, r {};
        do {
            l = r;
            l = line.find_first_not_of(" ", l);
            r = line.find_first_of(" ", l + 1);
            if (l != stn)
                newLine.append(line.substr(l, r - l));
        } while (r != stn && l != stn);
    }

    return newLine;
}

bool trySetTokenQueueFromStr(Queue<Token>& tokenQueue, const string& str) {
	bool state = true;
	const char* cStr = str.c_str();
	int indent {};
	Token token(Token::Id::x);
	while(*cStr && state) {
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
	int indent {};
	if (isdigit(*str)) {
		double n {};
		indent = setNumberFromStr(n, str);
		token = Token(n);
	} else if (strncmp(str, "x", 1)) {
		indent = 1;
		token.id = Token::Id::x;
	} else if (strncmp(str, "+", 1)) {
		indent = 1;
		token = Token(Token::Id::plus, Token::Priority::plus);
	} else if (strncmp(str, "-", 1)) {
		indent = 1;
		token = Token(Token::Id::minus, Token::Priority::minus);
	} else if (strncmp(str, "*", 1)) {
		indent = 1;
		token = Token(Token::Id::mult, Token::Priority::mult);
	} else if (strncmp(str, "/", 1)) {
		indent = 1;
		token = Token(Token::Id::div, Token::Priority::div);
	} else if (strncmp(str, "(", 1)) {
		indent = 1;
		token = Token(Token::Id::lBrace);
	} else if (strncmp(str, ")", 1)) {
		indent = 1;
		token = Token(Token::Id::rBrace);
	} else if (strncmp(str, "sin", 3)) {
		indent = 3;
		token = Token(Token::Id::sin);
	} else if (strncmp(str, "cos", 3)) {
		indent = 3;
		token = Token(Token::Id::cos);
	} else if (strncmp(str, "tan", 3)) {
		indent = 3;
		token = Token(Token::Id::tan);
	} else if (strncmp(str, "ctg", 3)) {
		indent = 3;
		token = Token(Token::Id::ctg);
	} else if (strncmp(str, "sqrt", 4)) {
		indent = 4;
		token = Token(Token::Id::sqrt);
	} else if (strncmp(str, "ln", 2)) {
		indent = 2;
		token = Token(Token::Id::ln);
	} else {
		indent = -1;
	}

	return indent;
}
} // namespace polish_notation::parser