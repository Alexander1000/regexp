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
        CppUnitTest::assertEquals(t, "^", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "H", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::CaptureOpen, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "(", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "e", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::OneOfVariant, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "|", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "a", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::CaptureClose, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, ")", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "l", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierOpen, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "{", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierNumber, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "2", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::QuantifierClose, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "}", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "o", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, " ", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "w", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "o", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "r", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "l", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "d", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Match, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "!", (*tokenIt)->getData());

        tokenIt++;
        RegExpTests::assertEquals(t, RegExp::Token::TokenType::Quantifier, (*tokenIt)->getType());
        CppUnitTest::assertEquals(t, "?", (*tokenIt)->getData());

        t->finish();
        return t;
    }
}
