#include <cpp-unit-test.h>
#include <tests.h>

namespace RegExpTests
{
    CppUnitTest::TestCase* testPredicate_Alphabet_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_Alphabet_TestCase01: [!@#a-z*_0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*_0-9]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto p = new RegExp::Predicate::Alphabet(testTokens);
        CppUnitTest::assertTrue(t, p->calc("alexander"));
        CppUnitTest::assertTrue(t, p->calc("alexander_1990"));
        CppUnitTest::assertTrue(t, p->calc("test_case#@123!"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!-"));

        t->finish();
        return t;
    }

    CppUnitTest::TestCase* testPredicate_Negative_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_Negative_TestCase01: [!@#a-z*_0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*_0-9]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto pa = new RegExp::Predicate::Alphabet(testTokens);
        auto p = new RegExp::Predicate::Negative(pa);
        CppUnitTest::assertFalse(t, p->calc("alexander"));
        CppUnitTest::assertFalse(t, p->calc("alexander_1990"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!"));
        CppUnitTest::assertTrue(t, p->calc("test_case#@123!-"));

        t->finish();
        return t;
    }

    CppUnitTest::TestCase* testPredicate_AlphabetInvert_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_AlphabetInvert_TestCase01: [!@#a-z*_0-9]");
        t->printTitle();

        RegExp::Lexer lexer("[!@#a-z*_0-9]");
        auto tokens = lexer.parseTokens();
        auto tokensIt = tokens->begin();

        tokensIt++; // skip [
        auto testTokens = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokens->push_back(*tokensIt);
            tokensIt++;
        } while (std::next(tokensIt) != tokens->end());

        auto p = new RegExp::Predicate::Alphabet(testTokens, true);
        CppUnitTest::assertFalse(t, p->calc("alexander"));
        CppUnitTest::assertFalse(t, p->calc("alexander_1990"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!-"));
        CppUnitTest::assertTrue(t, p->calc("ABC-DEF"));

        t->finish();
        return t;
    }

    CppUnitTest::TestCase* testPredicate_OneOf_TestCase01()
    {
        auto t = new CppUnitTest::TestCase("testPredicate_OneOf_TestCase01: [a-z]|[0-9]");
        t->printTitle();

        // ABC predicate
        RegExp::Lexer lexerAbc("[a-z]");
        auto tokensAbc = lexerAbc.parseTokens();
        auto tokensAbcIt = tokensAbc->begin();

        tokensAbcIt++; // skip [
        auto testTokensAbc = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokensAbc->push_back(*tokensAbcIt);
            tokensAbcIt++;
        } while (std::next(tokensAbcIt) != tokensAbc->end());

        auto pAbc = new RegExp::Predicate::Alphabet(testTokensAbc);

        // digits predicate
        RegExp::Lexer lexerDigit("[0-9]");
        auto tokensDigit = lexerDigit.parseTokens();
        auto tokensDigitIt = tokensDigit->begin();

        tokensDigitIt++; // skip [
        auto testTokensDigit = new std::list<SyntaxTree::Token::Token*>;

        do {
            testTokensDigit->push_back(*tokensDigitIt);
            tokensDigitIt++;
        } while (std::next(tokensDigitIt) != tokensDigit->end());

        auto pDigits = new RegExp::Predicate::Alphabet(testTokensDigit);

        // one of predicate

        auto pList = new std::list<RegExp::Predicate::Predicate*>;
        pList->push_back(pAbc);
        pList->push_back(pDigits);

        auto p = new RegExp::Predicate::OneOf(pList);

        CppUnitTest::assertTrue(t, p->calc("alexander"));
        CppUnitTest::assertFalse(t, p->calc("alexander_1990"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!"));
        CppUnitTest::assertFalse(t, p->calc("test_case#@123!-"));
        CppUnitTest::assertFalse(t, p->calc("ABC-DEF"));
        CppUnitTest::assertTrue(t, p->calc("7473853"));

        t->finish();
        return t;
    }
}
