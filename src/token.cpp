#include <regexp.h>

namespace RegExp
{
    Token::Token(TokenType type, void* data)
    {
        this->type = type;
        this->data = data;
    }
}
