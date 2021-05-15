#include <list>
#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp
{
    Expression::Expression(std::string *regexp)
    {
        RegExp::Lexer lexer(regexp);

        RegExp::Syntax::Tree tree;
        tree.initializeDefaults();

        auto syntaxTree = tree.parse(lexer.parseTokens());

        this->predicates = Expression::parseSyntaxTree(syntaxTree);
    }

    std::list<Predicate::Predicate*>* Expression::parseSyntaxTree(SyntaxTree::Syntax::SyntaxElement* tree)
    {
        auto elements = new std::list<Predicate::Predicate*>;
        return elements;
    }
}
