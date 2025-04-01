#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QObject>
#include <QVector>
#include "regal.h"
#include "artykul.h"

class Magazyn : public QObject
{
    Q_OBJECT

public:
    explicit Magazyn(QObject *parent = nullptr);

    void dodajRegal();
    bool dodajArtykul(const Artykul& artykul);
    QVector<Regal> pobierzRegaly() const;

signals:
    void artykulDodany(const Artykul& artykul);
    void bladDodawania(const QString& komunikat);

private:
    QVector<Regal> regaly;

    bool zapiszDoCSV(const Artykul& artykul, const QString& sciezka = "artykuly.csv");
    Polka* znajdzPierwszaWolnaPolka();
};

#endif // MAGAZYN_H
