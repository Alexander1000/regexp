#ifndef H_REGEXP_SYNTAX_INCLUDE
#define H_REGEXP_SYNTAX_INCLUDE

#include <syntax-tree-lib.h>

namespace RegExp::Syntax
{
    class Tree : public SyntaxTree::Syntax::Tree
    {
    public:
        Tree();
        void initializeDefaults() override;
    };

    bool isRule(SyntaxTree::Syntax::SyntaxElement*, const char*);
}

#endif
