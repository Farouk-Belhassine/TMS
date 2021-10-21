#include "modifier_partenariat.h"

modifier_partenariat::modifier_partenariat()
{

}

modifier_partenariat::modifier_partenariat(int id_par,QString nom_par,QString pre_par,int som_par)
{
   this->idpar = id_par;
   nompar = nom_par;
   prepar = pre_par;
   sompar = som_par;
}

bool modifier_partenariat::ajouter_partenariat()
{
   QSqlQuery query;
   QString res4 = QString::number(idpar);
   QString res3 = QString::number(sompar);
    query.prepare("INSERT INTO ABONNEMENTS (idpar,nompar,prepar,sompar)"
                  "values(:ID,:nom,:prenom,:somme)");
    query.bindValue(":ID",res4);
    query.bindValue(":nom",nompar);
    query.bindValue(":prenom",prepar);
    query.bindValue(":somme",res3);
    return query.exec();
}

bool modifier_partenariat::supprimer_partenariat(int idpar)
{
    QSqlQuery query;
    QString res4 = QString::number(idpar);
    query.prepare("Delete from abonnements WHERE ID = :idpar_supp");
    query.bindValue(":idpar_supp",res4);
    query.exec();
}

bool modifier_partenariat::modifier_par(int idpar, QString nompar , QString prepar, int sompar)
{
    QSqlQuery query;
    query.prepare("UPDATE abonnements set  prepar = :prepar ,nompar = :nompar,sompar = :sompar WHERE idpar = :idpar_mod");
    query.bindValue(":idpar_mod",idpar);
    query.bindValue(":prepar",prepar);
    query.bindValue(":nompar",nompar);
    query.bindValue(":sompar",sompar);
    query.exec();
}

QSqlQueryModel * modifier_partenariat::afficher_partenariat()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from partenariat");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Partenaire"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Partenaire "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom Partenaire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Somme Partenaire"));

    return model;
}





