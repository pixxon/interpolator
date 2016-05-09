#include <QString>
#include <QtTest>

#include "model/parseval/symbol.h"
#include "model/parseval/tokenizer.h"
#include "model/parseval/parser.h"
#include "model/parseval/evaluator.h"

class TestParseval : public QObject
{
    Q_OBJECT

public:
    TestParseval();

private Q_SLOTS:
    void testSymbol();
    void testTokenizer();
    void testParser();
    void testEvaluator();
};

TestParseval::TestParseval()
{
}

void TestParseval::testSymbol()
{
    SymbolTable* table1 = SymbolTable::getInstance();
    QVERIFY2(table1 != 0, "Hiba: getInstance nullpointerrel tért vissza.");

    SymbolTable* table2 = SymbolTable::getInstance();
    QVERIFY2(table1 == table2, "Hiba: SymbolTable nem singleton.");

    QVERIFY_EXCEPTION_THROWN(table1->operator[]("z"), SymbolException);

    QVERIFY_EXCEPTION_THROWN(table1->removeSymbol("z"), SymbolException);

    table1->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    QVERIFY_EXCEPTION_THROWN(table1->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0), SymbolException);
}

void TestParseval::testTokenizer()
{
    QVERIFY2(true, "Failure");
}

void TestParseval::testParser()
{
    QVERIFY2(true, "Failure");
}

void TestParseval::testEvaluator()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestParseval)

#include "tst_interpolatortest.moc"
