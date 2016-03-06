#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    QPushButton* button;
    QLineEdit* input;

public slots:
    void buttonClick();

signals:
    void inputSet(QString);
};

#endif // MAINVIEW_H
