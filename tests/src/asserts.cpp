#include <tests.h>
#include <memory>
#include <syntax-tree-lib.h>

namespace RegExpTests
{
    void assertEquals(CppUnitTest::TestCase* t, RegExp::Token::TokenType expectedTokenType, int actualTokenType)
    {
        t->increment();
        if (expectedTokenType != actualTokenType) {
            throw new CppUnitTest::AssertEqualsException;
        }
    }

    void assertEqualsTokenValue(CppUnitTest::TestCase* t, const char* expectedResult, SyntaxTree::Token::Token* token)
    {
        t->increment();
        char* actualValue = (char*) malloc(sizeof(char) * (strlen(expectedResult) + 1));
        memset(actualValue, 0, sizeof(char) * (strlen(expectedResult) + 1));
        auto reader = token->getReader();
        if (reader == nullptr) {
            throw new CppUnitTest::AssertEqualsException;
        }
        reader->read(actualValue, strlen(expectedResult));
        CppUnitTest::assertEquals(t, expectedResult, actualValue);
    }
}
