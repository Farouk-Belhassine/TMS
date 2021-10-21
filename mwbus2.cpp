#include "mwbus2.h"
#include "ui_mwbus2.h"
#include "bus2.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QDesktopServices>
#include <QStatusBar>

mwbus2::mwbus2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mwbus2)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
        ui->lineEdit_cin->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
        ui->lineEdit_nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]+"), this ));
        ui->lineEdit_prenom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]+"), this ));
        ui->lineEdit_email->setValidator(new QRegExpValidator( QRegExp("[A-Za-z0_9@.]+"), this ));
        ui->lineEdit_nbp->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
        ui->lineEdit_nbr->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
}

mwbus2::~mwbus2()
{
    delete ui;
}

void mwbus2::on_pb_ajouter_clicked()
{   QFile file("maillist.txt");
    file.open(QFile::Append | QFile::Text);

    int id = ui->lineEdit_id->text().toInt();
    int cin = ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();
    int nbbus = ui->lineEdit_nbp->text().toInt();
    int nbres = ui->lineEdit_nbr->text().toInt();
    QString td=ui->edit_td->text();
  bus2 p(id,cin,nom,prenom,email,nbbus,nbres,td);

  bool test=p.ajouter();
  if(test)
{ui->tabplace->setModel(tmp.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter bus a reserver"),
                  QObject::tr("bus ajouté.\n"
                              ), QMessageBox::Cancel);

QTextStream out(&file);
QString text = ui->lineEdit_email->text();
out << text <<endl;
file.flush();
file.close();
ui->lineEdit_id->clear();
ui->lineEdit_cin->clear();
ui->lineEdit_nom->clear();
ui->lineEdit_prenom->clear();
ui->lineEdit_email->clear();
ui->lineEdit_nbp->clear();
ui->lineEdit_nbr->clear();
ui->edit_td->clear();


}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter bus a reserver"),
                  QObject::tr("Erreur !.\n"
                              ), QMessageBox::Cancel);
}

void mwbus2::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int cin = ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();
    int nbbus = ui->lineEdit_nbp->text().toInt();
    int nbres = ui->lineEdit_nbr->text().toInt();
    QString td=ui->edit_td->text();

  bus2 p(id,cin,nom,prenom,email,nbbus,nbres,td);
  bool test=p.modifier(id);
  if(test)
{ui->tabplace->setModel(tmp.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier bus a reserver"),
                  QObject::tr("bus modifier.\n"
                              ), QMessageBox::Cancel);
ui->lineEdit_id->clear();
ui->lineEdit_cin->clear();
ui->lineEdit_nom->clear();
ui->lineEdit_prenom->clear();
ui->lineEdit_email->clear();
ui->lineEdit_nbp->clear();
ui->lineEdit_nbr->clear();
ui->edit_td->clear();


}
  else

      QMessageBox::critical(nullptr, QObject::tr("modifier bus a reserver"),
                  QObject::tr("Erreur !.\n"
                              ), QMessageBox::Cancel);


}



void mwbus2::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    bool test=tmp.supprimer(id);
    if(test)
    {ui->tabplace->setModel(tmp.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer bus a reserver"),
                    QObject::tr("bus supprimé.\n"
                                ), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer bus a reserver"),
                    QObject::tr("Erreur !.\n"
                                ), QMessageBox::Cancel);
}

void mwbus2::on_pb_show_clicked()
{
    ui->tabplace->setModel(tmp.afficher());
}

void mwbus2::on_tabplace_activated(const QModelIndex &index)
{
    QString valeur=ui->tabplace->model()->data(index).toString();
    QSqlQuery query;

    query.prepare(" select * from place WHERE ID=: valeur  ");
 if (query.exec())
 {  while (query.next())
     {


    ui->lineEdit_id->setText(query.value(0).toString());
    /*ui->lineEdit_cin->setText(query.value(1).toString());
    ui->lineEdit_nom->setText(query.value(2).toString());
    ui->lineEdit_prenom->setText(query.value(3).toString());
    ui->lineEdit_email->setText(query.value(4).toString());
    ui->lineEdit_nbp->setText(query.value(5).toString());
    ui->lineEdit_nbr->setText(query.value(6).toString());*/
     }
 }
 else
 {
     QMessageBox::critical(nullptr, QObject::tr("Bus"),
                 QObject::tr("Erreur !.\n"
                             ), QMessageBox::Cancel);
 }

}

void mwbus2::on_pushButton_4_clicked()
{
    m = new Mailer(this);
    m->show();
}

void mwbus2::on_pushButton_3_clicked()
{
    ui->tabplace->setModel(tmp.afficherf());

}

void mwbus2::on_pushButton_2_clicked()
{
    QSqlQueryModel * model=tmp.trier();
       ui->tabplace->setModel(model);
   }

   QSqlQueryModel * bus2::trier()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from bus2 order by id asc;");


   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRENOM"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBP"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("NBR"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("TD"));

   return model;
}

   void mwbus2::on_pb_retour_clicked()
   {
       mwbus2::hide();
   }

void mwbus2::on_pushButton_clicked()
{
    mwbus2::setStyleSheet("background-color: white");
    ui->label->setStyleSheet("color: black");
    ui->label_2->setStyleSheet("color: black");
    ui->label_3->setStyleSheet("color: black");
    ui->label_4->setStyleSheet("color: black");
    ui->label_5->setStyleSheet("color: black");
    ui->label_6->setStyleSheet("color: black");
    ui->label_7->setStyleSheet("color: black");
    ui->label_8->setStyleSheet("color: black");
    ui->tabplace->setStyleSheet("background-color:white ");
    ui->tabplace->setStyleSheet("color:black ");

    ui->pushButton->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_2->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_3->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_4->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_5->setStyleSheet("background-color:#c4c4c4");
    ui->pb_show->setStyleSheet("background-color:#c4c4c4");
    ui->pb_retour->setStyleSheet("background-color:#c4c4c4");
    ui->pb_ajouter->setStyleSheet("background-color:#c4c4c4");
    ui->pb_modifier->setStyleSheet("background-color:#c4c4c4");
    ui->pb_supprimer->setStyleSheet("background-color:#c4c4c4");
}

void mwbus2::on_pushButton_5_clicked()
{
    mwbus2::setStyleSheet("background-color: black");
    ui->label->setStyleSheet("color: white");
    ui->label_2->setStyleSheet("color: white");
    ui->label_3->setStyleSheet("color: white");
    ui->label_4->setStyleSheet("color: white");
    ui->label_5->setStyleSheet("color: white");
    ui->label_6->setStyleSheet("color: white");
    ui->label_7->setStyleSheet("color: white");
    ui->label_8->setStyleSheet("color: white");
    ui->tabplace->setStyleSheet("color:gray");
    ui->pushButton->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_2->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_3->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_4->setStyleSheet("background-color:#c4c4c4");
    ui->pushButton_5->setStyleSheet("background-color:#c4c4c4");
    ui->pb_show->setStyleSheet("background-color:#c4c4c4");
    ui->pb_retour->setStyleSheet("background-color:#c4c4c4");
    ui->pb_ajouter->setStyleSheet("background-color:#c4c4c4");
    ui->pb_modifier->setStyleSheet("background-color:#c4c4c4");
    ui->pb_supprimer->setStyleSheet("background-color:#c4c4c4");
}
