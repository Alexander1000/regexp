#include <iostream>
#include <cpp-unit-test.h>

CppUnitTest::TestCase* testCase01()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();
    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testCase01());

    testSuite.printTotal();

    return 0;
}
