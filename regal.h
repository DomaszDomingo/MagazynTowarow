#ifndef REGAL_H
#define REGAL_H

#include <QString>
#include <QVector>
#include "polka.h"

class Regal {
public:
    Regal();
    QString opis() const;
    const QVector<Polka>& pobierzPolki() const;

private:
    QString id;
    QVector<Polka> polki;
};

#endif // REGAL_H
