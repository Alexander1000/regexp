#include <cpp-unit-test.h>
#include <tests.h>

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(RegExpTests::testLexerMatchTokensCase01());
    testSuite.addTestCase(RegExpTests::testLexerMatchTokensCase02());
    testSuite.addTestCase(RegExpTests::testLexerMatchTokensCase03());

    testSuite.addTestCase(RegExpTests::testLexerMatchTokensCaptureCase01());

    testSuite.addTestCase(RegExpTests::testSyntaxTestCase01());

    testSuite.addTestCase(RegExpTests::testPredicate_Alphabet_TestCase01());
    testSuite.addTestCase(RegExpTests::testPredicate_Negative_TestCase01());
    testSuite.addTestCase(RegExpTests::testPredicate_AlphabetInvert_TestCase01());
    testSuite.addTestCase(RegExpTests::testPredicate_OneOf_TestCase01());

    testSuite.printTotal();

    return 0;
}
