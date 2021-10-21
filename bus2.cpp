#include "bus2.h"

#include <QDebug>
bus2::bus2()
{
    id=0;
    cin=0;
    nom="";
    prenom="";
    nbbus=0;
    nbres=0;
}

bus2::bus2(int id, int cin, QString nom,QString prenom,QString email, int nbbus,int nbres, QString td)
{
    this->id=id;
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->nbbus=nbbus;
    this->nbres=nbres;
    this->td=td;
}

QString bus2::get_nom(){return  nom;}
QString bus2::get_prenom(){return prenom;}
QString bus2::get_email(){return email;}
int bus2::get_id(){return  id;}
int bus2::get_cin(){return  cin;}
int bus2::get_nbbus(){return  nbbus;}
int bus2::get_nbres(){return  nbres;}



bool bus2::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("INSERT INTO bus2(ID,CIN,NOM,PRENOM,EMAIL,NBBUS,NBRES,TD)"
                  "VALUES(:id, :cin, :nom, :prenom,:email, :nbbus, :nbres, :td )");
    query.bindValue(":id", res);
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email",email);
    query.bindValue(":nbbus", nbbus);
    query.bindValue(":nbres", nbres);
    query.bindValue(":td", td);
    return query.exec();

}

QSqlQueryModel *bus2::afficher()
{
    QSqlQueryModel * mode1= new QSqlQueryModel();
    mode1->setQuery("select * from bus2");
    mode1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    mode1->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    mode1->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    mode1->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    mode1->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    mode1->setHeaderData(5, Qt::Horizontal, QObject::tr("NBbus"));
    mode1->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR"));
    mode1->setHeaderData(7, Qt::Horizontal, QObject::tr("TD"));
    return mode1;
}

bool bus2::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from bus2 WHERE ID =:id");
    query.bindValue(":id",res);
    return query.exec();

}

bool bus2::modifier(int idd)
{
    QSqlQuery query;
    QString res=QString::number(idd);
    query.prepare("UPDATE bus2 SET NBRES=:nbres  where ID=:id");

     query.bindValue(":id", res);
     query.bindValue(":nbres", nbres);
    return query.exec();
}


QSqlQueryModel *bus2::afficherf()
{
    QSqlQueryModel * mode1= new QSqlQueryModel();

    mode1->setQuery("select * from bus2 where nbres >=5 ");
    mode1->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    mode1->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    mode1->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    mode1->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
    mode1->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    mode1->setHeaderData(5, Qt::Horizontal, QObject::tr("NBBUS"));
    mode1->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR"));
    mode1->setHeaderData(7, Qt::Horizontal, QObject::tr("TD"));
    return mode1;
}
