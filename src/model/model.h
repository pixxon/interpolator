#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <QVector3D>

#include "parseval/symbol.h"
#include "parseval/evaluator.h"

#include "interpolate/lagrange.h"
#include "interpolate/partition.h"

class Model: public QObject
{
    Q_OBJECT
public:
    Model();
    ~Model();

private:
    SymbolTable* table;
    Evaluator* evaluator;
    QTimer* timer;
    Lagrange* interpolator;

    Partition partX;
    Partition partY;

public slots:
    void setInput(QString);
    void setPartX(double, double, int);
    void setPartY(double, double, int);
    void timerTick();

signals:
    void render();
    void init();
    void clear();
    void addData(QVector3D, QVector3D);
    void addData2(QVector3D, QVector3D);
};

#endif // MODEL_H
