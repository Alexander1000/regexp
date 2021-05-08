#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testPredicateTestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicateTestCase01: [a-z]+");
        t->printTitle();

        RegExp::Lexer lexer("[a-z]+");
        RegExp::Syntax::Tree tree;
        tree.initializeDefaults();

        auto syntaxTree = tree.parse(lexer.parseTokens());

        CppUnitTest::assertNotNull(t, syntaxTree);

        t->finish();
        return t;
    }
}
