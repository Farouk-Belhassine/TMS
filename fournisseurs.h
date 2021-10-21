#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H

#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class fournisseurs;
}

class fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurs(QWidget *parent = nullptr);
    ~fournisseurs();
    fournisseurs(QString,QString);
    bool ajouter(QString,QString);
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString,QString);
    QSqlQueryModel * recherche(QString r);
    QSqlQueryModel * trinom();
    QSqlQueryModel * triproduit();
    QSqlQueryModel *  statnom(QString nom);
    QSqlQueryModel * statproduit(QString produit);
    int control(QString);

private slots:
    void on_pushButton_retour_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_trinom_clicked();

    void on_pushButton_tricapacite_clicked();

    void on_pushButton_Afficher_clicked();

    void on_pushButton_statistiqueparnom_clicked();

    void on_pushButton_statistiqueparproduit_clicked();

    void on_lineEdit_nommodifier_textChanged(const QString &arg1);

    void on_lineEdit_nomsupprimer_textChanged(const QString &arg1);

    void on_lineEdit_nom_textChanged(const QString &arg1);

private:
    Ui::fournisseurs *ui;
    QString nom;
    QString produit;
};

#endif // FOURNISSEURS_H
