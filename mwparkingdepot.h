#ifndef MWPARKINGDEPOT_H
#define MWPARKINGDEPOT_H

#include <QString>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QApplication>
#include <QMessageBox>
#include "place_parking.h"
#include "depot.h"
#include <Qprinter>
#include <QFileDialog>
#include <QTextDocument>

namespace Ui {
class mwparkingdepot;
}

class mwparkingdepot : public QDialog
{
    Q_OBJECT

public:
    explicit mwparkingdepot(QWidget *parent = nullptr);
    ~mwparkingdepot();

private slots:
    void on_pushButton_Ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_Modifier_clicked();
    void on_pushButton_Recherche_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_Imprimer_clicked();

    void on_pushButton_Ajouter_M_clicked();

    void on_pushButton_supprimer_M_clicked();

    void on_pushButton_Modifier_M_clicked();

    void on_pushButton_Recherche_M_clicked();

    void on_pushButton_trier_M_clicked();

    void on_pushButton_Imprimer_D_clicked();

private:
    Ui::mwparkingdepot *ui;
    place_parking p;
    depot d;
};

#endif // MWPARKINGDEPOT_H
