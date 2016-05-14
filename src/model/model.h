#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <QVector3D>
#include <QEventLoop>

#include "parseval/symbol.h"
#include "parseval/evaluator.h"

#include "interpolate/lagrange.h"
#include "interpolate/newton.h"
#include "interpolate/partition.h"

class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();

private:
    SymbolTable* _table;
    Evaluator* _evaluator;
    QTimer* _timer;
    Interpolation* _interpolator;

    Partition _partX;
    Partition _partY;

    bool _twoDimension;
    bool volatile _advance;

    void messageLoop(QString msg);

public:
    void setInput(QString);
	void setInput(QVector<QVector<double>>);
    void setPart(char, double, double, int, QString);
    void setPart(char, QVector<double>);
    void setTwoDimension(bool);
    void advance();

private slots:
    void timerTick();

signals:
    void render();
    void init();
    void clear();
    void addFuncPoint(QVector3D, QVector3D);
    void addInterPoint(QVector3D, QVector3D);
    void addDiffPoint(QVector3D, QVector3D);
    void addCommonPoint(QVector3D);
    void message(QString);
    void error(QString);
    void partChanged(QVector<double>, QVector<double>);
};

#endif // MODEL_H
