#include <cpp-unit-test.h>
#include <tests.h>

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(RegExpTests::testLexerMatchTokensCase01());

    testSuite.printTotal();

    return 0;
}
