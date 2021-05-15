#ifndef REGEXP_TESTS_INCLUDE_H
#define REGEXP_TESTS_INCLUDE_H

#include <string>
#include <cpp-unit-test.h>
#include <regexp.h>
#include <syntax-tree-lib.h>

namespace RegExpTests
{
    // asserts
    void assertEquals(CppUnitTest::TestCase* t, RegExp::Token::TokenType expectedTokenType, int actualTokenType);
    void assertEqualsTokenValue(CppUnitTest::TestCase* t, const char* expectedResult, SyntaxTree::Token::Token* token);

    // test cases
    CppUnitTest::TestCase* testLexerMatchTokensCase01();
    CppUnitTest::TestCase* testLexerMatchTokensCase02();
    CppUnitTest::TestCase* testLexerMatchTokensCase03();

    CppUnitTest::TestCase* testLexerMatchTokensCaptureCase01();

    CppUnitTest::TestCase* testSyntaxTestCase01();

    CppUnitTest::TestCase* testPredicate_Alphabet_TestCase01();
    CppUnitTest::TestCase* testPredicate_Negative_TestCase01();
    CppUnitTest::TestCase* testPredicate_AlphabetInvert_TestCase01();
    CppUnitTest::TestCase* testPredicate_OneOf_TestCase01();

    CppUnitTest::TestCase* testExpressionMatchCase01();
}

#endif
