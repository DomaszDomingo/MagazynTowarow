#ifndef REGAL_H
#define REGAL_H

#include <QString>
#include <QVector>
#include "polka.h"

class Regal {
public:
    Regal();
    QString opis() const;

    const QVector<Polka>& pobierzPolki() const;
    QVector<Polka>& pobierzPolkiMutowalnie();

private:
    QString id;
    QVector<Polka> polki;

    static int licznikGlobalny;

    // 🔐 Prywatna metoda do tworzenia półek
    void stworzPolki();
};

#endif // REGAL_H
