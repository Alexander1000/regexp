#include <regexp.h>
#include <syntax-tree-lib.h>
#include <iostream>

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
            auto p = Expression::parseAlphabetPredicate(*itElement, invert);
            itElement++; // ] - token
            RegExp::Syntax::assertTokenType(*itElement, RegExp::Token::TokenType::SquareBracketClose);
            itElement++; // quantifier
        }
    }

    RegExp::Predicate::Predicate* Expression::parseAlphabetPredicate(SyntaxTree::Syntax::SyntaxElement *element, bool invert)
    {
        if (element->getType() == SyntaxTree::Syntax::SyntaxElementType::SyntaxType) {
            return Expression::parseAlphabetPredicate(element->getElement(), invert);
        }

        if (element->getType() == SyntaxTree::Syntax::SyntaxElementType::TokenListType) {
            auto tokens = new std::list<SyntaxTree::Token::Token*>;

            for (auto & token : *element->getListElements()) {
                if (token->getType() != SyntaxTree::Syntax::SyntaxElementType::TokenType) {
                    throw RegExp::Syntax::UnexpectedSyntaxElement();
                }
                tokens->push_back(token->getToken());
            }

            return new RegExp::Predicate::Alphabet(tokens, invert);
        }

        throw RegExp::Syntax::UnexpectedSyntaxElement();
    }
}
