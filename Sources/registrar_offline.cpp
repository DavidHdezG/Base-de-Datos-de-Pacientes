#include "ui_registrar_offline.h"
#include <bits/stdc++.h>
#include "../Headers/ver_pacientes_offline.h"
#include "../Headers/registrar_offline.h"
using namespace std;
registrar_offline::registrar_offline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrar_offline)
{
    ui->setupUi(this);
}

registrar_offline::~registrar_offline()
{
    delete ui;
}


void registrar_offline::on_pushButton_clicked()
{
    registrar(ui);
}

void registrar(Ui::registrar_offline *ui)
{

    ofstream myfile("Pacientes.txt", ofstream::app);
    QString nss = ui->nss->text();
    QString nombre = ui->nombre->text();
    QString apellp = ui->apellp->text();
    QString apellm = ui->apellm->text();
    QString edad = ui->edad->text();
    QString sexo = ui->sexo->text();
    QString sangre = ui->sangre->text();
    QString alergias = ui->alergias->text();
    QString ocupacion = ui->ocupacion->text();
    QString telefono = ui->telefono->text();

    myfile << "Número de Seguro Social: " << nss.toStdString() << endl;
    myfile << "Nombre(S): " << nombre.toStdString() << endl;
    myfile << "Apellido Paterno: " <<  apellp.toStdString() << endl;
    myfile << "Apellido Materno: " << apellm.toStdString() << endl;
    myfile << "Edad: " << edad.toStdString() << endl;
    myfile << "Sexo: " << sexo.toStdString() << endl;
    myfile << "Tipo de Sangre: " << sangre.toStdString() << endl;
    myfile << "Alergias: " << alergias.toStdString() << endl;
    myfile << "Ocupación: " << ocupacion.toStdString() << endl;
    myfile << "Telefono: " << telefono.toStdString() << endl;
    myfile << "\t\t-----------------------" << endl;




}

void registrar_offline::on_pushButton_2_clicked()
{
    ver_pacientes_offline *ver = new ver_pacientes_offline;
    ver->show();
}
