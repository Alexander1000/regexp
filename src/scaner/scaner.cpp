#include <memory>
#include <regexp.h>

namespace RegExp::Scaner
{
    Scaner::Scaner(std::list<RegExp::Predicate::Predicate*>* predicates)
    {
        this->predicates = predicates;
    }

    char* Scaner::scan(const char *input)
    {
        auto chars = new char[2];
        memset(chars, 0, sizeof(char) * 2);
        int nCurChar = 0;

        for (int i = 0; i < strlen(input); i++) {
            chars[0] = input[i];

            for (auto & predicate : *this->predicates) {
                if (predicate->calc(chars)) {
                    nCurChar++;
                    break;
                }
            }

            if (nCurChar != i + 1) {
                break;
            }
        }

        if (nCurChar > 0) {
            auto scannedString = (char*) malloc(sizeof(char) * (nCurChar + 1));
            memset(scannedString, 0, sizeof(char) * (nCurChar + 1));
            memcpy(scannedString, input, sizeof(char) * nCurChar);
            return scannedString;
        }

        return nullptr;
    }

    char * Scaner::scan(std::string *input)
    {
        return nullptr;
    }
}
