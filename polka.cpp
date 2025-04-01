#include "polka.h"

Polka::Polka(const QString& idRegalu) : idRegalu(idRegalu) {
    static int licznik = 1;
    id = QString("Półka %1").arg(licznik++);
}

QString Polka::opis() const {
    return id;
}

bool Polka::dodajArtykul(Artykul artykul) {
    if (artykuly.size() >= MAX_ARTYKULOW) {
        return false;
    }
    QString lokalizacja = QString("%1 / %2").arg(idRegalu, id);
    artykul.ustawLokalizacje(lokalizacja);
    artykuly.append(artykul);
    return true;
}

QVector<Artykul> Polka::pobierzArtykuly() const {
    return artykuly;
}

bool Polka::pelna() const {
    return artykuly.size() >= MAX_ARTYKULOW;
}
