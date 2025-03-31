#include <QCoreApplication>
#include <QDebug>
#include "magazyn.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Magazyn magazyn;
    magazyn.dodajRegal();
    magazyn.dodajRegal();

    for (const Regal& regal : magazyn.pobierzRegaly()) {
        qDebug() << regal.opis();
        for (const Polka& polka : regal.pobierzPolki()) {
            qDebug() << "   " << polka.opis();
        }
    }

    return a.exec();
}
