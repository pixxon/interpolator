#include "controller.h"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

Controller::Controller(MainView* mainView, OpenGLView* funcView, OpenGLView* interView, Model* model):
    QObject(0),
    _mainView(mainView),
    _funcView(funcView),
    _interView(interView),
    _model(model),
  _showFunc(false)
{
    QObject::connect(_mainView, SIGNAL(inputSet(QString)), this, SLOT(viewInput(QString)));
    QObject::connect(_mainView, SIGNAL(inputSet(QVector<QVector<double> >)), this, SLOT(viewInput(QVector<QVector<double> >)));
    QObject::connect(_mainView, SIGNAL(partSet(char,double,double,int,QString)), this, SLOT(viewPart(char,double,double,int,QString)));

    QObject::connect(_model, SIGNAL(render()), this, SLOT(modelRender()));
    QObject::connect(_model, SIGNAL(init()), this, SLOT(modelInit()));
    QObject::connect(_model, SIGNAL(clear()), this, SLOT(modelClear()));
    QObject::connect(_model, SIGNAL(addData(QVector3D,QVector3D)), this, SLOT(modelInterPoint(QVector3D,QVector3D)));
    QObject::connect(_model, SIGNAL(addData2(QVector3D,QVector3D)), this, SLOT(modelFuncPoint(QVector3D,QVector3D)));
    QObject::connect(_model, SIGNAL(part_changed(QVector<double>,QVector<double>)), this, SLOT(modelPartChanged(QVector<double>,QVector<double>)));
}

Controller::~Controller()
{
}

void Controller::start()
{
    _mainView->show();
    _mainView->move(300,400);
}

void Controller::modelRender()
{
    if(_showFunc)
        _funcView->update();
    _interView->update();
}

void Controller::modelInit()
{
    if(_showFunc)
        _funcView->init();
    _interView->init();
}

void Controller::modelClear()
{
    _interView->clear();
    if(_showFunc)
        _funcView->clear();
    _showFunc = false;
}

void Controller::modelFuncPoint(QVector3D pos, QVector3D col)
{
    _showFunc = true;
    _funcView->addPoint(pos, col);
}

void Controller::modelInterPoint(QVector3D pos, QVector3D col)
{
    _interView->addPoint(pos, col);
}

void Controller::modelPartChanged(QVector<double> partX, QVector<double> partY)
{
    _mainView->part_changed(partX, partY);
}

void Controller::viewInput(QString func)
{
    _model->setInput(func);
}

void Controller::viewInput(QVector<QVector<double>> points)
{
    _model->setInput(points);
}

void Controller::viewPart(char var, double min, double max, int count, QString type)
{
    _model->setPart(var, min, max, count, type);
}
