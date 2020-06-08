#include "../Headers/ver_pacientes_offline.h"
#include "ui_ver_pacientes_offline.h"

/**
 * Constructor del objeto ver_pacientes_offline
 * y abre el archivo de texto de respaldo
 * en el cuadro de texto de la ventana
*/

ver_pacientes_offline::ver_pacientes_offline(QWidget *parent) : QDialog(parent),
                                                                ui(new Ui::ver_pacientes_offline)
{
    ui->setupUi(this);

    //Se abre el registro localizado en la carpeta del ejecutable
    QFile file(QDir::currentPath() + "/Pacientes.txt");
    file.open(QIODevice::ReadWrite);
    QTextStream in(&file);

    //Se muestra en el cuadro de texto
    ui->textBrowser->setText(in.readAll());
}

/**
 * Se invoca el destructor del objeto al cerrar
 * la ventana para destruirlo
 */
ver_pacientes_offline::~ver_pacientes_offline()
{
    delete ui;
}
