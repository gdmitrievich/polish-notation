#include "user_input.h"

namespace polish_notation::user_input {
using polish_notation::renderer::FieldInfo;
using std::cout, std::endl, std::cin;

void setFunctionStr(::std::string& fStr) {
    cout << "Enter the function: ";
    getline(std::cin, fStr);
    cout << endl;
}
} // namespace polish_notation::user_input