#include <regexp.h>
#include <string>

namespace RegExp::Syntax
{
    bool isRule(SyntaxTree::Syntax::SyntaxElement* syntaxElement, const char* ruleName)
    {
        if (syntaxElement->getRule() == nullptr) {
            return false;
        }

        auto rule = syntaxElement->getRule();
        if (strcmp(rule->getName(), ruleName) == 0) {
            return true;
        }

        return false;
    }
}
