#ifndef VER_PACIENTES_H
#define VER_PACIENTES_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QtCore>
#include <QFileDialog>
#include <bits/stdc++.h>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSortFilterProxyModel>
#include "Headers/ver_pacientes_offline.h"
//Se crea el espacio de trabajo que representa la ventana de Registrar Paciente
namespace Ui
{
    class ver_pacientes;
}
class QSqlTableModel;
class ver_pacientes : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit ver_pacientes(QWidget *parent = nullptr);
    ~ver_pacientes();
    //Se crea un apuntador a un objeto QSortFilterProxyModel para establecer el filtro de la base de datos
    QSortFilterProxyModel *proxy;

private slots:
    //Metodos de la clase
    void on_pushButton_clicked();

    void on_buscar_clicked();

    void on_pushButton_2_clicked();

private:
    //Apuntador a un objeto del tipo de la clase Registrar
    Ui::ver_pacientes *ui;
    //Apuntador a un objeto QSqlTableModel para crear la base de datos
    QSqlTableModel *mModelOnline;
};

#endif // VER_PACIENTES_H
