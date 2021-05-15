#ifndef H_REGEXP_EXPRESSION_INCLUDE
#define H_REGEXP_EXPRESSION_INCLUDE

#include <string>
#include <list>
#include <syntax-tree-lib.h>
#include <regexp/predicate.h>

namespace RegExp
{
    class Expression
    {
    public:
        Expression(std::string*);
    private:
        std::list<Predicate::Predicate*>* predicates;

        static std::list<Predicate::Predicate*>* parseSyntaxTree(SyntaxTree::Syntax::SyntaxElement*);
    };
}

#endif
