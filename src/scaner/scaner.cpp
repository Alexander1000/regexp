#include <regexp.h>

namespace RegExp::Scaner
{
    Scaner::Scaner(std::list<RegExp::Predicate::Predicate*>* predicates)
    {
        this->predicates = predicates;
    }
}
