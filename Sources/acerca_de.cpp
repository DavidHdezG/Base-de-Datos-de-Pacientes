#include "Headers/acerca_de.h"
#include "ui_acerca_de.h"

/**
 * Constructor del objeto Acerca_de donde
 * se indica los valores que recibe
 * y se incialian
*/
Acerca_de::Acerca_de(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acerca_de)
{
    ui->setupUi(this);
}

/**
 * Se invoca el destructor del objeto al cerrar
 * la ventana para destruirlo
 */
Acerca_de::~Acerca_de()
{
    delete ui;
}
