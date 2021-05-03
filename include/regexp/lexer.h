#ifndef H_REGEXP_LEXER_INCLUDE
#define H_REGEXP_LEXER_INCLUDE

#include <list>
#include <regexp/token.h>

namespace RegExp
{
    enum StateMode {
        Main,
        SquareBlockSelect,
    };

    class Lexer
    {
    public:
        Lexer(std::string*);
        Lexer(const char*);
        std::list<Token*>* parseTokens();

    private:
        StateMode state;

        std::string* expr;
        int currentPosition;

        Token* getNextToken();
        const char* getNextChar();
    };
}

#endif
