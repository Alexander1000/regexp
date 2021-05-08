#include <regexp.h>

namespace RegExp::Predicate
{
    Negative::Negative(Predicate *predicate)
    {
        this->predicate = predicate;
    }

    bool Negative::calc(const char *text)
    {
        return !this->predicate->calc(text);
    }
}
