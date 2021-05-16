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
            itElement++; // - invert or alphabet
            bool invert = false;
            if ((*itElement)->getType() == SyntaxTree::Syntax::SyntaxElementType::TokenType) {
                RegExp::Syntax::assertTokenType(*itElement, RegExp::Token::TokenType::InvertAlphabet);
                invert = true;
                itElement++; // alphabet
            }
            itElement++; // ] - token
            RegExp::Syntax::assertTokenType(*itElement, RegExp::Token::TokenType::SquareBracketClose);
            itElement++; // quantifier
        }
    }
}
