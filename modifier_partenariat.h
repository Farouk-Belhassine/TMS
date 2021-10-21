#ifndef MODIFIER_PARTENARIAT_H
#define MODIFIER_PARTENARIAT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>

class modifier_partenariat
{
public:
    modifier_partenariat();
    modifier_partenariat(int,QString,QString,int);
    bool ajouter_partenariat();
    bool supprimer_partenariat(int);
    bool modifier_par(int,QString,QString,int);
    QSqlQueryModel * afficher_partenariat();
private:
    int idpar;
    QString nompar;
    QString prepar;
    int sompar;
};


#endif // MODIFIER_PARTENARIAT_H
