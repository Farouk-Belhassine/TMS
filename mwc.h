#ifndef MWC_H
#define MWC_H

#include <QDialog>

namespace Ui {
class mwc;
}

class mwc : public QDialog
{
    Q_OBJECT

public:
    explicit mwc(QWidget *parent = nullptr);
    ~mwc();

private slots:
    void on_pushButton_gestionbus_clicked();

    void on_pushButton_gestionfournisseurs_clicked();

    void on_pushButton_deconnexion_clicked();

    void on_pushButton_gestionreservationplace_clicked();

    void on_pushButton_gestionreservationbus_clicked();

    void on_pushButton_reseauetstation_clicked();

    void on_pushButton_gestionabonementpartenariat_clicked();

    void on_pushButton_gestionparkdepot_clicked();

private:
    Ui::mwc *ui;
};

#endif // MWC_H
