#ifndef MODIFIER_ABONNEMENT_H
#define MODIFIER_ABONNEMENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class modifier_abonnement
{
public:
    modifier_abonnement();
    modifier_abonnement(int,int,QString,QString,int);
    bool ajouter();
    bool supprimer_abonnemeent(int);
    bool modifier_abonnements(int,int,QString,QString,int);
    QSqlQueryModel * afficher();
private:
    int id;
    int duree;
    QString nom;
    QString prenom;
    int reseaux;
};



#endif // MODIFIER_ABONNEMENT_H
