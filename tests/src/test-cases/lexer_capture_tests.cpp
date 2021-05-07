#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase *testLexerMatchTokensCaptureCase01()
    {
        auto t = new CppUnitTest::TestCase("testLexerMatchTokensCaptureCase01: ^H(e|a)llo world!?");
        t->printTitle();

        RegExp::Lexer lexer("^H(e|a)l{2}o world!?");
        auto tokens = lexer.parseTokens();

        CppUnitTest::assertEquals(t, 20, tokens->size());

        auto tokenIt = tokens->begin();
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::StartOfLine, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "^", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "H", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::CaptureOpen, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "(", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "e", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::OneOfVariant, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "|", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "a", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::CaptureClose, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, ")", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "l", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierOpen, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "{", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierNumber, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "2", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierClose, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "}", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "o", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, " ", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "w", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "o", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "r", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "l", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "d", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "!", *tokenIt);

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Quantifier, (*tokenIt)->getType());
        RegExpTests::assertEqualsTokenValue(t, "?", *tokenIt);

        t->finish();
        return t;
    }
}
