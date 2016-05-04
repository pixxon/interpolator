#include "helpview.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QScrollArea>
#include <QLabel>

HelpView::HelpView(QWidget* parent):
    QDialog(parent)
{
    QVBoxLayout* usageLayout = new QVBoxLayout(this);
    usageLayout->addWidget(new QLabel("<b>Függvény bemenet:</b>", this));
    usageLayout->addWidget(new QLabel("A függvényt szöveges formában tudja megadni.\n"
                                      "Egyváltozó esetén a paraméter az 'x', kétváltozó esetén 'x' és 'y'.\n"
                                      "Ügyeljen arra, helyen legyen a bemenet, ellenkező esetben hibajelzés történik.\n"
                                      "A támogatott műveletek listája: +, -, *, /, ^\n"
                                      "A támogatott beépített függvények listája: sin, cos, tg, ctg, abs, log", this));
    usageLayout->addWidget(new QLabel("<b>Érték bemenet:</b>", this));
    usageLayout->addWidget(new QLabel("A táblázat dinamikusan méreteződik a felosztás, vagy alappontok alapján\n"
                                      "Változáskor újratöltődik, így először azokat állítsa be.\n"
                                      "Törtszámokat tizedesvessző (,) segítségével adhat meg.", this));

    usageLayout->addWidget(new QLabel("<b>Felosztás</b>", this));
    usageLayout->addWidget(new QLabel("Az intervallum két végpontja, a pontok száma és a típus alapján adható meg.\n"
                                      "Egyenletes felosztás esetén a pontok egyenlő távolságban helyezkednek el az intervallumban.\n"
                                      "Csebisev felosztás esetén a Csebisev polinom gyökeinek megfelelő transzformációja adja az alappontokat.\n"
                                      "Ügyeljen arra, hogy az intervallum alsó határa kisebb legyen, mint a felső.", this));

    usageLayout->addWidget(new QLabel("<b>Alappontok</b>", this));
    usageLayout->addWidget(new QLabel("Tetszőleges alappontokat ezzel a lehetőséggel adhat meg.\n"
                                      "Ügyeljen arra, hogy ne legyen két azonos alappont, ellenben hibajelzést kap.\n"
                                      "Ha üresen maradtak cellák, akkor előbb csökkentse az alappontok számát.", this));

    QWidget* usage = new QWidget(this);
    usage->setLayout(usageLayout);

    QTabWidget* tab = new QTabWidget(this);
    tab->addTab(usage, "Használat");


    _button = new QPushButton("Bezárás");
    QObject::connect(_button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(tab);
    layout->addWidget(_button);
    setLayout(layout);
}

HelpView::~HelpView()
{
    delete _button;
}

void HelpView::buttonClicked()
{
    done(0);
}



