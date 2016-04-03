#include "model.h"
#include <QVector3D>

#include <QDebug>
#include <QTime>

Model::Model():
    QObject()
{
    table = new SymbolTable();
    table->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("num", QRegExp("^[0-9]+(\\.[0-9]+)?"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("open", QRegExp("^\\("), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    table->insertSymbol("close", QRegExp("^\\)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);

    table->insertSymbol("add", QRegExp("^\\+"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a + b; });
    table->insertSymbol("min", QRegExp("^-"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a - b; });
    table->insertSymbol("mul", QRegExp("^\\*"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a * b; });
    table->insertSymbol("div", QRegExp("^/"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a / b; });
    table->insertSymbol("pow", QRegExp("^\\^"), ARITY_BINARY, ASSOCIATIVITY_RIGHT, 3, [](double a, double b){ return pow(a, b); });

    table->insertSymbol("abs", QRegExp("^abs"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return a<0?-a:a; });

    table->insertSymbol("sin", QRegExp("^sin"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return sin(a); });
    table->insertSymbol("cos", QRegExp("^cos"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return cos(a); });
    table->insertSymbol("tg", QRegExp("^tg"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return tan(a); });
    table->insertSymbol("ctg", QRegExp("^ctg"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return 1 / tan(a); });

    evaluator = new Evaluator(table);

    timer = new QTimer();
    timer->setInterval(33);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));

    interpolator = new Lagrange(table);
}

Model::~Model()
{
    delete table;
    delete evaluator;
    delete timer;
}

void Model::setInput(QString str)
{
    QTime time;
    time.start();

    clear();

    evaluator->setExpression(str);

    interpolator->clear();
    for (int i = 0; i < partX.getCount(); i++)
    {
        for (int j = 0; j < partY.getCount(); j++)
        {
            interpolator->addData(partX.at(i), partY.at(j), evaluator->calculate(partX.at(i), partY.at(j)));
        }
    }

    float delta = 0.1f;
    for (float i = partX.at(0); i <= partX.at(partX.getCount() - 1); i+= delta)
    {
        for (float j = partY.at(0); j <= partY.at(partY.getCount() - 1); j+= delta)
        {
            float tmp = interpolator->calculate(i, j);
            float tmp2 = evaluator->calculate(i, j);
            float diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addData({i, tmp, j}, {diff, diff, diff});
            addData2({i, tmp2, j}, {diff, diff, diff});


            tmp = interpolator->calculate(i, j + delta);
            tmp2 = evaluator->calculate(i, j + delta);
            diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addData({i, tmp, j + delta}, {diff, diff, diff});
            addData2({i, tmp2, j + delta}, {diff, diff, diff});


            tmp = interpolator->calculate(i + delta, j + delta);
            tmp2 = evaluator->calculate(i + delta, j + delta);
            diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addData({i + delta, tmp, j + delta}, {diff, diff, diff});
            addData2({i + delta, tmp2, j + delta}, {diff, diff, diff});


            tmp = interpolator->calculate(i + delta, j);
            tmp2 = evaluator->calculate(i + delta, j);
            diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addData({i + delta, tmp, j}, {diff, diff, diff});
            addData2({i + delta, tmp2, j}, {diff, diff, diff});
        }
    }


    init();

    qDebug() << time.elapsed();

    timer->start();
}

void Model::timerTick()
{
    render();
}

void Model::setPartX(double min, double max, int count, QString type)
{
    if (type == "Egyenletes")
    {
        partX.setPartition(min, max, count, PARTITION_TYPE_EVEN);
    }
    if (type == "Csebisev")
    {
        partX.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
    }

    QVector<double> resultX;
    for (int i = 0; i < partX.getCount(); i++)
    {
        resultX.push_back(partX.at(i));
    }

    QVector<double> resultY;
    for (int i = 0; i < partY.getCount(); i++)
    {
        resultY.push_back(partY.at(i));
    }

    part_changed(resultX, resultY);
}

void Model::setPartY(double min, double max, int count, QString type)
{
    if (type == "Egyenletes")
    {
        partY.setPartition(min, max, count, PARTITION_TYPE_EVEN);
    }
    if (type == "Csebisev")
    {
        partY.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
    }

    QVector<double> resultX;
    for (int i = 0; i < partX.getCount(); i++)
    {
        resultX.push_back(partX.at(i));
    }

    QVector<double> resultY;
    for (int i = 0; i < partY.getCount(); i++)
    {
        resultY.push_back(partY.at(i));
    }

    part_changed(resultX, resultY);
}
