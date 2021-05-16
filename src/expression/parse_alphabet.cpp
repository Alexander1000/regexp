#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Expression
{
    void Expression::parseAlphabetScope(SyntaxTree::Syntax::SyntaxElement *element)
    {
        if (element->getType() == SyntaxTree::Syntax::SyntaxElementType::SyntaxType) {
            Expression::parseAlphabetScope(element->getElement());
        }

        if (element->getType() == SyntaxTree::Syntax::SyntaxElementType::TokenListType) {
            auto listElements = element->getListElements();
            auto itElement = listElements->begin(); // [ - token
            RegExp::Syntax::assertTokenType(*itElement, RegExp::Token::TokenType::SquareBracketOpen);
            itElement++; // - alphabet
            itElement++; // ] - token
            itElement++; // quantifier
        }
    }
}
