#ifndef H_REGEXP_TOKEN_INCLUDE
#define H_REGEXP_TOKEN_INCLUDE

#include <io-buffer.h>
#include <syntax-tree-lib.h>

namespace RegExp::Token
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

    class Quantifier : public SyntaxTree::Token::Token {
    public:
        Quantifier(int line, int column, IOBuffer::IOReader *reader);

        int getType() final;
    };
}

#endif
