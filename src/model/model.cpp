#include "model.h"
#include <QVector3D>

#include <QDebug>
#include <QTime>
#include <qmath.h>

Model::Model():
    QObject()
{
    _table = SymbolTable::getInstance();

    _table->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    _table->insertSymbol("num", QRegExp("^[0-9]+(\\.[0-9]+)?"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    _table->insertSymbol("open", QRegExp("^\\("), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    _table->insertSymbol("close", QRegExp("^\\)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);

    _table->insertSymbol("add", QRegExp("^\\+"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a + b; });
    _table->insertSymbol("min", QRegExp("^-"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 1, [](double a, double b){ return a - b; });
    _table->insertSymbol("mul", QRegExp("^\\*"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a * b; });
    _table->insertSymbol("div", QRegExp("^/"), ARITY_BINARY, ASSOCIATIVITY_LEFT, 2, [](double a, double b){ return a / b; });
    _table->insertSymbol("pow", QRegExp("^\\^"), ARITY_BINARY, ASSOCIATIVITY_RIGHT, 3, [](double a, double b){ return pow(a, b); });

    _table->insertSymbol("abs", QRegExp("^abs"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return a<0?-a:a; });

    _table->insertSymbol("sin", QRegExp("^sin"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return sin(a); });
    _table->insertSymbol("cos", QRegExp("^cos"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return cos(a); });
    _table->insertSymbol("tg", QRegExp("^tg"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return tan(a); });
    _table->insertSymbol("ctg", QRegExp("^ctg"), ARITY_UNARY, ASSOCIATIVITY_NONE, 0, [](double a, double){ return 1 / tan(a); });

    _evaluator = new Evaluator();

    _timer = new QTimer();
    _timer->setInterval(33);
    QObject::connect(_timer, SIGNAL(timeout()), this, SLOT(timerTick()));
    _timer->start();

    _interpolator = new Lagrange();

    _oneDimension = false;
}

Model::~Model()
{
    delete _evaluator;
    delete _timer;
}

void Model::setInput(QString str)
{
    clear();

    messageLoop("Függvény elemzése, szintaxisfa felépítése.");

    try
    {
        _evaluator->setExpression(str);
    }
    catch(QException& ex)
    {
        error(ex.what());
        return;
    }

    messageLoop("Függvény értékének kiszámítása alappontokban.");

    _interpolator->clear();
    for (int i = 0; i < _partX.getCount(); i++)
    {
        if (_oneDimension)
        {
            _interpolator->addData(_partX.at(i), 0, _evaluator->calculate(_partX.at(i), 0));
        }
        else
        {
            for (int j = 0; j < _partY.getCount(); j++)
            {
                _interpolator->addData(_partX.at(i), _partY.at(j), _evaluator->calculate(_partX.at(i), _partY.at(j)));
            }
        }
    }

    messageLoop("Interpolációs polinom előállítása.");
    messageLoop("Függvény és közelítés kiértékelése a megjelenítéshez.");

    float deltaX = (_partX.at(_partX.getCount() - 1) - _partX.at(0)) / 50.f;
    for (float i = _partX.at(0); i <= _partX.at(_partX.getCount() - 1); i+= deltaX)
    {
        if (_oneDimension)
        {
            float tmp = _interpolator->calculate(i, 0);
            float tmp2 = _evaluator->calculate(i, 0);
            float diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addInterPoint({i, tmp, 0}, {diff, diff, diff});
            addFuncPoint({i, tmp2, 0}, {diff, diff, diff});


            tmp = _interpolator->calculate(i + deltaX, 0);
            tmp2 = _evaluator->calculate(i + deltaX, 0);
            diff = tmp - tmp2;
            if (diff < 0)
            {
                diff *= -1;
            }

            addInterPoint({i + deltaX, tmp, 0}, {diff, diff, diff});
            addFuncPoint({i + deltaX, tmp2, 0}, {diff, diff, diff});
        }
        else
        {
            float deltaY = (_partY.at(_partY.getCount() - 1) - _partY.at(0)) / 50.f;
            for (float j = _partY.at(0); j <= _partY.at(_partY.getCount() - 1); j+= deltaY)
            {
                float tmp = _interpolator->calculate(i, j);
                float tmp2 = _evaluator->calculate(i, j);
                float diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }

                addInterPoint({i, tmp, j}, {diff, diff, diff});
                addFuncPoint({i, tmp2, j}, {diff, diff, diff});


                tmp = _interpolator->calculate(i, j + deltaY);
                tmp2 = _evaluator->calculate(i, j + deltaY);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }

                addInterPoint({i, tmp, j + deltaY}, {diff, diff, diff});
                addFuncPoint({i, tmp2, j + deltaY}, {diff, diff, diff});


                tmp = _interpolator->calculate(i + deltaX, j + deltaY);
                tmp2 = _evaluator->calculate(i + deltaX, j + deltaY);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }

                addInterPoint({i + deltaX, tmp, j + deltaY}, {diff, diff, diff});
                addFuncPoint({i + deltaX, tmp2, j + deltaY}, {diff, diff, diff});


                tmp = _interpolator->calculate(i + deltaX, j);
                tmp2 = _evaluator->calculate(i + deltaX, j);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }

                addInterPoint({i + deltaX, tmp, j}, {diff, diff, diff});
                addFuncPoint({i + deltaX, tmp2, j}, {diff, diff, diff});
            }
        }
    }

    messageLoop("Adatok betöltése a grafikus kártyára, inicializálás.");

    init();
}

void Model::setInput(QVector<QVector<double>> points)
{
	clear();

    messageLoop("Alappontok beállítása az interpolációhoz.");

    _interpolator->clear();
    for (int i = 0; i < _partX.getCount(); i++)
    {
            for (int j = 0; j < _partY.getCount(); j++)
            {
                _interpolator->addData(_partX.at(i), _partY.at(j), points[j][i]);
            }
	}

    messageLoop("Interpolációs polinom előállítása.");
    messageLoop("Közelítés kiértékelése a megjelenítéshez.");

    double deltaX = (_partX.at(_partX.getCount() - 1) - _partX.at(0)) / 50.f;
    for (double i = _partX.at(0); i <= _partX.at(_partX.getCount() - 1); i+= deltaX)
    {
        if (_oneDimension)
        {
            double tmp = _interpolator->calculate(i, _partY.at(0));
            addInterPoint(QVector3D(i, tmp, _partY.at(0)), {0, 0, 0});


            tmp = _interpolator->calculate(i + deltaX, _partY.at(0));
            addInterPoint(QVector3D(i + deltaX, tmp, _partY.at(0)), {0, 0, 0});
        }
        else
        {
            double deltaY = (_partY.at(_partY.getCount() - 1) - _partY.at(0)) / 50.f;
            for (double j = _partY.at(0); j <= _partY.at(_partY.getCount() - 1); j+= deltaY)
            {
                double tmp = _interpolator->calculate(i, j);
                addInterPoint(QVector3D(i, tmp, j), {0, 0, 0});


                tmp = _interpolator->calculate(i, j + deltaY);
                addInterPoint(QVector3D(i, tmp, j + deltaY), {0, 0, 0});


                tmp = _interpolator->calculate(i + deltaX, j + deltaY);
                addInterPoint(QVector3D(i + deltaX, tmp, j + deltaY), {0, 0, 0});


                tmp = _interpolator->calculate(i + deltaX, j);
                addInterPoint(QVector3D(i + deltaX, tmp, j), {0, 0, 0});
            }
        }
	}

    messageLoop("Adatok betöltése a grafikus kártyára, inicializálás.");

    init();
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
            _partX.setPartition(min, max, count, PARTITION_TYPE_EVEN);
        }
        if (type == "Csebisev")
        {
            _partX.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
        }
    }
    if (var == 'y')
    {
        if (type == "Egyenletes")
        {
            _partY.setPartition(min, max, count, PARTITION_TYPE_EVEN);
        }
        if (type == "Csebisev")
        {
            _partY.setPartition(min, max, count, PARTITION_TYPE_CHEBYSHEV);
        }
    }

    QVector<double> resultX;
    resultX.resize(_partX.getCount());
    for (int i = 0; i < resultX.size(); i++)
    {
        resultX[i] = _partX.at(i);
    }

    QVector<double> resultY;
    resultY.resize(_partY.getCount());
    for (int i = 0; i < resultY.size(); i++)
    {
        resultY[i] = _partY.at(i);
    }

    partChanged(resultY, resultX);
}

void Model::setPart(char var, QVector<double> points)
{
    if (var == 'y')
    {
        _partY.setPoints(points);
    }
    if (var == 'x')
    {
        _partX.setPoints(points);
    }

    QVector<double> resultX;
    resultX.resize(_partX.getCount());
    for (int i = 0; i < resultX.size(); i++)
    {
        resultX[i] = _partX.at(i);
    }

    QVector<double> resultY;
    resultY.resize(_partY.getCount());
    for (int i = 0; i < resultY.size(); i++)
    {
        resultY[i] = _partY.at(i);
    }

    partChanged(resultY, resultX);
}

void Model::setOneDimension(bool enabled)
{
    if (enabled)
    {
        _table->removeSymbol("var");
        _table->insertSymbol("var", QRegExp("^x"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    }
    else
    {
        _table->removeSymbol("var");
        _table->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
    }
    _oneDimension = enabled;
}

void Model::advance()
{
    _advance = true;
}

void Model::messageLoop(QString msg)
{
    message(msg);
    _advance = false;
    while (!_advance);
}
