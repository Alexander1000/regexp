#include <tests.h>

namespace RegExpTests
{
    void assertEquals(CppUnitTest::TestCase* t, RegExp::Token::TokenType expectedTokenType, int actualTokenType)
    {
        t->increment();
        if (expectedTokenType != actualTokenType) {
            throw new CppUnitTest::AssertEqualsException;
        }
    }
}
