#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testExpressionMatchCase01()
    {
        auto t = new CppUnitTest::TestCase("testExpressionMatchCase01: [a-z]+");
        t->printTitle();

        RegExp::Expression::Expression expr("[a-z]+");

        CppUnitTest::assertFalse(t,expr.match("alexander1000"));

        t->finish();
        return t;
    }
}
