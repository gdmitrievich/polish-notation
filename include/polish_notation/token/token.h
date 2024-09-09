#ifndef TOKEN_H
#define TOKEN_H

namespace std {
template <typename T>
class initializer_list;
} // namespace std

namespace polish_notation::token {
struct Token {
   public:
    enum class Id {
        num,
        x,
        plus,
        minus,
        mult,
        div,
        lBrace,
        rBrace,
        sin,
        cos,
        tan,
        ctg,
        sqrt,
        ln
    };

    enum class Priority { minus = 0, plus = 0, mult = 1, div = 1 };

    union Data {
        double num;
        Priority priority;

        Data();
        Data(double n);
        Data(Priority p);
    };

    Id id;
    Data data;

    Token();
    explicit Token(Id id);
    explicit Token(double num);

    bool isBinaryOperator() const;

   private:
    Priority getBinaryOperatorPriority() const;
    bool isEqualToOneOfTheIdList(
        const ::std::initializer_list<Token::Id>& idList) const;
};

using t_id = Token::Id;
} // namespace polish_notation::token

#endif // TOKEN_H