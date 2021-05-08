#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testPredicate_Alphabet_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_Alphabet_TestCase01: [!@#a-z*_0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*_0-9]");
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
        CppUnitTest::assertTrue(t, p->calc("alexander_1990"));
        CppUnitTest::assertTrue(t, p->calc("test_case#@123!"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!-"));

        t->finish();
        return t;
    }

    CppUnitTest::TestCase* testPredicate_Invert_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_Invert_TestCase01: [!@#a-z*_0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*_0-9]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto pa = new RegExp::Predicate::Alphabet(testTokens);
        auto p = new RegExp::Predicate::Invert(pa);
        CppUnitTest::assertFalse(t, p->calc("alexander"));
        CppUnitTest::assertFalse(t, p->calc("alexander_1990"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!"));
        CppUnitTest::assertTrue(t, p->calc("test_case#@123!-"));

        t->finish();
        return t;
    }
}
