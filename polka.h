#ifndef POLKA_H
#define POLKA_H

#include <QString>
#include <QVector>
#include "artykul.h"

class Polka {
public:
    explicit Polka(const QString& idRegalu = "Regał ?");

    QString opis() const;               // np. "Półka 1"
    QString opisPelna() const;          // np. "Regał 2 / Półka 1"
    bool dodajArtykul(Artykul artykul); // kopia lokalna z lokalizacją
    QVector<Artykul> pobierzArtykuly() const;
    bool pelna() const;

private:
    QString id;
    QString idRegalu;
    QVector<Artykul> artykuly;
    static const int MAX_ARTYKULOW;
    static int licznikGlobalny;

    // 🔐 prywatne metody
    void wygenerujId();
    bool moznaDodacArtykul() const;
    void ustawLokalizacjeDlaArtykulu(Artykul& artykul);
};

#endif //
