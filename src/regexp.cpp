#include <list>
#include <regexp.h>

namespace RegExp
{
    Expression::Expression(std::string *regexp)
    {
        this->predicates = new std::list<Predicate::Predicate*>;
        RegExp::Lexer lexer("[a-z]");
        auto tokens = lexer.parseTokens();
    }
}
