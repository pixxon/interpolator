#include "model.h"
#include <QVector3D>

Model::Model():
    QObject()
{
    table = new SymbolTable();
    table->insertSymbol("var", std::regex("^(x|y)"), constant, none, 0, 0);
    table->insertSymbol("num", std::regex("^[[:d:]](\\.[[:d:]])?"), constant, none, 0, 0);
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
    timer->setInterval(10);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));
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

    const float delta = 0.1f;
    for (float i = -3.14f; i < 3.14f; i+=delta)
    {
        for (float j = -3.14f; j < 3.14f; j+=delta)
        {
            float res = evaluator->calculate(i, j);
            emit(addData({i, res, j},
                         {res / 2.0f + 0.5f, res / 2.0f + 0.5f, res / 2.0f + 0.5f}));

            res = evaluator->calculate(i, j + delta);
            emit(addData({i, res, j + delta},
                         {res / 2.0f + 0.5f, res / 2.0f + 0.5f, res / 2.0f + 0.5f}));

            res = evaluator->calculate(i + delta, j + delta);
            emit(addData({i + delta, res, j + delta},
                         {res / 2.0f + 0.5f, res / 2.0f + 0.5f, res / 2.0f + 0.5f}));

            res = evaluator->calculate(i + delta, j);
            emit(addData({i + delta, res, j},
                         {res / 2.0f + 0.5f, res / 2.0f + 0.5f, res / 2.0f + 0.5f}));
        }
    }

    emit(init());
    timer->start();
}

void Model::timerTick()
{
    emit(render());
}

