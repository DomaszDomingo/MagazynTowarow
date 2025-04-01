#include "dodajartykuldialog.h"
#include "ui_dodajartykuldialog.h"



DodajArtykulDialog::DodajArtykulDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajArtykulDialog)
{
    ui->setupUi(this);
    setWindowTitle("Dodaj artykuł");

    // Dodajemy przykładowe jednostki do comboBoxa
    ui->comboBoxJednostka->addItems({"sztuka", "litr", "kilogram", "metr"});
}

DodajArtykulDialog::~DodajArtykulDialog()
{
    delete ui;
}

Artykul DodajArtykulDialog::pobierzArtykul() const
{
    QString nazwa = ui->lineEditNazwa->text();
    QString jednostka = ui->comboBoxJednostka->currentText();
    QString kodEAN = ui->lineEditEAN->text();

    return Artykul(nazwa, jednostka, kodEAN);
}
