#ifndef TYPE_CONVERSION_ERROR_H
#define TYPE_CONVERSION_ERROR_H

#include <stdexcept>
#include <string>

namespace polish_notation::exceptions {
class TypeConversionError : public ::std::runtime_error {
   private:
    ::std::string value_;

   public:
    TypeConversionError(const ::std::string& value,
                        const ::std::string& message);

    ::std::string getValue() const noexcept;
};
} // namespace polish_notation::exceptions

namespace pn_e = polish_notation::exceptions;

#include "type_conversion_error.ipp"

#endif // TYPE_CONVERSION_ERROR_H