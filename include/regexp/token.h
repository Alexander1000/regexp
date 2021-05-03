#ifndef H_REGEXP_TOKEN_INCLUDE
#define H_REGEXP_TOKEN_INCLUDE

namespace RegExp
{
    enum TokenType {
        Quantifier
    };

    class Token
    {
    public:
        Token(TokenType, const char*);
    private:
        TokenType type;
        const char* value;
    };
}

#endif
