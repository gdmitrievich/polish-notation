#include "user_err_mess_printer.h"

#include <iostream>

namespace polish_notation::user_err_mess_printer {
void printErrMess(const ::std::exception& e) {
    if (dynamic_cast<const ::pn_e::InvalidFunction*>(&e)) {
        printInvalidFunctionErrMess(
            dynamic_cast<const ::pn_e::InvalidFunction&>(e));
    } else if (dynamic_cast<const ::pn_e::InvalidFieldInfoException*>(&e)) {
        printInvalidFieldInfoErrMess(
            dynamic_cast<const ::pn_e::InvalidFieldInfoException&>(e));
    } else if (dynamic_cast<const ::pn_e::TypeConversionError*>(&e)) {
        printTypeConversionErrorErrMess(
            dynamic_cast<const ::pn_e::TypeConversionError&>(e));
    }
}

void printInvalidFunctionErrMess(const ::pn_e::InvalidFunction& e) {
    using e_t = ::pn_e::InvalidFunction::ErrType;
    std::cout << "Invalid function: ";

    switch (e.getErrType()) {
        case e_t::LBraceNotFound:
            std::cout << "No closing left parenthesis.";
            break;
        case e_t::RBraceNotFound:
            std::cout << "No closing right parenthesis.";
            break;
        case e_t::OperatorsAreLessThenOperands:
            std::cout << "Operands are more than operators.";
            break;
        case e_t::FunctionWithoutArg:
            std::cout << "Function withourt argument.";
            break;
        case e_t::BinaryOperatorWithoutTwoOperands:
            std::cout << "Binary operator without two operands.";
            break;
        case e_t::InvalidToken:
            std::cout << "Invalid token detected.";
            break;
    }

    std::cout << " Please, rewrite your function." << std::endl;
}

void printInvalidFieldInfoErrMess(const ::pn_e::InvalidFieldInfoException& e) {
    using e_t = ::pn_e::InvalidFieldInfoException::ErrType;
    ::polish_notation::renderer::FieldInfo fInfo = e.getFieldInfo();
    std::cout << "Invalid field info: ";

    switch (e.getErrType()) {
        case e_t::NegativeOrZeroWidth:
            std::cout << "Width can not be less than or equal to zero. Given: "
                      << fInfo.width;
            break;
        case e_t::NegativeOrZeroHeigth:
            std::cout << "Height can not be less than or equal to zero. Given: "
                      << fInfo.height;
            break;
        case e_t::InvalidDomain:
            std::cout
                << "[n, m] (domain) - 'n' can not be more than 'm'. Given: ["
                << fInfo.domain.first << ", " << fInfo.domain.second << "]";
            break;
        case e_t::InvalidCodomain:
            std::cout
                << "[k, l] (codomain) - 'k' can not be more than 'l'. Given: ["
                << fInfo.codomain.first << ", " << fInfo.codomain.second << "]";
            break;
    }

    std::cout << std::endl;
    std::cout << "Please, correct it." << std::endl;
}

void printTypeConversionErrorErrMess(const ::pn_e::TypeConversionError& e) {
    std::cout << "Type conversion error: Incompatible object '" + e.getValue() +
                     "'. Please, use object with valid type."
              << std::endl;
}
} // namespace polish_notation::user_err_mess_printer