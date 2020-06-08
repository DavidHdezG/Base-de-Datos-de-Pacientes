#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDialog>
#include <QMessageBox>
#include "../Headers/databasemysql.h"
#include <bits/stdc++.h>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "../Headers/ver_pacientes.h"
#include "../Headers/mainmenu.h"
using namespace std;

//Se crea el espacio de trabajo que representa la ventana de Registrar Paciente
namespace Ui
{
    class Registrar;
}

class Registrar : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();

private slots:
    //Metodos de la clase
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    bool isValidInt(string str);

private:
    //Apuntador a un objeto del tipo de la clase Registrar
    Ui::Registrar *ui;
    //Se crea un objeto de la clase DatabaseMYSQL para crear la base de datos
    DatabaseMYSQL mysqldatabase;
};

#endif // REGISTRAR_H
