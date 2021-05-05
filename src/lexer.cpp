#include <regexp.h>

namespace RegExp
{
    Lexer::Lexer(std::string *expr)
    {
        this->expr = expr;
        this->currentPosition = 0;
        this->state = StateMode::Main;
        this->stateStack = new std::stack<StateMode>;
        this->lastSymbol = 0;
    }

    Lexer::Lexer(const char *expr)
    {
        this->expr = new std::string(expr);
        this->currentPosition = 0;
        this->state = StateMode::Main;
        this->stateStack = new std::stack<StateMode>;
        this->lastSymbol = 0;
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
                if (*symbol == '^') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::StartOfLine, val);
                }

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

                if (*symbol == '.') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::AnySymbol, val);
                }

                if (*symbol == '(') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    this->switchToMode(StateMode::Capture);
                    return new Token(TokenType::CaptureOpen, val);
                }

                char* val = new char[2];
                val[0] = *symbol;
                val[1] = 0;
                return new Token(TokenType::Match, val);
            }
            case StateMode::SquareBlockSelect: {
                if (*symbol == ']') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    this->switchToPreviousMode();
                    return new Token(TokenType::SquareBracketClose, val);
                }

                if (*symbol == '^' && this->lastSymbol == '[') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::InvertAlphabet, val);
                }

                const char* fSymbol = this->getForwardChar(0);
                if (fSymbol == nullptr || *fSymbol == ']') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::Alphabet, val);
                }

                if (*fSymbol == '-') {
                    const char* fSymbol2 = this->getForwardChar(1);
                    if (fSymbol2 == nullptr || *fSymbol2 == ']') {
                        char* val = new char[2];
                        val[0] = *symbol;
                        val[1] = 0;
                        return new Token(TokenType::Alphabet, val);
                    }

                    char* val = new char[4];
                    val[0] = *symbol;
                    val[1] = '-';
                    val[2] = *fSymbol2;
                    val[3] = 0;
                    this->currentPosition += 2;
                    return new Token(TokenType::AlphabetRange, val);
                }

                char* val = new char[2];
                val[0] = *symbol;
                val[1] = 0;
                return new Token(TokenType::Alphabet, val);
            }
            case StateMode::Capture: {
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

                if (*symbol == '.') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::AnySymbol, val);
                }

                if (*symbol == '(') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    this->switchToMode(StateMode::Capture);
                    return new Token(TokenType::CaptureOpen, val);
                }

                if (*symbol == ')') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    this->switchToPreviousMode();
                    return new Token(TokenType::CaptureClose, val);
                }

                if (*symbol == '|') {
                    char* val = new char[2];
                    val[0] = *symbol;
                    val[1] = 0;
                    return new Token(TokenType::OneOfVariant, val);
                }

                char* val = new char[2];
                val[0] = *symbol;
                val[1] = 0;
                return new Token(TokenType::Match, val);
            }
        }

        return nullptr;
    }

    const char* Lexer::getNextChar()
    {
        if (this->currentPosition == this->expr->length()) {
            return nullptr;
        }

        if (this->currentPosition > 0) {
            this->lastSymbol = this->expr->c_str()[this->currentPosition - 1];
        }

        return this->expr->c_str() + (this->currentPosition++);
    }

    const char * Lexer::getForwardChar(int delta)
    {
        if (this->currentPosition + delta >= this->expr->length()) {
            return nullptr;
        }

        return this->expr->c_str() + this->currentPosition + delta;
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
