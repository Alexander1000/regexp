#include <regexp.h>
#include <list>

namespace RegExp::Predicate
{
    Alphabet::Alphabet(std::list<SyntaxTree::Token::Token*>* tokens)
    {
        this->abc = new std::list<char>;
        this->ranges = new std::list<std::pair<char, char>*>;
        this->invert = false;
        this->initialize(tokens);
    }

    Alphabet::Alphabet(std::list<SyntaxTree::Token::Token*>* tokens, bool invert)
    {
        this->abc = new std::list<char>;
        this->ranges = new std::list<std::pair<char, char>*>;
        this->invert = invert;
        this->initialize(tokens);
    }

    void Alphabet::initialize(std::list<SyntaxTree::Token::Token*>* tokens)
    {
        for (auto & token : *tokens) {
            switch (token->getType()) {
                case RegExp::Token::TokenType::Alphabet: {
                    char symbol;
                    RESET_TOKEN_READER(token)
                    token->getReader()->read(&symbol, 1);
                    this->abc->push_back(symbol);
                    break;
                }
                case RegExp::Token::TokenType::AlphabetRange: {
                    auto symbol = new char[3];
                    RESET_TOKEN_READER(token)
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
        for (int i = 0; i < strlen(text); i++) {
            char curSymbol = text[i];
            bool foundMatch = false;
            for (auto & abcIt : *abc) {
                if (curSymbol == abcIt) {
                    foundMatch = true;
                    break;
                }
            }
            if (foundMatch) {
                continue;
            }
            for (auto & rangeIt : *ranges) {
                if (rangeIt->first <= curSymbol && rangeIt->second >= curSymbol) {
                    foundMatch = true;
                    break;
                }
            }

            if (!foundMatch) {
                return false;
            }
        }
        return true;
    }
}
