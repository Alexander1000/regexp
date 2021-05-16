#ifndef H_REGEXP_SCANER_INCLUDE
#define H_REGEXP_SCANER_INCLUDE

#include <list>
#include <syntax-tree-lib.h>
#include <regexp/predicate.h>

namespace RegExp::Scaner
{
    class Scaner
    {
    public:
        Scaner(RegExp::Predicate::Predicate*);
        Scaner(RegExp::Predicate::Predicate*, SyntaxTree::Syntax::Quantity*);

        char* scan(std::string*);
        char* scan(const char*);

    private:
        RegExp::Predicate::Predicate* predicate;
        SyntaxTree::Syntax::Quantity* quantity;
    };
}

#endif
