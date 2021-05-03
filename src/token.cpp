#include <regexp.h>

namespace RegExp
{
    Token::Token(TokenType type, const char* value)
    {
        this->type = type;
        this->value = value;
    }
}
