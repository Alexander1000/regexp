#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Syntax
{
    void assertTokenType(SyntaxTree::Syntax::SyntaxElement* element, int type)
    {
        if (element->getType() != SyntaxTree::Syntax::SyntaxElementType::TokenType) {
            throw new UnexpectedSyntaxElement;
        }

        auto token = element->getToken();
        if (token == nullptr) {
            throw new UnexpectedToken;
        }

        if (token->getType() != type) {
            throw new UnexpectedToken;
        }
    }
}
