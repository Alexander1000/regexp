#ifndef H_REGEXP_SYNTAX_INCLUDE
#define H_REGEXP_SYNTAX_INCLUDE

namespace RegExp::Syntax
{
    class Tree : public SyntaxTree::Syntax::Tree
    {
    public:
        Tree();
        void initializeDefaults() override;
    };
}

#endif
