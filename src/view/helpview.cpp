#include "helpview.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QScrollArea>
#include <QLabel>


namespace View
{
    HelpView::HelpView(QWidget* parent):
        QDialog(parent)
    {
        QVBoxLayout* menuLayout = new QVBoxLayout(this);
        menuLayout->addWidget(new QLabel("<b>Betöltés fájlból</b>", this));
        menuLayout->addWidget(new QLabel("A gomb megnyomása után lehetősége van kiválasztani egy bemeneti fájl.\n"
                                         "A fájl tartalma alapján a mezők automatikusan beállítódnak.", this));

        menuLayout->addWidget(new QLabel("<b>Mentés fájlba</b>", this));
        menuLayout->addWidget(new QLabel("A gomb megnyomása után lehetősége van megadni egy fájl, melyben a jelenlegi adatok tárolásra kerülnek.\n"
                                         "A fájlba minden fontos információ belekerül. A későbbiekben a betöltés segítségével visszatudjuk állítani a mentett állapotot.", this));

        menuLayout->addWidget(new QLabel("<b>Két dimenzió</b>", this));
        menuLayout->addWidget(new QLabel("A bekapcsolásával jeleníthetünk meg egyváltozós függvényeket.\n"
                                         "Ilyenkor a forgás leáll, és egy kétdimenziós koordináta-rendszerben jelenik meg a függvény.", this));

        menuLayout->addWidget(new QLabel("<b>Lépések kiírása</b>", this));
        menuLayout->addWidget(new QLabel("Ezt az pociót választva, a kirajzolás gomb megnyomása után a program megjeleníti az elvégzett lépéseket.\n"
                                         "A lépések egy felugró ablakban jelennek meg, és a bezárásáig a kirajzolás folyamata szünetel.", this));

        menuLayout->addWidget(new QLabel("<b>Súgó</b>", this));
        menuLayout->addWidget(new QLabel("A gomb lenyomásával érhetőek el az alábbi információk.\n"
                                         "Segítséget nyújthat a program használatához és az esetenként előforduló hibák értelmezésében.", this));


        menuLayout->addWidget(new QLabel("<b>Kirajzolás</b>", this));
        menuLayout->addWidget(new QLabel("A fő műveletet előidéző gomb, megnyomásával, amennyiben minden adat helyes, elindul a kirajzolás folyamata.\n"
                                         "A folyamat végén új ablak(ok)ban látható(ak) a függvény(ek) vizualizációja(i).", this));

        menuLayout->addStretch();

        QWidget* menu = new QWidget(this);
        menu->setLayout(menuLayout);


        QVBoxLayout* usageLayout = new QVBoxLayout(this);
        usageLayout->addWidget(new QLabel("<b>Függvény bemenet:</b>", this));
        usageLayout->addWidget(new QLabel("A függvényt szöveges formában tudja megadni.\n"
                                          "Egy változó esetén a paraméter az 'x', két változó esetén 'x' és 'y'.\n"
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

        usageLayout->addStretch();

        QWidget* usage = new QWidget(this);
        usage->setLayout(usageLayout);

        QVBoxLayout* warningLayout = new QVBoxLayout(this);
        warningLayout->addWidget(new QLabel("<b>Hiányzó adatok, vagy azonos alappont!</b>", this));
        warningLayout->addWidget(new QLabel("Ez a hibaüzenet a kirajzolás, vagy a mentés gomb megnyomására jelenhet meg.\n"
                                            "Két oka lehet, az első, hogy az alappontok manuális megadásakor kettő megegyezik.\n"
                                            "A másik ok, ha valamely mezőt üresen hagytunk.", this));

        warningLayout->addWidget(new QLabel("<b>Hibás bemenet.</b>", this));
        warningLayout->addWidget(new QLabel("Ha megjelenik, akkor függvény szövegében ismeretlen szimbólum van.\n"
                                            "A megoldáshoz ellenőrizze a bemenetet, és javítsa ki a hibát.", this));

        warningLayout->addWidget(new QLabel("<b>A bemenet hirtelen véget ért.</b>", this));
        warningLayout->addWidget(new QLabel("A függvény olyan szimbólummal végződik, mely további szimbólumokat vár.", this));

        warningLayout->addWidget(new QLabel("<b>Nem várt szimbólum.</b>", this));
        warningLayout->addWidget(new QLabel("Feldolgozás közben a bemenetben nem odaillő szimbólum következett.", this));

        warningLayout->addWidget(new QLabel("<b>Hiányzó zárójel!</b>", this));
        warningLayout->addWidget(new QLabel("Egy kifejezés körüli zárójelnek hiányzik a zárójele.", this));

        warningLayout->addStretch();

        QWidget* warning = new QWidget(this);
        warning->setLayout(warningLayout);

        QTabWidget* tab = new QTabWidget(this);
        tab->addTab(menu, "Menüpontok");
        tab->addTab(usage, "Használat");
        tab->addTab(warning, "Hibaüzenetek");


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
}
