#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <QObject>
#include <QVector>
#include "regal.h"

class Magazyn : public QObject
{
    Q_OBJECT

public:
    explicit Magazyn(QObject *parent = nullptr);

    void dodajRegal();
    QVector<Regal> pobierzRegaly() const;

signals:
    void regalDodany(const QString& opis);

private:
    QVector<Regal> regaly;
};

#endif // MAGAZYN_H
