#include "polka.h"

Polka::Polka() {
    static int licznik = 1;
    id = QString("Półka %1").arg(licznik++);
}

QString Polka::opis() const {
    return id;
}
