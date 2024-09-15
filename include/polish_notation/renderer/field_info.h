#ifndef FIELD_INFO_H
#define FIELD_INFO_H

#include <utility>

namespace polish_notation::renderer {
struct FieldInfo {
    int width;
    int height;
    ::std::pair<double, double> domain; // Область определения.
    ::std::pair<double, double> codomain; // Область значений.
    ::std::pair<int, int> centerOfCoordinates;
};
} // namespace polish_notation::renderer

#endif // FIELD_INFO_H