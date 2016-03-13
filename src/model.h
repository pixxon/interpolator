#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTimer>
#include <QVector3D>

#include "parseval/symbol.h"
#include "parseval/evaluator.h"

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

public slots:
    void setInput(QString);
    void timerTick();

signals:
    void render();
    void init();
    void addData(QVector3D, QVector3D);
};

#endif // MODEL_H
