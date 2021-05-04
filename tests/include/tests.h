#ifndef REGEXP_TESTS_INCLUDE_H
#define REGEXP_TESTS_INCLUDE_H

#include <string>
#include <cpp-unit-test.h>
#include <regexp.h>

namespace RegExpTests
{
    // asserts
    void assertEquals(CppUnitTest::TestCase* t, RegExp::TokenType expectedTokenType, RegExp::TokenType actualTokenType);

    // test cases
    CppUnitTest::TestCase* testLexerMatchTokensCase01();
}

#endif
