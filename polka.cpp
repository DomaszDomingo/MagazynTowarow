#include "polka.h"

int Polka::licznikGlobalny = 1;
const int Polka::MAX_ARTYKULOW = 10;

Polka::Polka(const QString& idRegalu) : idRegalu(idRegalu) {
    wygenerujId();
}

void Polka::wygenerujId() {
    id = QString("Półka %1").arg(licznikGlobalny++);
}

QString Polka::opis() const {
    return id;
}

QString Polka::opisPelna() const {
    return QString("%1 / %2").arg(idRegalu, id);
}

bool Polka::moznaDodacArtykul() const {
    return artykuly.size() < MAX_ARTYKULOW;
}

void Polka::ustawLokalizacjeDlaArtykulu(Artykul& artykul) {
    artykul.ustawLokalizacje(opisPelna());
}

bool Polka::dodajArtykul(Artykul artykul) {
    if (!moznaDodacArtykul()) {
        return false;
    }

    ustawLokalizacjeDlaArtykulu(artykul);
    artykuly.append(artykul);
    return true;
}

QVector<Artykul> Polka::pobierzArtykuly() const {
    return artykuly;
}

bool Polka::pelna() const {
    return !moznaDodacArtykul();
}
