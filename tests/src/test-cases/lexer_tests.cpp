#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase *testLexerMatchTokensCase01()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCase01");
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

    CppUnitTest::TestCase *testLexerMatchTokensCase02()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCase02");
        t->printTitle();

        RegExp::Lexer lexer("[abc-]?");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 7, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketOpen, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "[", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Alphabet, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "a", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Alphabet, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "b", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Alphabet, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "c", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Alphabet, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "-", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketClose, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "]", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::TokenType::Quantifier, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "?", (*tokenIt)->getData());

        t->finish();
        return t;
    }
}
