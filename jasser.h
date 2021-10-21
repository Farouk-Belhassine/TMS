#ifndef JASSER_H
#define JASSER_H
#include"reseau.h"
#include <QDialog>
#include <QPrinter>
#include<QFileDialog>
#include <QTextDocument>
#include "station.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class jasser; }
QT_END_NAMESPACE

class jasser : public QDialog
{
   /* Q_OBJECT

public:
    jasser(QWidget *parent = nullptr);
    ~jasser();*/
    Q_OBJECT

public:
    explicit jasser(QWidget *parent = nullptr);
    ~jasser();
    void combo();
    QString trajet();
private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_modifier_clicked();
    void on_trier_clicked();
    void on_imprimer_clicked();

    void sendMail();
    void sendMailstation();
    void mailSent(QString);

    void on_stat_clicked();



    void on_afficher_clicked();

    void on_send0_clicked();

    void on_pushButton_clicked();



    void on_ajouter2_clicked();

    void on_modifiers_clicked();

    void on_pb_supprimers_clicked();

    void on_affichers_clicked();

    void on_triers_clicked();

    void on_stats_clicked();

    void on_send0s_clicked();

    void on_imprimers_clicked();

    void on_pushButtons_clicked();



    void on_recherche_clicked();

    void on_recherches_clicked();


    void on_uploadButton_clicked();

    void uploadFinished(QNetworkReply *reply);  // Upload finish slot
        void uploadProgress(qint64 bytesSent, qint64 bytesTotal);  // Upload progress slot


        QString * html();
private:
    Ui::jasser *ui;
    reseau tmpreseau;
    station tmpstation;
    QNetworkAccessManager *m_manager;
        QString m_fileName;

        QFile *m_file;
};
#endif // JASSER_H
