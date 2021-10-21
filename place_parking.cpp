#include "place_parking.h"


place_parking::place_parking(int matriculation,int kilometrage,QString categorie,int datedentrer)
{
    this->matriculation=matriculation;
    this->kilometrage=kilometrage;
    this->categorie=categorie;
    this->datedentrer=datedentrer;
}

    int place_parking::get_matriculation(){return matriculation;}
    int place_parking::get_kilometrage(){return kilometrage;}
    QString place_parking::get_categorie(){return categorie;}
    int place_parking::get_datedentrer(){return datedentrer;}

    void place_parking::set_matriculation(int matriculation){this->matriculation=matriculation;}
    void place_parking::set_kilometrage(int kilometrage){this->kilometrage=kilometrage;}
    void place_parking::set_categorie(QString categorie){this->categorie=categorie;}
    void place_parking::set_datedentrer(int datedentrer){this->datedentrer=datedentrer;}

bool place_parking::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO PLACE_PARKING (MATRICULATION,KILOMETRAGE,CATEGORIE,DATEDENTRER) "
                        "VALUES (:MATRICULATION , :KILOMETRAGE , :CATEGORIE , :DATEDENTRER )");
    query.bindValue(":MATRICULATION",matriculation);
    query.bindValue(":KILOMETRAGE",kilometrage);
    query.bindValue(":CATEGORIE",categorie);
    query.bindValue(":DATEDENTRER",datedentrer);
    return query.exec();
}

QSqlQueryModel *place_parking::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from PLACE_PARKING");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

bool place_parking::supprimer(int matriculation)
{
    QSqlQuery query;
    query.prepare("Delete from PLACE_PARKING where MATRICULATION=:matriculation");
    query.bindValue(":matriculation",matriculation);
    return query.exec();
}

bool place_parking::modifier(int matriculation,int kilometrage,QString categorie,int datedentrer,int mat)
{
    QSqlQuery query;
    query.prepare("Update PLACE_PARKING set MATRICULATION=:MATRICULATION ,KILOMETRAGE=:KILOMETRAGE,CATEGORIE=:CATEGORIE, DATEDENTRER=:DATEDENTRER where MATRICULATION=:mat");
    query.bindValue(":MATRICULATION",matriculation);
    query.bindValue(":KILOMETRAGE",kilometrage);
    query.bindValue(":CATEGORIE",categorie);
    query.bindValue(":DATEDENTRER",datedentrer);
    query.bindValue(":mat",mat);
    return query.exec();
}

QSqlQueryModel *place_parking::recherchermat(QString mat)
{
    QSqlQuery query;
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select * from PLACE_PARKING where MATRICULATION like '"+mat+"%'");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

QSqlQueryModel *place_parking::rechercherdate(QString date)
{
    QSqlQuery query;
    QSqlQueryModel *model= new QSqlQueryModel();
    query.prepare("select * from PLACE_PARKING where DATEDENTRER like '"+date+"%'");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));
    return model;
}

QSqlQueryModel * place_parking::trier(QString tri)
 {

     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from PLACE_PARKING order by "+tri);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr(" Matriculation "));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr(" Kilometrage "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr(" Categorie "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr(" Date "));

         return model;
 }













