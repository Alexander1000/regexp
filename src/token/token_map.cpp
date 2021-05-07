#include <regexp.h>
#include <string>
#include <map>

namespace RegExp::Token
{
    TokenMap::TokenMap()
    {
        this->tokenMap = new std::map<std::string, int>{
                {"quantifier",          TokenType::Quantifier},
                {"captureOpen",         TokenType::CaptureOpen},
                {"captureClose",        TokenType::CaptureClose},
                {"squareBracketOpen",   TokenType::SquareBracketOpen},
                {"squareBracketClose",  TokenType::SquareBracketClose},
                {"match",               TokenType::Match},
                {"quantifierNumber",    TokenType::QuantifierNumber},
                {"quantifierDelimiter", TokenType::QuantifierDelimiter},
                {"quantifierOpen",      TokenType::QuantifierOpen},
                {"quantifierClose",     TokenType::QuantifierClose},
                {"alphabet",            TokenType::Alphabet},
                {"alphabetRange",       TokenType::AlphabetRange},
                {"invertAlphabet",      TokenType::InvertAlphabet},
                {"oneof",               TokenType::OneOfVariant},
                /**
        StartOfLine, // ^
        EndOfLine, // $
        AnySymbol, // .
        Whitespace, // \s
                 */
        };
    }
}
