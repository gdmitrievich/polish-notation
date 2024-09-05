#include "parser.h"

#include <cstddef>
#include <string>

namespace polish_notation::parser {
using std::string;

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
} // namespace polish_notation::parser