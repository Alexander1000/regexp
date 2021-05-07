#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Syntax
{
    Tree::Tree() : SyntaxTree::Syntax::Tree() {
        this->tokenMap = new RegExp::Token::TokenMap;
    }

    void Tree::initializeDefaults()
    {
        // build command: syntax-tree -s syntax.s -i src/trw/syntax/tree.cpp
        // @syntax-tree: start-autogenerate

        // @syntax-tree: stop-autogenerate
    }
}
