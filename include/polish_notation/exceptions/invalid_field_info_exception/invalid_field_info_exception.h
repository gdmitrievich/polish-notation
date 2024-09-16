#ifndef INVALID_FIELD_INFO_H
#define INVALID_FIELD_INFO_H

#include <stdexcept>
#include <string>

#include "polish_notation/renderer/field_info.h"

namespace polish_notation::exceptions {
class InvalidFieldInfoException : public ::std::runtime_error {
   public:
    enum class ErrType : char {
        NegativeOrZeroWidth,
        NegativeOrZeroHeigth,
        InvalidDomain,
        InvalidCodomain
    };

    InvalidFieldInfoException(::polish_notation::renderer::FieldInfo fInfo,
                              ErrType errType,
                              const ::std::string& message) noexcept;

    ErrType getErrType() const noexcept;
    ::polish_notation::renderer::FieldInfo getFieldInfo() const;

   private:
    ErrType errType_;
    ::polish_notation::renderer::FieldInfo fInfo_;
};
} // namespace polish_notation::exceptions

namespace pn_e = polish_notation::exceptions;

#endif // INVALID_FIELD_INFO_H