#ifndef USER_ERR_MESS_PRINTER_H
#define USER_ERR_MESS_PRINTER_H

#include <stdexcept>

#include "polish_notation/exceptions/invalid_field_info_exception/invalid_field_info_exception.h"
#include "polish_notation/exceptions/invalid_function/invalid_function.h"
#include "polish_notation/exceptions/type_conversion_error/type_conversion_error.h"

namespace polish_notation::user_err_mess_printer {
void printErrMess(const ::std::exception& e);

void printInvalidFunctionErrMess(const ::pn_e::InvalidFunction& e);

void printInvalidFieldInfoErrMess(const ::pn_e::InvalidFieldInfoException& e);

void printTypeConversionErrorErrMess(const ::pn_e::TypeConversionError& e);
} // namespace polish_notation::user_err_mess_printer

namespace pn_uemp = polish_notation::user_err_mess_printer;

#endif // USER_ERR_MESS_PRINTER_H