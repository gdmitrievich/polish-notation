#ifndef UTILITY_H
#define UTILITY_H

#include <termios.h>
#include <unistd.h>

#include <experimental/source_location>
#include <string>

namespace polish_notation::utility {
using size_t = decltype(sizeof(1));

inline ::std::string debugTrace(
    const ::std::string& what,
    ::std::experimental::source_location src =
        ::std::experimental::source_location::current()) {
    return what + " From: " + src.file_name() + ":" +
           std::to_string(src.line());
}

namespace console::raw_mode {
static struct termios original;

inline void setRawMode() {
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    tcgetattr(STDIN_FILENO, &original);
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
}

inline void resetMode(struct termios& original) {
    tcsetattr(STDIN_FILENO, TCSANOW, &original);
}
} // namespace console::raw_mode
} // namespace polish_notation::utility

namespace pn_u = polish_notation::utility;
namespace pn_u_c_rm = polish_notation::utility::console::raw_mode;

#endif // UTILITY_H