#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QTabWidget>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
	QTabWidget* _top;
    QWidget* _top_page_1;
    QWidget* _top_page_2;

	QTabWidget* _bottom;
    QWidget* _bottom_page_1;
    QWidget* _bottom_page_2;

    QPushButton* _render_button;

    QLineEdit* _func_input;
    QVector<QVector<QLineEdit*> > _point_input;

    QDoubleSpinBox* _part_min_X;
    QDoubleSpinBox* _part_max_X;
    QSpinBox* _part_count_X;
    QComboBox* _part_type_X;

    QDoubleSpinBox* _part_min_Y;
    QDoubleSpinBox* _part_max_Y;
    QSpinBox* _part_count_Y;
    QComboBox* _part_type_Y;

    void showEvent(QShowEvent*);

public slots:
    void buttonClick();
    void count_x_changed();
    void count_y_changed();

    void part_changed(QVector<double>, QVector<double>);

signals:
    void inputSet(QString);
	void inputSet(QVector<QVector<double>>);
    void partXSet(double, double, int, QString);
    void partYSet(double, double, int, QString);
};

#endif // MAINVIEW_H
