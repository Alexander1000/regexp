#ifndef H_REGEXP_LEXER_INCLUDE
#define H_REGEXP_LEXER_INCLUDE

#include <list>
#include <stack>
#include <regexp/token.h>
#include <syntax-tree-lib.h>

namespace RegExp
{
    enum StateMode {
        Main,
        SquareBlockSelect,
        Capture,
        QuantifierMode,
    };

    class Lexer
    {
    public:
        Lexer(std::string*);
        Lexer(const char*);
        std::list<SyntaxTree::Token::Token*>* parseTokens();

    private:
        StateMode state;
        std::stack<StateMode>* stateStack;

        char lastSymbol;

        std::string* expr;
        int currentPosition;

        SyntaxTree::Token::Token* getNextToken();
        const char* getNextChar();
        const char* getForwardChar(int delta);

        void switchToMode(StateMode);
        void switchToPreviousMode();
    };
}

#endif
