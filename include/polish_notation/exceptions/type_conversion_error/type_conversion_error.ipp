#include "type_conversion_error.h"

namespace polish_notation::exceptions {
inline TypeConversionError::TypeConversionError(const ::std::string& value,
                                                const ::std::string& message) :
    value_(value),
    runtime_error(message) {}

inline ::std::string TypeConversionError::getValue() const noexcept {
    return value_;
}
} // namespace polish_notation::exceptions
