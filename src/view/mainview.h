#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>

#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QSpinBox>
#include <QDoubleSpinBox>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    QWidget* _top_page_1;
    QWidget* _top_page_2;
    QWidget* _bottom_page_1;
    QWidget* _bottom_page_2;

    QPushButton* _render_button;

    QLineEdit* _func_input;
    QVector<QVector<QLineEdit*>> _point_input;
    int _point_input_x_size;
    int _point_input_y_size;

    QDoubleSpinBox* _part_min_X;
    QDoubleSpinBox* _part_max_X;
    QSpinBox* _part_count_X;

    QDoubleSpinBox* _part_min_Y;
    QDoubleSpinBox* _part_max_Y;
    QSpinBox* _part_count_Y;

    void initialize();

public slots:
    void buttonClick();
    void count_x_changed(int);
    void count_y_changed(int);

signals:
    void inputSet(QString);
    void partXSet(double, double, int);
    void partYSet(double, double, int);
};

#endif // MAINVIEW_H
