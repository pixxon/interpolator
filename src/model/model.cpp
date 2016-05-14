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

    _twoDimension = false;
}

Model::~Model()
{
    delete _evaluator;
    delete _timer;
    delete _interpolator;
}

void Model::setInput(QString str)
{
    clear();

    try
    {
        _evaluator->setExpression(str);
    }
    catch(QException& ex)
    {
        error(ex.what());
        _evaluator->setExpression("x");
        return;
    }

    messageLoop("Függvény elemzése, szintaxisfa felépítése.\n\n" + _evaluator->toString());

    _interpolator->clear();
    for (int i = 0; i < _partX.getCount(); i++)
    {
        if (_twoDimension)
        {
            double res = _evaluator->calculate(_partX.at(i), 0);
            _interpolator->addData(_partX.at(i), 0, res);
            addCommonPoint(QVector3D(_partX.at(i), res, 0));
        }
        else
        {
            for (int j = 0; j < _partY.getCount(); j++)
            {
                double res = _evaluator->calculate(_partX.at(i), _partY.at(j));
                _interpolator->addData(_partX.at(i), _partY.at(j),res);
                addCommonPoint(QVector3D(_partX.at(i), res, _partY.at(j)));
            }
        }
    }

    messageLoop("Függvény értékének kiszámítása alappontokban.\n\n" +
                QString::number(_partX.getCount()) + (_twoDimension?"":(" x " + QString::number(_partX.getCount()))) + " pontban.");

    _interpolator->initialize();

    messageLoop("Interpolációs polinom előállítása.\n\n" +
                _interpolator->sampleData());

    messageLoop(QString("Függvény és közelítés kiértékelése a megjelenítéshez.\n\n") +
                "50" + (_twoDimension?"":" x 50") + " pontban.");



    double maxDiff = 0;
    double deltaX = (_partX.at(_partX.getCount() - 1) - _partX.at(0)) / 50.f;
    for (double i = _partX.at(0); i <= _partX.at(_partX.getCount() - 1); i+= deltaX)
    {
        if (_twoDimension)
        {
            double tmp1 = _interpolator->calculate(i, 0);
            double tmp2 = _evaluator->calculate(i, 0);
            double diff1 = tmp1 - tmp2;
            if (diff1 < 0)
            {
                diff1 *= -1;
            }
            maxDiff = (maxDiff < diff1)?diff1:maxDiff;

            double tmp3 = _interpolator->calculate(i + deltaX, 0);
            double tmp4 = _evaluator->calculate(i + deltaX, 0);
            double diff2 = tmp3 - tmp4;
            if (diff2 < 0)
            {
                diff2 *= -1;
            }
            maxDiff = (maxDiff < diff2)?diff2:maxDiff;

            addInterPoint(QVector3D(i, tmp1, 0), QVector3D(diff1, diff1, diff1));
            addInterPoint(QVector3D(i + deltaX, tmp3, 0), QVector3D(diff2, diff2, diff2));

            addDiffPoint(QVector3D(i, diff1, 0), QVector3D(1, 1, 1));
            addDiffPoint(QVector3D(i + deltaX, diff2, 0), QVector3D(1, 1, 1));

            addInterPoint(QVector3D(i, tmp2, 0), QVector3D(0, 0, 0));
            addInterPoint(QVector3D(i + deltaX, tmp4, 0), QVector3D(0, 0, 0));
        }
        else
        {
            double deltaY = (_partY.at(_partY.getCount() - 1) - _partY.at(0)) / 50.f;
            for (double j = _partY.at(0); j <= _partY.at(_partY.getCount() - 1); j+= deltaY)
            {
                double tmp = _interpolator->calculate(i, j);
                double tmp2 = _evaluator->calculate(i, j);
                double diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }
                maxDiff = (maxDiff < diff)?diff:maxDiff;

                addInterPoint(QVector3D(i, tmp, j), QVector3D(diff, diff, diff));
                addFuncPoint(QVector3D(i, tmp2, j), QVector3D(0, 0, 0));
                addDiffPoint(QVector3D(i, diff, j), QVector3D(1, 1, 1));


                tmp = _interpolator->calculate(i, j + deltaY);
                tmp2 = _evaluator->calculate(i, j + deltaY);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }
                maxDiff = (maxDiff < diff)?diff:maxDiff;

                addInterPoint(QVector3D(i, tmp, j + deltaY), QVector3D(diff, diff, diff));
                addFuncPoint(QVector3D(i, tmp2, j + deltaY), QVector3D(0.1, 0.1, 0.1));
                addDiffPoint(QVector3D(i, diff, j + deltaY), QVector3D(0.9, 0.9, 0.9));


                tmp = _interpolator->calculate(i + deltaX, j + deltaY);
                tmp2 = _evaluator->calculate(i + deltaX, j + deltaY);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }
                maxDiff = (maxDiff < diff)?diff:maxDiff;

                addInterPoint(QVector3D(i + deltaX, tmp, j + deltaY), QVector3D(diff, diff, diff));
                addFuncPoint(QVector3D(i + deltaX, tmp2, j + deltaY), QVector3D(0, 0, 0));
                addDiffPoint(QVector3D(i + deltaX, diff, j + deltaY), QVector3D(1, 1, 1));


                tmp = _interpolator->calculate(i + deltaX, j);
                tmp2 = _evaluator->calculate(i + deltaX, j);
                diff = tmp - tmp2;
                if (diff < 0)
                {
                    diff *= -1;
                }
                maxDiff = (maxDiff < diff)?diff:maxDiff;

                addInterPoint(QVector3D(i + deltaX, tmp, j), QVector3D(diff, diff, diff));
                addFuncPoint(QVector3D(i + deltaX, tmp2, j), QVector3D(0.1, 0.1, 0.1));
                addDiffPoint(QVector3D(i + deltaX, diff, j), QVector3D(0.9, 0.9, 0.9));
            }
        }
    }

    messageLoop(QString("A kiértékelések után, a legnagyobb abszolút hiba " +
                        QString::number(maxDiff, 'f', 4) + " volt."));

    messageLoop(QString("OpenGL inicializás és adatok betöltése a grafikus kártyára.\n\n") +
                "Shaderek betöltése, shaderprogram összekapcsolása.\n" +
                "50" + (_twoDimension?"":" x 50") + " pont másolása.");

    init();
}

void Model::setInput(QVector<QVector<double>> points)
{
	clear();

    messageLoop("Alappontok beállítása az interpolációhoz.\n\n" +
                QString::number(_partX.getCount()) + (_twoDimension?"":(" x " + QString::number(_partX.getCount()))) + " pontban.");

    _interpolator->clear();
    for (int i = 0; i < _partX.getCount(); i++)
    {
            for (int j = 0; j < _partY.getCount(); j++)
            {
                _interpolator->addData(_partX.at(i), _partY.at(j), points[j][i]);
                addCommonPoint(QVector3D(_partX.at(i), points[j][i], _partY.at(j)));
            }
    }

    _interpolator->initialize();

    messageLoop("Interpolációs polinom előállítása.\n\n" +
                _interpolator->sampleData());

    messageLoop(QString("Közelítő polinom kiértékelése a megjelenítéshez.\n\n") +
                "50" + (_twoDimension?"":" x 50") + " pontban.");

    double deltaX = (_partX.at(_partX.getCount() - 1) - _partX.at(0)) / 50.f;
    for (double i = _partX.at(0); i <= _partX.at(_partX.getCount() - 1); i+= deltaX)
    {
        if (_twoDimension)
        {
            double tmp = _interpolator->calculate(i, _partY.at(0));
            addInterPoint(QVector3D(i, tmp, _partY.at(0)), QVector3D(0, 0, 0));


            tmp = _interpolator->calculate(i + deltaX, _partY.at(0));
            addInterPoint(QVector3D(i + deltaX, tmp, _partY.at(0)), QVector3D(0, 0, 0));
        }
        else
        {
            double deltaY = (_partY.at(_partY.getCount() - 1) - _partY.at(0)) / 50.f;
            for (double j = _partY.at(0); j <= _partY.at(_partY.getCount() - 1); j+= deltaY)
            {
                double tmp = _interpolator->calculate(i, j);
                addInterPoint(QVector3D(i, tmp, j), QVector3D(0.1, 0.1, 0.1));


                tmp = _interpolator->calculate(i, j + deltaY);
                addInterPoint(QVector3D(i, tmp, j + deltaY), QVector3D(0, 0, 0));


                tmp = _interpolator->calculate(i + deltaX, j + deltaY);
                addInterPoint(QVector3D(i + deltaX, tmp, j + deltaY), QVector3D(0.1, 0.1, 0.1));


                tmp = _interpolator->calculate(i + deltaX, j);
                addInterPoint(QVector3D(i + deltaX, tmp, j), QVector3D(0, 0, 0));
            }
        }
	}

    messageLoop(QString("OpenGL inicializás és adatok betöltése a grafikus kártyára.\n\n") +
                "Shaderek betöltése, shaderprogram összekapcsolása.\n" +
                "50" + (_twoDimension?"":" x 50") + " pont másolása.");

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
    for (int i = 0; i < _partX.getCount(); i++)
    {
        resultX[i] = _partX.at(i);
    }

    QVector<double> resultY;
    resultY.resize(_partY.getCount());
    for (int i = 0; i < _partY.getCount(); i++)
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
    for (int i = 0; i < _partX.getCount(); i++)
    {
        resultX[i] = _partX.at(i);
    }

    QVector<double> resultY;
    resultY.resize(_partY.getCount());
    for (int i = 0; i < _partY.getCount(); i++)
    {
        resultY[i] = _partY.at(i);
    }

    partChanged(resultY, resultX);
}

void Model::setTwoDimension(bool enabled)
{
    if (enabled)
    {
        _table->removeSymbol("var");
        _table->insertSymbol("var", QRegExp("^x"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
        delete _interpolator;
        _interpolator = new Newton();
    }
    else
    {
        _table->removeSymbol("var");
        _table->insertSymbol("var", QRegExp("^(x|y)"), ARITY_CONSTANT, ASSOCIATIVITY_NONE, 0, 0);
        delete _interpolator;
        _interpolator = new Lagrange();
    }
    _twoDimension = enabled;
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
