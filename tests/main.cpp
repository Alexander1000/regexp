#include <iostream>
#include <cpp-unit-test.h>
#include <regexp.h>

CppUnitTest::TestCase* testCase01()
{
    CppUnitTest::TestCase* t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();

    RegExp::Lexer lexer("[a-z]+");
    auto tokens = lexer.parseTokens();

    CppUnitTest::assertEquals(t, 4, tokens->size());

    auto tokenIt = tokens->begin();
    (*tokenIt)->getType();

    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testCase01());

    testSuite.printTotal();

    return 0;
}
