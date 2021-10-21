#include "mwabonnementpartenariat.h"
#include "ui_mwabonnementpartenariat.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "modifier_abonnement.h"
#include "modifier_partenariat.h"
#include <QMessageBox>

mwabonnementpartenariat::mwabonnementpartenariat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mwabonnementpartenariat)
{
    ui->setupUi(this);
}

mwabonnementpartenariat::~mwabonnementpartenariat()
{
    delete ui;
}

void mwabonnementpartenariat::on_pushButton_clicked()
{
    QSqlQuery query;
    int idd = ui->ID->text().toInt();
    int a = ui->duree->text().toInt();
    QString b = ui->nom->text();
    QString c = ui->prenom->text();
    int d = ui->reseaux->text().toInt();
    modifier_abonnement m(idd,a,b,c,d);
    bool test;
    query.prepare("select * from abonnements where nom = :id");
    query.bindValue(":id",ui->ID->text());
    query.exec();
    if (!(query.next()))
    {
        bool test=m.ajouter();
        if (test)
        {
           ui->table->setModel(mtable.afficher());
           QMessageBox::information(nullptr,QObject::tr("Ajouter"),
                   QObject::tr("Ajout validé \n "
                               "Sortir"),QMessageBox::Cancel);
        }


    }
    else {
        QMessageBox::critical(nullptr,QObject::tr("Demande"),
                QObject::tr("Erreur! \n"
                            "Sortir"),QMessageBox::Cancel);
    }

    ui->table->setModel(mtable.afficher());
}


void mwabonnementpartenariat::on_supprimer_clicked()
{
    int nom_supp = ui->ID_supp->text().toInt();
    modifier_abonnement m;
    bool test = m.supprimer_abonnemeent(nom_supp);
    ui->table->setModel(mtable.afficher());
}

void mwabonnementpartenariat::on_pushButton_3_clicked()
{
    int e =ui->ID_mod->text().toInt();
    int a = ui->duree_mod->text().toInt();
    QString b = ui->nom_mod->text();
    QString c = ui->prenom_mod->text();
    int d = ui->reseau_mod->text().toInt();
    bool test;
    modifier_abonnement m;
    test = m.modifier_abonnements(e,a,c,b,d);
    ui->table->setModel(mtable.afficher());
}



void mwabonnementpartenariat::on_lineEdit_4_textChanged(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
    ui->table->setModel(mtable.afficher());
        query.prepare("select * from abonnements where nom = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "ID "));
        ui->table->setModel(mtable.afficher());
}
/*
void mwabonnementpartenariat::on_lineEdit_4_textEdited(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
   ui->table->setModel(mtable.afficher());
        query.prepare("select * from abonnements where nom = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "NOM "));
        ui->table->setModel(mtable.afficher());
}
*/

void mwabonnementpartenariat::on_rech_textChanged(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
    //ui->table->setModel(mtable.afficher());
        query.prepare("select * from abonnements where ID = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "ID "));
       // ui->table->setModel(model);
}

void mwabonnementpartenariat::on_rech_textEdited(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
   // ui->table->setModel(mtable.afficher());
        query.prepare("select * from abonnements where ID = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "ID "));
        ui->table->setModel(model);
}

void mwabonnementpartenariat::on_pushButton_4_clicked()
{
    ui->table->setModel(mtable.afficher());

}


void mwabonnementpartenariat::on_pushButton_8_clicked()
    {
        QSqlQuery query;
        int idpar = ui->idpar->text().toInt();
        QString nompar = ui->nompar->text();
        QString prepar = ui->prepar->text();
        int sompar = ui->sompar->text().toInt();
        modifier_partenariat mp(idpar,nompar,prepar,sompar);
        bool test;
        query.prepare("select * from partenariat where ID = :id");
        query.bindValue(":id",ui->idpar->text());
        query.exec();
        if (!(query.next()))
        {
            bool test=mp.ajouter_partenariat();
            if (test)
            {
               ui->tablepar->setModel(mptable.afficher_partenariat());
               QMessageBox::information(nullptr,QObject::tr("Ajouter"),
                       QObject::tr("Ajout validé \n "
                                   "Sortir"),QMessageBox::Cancel);
            }


        }
        else {
            QMessageBox::critical(nullptr,QObject::tr("Demande"),
                    QObject::tr("Erreur! \n"
                                "Sortir"),QMessageBox::Cancel);
        }

        ui->tablepar->setModel(mptable.afficher_partenariat());
    }



void mwabonnementpartenariat::on_pushButton_9_clicked()
{
    int nompar_supp = ui->idpar_supp->text().toInt();
    modifier_partenariat mp;
    bool test = mp.supprimer_partenariat(nompar_supp);
    ui->tablepar->setModel(mptable.afficher_partenariat());
}


void mwabonnementpartenariat::on_pushButton_10_clicked()
{
    int e =ui->idpar_mod->text().toInt();
    QString b = ui->nompar_mod->text();
    QString c = ui->prepar_mod->text();
    int d = ui->sompar_mod->text().toInt();
    bool test;
    modifier_partenariat mp;
    test = mp.modifier_par(e,b,c,d);
    ui->tablepar->setModel(mptable.afficher_partenariat());
}

void mwabonnementpartenariat::on_rechpar_textChanged(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
    //ui->table->setModel(mptable.afficher_partenariat());
        query.prepare("select * from partenariat where ID = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "ID "));
       // ui->table->setModel(model);

}

void mwabonnementpartenariat::on_rechpar_textEdited(const QString &arg1)
{
    QString r;
        QSqlQuery query;
        QSqlQueryModel *model =new QSqlQueryModel();
       // r="select * from CLIENT where CIN like "+arg1;
   // ui->table->setModel(mtable.afficher());
        query.prepare("select * from partenariat where ID = :id");
        query.bindValue(":id",arg1);
        query.exec();
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr( "ID "));
        ui->tablepar->setModel(model);
}



void mwabonnementpartenariat::on_pushButton_7_clicked()
{
    ui->tablepar->setModel(mptable.afficher_partenariat());
}
