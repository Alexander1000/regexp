#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Syntax
{
    void assertTokenType(SyntaxTree::Syntax::SyntaxElement* element, int type)
    {
        if (element->getType() != SyntaxTree::Syntax::SyntaxElementType::TokenType) {
            throw UnexpectedSyntaxElement();
        }

        auto token = element->getToken();
        if (token == nullptr) {
            throw UnexpectedToken();
        }

        if (token->getType() != type) {
            throw UnexpectedToken();
        }
    }
}
