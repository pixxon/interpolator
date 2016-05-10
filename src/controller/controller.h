#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include "view/mainview.h"
#include "view/openglview.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(MainView* mainView, OpenGLView* funcView, OpenGLView* interView, OpenGLView* diffView, Model* model);
    ~Controller();

    void start();

private:
    MainView* _mainView;
    OpenGLView* _funcView;
    OpenGLView* _interView;
    OpenGLView* _diffView;
    Model* _model;

    bool _showFunc;
    bool _showDiff;

private slots:
    void modelRender();
    void modelInit();
    void modelClear();
    void modelFuncPoint(QVector3D, QVector3D);
    void modelInterPoint(QVector3D, QVector3D);
    void modelDiffPoint(QVector3D pos, QVector3D col);
    void modelCommonPoint(QVector3D);
    void modelPartChanged(QVector<double>, QVector<double>);
    void modelMessage(QString);
    void modelError(QString message);

    void viewInput(QString);
    void viewInput(QVector<QVector<double>>);
    void viewPart(char, double, double, int, QString);
    void viewPart(char, QVector<double>);
    void viewDimensionChanged(bool enabled);
    void viewContinue();

    void viewClosed();
};

#endif // CONTROLLER_H
