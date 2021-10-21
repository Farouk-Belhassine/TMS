#ifndef PLACE_PARKING_H
#define PLACE_PARKING_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>


class place_parking
{
private:
    int matriculation,kilometrage,datedentrer;
    QString categorie;
public:
    place_parking(int matriculation=0,int kilometrage=0,QString categorie="",int datedentrer=0);

    int get_matriculation();
    int get_kilometrage();
    QString get_categorie();
    int get_datedentrer();
    void set_matriculation(int);
    void set_kilometrage(int);
    void set_categorie(QString);
    void set_datedentrer(int);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int matriculation=0,int kilometrage=0,QString categorie="",int datedentrer=0,int mat=0);
    QSqlQueryModel * recherchermat(QString);
    QSqlQueryModel * rechercherdate(QString);
    QSqlQueryModel * trier(QString);

};

#endif // PLACE_PARKING_H
