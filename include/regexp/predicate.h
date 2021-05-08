#ifndef H_REGEXP_PREDICATE_INCLUDE
#define H_REGEXP_PREDICATE_INCLUDE

namespace RegExp::Predicate
{
    class Predicate
    {
    public:
        virtual bool calc(const char*) = 0;
    };
}

#endif
