#ifndef REGEXP_TESTS_INCLUDE_H
#define REGEXP_TESTS_INCLUDE_H

#include <string>
#include <cpp-unit-test.h>
#include <regexp.h>

namespace RegExpTests
{
    // asserts
    void assertEquals(CppUnitTest::TestCase* t, RegExp::Token::TokenType expectedTokenType, int actualTokenType);

    // test cases
    CppUnitTest::TestCase* testLexerMatchTokensCase01();
    CppUnitTest::TestCase* testLexerMatchTokensCase02();
    CppUnitTest::TestCase* testLexerMatchTokensCase03();

    CppUnitTest::TestCase* testLexerMatchTokensCaptureCase01();

    CppUnitTest::TestCase* testSyntaxTestCase01();
}

#endif
