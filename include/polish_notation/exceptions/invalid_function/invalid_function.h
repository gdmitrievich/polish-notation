#ifndef INVALID_FUNCTION
#define INVALID_FUNCTION

#include <stdexcept>
#include <string>

namespace polish_notation::exceptions {
class InvalidFunction : public ::std::runtime_error {
   public:
    enum class ErrType : char {
        LBraceNotFound,
        RBraceNotFound,
        OperatorsAreLessThenOperands,
        FunctionWithoutArg,
        BinaryOperatorWithoutTwoOperands,
        InvalidToken
    };

    InvalidFunction(ErrType errType, const ::std::string& message) noexcept;

    ErrType getErrType() const noexcept;

   private:
    ErrType errType_;
};
} // namespace polish_notation::exceptions

namespace pn_e = polish_notation::exceptions;

#endif // INVALID_FUNCTION