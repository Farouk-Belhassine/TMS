#include "bus.h"
#include "ui_bus.h"
#include <QMessageBox>

bus::bus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bus)

{
    ui->setupUi(this);
    bus::makeplot();
    ui->tableView_bus->setModel(afficher());
    ui->tableView_busajout->setModel(afficher());
    ui->tableView_busmodifier->setModel(afficher());
    ui->tableView_bussupprimer->setModel(afficher());
    ui->label_lowcapacite->hide();
    ui->label_numero0->hide();
    ui->label_lowcapacite_2->hide();
    ui->label_nobus->hide();
    ui->label_busexiste->hide();
    QValidator *validator=new QRegExpValidator(QRegExp("[0-9]+"),this);
    ui->lineEdit_numeroajout->setValidator(validator);
    ui->lineEdit_capacite->setValidator(validator);
    ui->lineEdit_capacitestat->setValidator(validator);
    ui->lineEdit_etatstat->setValidator(validator);
    ui->lineEdit_afficher->setValidator(validator);
    ui->lineEdit_numeromodifier->setValidator(validator);
    ui->lineEdit_capacitemodifier->setValidator(validator);
    ui->lineEdit_numerosupprimer->setValidator(validator);
    numero_bus=0;
    capacite=0;
    etat="";
}

bus::~bus()
{
    delete ui;
}

bus::bus(int numero_bus,int capacite, QString etat)
{
    this->numero_bus=numero_bus;
    this->capacite=capacite;
    this->etat=etat;
}

bool bus::ajouter(int numero,int capacite, QString etat)
{
    QSqlQuery query;
    QString nnum=QString::number(numero);
    QString ccap=QString::number(capacite);
    query.prepare("INSERT INTO BUS (NUMERO_BUS, CAPACITE, ETAT) "
                  "VALUES (:NUMERO_BUS, :CAPACITE, :ETAT)");
    query.bindValue(":NUMERO_BUS",nnum);
    query.bindValue(":CAPACITE",ccap);
    query.bindValue(":ETAT",etat);

    return query.exec();
}

QSqlQueryModel * bus::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from bus");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO_BUS"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

QSqlQueryModel * bus::tricapacite()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from bus order by CAPACITE");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO_BUS"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

QSqlQueryModel * bus::trinumero()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from bus order by NUMERO_BUS");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO_BUS"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool bus::supprimer(int numero)
{
    QSqlQuery query;
    QString nnum=QString::number(numero);
    query.prepare("Delete from bus where NUMERO_BUS = :NUMERO_BUS ");
    query.bindValue(":NUMERO_BUS", nnum);

    return query.exec();
}

void bus::on_pushButton_ajouter_clicked()
{
    bool test=false;

    int numero=ui->lineEdit_numeroajout->text().toInt();
    int capacite=ui->lineEdit_capacite->text().toInt();
    QString etat=ui->combobox_etat->currentText();

    if(capacite>=10&&numero>=0&&control(numero)==0){
        test=ajouter(numero,capacite,etat);
    }

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Ajouter un bus"),
        QObject::tr("successful.\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_bus->setModel(afficher());
        ui->tableView_busajout->setModel(recherche(ui->lineEdit_numeroajout->text()));
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un bus"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void bus::on_pushButton_supprimer_clicked()
{
    bool test=false;
    int numero=ui->lineEdit_numerosupprimer->text().toInt();
    if(control(numero)) test=supprimer(numero);

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Supprimer un bus"),
        QObject::tr("successful.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_bus->setModel(afficher());
        ui->tableView_bussupprimer->setModel(afficher());
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un bus"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void bus::on_pushButton_retour_clicked()
{
    hide();
}

bool bus::modifier(int numero,int capacite, QString etat)
{
    QSqlQuery query;
    QString nnum=QString::number(numero);
    QString ccap=QString::number(capacite);
    query.prepare("Update bus set CAPACITE=:capacite ,ETAT=:etat where NUMERO_BUS=:numero_bus");
    query.bindValue(":numero_bus", nnum);
    query.bindValue(":capacite", ccap);
    query.bindValue(":etat", etat);

    return query.exec();
}

void bus::on_pushButton_modifier_clicked()
{
    bool test=false;
    int numero=ui->lineEdit_numeromodifier->text().toInt();
    int capacite=ui->lineEdit_capacitemodifier->text().toInt();
    QString etat=ui->comboBox_etatmodification->currentText();

    if(capacite>=10&&control(numero)){
        test=modifier(numero,capacite,etat);
    }

    if(test){
        QMessageBox::information(nullptr, QObject::tr("Modifier un bus"),
        QObject::tr("successful.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView_bus->setModel(afficher());
        ui->tableView_busmodifier->setModel(recherche(ui->lineEdit_numeromodifier->text()));
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("modifier un bus"),
        QObject::tr("failed.\n"
                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void bus::on_pushButton_tricapacite_clicked()
{
    ui->tableView_bus->setModel(tricapacite());
}

void bus::on_pushButton_trinumero_clicked()
{
    ui->tableView_bus->setModel(trinumero());
}

QSqlQueryModel * bus::recherche(QString r)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QString req="select * from bus where NUMERO_BUS like "+r;
    model->setQuery(req);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("NUMERO_BUS"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("CAPACITE"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

void bus::on_pushButton_afficher_clicked()
{
    QString numero=ui->lineEdit_afficher->text();
    ui->tableView_bus->setModel(recherche(numero));
}

QSqlQueryModel * bus::statetat(QString etat)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select sum(case when ETAT=:etat then 1 else 0 end) from bus");
    query.bindValue(":etat", etat);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Total"));

    return model;
}

void bus::on_pushButton_etatstat_clicked()
{
    QString etat=ui->lineEdit_etatstat->text();
    ui->tableView_bus->setModel(statetat(etat));
}

QSqlQueryModel * bus::statcapacite(QString capacite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select sum(case when CAPACITE=:capacite then 1 else 0 end) from bus");
    query.bindValue(":capacite", capacite);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Total"));

    return model;
}

void bus::on_pushButton_capacitestat_clicked()
{
    QString capacite=ui->lineEdit_capacitestat->text();
    ui->tableView_bus->setModel(statcapacite(capacite));
}

void bus::on_lineEdit_numeromodifier_textChanged(const QString &arg1)
{
    if(arg1==nullptr) ui->tableView_busmodifier->setModel(afficher());
    else ui->tableView_busmodifier->setModel(recherche(arg1));
}

void bus::on_lineEdit_numerosupprimer_textChanged(const QString &arg1)
{
    if(arg1==nullptr) ui->tableView_bussupprimer->setModel(afficher());
    else{
        ui->tableView_bussupprimer->setModel(recherche(arg1));
        int n=arg1.toInt();
        if(control(n)==0) ui->label_nobus->show();
        else ui->label_nobus->hide();
    }
}

void bus::on_lineEdit_capacite_textChanged(const QString &arg1)
{
    int nm=arg1.toInt();
    if(nm<10) ui->label_lowcapacite->show();
    else ui->label_lowcapacite->hide();
}

void bus::on_lineEdit_numeroajout_textChanged(const QString &arg1)
{
    int nm=arg1.toInt();
    if(nm<=0) ui->label_numero0->show();
    else ui->label_numero0->hide();
    if(control(nm)) ui->label_busexiste->show();
    else ui->label_busexiste->hide();
}

void bus::on_lineEdit_capacitemodifier_textChanged(const QString &arg1)
{
    int nm=arg1.toInt();
    if(nm<10) ui->label_lowcapacite_2->show();
    else ui->label_lowcapacite_2->hide();
}

int bus::control(int numero)
{
    QSqlQuery query;

    query.prepare("select sum(case when NUMERO_BUS=:numero then 1 else 0 end) from bus");
    query.bindValue(":numero", numero);
    query.exec();
    query.next();
    int n=query.value(0).toInt();

    return n;
}

void bus::makeplot()
{
    // set dark background gradient:
       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));

       // create empty bar chart objects:
       QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
       amande->setAntialiased(false);
       //amande->setStackingGap(1);
       // set names and colors:
       amande->setName("Nombre de bus");
       amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       amande->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with libelle produit labels:
       QVector<double> ticks;
       QVector<QString> labels;
       QSqlQuery q;
       int i=0;
       q.exec("select capacite from bus");
       while (q.next()) {
           QString id= q.value(0).toString();
           i++;
           ticks<<i;
           labels <<id;
       }
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 4);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);

       // prepare y axis:
       ui->customPlot->yAxis->setRange(0,10);
       ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Capacité");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
       ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
       ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

       // Add data:
       QVector<double> PlaceData;
       QSqlQuery q1("select * from bus");
       while (q1.next()) {
                     int  note = q1.value(1).toInt();
                     PlaceData<< note;
                       }
       amande->setData(ticks, PlaceData);
       // setup legend:
       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
