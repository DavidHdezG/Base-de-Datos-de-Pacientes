#ifndef OFFREGISTRO_H
#define OFFREGISTRO_H

#include <QDialog>
#include <QSqlDatabase>
#include "../Headers/databasesqlite.h"
#include <bits/stdc++.h>
#include "Headers/ver_pacientes_offline.h"
#include <QDir>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include "../Headers/offver_database.h"
using namespace std;

//Se crea el espacio de trabajo que representa la ventana del Menu Principal
namespace Ui
{
    class offregistro;
}

class offregistro : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit offregistro(QWidget *parent = nullptr);
    ~offregistro();

private slots:
    //Metodos de la clase
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    bool isValidInt(string str);

private:
    //Apuntador a un objeto del tipo de la clase MainMenu
    Ui::offregistro *ui;
    //Se crea un objeto de la clase databaseSqlite para crear la base de datos
    databaseSqlite sqlitedatabase;
};

#endif // OFFREGISTRO_H
