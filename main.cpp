#include <QCoreApplication>
#include <QDebug>
#include "polka.h"
#include "artykul.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Polka polka("Regał 1");

    polka.dodajArtykul(Artykul("Młotek", "sztuka", "5901234123457"));
    polka.dodajArtykul(Artykul("Farba", "litr", "5901111222233"));

    for (const Artykul& a : polka.pobierzArtykuly()) {
        qDebug() << "ID:" << a.pobierzId()
                 << "| Nazwa:" << a.pobierzNazwe()
                 << "| Jednostka:" << a.pobierzJednostka()
                 << "| EAN:" << a.pobierzKodEAN()
                 << "| Lokalizacja:" << a.pobierzLokalizacje();
    }

    return a.exec();
}
