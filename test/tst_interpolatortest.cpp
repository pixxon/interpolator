#include <QString>
#include <QtTest>

#include "../src/model/parseval/symbol.h"
#include "../src/model/parseval/tokenizer.h"
#include "../src/model/parseval/parser.h"
#include "../src/model/parseval/evaluator.h"

#include "../src/model/interpolate/newton.h"
#include "../src/model/interpolate/lagrange.h"

class InterpolatorTest : public QObject
{
    Q_OBJECT

public:
    InterpolatorTest();

private Q_SLOTS:
    void SymbolTest();
    void TokenizerTest();
    void ParserTest();
    void EvaluatorTest();
    void LagrangeTest();
    void NewtonTest();
};

InterpolatorTest::InterpolatorTest()
{
    Model::Parseval::SymbolTable* table = Model::Parseval::SymbolTable::getInstance();
    table->insertSymbol("var", QRegExp("^(x|y)"), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("num", QRegExp("^[0-9]+(\\.[0-9]+)?"), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("open", QRegExp("^\\("), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("close", QRegExp("^\\)"), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0);

    table->insertSymbol("add", QRegExp("^\\+"), Model::Parseval::ARITY_BINARY, Model::Parseval::ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a + b; });
    table->insertSymbol("min", QRegExp("^-"), Model::Parseval::ARITY_BINARY, Model::Parseval::ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a - b; });
    table->insertSymbol("mul", QRegExp("^\\*"), Model::Parseval::ARITY_BINARY, Model::Parseval::ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a * b; });
    table->insertSymbol("div", QRegExp("^/"), Model::Parseval::ARITY_BINARY, Model::Parseval::ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a / b; });
    table->insertSymbol("pow", QRegExp("^\\^"), Model::Parseval::ARITY_BINARY, Model::Parseval::ASSOCIATIVITY_RIGHT, 3, [](double a, double b){ return pow(a, b); });

    table->insertSymbol("abs", QRegExp("^abs"), Model::Parseval::ARITY_UNARY, Model::Parseval::ASSOCIATIVITY_NONE, 0, [](double a, double){ return a<0?-a:a; });

    table->insertSymbol("sin", QRegExp("^sin"), Model::Parseval::ARITY_UNARY, Model::Parseval::ASSOCIATIVITY_NONE, 0, [](double a, double){ return sin(a); });
    table->insertSymbol("cos", QRegExp("^cos"), Model::Parseval::ARITY_UNARY, Model::Parseval::ASSOCIATIVITY_NONE, 0, [](double a, double){ return cos(a); });
    table->insertSymbol("tg", QRegExp("^tg"), Model::Parseval::ARITY_UNARY, Model::Parseval::ASSOCIATIVITY_NONE, 0, [](double a, double){ return tan(a); });
    table->insertSymbol("ctg", QRegExp("^ctg"), Model::Parseval::ARITY_UNARY, Model::Parseval::ASSOCIATIVITY_NONE, 0, [](double a, double){ return 1 / tan(a); });
}

void InterpolatorTest::SymbolTest()
{
    Model::Parseval::SymbolTable* table1 = Model::Parseval::SymbolTable::getInstance();
    QVERIFY2(table1 != 0, "Hiba: getInstance nullpointerrel tért vissza.");

    Model::Parseval::SymbolTable* table2 = Model::Parseval::SymbolTable::getInstance();
    QVERIFY2(table1 == table2, "Hiba: SymbolTable nem singleton.");

    QVERIFY_EXCEPTION_THROWN(table1->operator[]("z"), Model::Parseval::SymbolException);

    QVERIFY_EXCEPTION_THROWN(table1->removeSymbol("z"), Model::Parseval::SymbolException);

    table1->insertSymbol("var2", QRegExp("^(x|y)"), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0);
    QVERIFY_EXCEPTION_THROWN(table1->insertSymbol("var2", QRegExp("^(x|y)"), Model::Parseval::ARITY_CONSTANT, Model::Parseval::ASSOCIATIVITY_NONE, 0, 0),
                             Model::Parseval::SymbolException);
}

void InterpolatorTest::TokenizerTest()
{
    Model::Parseval::Tokenizer tokenizer;
    tokenizer.setInput("sin(x)*cos(y)");

    bool fail = false;
    while(tokenizer.hasNext())
    {
        try
        {
            tokenizer.next();
        }catch(QException)
        {
            fail = true;
            break;
        }
    }
    QCOMPARE(fail, false);

    tokenizer.setInput("sin(x)*cos(5.123)");
    fail = false;
    while(tokenizer.hasNext())
    {
        try
        {
            tokenizer.next();
        }catch(QException)
        {
            fail = true;
            break;
        }
    }
    QCOMPARE(fail, false);

    tokenizer.setInput("sin(asd)*cos(y)");
    fail = false;
    while(tokenizer.hasNext())
    {
        try
        {
            tokenizer.next();
        }catch(QException)
        {
            fail = true;
            break;
        }
    }
    QCOMPARE(fail, true);

    tokenizer.setInput("asd");
    fail = false;
    while(tokenizer.hasNext())
    {
        try
        {
            tokenizer.next();
        }catch(QException)
        {
            fail = true;
            break;
        }
    }
    QCOMPARE(fail, true);

    tokenizer.setInput("5.123.123*x");
    fail = false;
    while(tokenizer.hasNext())
    {
        try
        {
            tokenizer.next();
        }catch(QException)
        {
            fail = true;
            break;
        }
    }
    QCOMPARE(fail, true);
}

void InterpolatorTest::ParserTest()
{
    Model::Parseval::Parser parser;

    parser.setInput("x*y");
    QVERIFY(parser.getTree() != 0);

    parser.setInput("((x*-5)+y*(x/y))");
    QVERIFY(parser.getTree() != 0);

    parser.setInput("sin(4*x)-cos(y)");
    QVERIFY(parser.getTree() != 0);

    parser.setInput("x**y");
    QVERIFY_EXCEPTION_THROWN(parser.getTree(), Model::Parseval::ParserException);

    parser.setInput("(x**y)x");
    QVERIFY_EXCEPTION_THROWN(parser.getTree(), Model::Parseval::ParserException);

    parser.setInput(")*x");
    QVERIFY_EXCEPTION_THROWN(parser.getTree(), Model::Parseval::ParserException);

    parser.setInput("sin*x");
    QVERIFY_EXCEPTION_THROWN(parser.getTree(), Model::Parseval::ParserException);
}

void InterpolatorTest::EvaluatorTest()
{
    Model::Parseval::Evaluator evaluator;

    evaluator.setExpression("sin(x)*cos(y)");
    QCOMPARE(evaluator.calculate(0,0), 0.0);
    QCOMPARE(evaluator.calculate(M_PI / 2.f,0), 1.0);
    QCOMPARE(evaluator.calculate(M_PI/3, M_PI/5), evaluator.calculate(M_PI/3, M_PI/5));

    evaluator.setExpression("2*x+y");
    QCOMPARE(evaluator.calculate(3,10), 16.0);
    QCOMPARE(evaluator.calculate(0, 7), 7.0);
}

void InterpolatorTest::LagrangeTest()
{
    Model::Interpolate::Lagrange lagrange;

    lagrange.addData(3, 9, 6);
    lagrange.addData(3, 5, -4);
    lagrange.addData(6, 5, 0);
    lagrange.addData(6, 9, 7);

    lagrange.initialize();
    QCOMPARE(lagrange.calculate(3, 9), 6.0);
    QCOMPARE(lagrange.calculate(3, 5), -4.0);
    QCOMPARE(lagrange.calculate(6, 5), 0.0);
    QCOMPARE(lagrange.calculate(6, 9), 7.0);
}

void InterpolatorTest::NewtonTest()
{
    Model::Interpolate::Newton newton;

    newton.addData(-10, 0, 6);
    newton.addData(-3, 0, -4);
    newton.addData(8, 0, 1);

    newton.initialize();
    QCOMPARE(newton.calculate(-10, 0), 6.0);
    QCOMPARE(newton.calculate(-3, 0), -4.0);
    QCOMPARE(newton.calculate(8, 0), 1.0);
}

QTEST_APPLESS_MAIN(InterpolatorTest)

#include "tst_interpolatortest.moc"
