#ifndef H_REGEXP_PREDICATE_INCLUDE
#define H_REGEXP_PREDICATE_INCLUDE

#include <list>
#include <syntax-tree-lib.h>

namespace RegExp::Predicate
{
    class InvalidArgumentException : public std::exception
    {};

    class Predicate
    {
    public:
        virtual bool calc(const char*) = 0;
    };

    class Alphabet : public Predicate
    {
    public:
        Alphabet(std::list<SyntaxTree::Token::Token*>*);
        bool calc(const char *) override;

    private:
        std::list<char>* abc;
        std::list<std::pair<char, char>*>* ranges;
    };
}

#endif
