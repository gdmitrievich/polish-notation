#include "parser.h"

#include <cstddef>
#include <string>

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
} // namespace polish_notation::parser