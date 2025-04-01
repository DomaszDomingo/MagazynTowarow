#include "regal.h"

int Regal::licznikGlobalny = 1;

Regal::Regal() {
    id = QString("Regał %1").arg(licznikGlobalny++);
    stworzPolki(); // 👈 korzystamy z prywatnej metody
}

QString Regal::opis() const {
    return id;
}

const QVector<Polka>& Regal::pobierzPolki() const {
    return polki;
}

QVector<Polka>& Regal::pobierzPolkiMutowalnie() {
    return polki;
}

// 🔐 Prywatna metoda odpowiedzialna za tworzenie półek
void Regal::stworzPolki() {
    for (int i = 0; i < 3; ++i) {
        polki.append(Polka(id)); // przekazujemy id regału, żeby półka znała swoją lokalizację
    }
}
