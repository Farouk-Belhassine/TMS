#ifndef BUS_H
#define BUS_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class bus;
}

class bus : public QDialog
{
    Q_OBJECT

public:
    explicit bus(QWidget *parent = nullptr);
    ~bus();
    bus(int,int,QString);
    bool ajouter(int,int,QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tricapacite();
    QSqlQueryModel * trinumero();
    bool supprimer(int);
    bool modifier(int,int,QString);
    QSqlQueryModel * recherche(QString r);
    QSqlQueryModel *  statcapacite(QString nom);
    QSqlQueryModel * statetat(QString produit);
    int control(int);
    void makeplot();


private slots:
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_tricapacite_clicked();

    void on_pushButton_trinumero_clicked();

    void on_pushButton_etatstat_clicked();

    void on_pushButton_capacitestat_clicked();

    void on_lineEdit_numeromodifier_textChanged(const QString &arg1);

    void on_lineEdit_numerosupprimer_textChanged(const QString &arg1);

    void on_lineEdit_capacite_textChanged(const QString &arg1);

    void on_lineEdit_numeroajout_textChanged(const QString &arg1);

    void on_lineEdit_capacitemodifier_textChanged(const QString &arg1);

private:
    Ui::bus *ui;
    QString etat;
    int capacite;
    int numero_bus;
};

#endif // BUS_H
