#include "regal.h"

Regal::Regal() {
    static int licznik = 1;
    id = QString("Regał %1").arg(licznik++);

    // Tworzymy 3 półki
    for (int i = 0; i < 3; ++i) {
        polki.append(Polka());
    }
}

QString Regal::opis() const {
    return id;
}

const QVector<Polka>& Regal::pobierzPolki() const {
    return polki;
}
