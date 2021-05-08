#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testPredicate_Alphabet_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicateTestCase01: [!@#a-z*0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*0-9]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto p = new RegExp::Predicate::Alphabet(testTokens);
        CppUnitTest::assertTrue(t, p->calc("alexander"));

        t->finish();
        return t;
    }
}
