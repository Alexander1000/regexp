#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testSyntaxTestCase01()
    {
        auto t = new CppUnitTest::TestCase("testSyntaxTestCase01: [a-z]+");
        t->printTitle();

        t->finish();
        return t;
    }
}
