#include <regexp.h>

namespace RegExp
{
    Token::Token(TokenType type, const char* data)
    {
        this->type = type;
        this->data = data;
    }

    TokenType Token::getType()
    {
        return this->type;
    }

    const char* Token::getData()
    {
        return this->data;
    }
}
