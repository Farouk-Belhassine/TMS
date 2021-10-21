#include "mwparkingdepot.h"
#include "ui_mwparkingdepot.h"
#include "place_parking.h"
#include "depot.h"

mwparkingdepot::mwparkingdepot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mwparkingdepot)
{
    ui->setupUi(this);
    ui->tableafficheplace->setModel(p.afficher());

        QRegExp rx("[A-Za-z_]+");//[A-Za-z0-9_]
            QRegExp rx1("[/0-9_]+");
            QValidator *validator = new QRegExpValidator(rx, this);
            QValidator *validator2 = new QRegExpValidator(rx1, this);
            ui->lineEdit_mat->setValidator(validator2);
            ui->lineEdit_km->setValidator(validator2);
            ui->lineEdit_categorie->setValidator(validator);
            ui->lineEdit_date->setValidator(validator2);

            ui->lineEdit_matSupp->setValidator(validator2);

            ui->lineEdit_matRech_M->setValidator(validator2);
            ui->lineEdit_mat_M->setValidator(validator2);
            ui->lineEdit_km_M->setValidator(validator2);
            ui->lineEdit_categorie_M->setValidator(validator);
            ui->lineEdit_date_M->setValidator(validator2);

            ui->lineEdit_mat_Rech->setValidator(validator2);
            ui->lineEdit_date_Rech->setValidator(validator2);

        ui->tableaffichedepot->setModel(d.afficher());

        ui->lineEdit_mat_D->setValidator(validator2);
        ui->lineEdit_km_D->setValidator(validator2);
        ui->lineEdit_categorie_D->setValidator(validator);
        ui->lineEdit_date_D->setValidator(validator2);

        ui->lineEdit_matsupp_D->setValidator(validator2);

        ui->lineEdit_matRech_M_D->setValidator(validator2);
        ui->lineEdit_mat_M_D->setValidator(validator2);
        ui->lineEdit_km_M_D->setValidator(validator2);
        ui->lineEdit_categorie_M_D->setValidator(validator);
        ui->lineEdit_date_M_D->setValidator(validator2);

        ui->lineEdit_matRech_D->setValidator(validator2);
        ui->lineEdit_datRech_D->setValidator(validator2);
}

mwparkingdepot::~mwparkingdepot()
{
    delete ui;
}

void mwparkingdepot::on_pushButton_Ajouter_clicked()
{
    int matriculation=ui->lineEdit_mat->text().toInt();
    int kilometrage=ui->lineEdit_km->text().toInt();
    QString categorie=ui->lineEdit_categorie->text();
    int datedentrer=ui->lineEdit_date->text().toInt();


    place_parking NewP(matriculation,kilometrage,categorie,datedentrer);

    if(NewP.ajouter())
             QMessageBox::information(nullptr, QObject::tr("Ajouter une Place Parking"),
                         QObject::tr("Place Parking ajoutée"), QMessageBox::Ok );

         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter une Place Parking"),
                         QObject::tr("Place Parking n'est pas ajoutée"), QMessageBox::Close);

    ui->tableafficheplace->setModel(p.afficher());
}

void mwparkingdepot::on_pushButton_supprimer_clicked()
{
    int matriculation=ui->lineEdit_matSupp->text().toInt();

    if(p.supprimer(matriculation))
         {
             QMessageBox::information(nullptr, QObject::tr("Supprimer une Place Parking"),
                         QObject::tr("Place Parking Supprimée"), QMessageBox::Ok );

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Supprimer une Place Parking"),
                         QObject::tr("Place Parking n'est pas Supprimée"), QMessageBox::Close);

    ui->tableafficheplace->setModel(p.afficher());
}

void mwparkingdepot::on_pushButton_Modifier_clicked()
{
    int mat=ui->lineEdit_matRech_M->text().toInt();
    int matriculation=ui->lineEdit_mat_M->text().toInt();
    int kilometrage=ui->lineEdit_km_M->text().toInt();
    QString categorie=ui->lineEdit_categorie_M->text();
    int datedentrer=ui->lineEdit_date_M->text().toInt();

    if(p.modifier(matriculation,kilometrage,categorie,datedentrer,mat))
         {
             QMessageBox::information(nullptr, QObject::tr("Modifier une Place Parking"),
                         QObject::tr("Place Parking Modifié"), QMessageBox::Ok );

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier une Place Parking"),
                         QObject::tr("Place Parking n'est pas modifié"), QMessageBox::Close);

    QString matQS=QString::number(mat);
    ui->tableafficheplace->setModel(p.afficher());
}

void mwparkingdepot::on_pushButton_Recherche_clicked()
{
    if(ui->radioButton_matRech->isChecked())
    {
    QString mat=ui->lineEdit_mat_Rech->text();
    ui->tableafficheplace_OP->setModel(p.recherchermat(mat));
    }

    if(ui->radioButton_dateRech->isChecked())
    {
    QString date=ui->lineEdit_date_Rech->text();
    ui->tableafficheplace_OP->setModel(p.rechercherdate(date));
    }
}

void mwparkingdepot::on_pushButton_trier_clicked()
{
    ui->tableafficheplace_OP->setModel(p.trier("DATEDENTRER"));
}

void mwparkingdepot::on_pushButton_Imprimer_clicked()
{
    QString str;
      str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> PLACE PARKING</font><br /> <br /> "));
      str.append("<table border=1><tr>");


      str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">Matriculation</font>&nbsp;&nbsp;"+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Kilometrage</font>&nbsp;&nbsp;")+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Categorie</font>&nbsp;&nbsp;")+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Date</font>&nbsp;&nbsp;")+"</td>");



      QSqlQuery * query=new QSqlQuery();
      query->exec("SELECT MATRICULATION,KILOMETRAGE,CATEGORIE,DATEDENTRER FROM PLACE_PARKING");
      while(query->next())
      {
          str.append("<tr><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(4).toString()+"&nbsp;&nbsp;");
          str.append("</td></tr>");


      }


    str.append("</table></center><body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path= QFileDialog::getSaveFileName(NULL,"imprimer","Gestion Parking","PDF(*.pdf");
     if(path.isEmpty()) return;
     printer.setOutputFileName(path);
     QTextDocument doc;
     doc.setHtml(str);
     doc.print(&printer);
}

void mwparkingdepot::on_pushButton_Ajouter_M_clicked()
{
    int matriculation=ui->lineEdit_mat_D->text().toInt();
    int kilometrage=ui->lineEdit_km_D->text().toInt();
    QString categorie=ui->lineEdit_categorie_D->text();
    int datedentrer=ui->lineEdit_date_D->text().toInt();


    depot NewD(matriculation,kilometrage,categorie,datedentrer);

    if(NewD.ajouter())
             QMessageBox::information(nullptr, QObject::tr("Ajouter Depot"),
                         QObject::tr("Depot ajoutée"), QMessageBox::Ok );

         else
             QMessageBox::critical(nullptr, QObject::tr("Ajouter Depot"),
                         QObject::tr("Depot n'est pas ajoutée"), QMessageBox::Close);

    ui->tableaffichedepot->setModel(d.afficher());
}

void mwparkingdepot::on_pushButton_supprimer_M_clicked()
{
    int matriculation=ui->lineEdit_matsupp_D->text().toInt();

    if(d.supprimer(matriculation))
         {
             QMessageBox::information(nullptr, QObject::tr("Supprimer Depot"),
                         QObject::tr("Depot Supprimée"), QMessageBox::Ok );

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Supprimer Depot"),
                         QObject::tr("Depot n'est pas Supprimée"), QMessageBox::Close);

    ui->tableaffichedepot->setModel(d.afficher());
}

void mwparkingdepot::on_pushButton_Modifier_M_clicked()
{
    int mat=ui->lineEdit_matRech_M_D->text().toInt();
    int matriculation=ui->lineEdit_mat_M_D->text().toInt();
    int kilometrage=ui->lineEdit_km_M_D->text().toInt();
    QString categorie=ui->lineEdit_categorie_M_D->text();
    int datedentrer=ui->lineEdit_date_M_D->text().toInt();

    if(d.modifier(matriculation,kilometrage,categorie,datedentrer,mat))
         {
             QMessageBox::information(nullptr, QObject::tr("Modifier Depot"),
                         QObject::tr("Depot Modifié"), QMessageBox::Ok );

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier Depot"),
                         QObject::tr("Depot n'est pas modifié"), QMessageBox::Close);

    QString matQS=QString::number(mat);
    ui->tableaffichedepot->setModel(d.afficher());
}

void mwparkingdepot::on_pushButton_Recherche_M_clicked()
{
    if(ui->radioButton_matRech_D->isChecked())
    {
    QString mat=ui->lineEdit_matRech_D->text();
    ui->tableaffichedepot_OP->setModel(d.recherchermat(mat));
    }

    if(ui->radioButton_dateRech_D->isChecked())
    {
    QString date=ui->lineEdit_datRech_D->text();
    ui->tableaffichedepot_OP->setModel(d.rechercherdate(date));
    }
}

void mwparkingdepot::on_pushButton_trier_M_clicked()
{
    ui->tableaffichedepot_OP->setModel(d.trier("DATEDENTRER"));
}

void mwparkingdepot::on_pushButton_Imprimer_D_clicked()
{
    QString str;
      str.append("<html><head></head><body><center>"+QString("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;;<font size=""10"" color =""red""> DEPOT</font><br /> <br /> "));
      str.append("<table border=1><tr>");


      str.append("<td>"+QString("  ")+"&nbsp;&nbsp;<font color =""blue""  size=""10"">Matriculation</font>&nbsp;&nbsp;"+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Kilometrage</font>&nbsp;&nbsp;")+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Categorie</font>&nbsp;&nbsp;")+"</td>");
      str.append("<td>"+QString("&nbsp;&nbsp;<font color =""blue""  size=""10"">Date</font>&nbsp;&nbsp;")+"</td>");



      QSqlQuery * query=new QSqlQuery();
      query->exec("SELECT MATRICULATION,KILOMETRAGE,CATEGORIE,DATEDENTRER FROM DEPOT");
      while(query->next())
      {
          str.append("<tr><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size= ""10"">"+query->value(0).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green""  size=""10"">"+query->value(1).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(3).toString()+"&nbsp;&nbsp;");
          str.append("</td><td>");
          str.append("&nbsp;&nbsp;<font color =""green"" size=""10"">"+query->value(4).toString()+"&nbsp;&nbsp;");
          str.append("</td></tr>");


      }


    str.append("</table></center><body></html>");

    QPrinter printer;
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);

    QString path= QFileDialog::getSaveFileName(NULL,"imprimer","Gestion Parking","PDF(*.pdf");
     if(path.isEmpty()) return;
     printer.setOutputFileName(path);
     QTextDocument doc;
     doc.setHtml(str);
     doc.print(&printer);
}
