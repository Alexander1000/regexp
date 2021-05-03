#include <regexp.h>

namespace RegExp
{
    Lexer::Lexer(std::string *expr)
    {
        this->expr = expr;
        this->currentPosition = 0;
        this->state = StateMode::Main;
        this->stateStack = new std::stack<StateMode>;
    }

    Lexer::Lexer(const char *expr)
    {
        this->expr = new std::string(expr);
        this->currentPosition = 0;
        this->state = StateMode::Main;
        this->stateStack = new std::stack<StateMode>;
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
        const char* symbol = this->getNextChar();
        if (symbol == nullptr) {
            return nullptr;
        }

        switch (this->state) {
            case StateMode::Main: {
                if (*symbol == '?' || *symbol == '+' || *symbol == '*') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::Quantifier, val);
                }

                if (*symbol == '[') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    this->switchToMode(StateMode::SquareBlockSelect);
                    return new Token(TokenType::SquareBracketOpen, val);
                }
                break;
            }
            case StateMode::SquareBlockSelect: {
                break;
            }
        }

        return nullptr;
    }

    const char* Lexer::getNextChar()
    {
        if (this->currentPosition == this->expr->length()) {
            return nullptr;
        }

        return this->expr->c_str() + (this->currentPosition++);
    }

    void Lexer::switchToMode(StateMode newState)
    {
        this->stateStack->push(this->state);
        this->state = newState;
    }

    void Lexer::switchToPreviousMode()
    {
        this->state = this->stateStack->top();
        this->stateStack->pop();
    }
}
