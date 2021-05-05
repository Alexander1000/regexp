#ifndef H_REGEXP_TOKEN_INCLUDE
#define H_REGEXP_TOKEN_INCLUDE

namespace RegExp
{
    enum TokenType {
        Quantifier, // ?, +, *
        CaptureOpen, // (
        CaptureClose, // )
        SquareBracketOpen, // [
        SquareBracketClose, // ]
        StartOfLine, // ^
        EndOfLine, // $
        InvertAlphabet, // ^ (context: [^abc])
        Alphabet, // context: [abc]
        AlphabetRange, // context: [a-z]
        AnySymbol, // .
        Whitespace, // \s
        Match, // similar alphabet, but full match
        QuantifierOpen, // {
        QuantifierClose, // }
        // complex quantifier
        QuantifierNumber, // context: [a-z]{n,m}
        QuantifierDelimiter, // context: [a-z]{n,m}
        OneOfVariant, // context: (apple|banana)
    };

    class Token
    {
    public:
        Token(TokenType, const char*);
        TokenType getType();
        const char* getData();
    private:
        TokenType type;
        const char* data;
    };
}

#endif
