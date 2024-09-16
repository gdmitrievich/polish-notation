#ifndef UTILITY_H
#define UTILITY_H

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
} // namespace polish_notation::utility

namespace pn_u = polish_notation::utility;

#endif // UTILITY_H