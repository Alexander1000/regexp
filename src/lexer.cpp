#include <regexp.h>

namespace RegExp
{
    Lexer::Lexer(std::string *expr)
    {
        this->expr = expr;
    }

    std::list<Token*>* Lexer::parseTokens()
    {
        auto tokens = new std::list<Token*>;
        while (true) {
            auto token = this->getNextToken();
            if (token == nullptr) {
                break;
            }
            tokens->push_back(token);
        }
        return tokens;
    }

    Token* Lexer::getNextToken()
    {
        return nullptr;
    }
}
