#include "polish_notation/exceptions/invalid_field_info_exception/invalid_field_info_exception.h"

namespace polish_notation::exceptions {
using f_info = ::polish_notation::renderer::FieldInfo;

InvalidFieldInfoException::InvalidFieldInfoException(
    f_info fInfo, InvalidFieldInfoException::ErrType errType,
    const ::std::string& message) noexcept :
    fInfo_(fInfo),
    errType_(errType),
    runtime_error(message) {}

InvalidFieldInfoException::ErrType InvalidFieldInfoException::getErrType()
    const noexcept {
    return errType_;
}

f_info InvalidFieldInfoException::getFieldInfo() const {
    return fInfo_;
}
} // namespace polish_notation::exceptions