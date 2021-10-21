#include "depot.h"

depot::depot(int matriculation,int kilometrage,QString categorie,int datedentrer)
{
    this->matriculation=matriculation;
    this->kilometrage=kilometrage;
    this->categorie=categorie;
    this->datedentrer=datedentrer;
}
    int depot::get_matriculation(){return matriculation;}
    int depot::get_kilometrage(){return kilometrage;}
    QString depot::get_categorie(){return categorie;}
    int depot::get_datedentrer(){return datedentrer;}

    void depot::set_matriculation(int matriculation){this->matriculation=matriculation;}
    void depot::set_kilometrage(int kilometrage){this->kilometrage=kilometrage;}
    void depot::set_categorie(QString categorie){this->categorie=categorie;}
    void depot::set_datedentrer(int datedentrer){this->datedentrer=datedentrer;}

bool depot::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO DEPOT (MATRICULATION,KILOMETRAGE,CATEGORIE,DATEDENTRER) "
                        "VALUES (:MATRICULATION , :KILOMETRAGE , :CATEGORIE , :DATEDENTRER )");
    query.bindValue(":MATRICULATION",matriculation);
    query.bindValue(":KILOMETRAGE",kilometrage);
    query.bindValue(":CATEGORIE",categorie);
    query.bindValue(":DATEDENTRER",datedentrer);
    return query.exec();
}

QSqlQueryModel *depot::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from DEPOT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

bool depot::supprimer(int matriculation)
{
    QSqlQuery query;
    query.prepare("Delete from DEPOT where MATRICULATION=:matriculation");
    query.bindValue(":matriculation",matriculation);
    return query.exec();
}

bool depot::modifier(int matriculation,int kilometrage,QString categorie,int datedentrer,int mat)
{
    QSqlQuery query;
    query.prepare("Update DEPOT set MATRICULATION=:MATRICULATION ,KILOMETRAGE=:KILOMETRAGE,CATEGORIE=:CATEGORIE, DATEDENTRER=:DATEDENTRER where MATRICULATION=:mat");
    query.bindValue(":MATRICULATION",matriculation);
    query.bindValue(":KILOMETRAGE",kilometrage);
    query.bindValue(":CATEGORIE",categorie);
    query.bindValue(":DATEDENTRER",datedentrer);
    query.bindValue(":mat",mat);
    return query.exec();
}

QSqlQueryModel *depot::recherchermat(QString mat)
{
    QSqlQuery query;
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select * from DEPOT where MATRICULATION like '"+mat+"%'");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

QSqlQueryModel *depot::rechercherdate(QString date)
{
    QSqlQuery query;
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select * from DEPOT where DATEDENTRER like '"+date+"%'");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

QSqlQueryModel * depot::trier(QString tri)
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from DEPOT order by "+tri);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));

         return model;
 }
