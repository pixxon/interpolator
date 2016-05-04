#ifndef HELPVIEW_H
#define HELPVIEW_H


#include <QDialog>

class HelpView: public QDialog
{
    Q_OBJECT
public:
    HelpView(QWidget* parent = 0);
    ~HelpView();

private:
    QPushButton* _button;

public slots:
    void buttonClicked();
};

#endif // HELPVIEW_H
