#ifndef ARTYKUL_H
#define ARTYKUL_H

#include <QString>

class Artykul {
public:
    Artykul(const QString& nazwa = "",
            const QString& jednostka = "sztuka",
            const QString& kodEAN = "");

    QString pobierzId() const;
    QString pobierzNazwe() const;
    QString pobierzJednostka() const;
    QString pobierzKodEAN() const;
    QString pobierzLokalizacje() const;

    void ustawLokalizacje(const QString& lokalizacja);

private:
    QString id;
    QString nazwa;
    QString jednostka;
    QString kodEAN;
    QString lokalizacja;

    static int licznikGlobalny;
};

#endif // ARTYKUL_H
