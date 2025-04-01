#ifndef POLKA_H
#define POLKA_H

#include <QString>
#include <QVector>
#include "artykul.h"

class Polka {
public:
    Polka(const QString& idRegalu = "Regał ?");
    QString opis() const;
    bool dodajArtykul(Artykul artykul); // kopia lokalna
    QVector<Artykul> pobierzArtykuly() const;
    bool pelna() const;

private:
    QString id;
    QString idRegalu;
    QVector<Artykul> artykuly;
    static const int MAX_ARTYKULOW = 10;
};

#endif // POLKA_H
