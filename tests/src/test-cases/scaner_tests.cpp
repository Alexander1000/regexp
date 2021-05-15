#include <regexp.h>
#include <list>
#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testScanerCase01()
    {
        auto t = new CppUnitTest::TestCase("testSyntaxTestCase01: [a-z]+");
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

        auto pList = new std::list<RegExp::Predicate::Predicate*>;
        pList->push_back(p);

        auto scaner = new RegExp::Scaner::Scaner(pList);

        auto parsedString = scaner->scan("alexander");
        CppUnitTest::assertEquals(t, "alexander", parsedString);

        parsedString = scaner->scan("alexander1990");
        CppUnitTest::assertEquals(t, "alexander", parsedString);

        t->finish();
        return t;
    }
}
