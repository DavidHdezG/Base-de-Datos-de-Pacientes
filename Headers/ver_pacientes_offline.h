#ifndef VER_PACIENTES_OFFLINE_H
#define VER_PACIENTES_OFFLINE_H
#include <QDialog>
#include <QFile>
#include <QTextBrowser>
#include <QTextStream>
#include <QDir>

//Se crea el espacio de trabajo que representa la ventana de Registrar Paciente
namespace Ui
{
    class ver_pacientes_offline;
}

class ver_pacientes_offline : public QDialog
{
    Q_OBJECT

public:
    //Se crea un apuntador de tipo QWidget(Ventanas en este framework) que no apunta a nada
    explicit ver_pacientes_offline(QWidget *parent = nullptr);
    ~ver_pacientes_offline();

private slots:

private:
    //Apuntador a un objeto del tipo de la clase Registrar
    Ui::ver_pacientes_offline *ui;
};

#endif // VER_PACIENTES_OFFLINE_H
