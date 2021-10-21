#ifndef bus2_H
#define bus2_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class bus2
{
public:
    bus2();
    bus2(int,int,QString,QString,QString,int,int,QString);
    QString get_nom();
    QString get_prenom();
     QString get_email();
    int get_id();
    int get_cin();
    int get_nbbus();
    int get_nbres();
    bool ajouter();
    QString get_td();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     QSqlQueryModel * afficherf();
    bool modifier(int);
   QSqlQueryModel * trier();
    private:
    QString nom , prenom , email,td;
    int id , cin , nbbus , nbres;

};

#endif // bus2_H
