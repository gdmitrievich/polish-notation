#include "polish_notation/polish_calculation/polish_calculation.h"

#include <cmath>
#include <stdexcept>

#include "polish_notation/exceptions/invalid_function/invalid_function.h"
#include "polish_notation/utility/utility.h"

namespace polish_notation::polish_calculation {
namespace pn = polish_notation;
using pn::data_structures::queue::Queue;
using pn::data_structures::stack::Stack;
using pn::token::t_id;
using pn::token::Token;

using pn::utility::size_t;

void replaceAllXWithNumInTokenQueue(Queue<Token>& q, double num) {
    size_t qSize = q.size();
    Token t;

    for (size_t i {}; i < qSize; ++i) {
        t = q.dequeue();
        if (t.id == t_id::x)
            q.enqueue(Token(num));
        else
            q.enqueue(t);
    }
}

double calculatePostfixTokenQueue(Queue<Token> qPostfix) {
    Stack<Token> s;

    while (!qPostfix.isEmpty())
        calculateRetrievedToken(qPostfix.dequeue(), s);

    if (s.size() == 1)
        return s.pop().data.num;
    else
        throw ::pn_e::InvalidFunction(
            ::pn_e::InvalidFunction::ErrType::OperatorsAreLessThenOperands,
            "invalid_function: Operators are less then operands error.");
}

void calculateRetrievedToken(const Token& t, Stack<Token>& s) {
    if (t.id == t_id::num) {
        s.push(t);
    } else if (t.isFunction()) {
        if (s.size() >= 1)
            s.push(Token(calculateFunction(t.id, s.pop().data.num)));
        else
            throw ::pn_e::InvalidFunction(
                ::pn_e::InvalidFunction::ErrType::FunctionWithoutArg,
                "invalid_function: Function without argument error.");
    } else if (t.isBinaryOperator()) {
        if (s.size() >= 2) {
            double first = s.pop().data.num;
            double second = s.pop().data.num;
            s.push(Token(calculateBinaryOperator(t.id, first, second)));
        } else {
            throw ::pn_e::InvalidFunction(::pn_e::InvalidFunction::ErrType::
                                              BinaryOperatorWithoutTwoOperands,
                                          "invalid_function: Binary operator "
                                          "without two operands error.");
        }
    }
}

double calculateFunction(Token::Id funcId, double v) {
    double res {};

    switch (funcId) {
        case t_id::sin:
            res = sin(v);
            break;
        case t_id::cos:
            res = cos(v);
            break;
        case t_id::tan:
            if (::std::fmod(v, M_PI) == M_PI / 2)
                throw ::std::domain_error("domain_error: The tangent is not "
                                          "defined for x = pi/2 + pi*k");

            res = tan(v);
            break;
        case t_id::ctg:
            if (::std::fmod(v, M_PI) == 0)
                throw ::std::domain_error(
                    "domain_error: The cotangent is not defined for x = pi*k");

            res = 1 / tan(v);
            break;
        case t_id::sqrt:
            if (v < 0)
                throw ::std::domain_error(
                    "domain_error: The sqrt is not defined for x < 0");

            res = sqrt(v);
            break;
        case t_id::ln:
            if (v <= 0)
                throw ::std::domain_error(
                    "domain_error: The ln is not defined for x <= 0");

            res = log(v);
            break;
    }

    return res;
}

double calculateBinaryOperator(Token::Id binId, double first, double second) {
    double res {};

    switch (binId) {
        case t_id::plus:
            res = second + first;
            break;
        case t_id::minus:
            res = second - first;
            break;
        case t_id::mult:
            res = second * first;
            break;
        case t_id::div:
            if (first == 0)
                throw ::std::domain_error("domain_error: Division by zero.");

            res = second / first;
            break;
    }

    return res;
}
} // namespace polish_notation::polish_calculation