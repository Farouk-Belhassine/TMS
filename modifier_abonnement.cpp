#include "modifier_abonnement.h"


modifier_abonnement::modifier_abonnement()
{

}
modifier_abonnement::modifier_abonnement(int id,int a,QString b,QString c,int d)
{
   this->id = id;
   duree = a;
   nom = b;
   prenom = c;
   reseaux = d;
}
bool modifier_abonnement::ajouter()
{
   QSqlQuery query;
   QString res2 = QString::number(id);
   QString res = QString::number(duree);
   QString res1 = QString::number(reseaux);
    query.prepare("INSERT INTO ABONNEMENTS (ID,duree,nom,prenom,reseaux)"
                  "values(:ID,:duree,:nom,:prenom,:reseaux)");
    query.bindValue(":ID",res2);
    query.bindValue(":duree",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":reseaux",res1);
    return query.exec();
}
bool modifier_abonnement::supprimer_abonnemeent(int ID)
{
    QSqlQuery query;
    QString res2 = QString::number(ID);
    query.prepare("Delete from abonnements WHERE ID = :ID_supp");
    query.bindValue(":ID_supp",res2);
    query.exec();
}
bool modifier_abonnement::modifier_abonnements(int id,int a,QString b,QString c,int d)
{
    QSqlQuery query;
    query.prepare("UPDATE abonnements set duree = :duree, prenom = :prenom ,nom = :nom,reseaux = :reseaux WHERE ID = :ID_mod");
    query.bindValue(":ID_mod",id);
    query.bindValue(":prenom",b);
    query.bindValue(":nom",c);
    query.bindValue(":reseaux",d);
    query.bindValue(":duree",a);
    query.exec();
}
QSqlQueryModel * modifier_abonnement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnements");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("reseaux"));

    return model;
}






