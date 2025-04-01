#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "magazyn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

extern Magazyn* magazyn; // lub wskaźnik przekazany do MainWindow

void MainWindow::on_pushButton_clicked()
{
    DodajArtykulDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Artykul nowy = dialog.pobierzArtykul();
        if (!magazyn->dodajArtykul(nowy)) {
            QMessageBox::warning(this, "Błąd", "Nie udało się dodać artykułu do magazynu.");
        }
    }
}

