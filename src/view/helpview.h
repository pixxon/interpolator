#ifndef HELPVIEW_H
#define HELPVIEW_H


#include <QDialog>


namespace View
{
    class HelpView: public QDialog
    {
        Q_OBJECT
        public:
            HelpView(QWidget* parent = 0);
            ~HelpView();

        private:
            QPushButton* _button;

        private slots:
            void buttonClicked();
    };
}

#endif // HELPVIEW_H
