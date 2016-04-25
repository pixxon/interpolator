#include "model.h"
#include <QVector3D>

#include <QDebug>
#include <QTime>
#include <qmath.h>

Model::Model():
    QObject()
{
    table = SymbolTable::getInstance();

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

    evaluator = new Evaluator();

    timer = new QTimer();
    timer->setInterval(33);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));

    interpolator = new Lagrange();
}

Model::~Model()
{
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


void Model::setInput(QVector<QVector<double>> points)
{
	QTime time;
	time.start();

	clear();

	interpolator->clear();
	for (int i = 0; i < partX.getCount(); i++)
	{
		for (int j = 0; j < partY.getCount(); j++)
		{
			interpolator->addData(partX.at(i), partY.at(j), points[i][j]);
		}
	}

	float delta = 0.2f;
	for (float i = partX.at(0); i <= partX.at(partX.getCount() - 1); i += delta)
	{
		for (float j = partY.at(0); j <= partY.at(partY.getCount() - 1); j += delta)
		{
			float tmp = interpolator->calculate(i, j);
			addData({ i, tmp, j }, { 0, 0, 0 });


			tmp = interpolator->calculate(i, j + delta);
			addData({ i, tmp, j + delta }, { 0, 0, 0 });


			tmp = interpolator->calculate(i + delta, j + delta);
			addData({ i + delta, tmp, j + delta }, { 0, 0, 0 });


			tmp = interpolator->calculate(i + delta, j);
			addData({ i + delta, tmp, j }, { 0, 0, 0 });
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

void Model::setPart(char var, double min, double max, int count, QString type)
{
    if (var == 'x')
    {
        if (type == "Egyenletes")
        {
            partX.setPartition(min, max, count, PARTITION_TYPE_EVEN);
        }
        if (type == "Csebisev")
        {
            partX.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
        }
    }
    if (var == 'y')
    {
        if (type == "Egyenletes")
        {
            partY.setPartition(min, max, count, PARTITION_TYPE_EVEN);
        }
        if (type == "Csebisev")
        {
            partY.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
        }
    }

    QVector<double> resultX;
    resultX.resize(partX.getCount());
    for (int i = 0; i < resultX.size(); i++)
    {
        resultX[i] = partX.at(i);
    }

    QVector<double> resultY;
    resultY.resize(partY.getCount());
    for (int i = 0; i < resultY.size(); i++)
    {
        resultY[i] = partY.at(i);
    }

    part_changed(resultX, resultY);
}

