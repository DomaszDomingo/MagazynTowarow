#include "magazyn.h"

Magazyn::Magazyn(QObject *parent) : QObject(parent)
{
}

void Magazyn::dodajRegal()
{
    Regal nowyRegal;
    regaly.append(nowyRegal);
    emit regalDodany(nowyRegal.opis());
}

QVector<Regal> Magazyn::pobierzRegaly() const
{
    return regaly;
}
