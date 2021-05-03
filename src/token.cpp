#include <regexp.h>

namespace RegExp
{
    Token::Token(int id, const char* value)
    {
        this->id = id;
        this->value = value;
    }
}
