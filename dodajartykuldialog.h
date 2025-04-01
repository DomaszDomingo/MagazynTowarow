#ifndef DODAJARTYKULDIALOG_H
#define DODAJARTYKULDIALOG_H

#include <QDialog>
#include "artykul.h"

namespace Ui {
class DodajArtykulDialog;
}

class DodajArtykulDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajArtykulDialog(QWidget *parent = nullptr);
    ~DodajArtykulDialog();

    Artykul pobierzArtykul() const;

private:
    Ui::DodajArtykulDialog *ui;
};

#endif // DODAJARTYKULDIALOG_H
