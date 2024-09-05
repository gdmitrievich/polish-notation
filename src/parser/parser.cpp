#include "parser.h"

#include <cstddef>
#include <string>

namespace polish_notation::parser {
using std::string;

string getLineWithoutSpaces(const string& line) {
    string newLine;
    if (!line.empty() && line.find_first_not_of(" ", 0) != std::string::npos) {
        size_t l {}, r {};
        do {
            l = r;
            l = line.find_first_not_of(" ", l);
            r = line.find_first_of(" ", l + 1);
            if (l != std::string::npos)
                newLine.append(line.substr(l, r - l));
        } while (r != std::string::npos && l != std::string::npos);
    }

    return newLine;
}
} // namespace polish_notation::parser