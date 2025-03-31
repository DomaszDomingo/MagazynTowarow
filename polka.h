#ifndef POLKA_H
#define POLKA_H

#include <QString>

class Polka {
public:
    Polka();
    QString opis() const;

private:
    QString id;
};

#endif // POLKA_H
