#include <regexp.h>

namespace RegExp
{
    Lexer::Lexer(std::string *expr)
    {
        this->expr = expr;
    }

    std::list<Token*>* Lexer::parseTokens()
    {
        return nullptr;
    }
}
