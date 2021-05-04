#include <tests.h>

namespace RegExpTests
{
    void assertEquals(CppUnitTest::TestCase* t, RegExp::TokenType expectedTokenType, RegExp::TokenType actualTokenType)
    {
        t->increment();
        if (expectedTokenType != actualTokenType) {
            throw new CppUnitTest::AssertEqualsException;
        }
    }
}
