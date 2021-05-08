#include <regexp.h>

namespace RegExp::Predicate
{
    OneOf::OneOf(std::list<Predicate*>* predicates)
    {
        this->predicates = predicates;
    }

    bool OneOf::calc(const char *text)
    {
        for (auto & p : *predicates) {
            if (p->calc(text)) {
                return true;
            }
        }

        return false;
    }
}
