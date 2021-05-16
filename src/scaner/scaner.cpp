#include <memory>
#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Scaner
{
    Scaner::Scaner(RegExp::Predicate::Predicate* predicate)
    {
        this->predicate = predicate;
        this->quantity = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::CustomMatchType, 1, 1);
    }

    Scaner::Scaner(RegExp::Predicate::Predicate* predicate, SyntaxTree::Syntax::Quantity* quantity)
    {
        this->predicate = predicate;
        this->quantity = quantity;
    }

    char* Scaner::scan(const char *input)
    {
        auto chars = new char[2];
        memset(chars, 0, sizeof(char) * 2);

        switch (this->quantity->getType()) {
            case SyntaxTree::Syntax::QuantityType::CustomMatchType: {
                int i;
                for (i = 0; i < strlen(input) && i < this->quantity->getMax(); i++) {
                    chars[0] = input[i];
                    if (!this->predicate->calc(chars)) {
                        break;
                    }
                }

                if (i < this->quantity->getMin()) {
                    return nullptr;
                }

                auto scannedString = (char*) malloc(sizeof(char) * (i + 1));
                memset(scannedString, 0, sizeof(char) * (i + 1));
                memcpy(scannedString, input, sizeof(char) * i);
                return scannedString;
            }

            case SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType: {
                int i;
                for (i = 0; i < strlen(input); i++) {
                    chars[0] = input[i];
                    if (!this->predicate->calc(chars)) {
                        break;
                    }
                }

                if (i == 0) {
                    return nullptr;
                }

                auto scannedString = (char*) malloc(sizeof(char) * (i + 1));
                memset(scannedString, 0, sizeof(char) * (i + 1));
                memcpy(scannedString, input, sizeof(char) * i);
                return scannedString;
            }
        }

        return nullptr;
    }

    char * Scaner::scan(std::string *input)
    {
        return nullptr;
    }
}
