#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase *testLexerMatchTokensCase01()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCase01: [a-z]+");
        t->printTitle();

        RegExp::Lexer lexer("[a-z]+");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 4, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketOpen, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "[", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::AlphabetRange, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "a-z", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketClose, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "]", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Quantifier, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "+", *tokenIt);

        t->finish();
        return t;
    }

    CppUnitTest::TestCase *testLexerMatchTokensCase02()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCase02: [abc-]?");
        t->printTitle();

        RegExp::Lexer lexer("[abc-]?");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 7, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketOpen, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "[", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "a", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "b", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "c", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "-", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketClose, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "]", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Quantifier, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "?", *tokenIt);

        t->finish();
        return t;
    }

    CppUnitTest::TestCase *testLexerMatchTokensCase03()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCase03: [^abc-e^]*");
        t->printTitle();

        RegExp::Lexer lexer("[^abc-e^]*");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 8, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketOpen, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "[", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::InvertAlphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "^", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "a", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "b", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::AlphabetRange, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "c-e", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Alphabet, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "^", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::SquareBracketClose, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "]", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Quantifier, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "*", *tokenIt);

        t->finish();
        return t;
    }
}
