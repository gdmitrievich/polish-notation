#include "polish_notation/exceptions/invalid_field_info_exception/invalid_field_info_exception.h"

namespace polish_notation::exceptions {
InvalidFieldInfoException::InvalidFieldInfoException(
    InvalidFieldInfoException::ErrType errType,
    const ::std::string& message) noexcept :
    errType_(errType),
    runtime_error(message) {}

InvalidFieldInfoException::ErrType InvalidFieldInfoException::getErrType()
    const noexcept {
    return errType_;
}
} // namespace polish_notation::exceptions