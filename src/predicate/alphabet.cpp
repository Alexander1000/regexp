#include <regexp.h>
#include <list>

namespace RegExp::Predicate
{
    Alphabet::Alphabet(std::list<SyntaxTree::Token::Token*>* tokens)
    {
        this->abc = new std::list<char>;
        this->ranges = new std::list<std::pair<char, char>*>;

        for (auto & token : *tokens) {
            switch (token->getType()) {
                case RegExp::Token::TokenType::Alphabet: {
                    char symbol;
                    token->getReader()->read(&symbol, 1);
                    this->abc->push_back(symbol);
                    break;
                }
                case RegExp::Token::TokenType::AlphabetRange: {
                    auto symbol = new char[3];
                    token->getReader()->read(symbol, 3);
                    auto range = new std::pair<char, char>();
                    range->first = symbol[0];
                    range->second = symbol[2];
                    this->ranges->push_back(range);
                    break;
                }
                default: {
                    throw InvalidArgumentException();
                }
            }
        }
    }

    bool Alphabet::calc(const char *text)
    {
        return true;
    }
}
