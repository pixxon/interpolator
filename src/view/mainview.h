#ifndef MAINVIEW_H
#define MAINVIEW_H


#include "helpview.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QTabWidget>
#include <QCheckBox>


namespace View
{
    class MainView : public QWidget
    {
        Q_OBJECT
        public:
            explicit MainView(QWidget *parent = 0);
            ~MainView();

            void partChanged(QVector<double>, QVector<double>);
            void showMessage(QString);
            void showError(QString);

        private:
            QTabWidget* _top;
            QWidget* _topPage1;
            QWidget* _topPage2;

            QTabWidget* _bottom;
            QWidget* _bottomPage1;
            QWidget* _bottomPage2;

            QLineEdit* _funcInput;
            QVector<QVector<QLineEdit*> > _pointInput;

            QDoubleSpinBox* _partMinX;
            QDoubleSpinBox* _partMinY;
            QDoubleSpinBox* _partMaxX;
            QDoubleSpinBox* _partMaxY;
            QSpinBox* _partCountX;
            QSpinBox* _partCountY;
            QComboBox* _partTypeX;
            QComboBox* _partTypeY;

            QSpinBox* _part2CountX;
            QSpinBox* _part2CountY;
            QVector<QLineEdit*> _part2BaseX;
            QVector<QLineEdit*> _part2BaseY;


            QPushButton* _renderButton;
            QPushButton* _twoDimension;
            QPushButton* _helpButton;
            QPushButton* _showSteps;

            HelpView* _help;

            bool hasEmpty();

        signals:
            void inputSet(QString);
            void inputSet(QVector<QVector<double>>);
            void partSet(char, double, double, int, QString);
            void partSet(char, QVector<double>);
            void dimensionChanged(bool enabled);
            void closed();
            void advance();

        private slots:
            void buttonClick();
            void partChangedX();
            void partChangedY();
            void countChanged();
            void dimensionChanged();
            void helpClicked();

            void showEvent(QShowEvent*);
            void closeEvent(QCloseEvent *);

            void loadFromFile();
            void saveToFile();
        };
}

#endif // MAINVIEW_H
