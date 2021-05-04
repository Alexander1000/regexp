#include <iostream>
#include <cpp-unit-test.h>
#include <regexp.h>
#include <tests.h>

CppUnitTest::TestCase* testCase01()
{
    auto t = new CppUnitTest::TestCase("001-simple-test");
    t->printTitle();

    RegExp::Lexer lexer("[a-z]+");
    auto tokens = lexer.parseTokens();

    CppUnitTest::assertEquals(t, 4, tokens->size());

    auto tokenIt = tokens->begin();
    RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketOpen, (*tokenIt)->getType());
    CppUnitTest::assertEquals(t, "[", (*tokenIt)->getData());

    tokenIt++;
    RegExpTests::assertEquals(t, RegExp::TokenType::AlphabetRange, (*tokenIt)->getType());
    CppUnitTest::assertEquals(t, "a-z", (*tokenIt)->getData());

    tokenIt++;
    RegExpTests::assertEquals(t, RegExp::TokenType::SquareBracketClose, (*tokenIt)->getType());
    CppUnitTest::assertEquals(t, "]", (*tokenIt)->getData());

    tokenIt++;
    RegExpTests::assertEquals(t, RegExp::TokenType::Quantifier, (*tokenIt)->getType());
    CppUnitTest::assertEquals(t, "+", (*tokenIt)->getData());

    t->finish();
    return t;
}

int main() {
    CppUnitTest::TestSuite testSuite;

    testSuite.addTestCase(testCase01());

    testSuite.printTotal();

    return 0;
}
