#ifndef INVALID_FIELD_INFO_H
#define INVALID_FIELD_INFO_H

#include <stdexcept>
#include <string>

namespace polish_notation::exceptions {
class InvalidFieldInfoException : public ::std::runtime_error {
   public:
    enum class ErrType : char {
        NegativeOrZeroWidth,
        NegativeOrZeroHeigth,
        InvalidDomain,
        InvalidCodomain
    };

    InvalidFieldInfoException(ErrType errType,
                              const ::std::string& message) noexcept;

    ErrType getErrType() const noexcept;

   private:
    ErrType errType_;
};
} // namespace polish_notation::exceptions

#endif // INVALID_FIELD_INFO_H