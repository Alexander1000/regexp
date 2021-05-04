#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase *testCase01()
    {
        auto t = new CppUnitTest::TestCase("001-simple-test");
        t->printTitle();

        RegExp::Lexer lexer("[a-z]+");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 4, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketOpen, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "[", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::AlphabetRange, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "a-z", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketClose, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "]", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Quantifier, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "+", (*tokenIt)->getData());

        t->finish();
        return t;
    }
}
