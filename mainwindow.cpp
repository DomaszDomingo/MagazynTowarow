#include "mainwindow.h"
#include "./ui_mainwindow.h"


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

void MainWindow::on_pushButton_clicked()
{
    DodajArtykulDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Artykul nowy = dialog.pobierzArtykul();
        // Tu możesz go dodać do półki, listy itp.
        qDebug() << "Dodano artykuł:" << nowy.pobierzNazwe()
                 << "| Jednostka:" << nowy.pobierzJednostka()
                 << "| EAN:" << nowy.pobierzKodEAN();
    }
}

