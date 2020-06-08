#ifndef OFFVER_DATABASE_H
#define OFFVER_DATABASE_H
#include <QSqlTableModel>
#include <QDialog>
#include <QDir>
#include "Headers/ver_pacientes_offline.h"
#include <QSortFilterProxyModel>

//Se crea el espacio de trabajo que representa la ventana del Menu Principal
namespace Ui
{
    class offver_database;
}
class QSqlTableModel;
class offver_database : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit offver_database(QWidget *parent = nullptr);
    ~offver_database();
    //Se crea un apuntador a un objeto QSortFilterProxyModel para establecer el filtro de la base de datos
    QSortFilterProxyModel *proxy;
private slots:
    //Metodos de la clase
    void on_pushButton_clicked();

    void on_buscar_clicked();


    void on_pacientes_eliminados_clicked();

private:
    //Apuntador a un objeto del tipo de la clase MainMenu
    Ui::offver_database *ui;
    //Apuntador a un objeto QSqlTableModel para crear la base de datos
    QSqlTableModel *mModel;
};

#endif // OFFVER_DATABASE_H
