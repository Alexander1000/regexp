#include <string>
#include <list>
#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Expression
{
    Expression::Expression(std::string* regexp)
    {
        RegExp::Lexer lexer(regexp);

        RegExp::Syntax::Tree tree;
        tree.initializeDefaults();

        auto syntaxTree = tree.parse(lexer.parseTokens());

        this->predicates = Expression::parseSyntaxTree(syntaxTree);
    }

    Expression::Expression(const char* regexp)
    {
        RegExp::Lexer lexer(regexp);

        RegExp::Syntax::Tree tree;
        tree.initializeDefaults();

        auto syntaxTree = tree.parse(lexer.parseTokens());

        this->predicates = Expression::parseSyntaxTree(syntaxTree);
    }

    std::list<RegExp::Predicate::Predicate*>* Expression::parseSyntaxTree(SyntaxTree::Syntax::SyntaxElement* tree)
    {
        if (tree->getType() == SyntaxTree::Syntax::SyntaxElementType::SyntaxType) {
            return Expression::parseSyntaxTree(tree->getElement());
        }

        auto elements = new std::list<RegExp::Predicate::Predicate*>;

        if (tree->getType() == SyntaxTree::Syntax::SyntaxElementType::TokenListType) {
            auto treeElements = tree->getListElements();
            for (auto & treeElement : *treeElements) {
                if (RegExp::Syntax::isRule(treeElement, "expr")) {
                    auto subElements = Expression::parseSyntaxTree(treeElement);
                }
            }
        }

        return elements;
    }

    bool Expression::match(std::string* str)
    {
        return false;
    }

    bool Expression::match(const char* str)
    {
        return false;
    }
}
