#include "token_test.h"

namespace polish_notation::tests::token_test {
bool TokenTest::operator==(const TokenTest& t) const {
    bool isEqual = true;

    isEqual = this->id == t.id;
    isEqual = isEqual && this->id == Token::Id::num ?
                  this->data.num == t.data.num :
                  isEqual;

    return isEqual;
}

bool TokenTest::operator!=(const TokenTest& t) const {
	return !(*this == t);
}
}