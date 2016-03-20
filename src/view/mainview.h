#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>

#include <QLineEdit>
#include <QPushButton>

#include <QSpinBox>
#include <QDoubleSpinBox>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    QPushButton* button;
    QLineEdit* input;

    QDoubleSpinBox* minX;
    QDoubleSpinBox* maxX;
    QSpinBox* countX;

    QDoubleSpinBox* minY;
    QDoubleSpinBox* maxY;
    QSpinBox* countY;

public slots:
    void buttonClick();

signals:
    void inputSet(QString);
};

#endif // MAINVIEW_H
