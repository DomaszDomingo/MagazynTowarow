#include "artykul.h"

int Artykul::licznikGlobalny = 1;

Artykul::Artykul(const QString& nazwa, const QString& jednostka, const QString& kodEAN)
    : nazwa(nazwa), jednostka(jednostka), kodEAN(kodEAN)
{
    id = QString("A%1").arg(licznikGlobalny++);
}

QString Artykul::pobierzId() const {
    return id;
}

QString Artykul::pobierzNazwe() const {
    return nazwa;
}

QString Artykul::pobierzJednostka() const {
    return jednostka;
}

QString Artykul::pobierzKodEAN() const {
    return kodEAN;
}

QString Artykul::pobierzLokalizacje() const {
    return lokalizacja;
}

void Artykul::ustawLokalizacje(const QString& lok) {
    lokalizacja = lok;
}
