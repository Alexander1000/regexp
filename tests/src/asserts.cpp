#include <tests.h>

namespace RegExpTests
{
    void assertEquals(CppUnitTest::TestCase* t, RegExp::Token::TokenType expectedTokenType, RegExp::Token::TokenType actualTokenType)
    {
        t->increment();
        if (expectedTokenType != actualTokenType) {
            throw new CppUnitTest::AssertEqualsException;
        }
    }
}
