#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include "view/mainview.h"
#include "view/openglview.h"

#include <QObject>


namespace Controller
{
    class Controller : public QObject
    {
        Q_OBJECT
        public:
            /**
             * @brief Controller Connects to the private slots to the given objects' signals.
             */
            explicit Controller(View::MainView*, View::OpenGLView*, View::OpenGLView*, View::OpenGLView*, Model::Model*);
            ~Controller();

            /**
             * @brief start Main entrypoint for the application
             */
            void start();

        private:
            View::MainView* _mainView;
            View::OpenGLView* _funcView;
            View::OpenGLView* _interView;
            View::OpenGLView* _diffView;
            Model::Model* _model;

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
}

#endif // CONTROLLER_H
