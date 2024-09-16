#include "polish_notation/exceptions/invalid_function/invalid_function.h"

#include "polish_notation/utility/utility.h"

namespace polish_notation::exceptions {
InvalidFunction::InvalidFunction(ErrType errType,
                                 const ::std::string& message) noexcept :
    errType_(errType),
    runtime_error(message) {}

InvalidFunction::ErrType InvalidFunction::getErrType() const noexcept {
    return errType_;
}
} // namespace polish_notation::exceptions