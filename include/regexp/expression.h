#ifndef H_REGEXP_EXPRESSION_INCLUDE
#define H_REGEXP_EXPRESSION_INCLUDE

#include <string>
#include <list>
#include <syntax-tree-lib.h>
#include <regexp/predicate.h>

namespace RegExp::Expression
{
    class Expression
    {
    public:
        Expression(std::string*);
        Expression(const char*);

        bool match(std::string*);
        bool match(const char*);
    private:
        std::list<RegExp::Predicate::Predicate*>* predicates;

        static std::list<RegExp::Predicate::Predicate*>* parseSyntaxTree(SyntaxTree::Syntax::SyntaxElement*);

        static void parseAlphabetScope(SyntaxTree::Syntax::SyntaxElement*);
        static RegExp::Predicate::Predicate* parseAlphabetPredicate(SyntaxTree::Syntax::SyntaxElement*, bool);
    };
}

#endif
