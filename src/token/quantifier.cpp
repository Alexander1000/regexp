#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Token
{
    Quantifier::Quantifier(int line, int column, IOBuffer::IOReader *reader) : SyntaxTree::Token::Token(line, column, reader)
    {
    }

    int Quantifier::getType() {
        return TokenType::Quantifier;
    }
}
