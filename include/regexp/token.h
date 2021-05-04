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
        QuantifierFrom, // context: [a-z]{n,m}
        QuantifierDelimiter, // context: [a-z]{n,m}
        QuantifierTo, // context: [a-z]{n,m}
    };

    class Token
    {
    public:
        Token(TokenType, void*);
    private:
        TokenType type;
        void* data;
    };
}

#endif
