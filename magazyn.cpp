#include "magazyn.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

Magazyn magazyn;

Magazyn::Magazyn(QObject *parent) : QObject(parent)
{
    // przykładowo: od razu dodaj jeden regał
    dodajRegal();
}

void Magazyn::dodajRegal()
{
    regaly.append(Regal());
}

QVector<Regal> Magazyn::pobierzRegaly() const
{
    return regaly;
}

bool Magazyn::dodajArtykul(const Artykul& artykul)
{
    Polka* wolnaPolka = znajdzPierwszaWolnaPolka();
    if (!wolnaPolka) {
        emit bladDodawania("Brak dostępnego miejsca w magazynie!");
        return false;
    }

    Artykul kopia = artykul;
    kopia.ustawLokalizacje(wolnaPolka->opisPelna());

    if (!wolnaPolka->dodajArtykul(kopia)) {
        emit bladDodawania("Nie udało się dodać artykułu do półki.");
        return false;
    }

    zapiszDoCSV(kopia);
    emit artykulDodany(kopia);
    return true;
}

Polka* Magazyn::znajdzPierwszaWolnaPolka()
{
    for (Regal& r : regaly) {
        for (Polka& p : r.pobierzPolkiMutowalnie()) {
            if (!p.pelna()) {
                return &p;
            }
        }
    }
    return nullptr;
}

bool Magazyn::zapiszDoCSV(const Artykul& artykul, const QString& sciezka)
{
    QFile plik(sciezka);
    bool nowyPlik = !QFileInfo::exists(sciezka);

    if (!plik.open(QIODevice::Append | QIODevice::Text))
        return false;

    QTextStream out(&plik);
    if (nowyPlik)
        out << "ID,Nazwa,Jednostka,Kod EAN,Lokalizacja\n";

    out << artykul.pobierzId() << ","
        << artykul.pobierzNazwe() << ","
        << artykul.pobierzJednostka() << ","
        << artykul.pobierzKodEAN() << ","
        << artykul.pobierzLokalizacje() << "\n";

    return true;
}
