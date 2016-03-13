#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <QLCDNumber>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    QPushButton* button;
    QLineEdit* input;
    QSlider* maxSlider;
    QSlider* minSlider;
    QSpinBox* counter;

public slots:
    void buttonClick();

signals:
    void inputSet(QString);
};

#endif // MAINVIEW_H
