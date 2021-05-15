#ifndef H_REGEXP_SCANER_INCLUDE
#define H_REGEXP_SCANER_INCLUDE

#include <list>
#include <regexp/predicate.h>

namespace RegExp::Scaner
{
    class Scaner
    {
    public:
        Scaner(std::list<RegExp::Predicate::Predicate*>* predicates);

        char* scan(std::string*);
        char* scan(const char*);

    private:
        std::list<RegExp::Predicate::Predicate*>* predicates;
    };
}

#endif
