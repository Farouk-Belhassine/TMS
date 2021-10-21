#include "fournisseurs.h"
#include "ui_fournisseurs.h"
#include <QMessageBox>

fournisseurs::fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseurs)
{
    ui->setupUi(this);
    ui->tableView_fournisseurs->setModel(afficher());
    ui->tableView_fournisseursajout->setModel(afficher());
    ui->tableView_fournisseursmodification->setModel(afficher());
    ui->tableView_fournisseurssupprimer->setModel(afficher());
    ui->label_nofour->hide();
    ui->label_nofour_2->hide();
    ui->label_ecriveznom->hide();
    QValidator *validator=new QRegExpValidator(QRegExp("[A-Za-z]+"),this);
    ui->lineEdit_nom->setValidator(validator);
    ui->lineEdit_nommodifier->setValidator(validator);
    ui->lineEdit_nomstat->setValidator(validator);
    ui->lineEdit_produitstat->setValidator(validator);
    ui->lineEdit_nomafficher->setValidator(validator);
    ui->lineEdit_nomsupprimer->setValidator(validator);
    nom="";
    produit="";
}

fournisseurs::~fournisseurs()
{
    delete ui;
}

void fournisseurs::on_pushButton_retour_clicked()
{
    hide();
}

fournisseurs::fournisseurs(QString nom, QString produit)
{
    this->nom=nom;
    this->produit=produit;
}

bool fournisseurs::ajouter(QString nom,QString produit)
{
    QSqlQuery query;
    query.prepare("INSERT INTO fournisseurs (NOM, PRODUIT)"
                  "VALUES (:NOM, :PRODUIT)");
    query.bindValue(":NOM",nom);
    query.bindValue(":PRODUIT",produit);

    return query.exec();
}

QSqlQueryModel * fournisseurs::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseurs");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRODUIT"));

    return model;
}

bool fournisseurs::supprimer(QString nom)
{
    QSqlQuery query;
    query.prepare("Delete from fournisseurs where NOM = :NOM ");
    query.bindValue(":NOM", nom);

    return query.exec();
}

void fournisseurs::on_pushButton_ajouter_clicked()
{
    bool test=false;
    QString nom=ui->lineEdit_nom->text();
    QString produit=ui->comboBox_pob->currentText();

    if(control(nom)==0) test=ajouter(nom,produit);

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
        QObject::tr("successful.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_fournisseurs->setModel(afficher());
        ui->tableView_fournisseursajout->setModel(afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void fournisseurs::on_pushButton_supprimer_clicked()
{
    bool test=false;

    QString nom=ui->lineEdit_nomsupprimer->text();
    if(control(nom)) test=supprimer(nom);

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
        QObject::tr("successful.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_fournisseurs->setModel(afficher());
        ui->tableView_fournisseurssupprimer->setModel(afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

bool fournisseurs::modifier(QString nom, QString produit)
{
    QSqlQuery query;
    query.prepare("Update fournisseurs set PRODUIT=:produit where NOM=:nom");
    query.bindValue(":nom", nom);
    query.bindValue(":produit", produit);

    return query.exec();
}

void fournisseurs::on_pushButton_modifier_clicked()
{
    bool test=false;

    QString nom=ui->lineEdit_nommodifier->text();
    QString produit=ui->comboBox_pob2->currentText();
    if(control(nom)) test=modifier(nom,produit);

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
        QObject::tr("successful.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_fournisseurs->setModel(afficher());
        ui->tableView_fournisseursmodification->setModel(recherche(nom));
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

QSqlQueryModel * fournisseurs::trinom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseurs order by NOM");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRODUIT"));

    return model;
}

QSqlQueryModel * fournisseurs::triproduit()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseurs order by PRODUIT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRODUIT"));

    return model;
}

void fournisseurs::on_pushButton_trinom_clicked()
{
    ui->tableView_fournisseurs->setModel(trinom());
}

void fournisseurs::on_pushButton_tricapacite_clicked()
{
    ui->tableView_fournisseurs->setModel(triproduit());
}

QSqlQueryModel * fournisseurs::recherche(QString r)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from fournisseurs where NOM=:nom");
    query.bindValue(":nom",r);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("PRODUIT"));

    return model;
}

void fournisseurs::on_pushButton_Afficher_clicked()
{
    QString nom=ui->lineEdit_nomafficher->text();
    ui->tableView_fournisseurs->setModel(recherche(nom));
}

QSqlQueryModel * fournisseurs::statproduit(QString produit)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select sum(case when PRODUIT=:produit then 1 else 0 end) from fournisseurs");
    query.bindValue(":produit", produit);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Total"));

    return model;
}

void fournisseurs::on_pushButton_statistiqueparproduit_clicked()
{
    QString nom=ui->lineEdit_produitstat->text();
    ui->tableView_fournisseurs->setModel(statproduit(nom));
}

QSqlQueryModel *  fournisseurs::statnom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select sum(case when NOM=:nom then 1 else 0 end ) from fournisseurs");
    query.bindValue(":nom", nom);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Total"));

    return model;
}

void fournisseurs::on_pushButton_statistiqueparnom_clicked()
{
    QString produit=ui->lineEdit_nomstat->text();
    ui->tableView_fournisseurs->setModel(statnom(produit));
}

void fournisseurs::on_lineEdit_nommodifier_textChanged(const QString &arg1)
{
    if(arg1!=nullptr){
        ui->tableView_fournisseursmodification->setModel(recherche(arg1));
        if(control(arg1)==0) ui->label_nofour_2->show();
        else ui->label_nofour_2->hide();
    }
    else{
        ui->tableView_fournisseursmodification->setModel(afficher());
        ui->label_nofour_2->hide();
    }
}

void fournisseurs::on_lineEdit_nomsupprimer_textChanged(const QString &arg1)
{
    if(arg1!=nullptr){
        ui->tableView_fournisseurssupprimer->setModel(recherche(arg1));
        if(control(arg1)==0) ui->label_nofour->show();
        else ui->label_nofour->hide();
    }
    else{
        ui->tableView_fournisseurssupprimer->setModel(afficher());
        ui->label_nofour->hide();
    }
}

void fournisseurs::on_lineEdit_nom_textChanged(const QString &arg1)
{
    if(arg1==nullptr) ui->label_ecriveznom->show();
    else ui->label_ecriveznom->hide();
}

int fournisseurs::control(QString nom)
{
    QSqlQuery query;

    query.prepare("select sum(case when NOM=:nom then 1 else 0 end) from fournisseurs");
    query.bindValue(":nom", nom);
    query.exec();
    query.next();
    int n=query.value(0).toInt();

    return n;
}
