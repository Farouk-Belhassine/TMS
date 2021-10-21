#include "mwc.h"
#include "ui_mwc.h"
#include "bus.h"
#include "fournisseurs.h"
#include "mwplace.h"
#include "mwbus2.h"
#include "jasser.h"
#include "mwabonnementpartenariat.h"
#include "mwparkingdepot.h"

mwc::mwc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mwc)
{
    ui->setupUi(this);
}

mwc::~mwc()
{
    delete ui;
}

void mwc::on_pushButton_gestionbus_clicked()
{
    bus a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}


void mwc::on_pushButton_gestionfournisseurs_clicked()
{
    fournisseurs a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}

void mwc::on_pushButton_deconnexion_clicked()
{
    hide();
}

void mwc::on_pushButton_gestionreservationplace_clicked()
{
    mwplace a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}

void mwc::on_pushButton_gestionreservationbus_clicked()
{
    mwbus2 a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}

void mwc::on_pushButton_reseauetstation_clicked()
{
    jasser a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}

void mwc::on_pushButton_gestionabonementpartenariat_clicked()
{
    mwabonnementpartenariat a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}

void mwc::on_pushButton_gestionparkdepot_clicked()
{
    mwparkingdepot a;
    hide();
    a.setModal(true);
    a.exec();
    show();
}
