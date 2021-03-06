#include "controller.h"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>


namespace Controller
{
    Controller::Controller(View::MainView* mainView, View::OpenGLView* funcView, View::OpenGLView* interView, View::OpenGLView* diffView, Model::Model* model):
        QObject(0),
        _mainView(mainView),
        _funcView(funcView),
        _interView(interView),
        _diffView(diffView),
        _model(model),
        _showFunc(false),
        _showDiff(false)
    {
        QObject::connect(_mainView, SIGNAL(inputSet(QString)), this, SLOT(viewInput(QString)));
        QObject::connect(_mainView, SIGNAL(inputSet(QVector<QVector<double> >)), this, SLOT(viewInput(QVector<QVector<double> >)));
        QObject::connect(_mainView, SIGNAL(partSet(char,double,double,int,QString)), this, SLOT(viewPart(char,double,double,int,QString)));
        QObject::connect(_mainView, SIGNAL(partSet(char,QVector<double>)), this, SLOT(viewPart(char,QVector<double>)));
        QObject::connect(_mainView, SIGNAL(closed()), this, SLOT(viewClosed()));
        QObject::connect(_mainView, SIGNAL(dimensionChanged(bool)), this, SLOT(viewDimensionChanged(bool)));
        QObject::connect(_mainView, SIGNAL(advance()), this, SLOT(viewContinue()));

        QObject::connect(_model, SIGNAL(render()), this, SLOT(modelRender()));
        QObject::connect(_model, SIGNAL(init()), this, SLOT(modelInit()));
        QObject::connect(_model, SIGNAL(clear()), this, SLOT(modelClear()));
        QObject::connect(_model, SIGNAL(addInterPoint(QVector3D,QVector3D)), this, SLOT(modelInterPoint(QVector3D,QVector3D)));
        QObject::connect(_model, SIGNAL(addFuncPoint(QVector3D,QVector3D)), this, SLOT(modelFuncPoint(QVector3D,QVector3D)));
        QObject::connect(_model, SIGNAL(addDiffPoint(QVector3D,QVector3D)), this, SLOT(modelDiffPoint(QVector3D,QVector3D)));
        QObject::connect(_model, SIGNAL(addCommonPoint(QVector3D)), this, SLOT(modelCommonPoint(QVector3D)));
        QObject::connect(_model, SIGNAL(partChanged(QVector<double>,QVector<double>)), this, SLOT(modelPartChanged(QVector<double>,QVector<double>)));
        QObject::connect(_model, SIGNAL(message(QString)), this, SLOT(modelMessage(QString)));
        QObject::connect(_model, SIGNAL(error(QString)), this, SLOT(modelError(QString)));
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
        {
            _funcView->update();
        }
        if(_showDiff)
        {
            _diffView->update();
        }
        _interView->update();
    }

    void Controller::modelInit()
    {
        if(_showFunc)
        {
            _funcView->init();
        }
        if(_showDiff)
        {
            _diffView->init();
        }
        _interView->init();
    }

    void Controller::modelClear()
    {
        _interView->clear();
        if(_showFunc)
        {
            _funcView->clear();
        }
        if(_showDiff)
        {
            _diffView->clear();
        }
        _showFunc = false;
        _showDiff = false;
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

    void Controller::modelDiffPoint(QVector3D pos, QVector3D col)
    {
        _showDiff = true;
        _diffView->addPoint(pos, col);
    }

    void Controller::modelCommonPoint(QVector3D pos)
    {
        _funcView->addCommonPoint(pos);
        _interView->addCommonPoint(pos);
    }

    void Controller::modelPartChanged(QVector<double> partX, QVector<double> partY)
    {
        _mainView->partChanged(partX, partY);
    }

    void Controller::modelMessage(QString message)
    {
        _mainView->showMessage(message);
    }

    void Controller::modelError(QString message)
    {
        _mainView->showError(message);
    }

    void Controller::viewInput(QString func)
    {
        void (Model::Model::*mf1)(QString) = &Model::Model::setInput;
        QtConcurrent::run(_model, mf1, func);
    }

    void Controller::viewInput(QVector<QVector<double>> points)
    {
        void (Model::Model::*mf1)(QVector<QVector<double>>) = &Model::Model::setInput;
        QtConcurrent::run(_model, mf1, points);
    }

    void Controller::viewPart(char var, double min, double max, int count, QString type)
    {
        _model->setPart(var, min, max, count, type);
    }

    void Controller::viewPart(char var, QVector<double> points)
    {
        _model->setPart(var, points);
    }

    void Controller::viewDimensionChanged(bool enabled)
    {
        _funcView->setTwoDimension(enabled);
        _interView->setTwoDimension(enabled);
        _diffView->setTwoDimension(enabled);
        _model->setTwoDimension(enabled);
    }

    void Controller::viewClosed()
    {
        _funcView->close();
        _interView->close();
        _diffView->close();
    }

    void Controller::viewContinue()
    {
        _model->advance();
    }
}
