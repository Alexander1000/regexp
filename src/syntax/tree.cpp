#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExp::Syntax
{
    Tree::Tree() : SyntaxTree::Syntax::Tree() {
        this->tokenMap = new RegExp::Token::TokenMap;
    }

    void Tree::initializeDefaults()
    {
        // build command: syntax-tree -s syntax.s -i src/syntax/tree.cpp
        // @syntax-tree: start-autogenerate

        auto rule00 = new SyntaxTree::Syntax::Rule("quantifier");
        rule00->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifier")));
        this->rules->push_back(rule00);

        auto rule01 = new SyntaxTree::Syntax::Rule("quantifier");
        rule01->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierOpen")));
        rule01->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierNumber")));
        rule01->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierClose")));
        this->rules->push_back(rule01);

        auto rule02 = new SyntaxTree::Syntax::Rule("quantifier");
        rule02->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierOpen")));
        rule02->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierNumber")));
        rule02->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierDelimiter")));
        auto q02 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::ZeroOrOneMatchType);
        rule02->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierNumber"), q02));
        rule02->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("quantifierClose")));
        this->rules->push_back(rule02);

        auto rule03 = new SyntaxTree::Syntax::Rule("alphabet");
        auto q03 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType);
        rule03->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("alphabet"), q03));
        this->rules->push_back(rule03);

        auto rule04 = new SyntaxTree::Syntax::Rule("alphabet");
        auto q04 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType);
        rule04->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("alphabetRange"), q04));
        this->rules->push_back(rule04);

        auto rule05 = new SyntaxTree::Syntax::Rule("alphabetScope");
        rule05->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("squareBracketOpen")));
        auto q05 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::ZeroOrOneMatchType);
        rule05->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("invertAlphabet"), q05));
        auto q051 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType);
        rule05->addMatch(new SyntaxTree::Syntax::RuleMatch("alphabet", q051));
        rule05->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("squareBracketClose")));
        auto q052 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::ZeroOrOneMatchType);
        rule05->addMatch(new SyntaxTree::Syntax::RuleMatch("quantifier", q052));
        this->rules->push_back(rule05);

        auto rule06 = new SyntaxTree::Syntax::Rule("matchQuantified");
        rule06->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("match")));
        auto q06 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::ZeroOrOneMatchType);
        rule06->addMatch(new SyntaxTree::Syntax::RuleMatch("quantifier", q06));
        this->rules->push_back(rule06);

        auto rule07 = new SyntaxTree::Syntax::Rule("match");
        auto q07 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType);
        rule07->addMatch(new SyntaxTree::Syntax::RuleMatch("matchQuantified", q07));
        this->rules->push_back(rule07);

        auto rule08 = new SyntaxTree::Syntax::Rule("oneof");
        rule08->addMatch(new SyntaxTree::Syntax::RuleMatch("match"));
        rule08->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("oneof")));
        rule08->addMatch(new SyntaxTree::Syntax::RuleMatch("match"));
        this->rules->push_back(rule08);

        auto rule09 = new SyntaxTree::Syntax::Rule("oneof");
        rule09->addMatch(new SyntaxTree::Syntax::RuleMatch("expr"));
        rule09->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("oneof")));
        rule09->addMatch(new SyntaxTree::Syntax::RuleMatch("expr"));
        this->rules->push_back(rule09);

        auto rule10 = new SyntaxTree::Syntax::Rule("capture");
        rule10->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("captureOpen")));
        rule10->addMatch(new SyntaxTree::Syntax::RuleMatch("expr"));
        rule10->addMatch(new SyntaxTree::Syntax::RuleMatch(this->tokenMap->getType("captureClose")));
        auto q10 = new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::ZeroOrOneMatchType);
        rule10->addMatch(new SyntaxTree::Syntax::RuleMatch("quantifier", q10));
        this->rules->push_back(rule10);

        auto rule11 = new SyntaxTree::Syntax::Rule("expr");
        rule11->addMatch(new SyntaxTree::Syntax::RuleMatch("alphabetScope"));
        this->rules->push_back(rule11);

        auto rule12 = new SyntaxTree::Syntax::Rule("expr");
        rule12->addMatch(new SyntaxTree::Syntax::RuleMatch("capture"));
        this->rules->push_back(rule12);

        auto rule13 = new SyntaxTree::Syntax::Rule("expr");
        rule13->addMatch(new SyntaxTree::Syntax::RuleMatch("match"));
        this->rules->push_back(rule13);

        auto rule14 = new SyntaxTree::Syntax::Rule("expr");
        rule14->addMatch(new SyntaxTree::Syntax::RuleMatch("oneof"));
        this->rules->push_back(rule14);

        // @syntax-tree: stop-autogenerate
    }
}
