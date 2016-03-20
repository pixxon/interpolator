#include "model.h"
#include <QVector3D>

#include <QDebug>

Model::Model():
    QObject()
{
    table = new SymbolTable();
    table->insertSymbol("var", std::regex("^(x|y)"), constant, none, 0, 0);
    table->insertSymbol("num", std::regex("^[0-9]+(\\.[0-9]+)?"), constant, none, 0, 0);
    table->insertSymbol("open", std::regex("^\\("), constant, none, 0, 0);
    table->insertSymbol("close", std::regex("^\\)"), constant, none, 0, 0);

    table->insertSymbol("add", std::regex("^\\+"), binary, asd, 1, [](double a, double b){ return a + b; });
    table->insertSymbol("min", std::regex("^-"), binary, asd, 1, [](double a, double b){ return a - b; });
    table->insertSymbol("mul", std::regex("^\\*"), binary, asd, 2, [](double a, double b){ return a * b; });
    table->insertSymbol("div", std::regex("^/"), binary, asd, 2, [](double a, double b){ return a / b; });
    table->insertSymbol("pow", std::regex("^\\^"), binary, dsa, 3, [](double a, double b){ return pow(a, b); });

    table->insertSymbol("abs", std::regex("^abs"), unary, none, 0, [](double a, double){ return abs(a); });

    table->insertSymbol("sin", std::regex("^sin"), unary, none, 0, [](double a, double){ return sin(a); });
    table->insertSymbol("cos", std::regex("^cos"), unary, none, 0, [](double a, double){ return cos(a); });
    table->insertSymbol("tg", std::regex("^tg"), unary, none, 0, [](double a, double){ return tan(a); });
    table->insertSymbol("ctg", std::regex("^ctg"), unary, none, 0, [](double a, double){ return 1 / tan(a); });

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
    evaluator->setExpression(str.toStdString());

    for (float i = -5; i < 5; i+= 1.0)
    {
        for (float j = -5; j < 5; j+= 1.0)
        {
            interpolator->addData(i, j, evaluator->calculate(i, j));
        }
    }

    float delta = 0.1f;
    for (float i = -5; i < 4; i+= delta)
    {
        for (float j = -5; j < 4; j+= delta)
        {
            float tmp = interpolator->calculate(i, j);
            float diff = tmp - evaluator->calculate(i, j);
            if (diff < 0)
            {
                diff *= -1;
            }

            emit(addData({i, tmp, j}, {diff, diff, diff}));


            tmp = interpolator->calculate(i, j + delta);
            diff = tmp - evaluator->calculate(i, j + delta);
            if (diff < 0)
            {
                diff *= -1;
            }

            emit(addData({i, tmp, j + delta}, {diff, diff, diff}));


            tmp = interpolator->calculate(i + delta, j + delta);
            diff = tmp - evaluator->calculate(i + delta, j + delta);
            if (diff < 0)
            {
                diff *= -1;
            }

            emit(addData({i + delta, tmp, j + delta}, {diff, diff, diff}));


            tmp = interpolator->calculate(i + delta, j);
            diff = tmp - evaluator->calculate(i + delta, j);
            if (diff < 0)
            {
                diff *= -1;
            }

            emit(addData({i + delta, tmp, j}, {diff, diff, diff}));
        }
    }


    emit(init());
    timer->start();
}

void Model::timerTick()
{
    emit(render());
}

