#include <regexp.h>

namespace RegExp::Predicate
{
    Invert::Invert(Predicate *predicate)
    {
        this->predicate = predicate;
    }

    bool Invert::calc(const char *text)
    {
        return !this->predicate->calc(text);
    }
}
