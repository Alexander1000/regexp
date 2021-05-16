#include <regexp.h>
#include <list>
#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testScaner_OneOrMoreMatchType_Case01()
    {
        auto t = new CppUnitTest::TestCase("testScaner_OneOrMoreMatchType_Case01: [a-z]+");
        t->printTitle();

        RegExp::Lexer lexer("[a-z]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto p = new RegExp::Predicate::Alphabet(testTokens);

        auto scaner = new RegExp::Scaner::Scaner(p, new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::OneOrMoreMatchType));

        auto parsedString = scaner->scan("alexander");
        CppUnitTest::assertEquals(t, "alexander", parsedString);

        parsedString = scaner->scan("alexander1990");
        CppUnitTest::assertEquals(t, "alexander", parsedString);

        t->finish();
        return t;
    }

    CppUnitTest::TestCase* testScaner_CustomMatchType_From3To6_Case01()
    {
        auto t = new CppUnitTest::TestCase("testScaner_CustomMatchType_From3To6_Case01: [a-z]{3,6}");
        t->printTitle();

        RegExp::Lexer lexer("[a-z]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto p = new RegExp::Predicate::Alphabet(testTokens);

        auto scaner = new RegExp::Scaner::Scaner(p, new SyntaxTree::Syntax::Quantity(SyntaxTree::Syntax::QuantityType::CustomMatchType, 3, 6));

        auto parsedString = scaner->scan("alexander");
        CppUnitTest::assertEquals(t, "alexan", parsedString);

        parsedString = scaner->scan("alexander1990");
        CppUnitTest::assertEquals(t, "alexan", parsedString);

        parsedString = scaner->scan("al");
        CppUnitTest::assertNull(t, parsedString);

        t->finish();
        return t;
    }
}
