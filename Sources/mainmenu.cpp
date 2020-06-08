#include "../Headers/mainmenu.h"
#include "ui_mainmenu.h"

/**
 * Constructor del objeto MainMenu donde
 * se indica los valores y cómo se usarán
 * los atributos que contiene
*/
MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

/**
 * Destructor del objeto MainMenu
 */
MainMenu::~MainMenu()
{
    delete ui;
}

/**
 * Esta función es la acción que se ejecuta
 * al presionar elegir la opción -Si-
 * creando un objeto de tipo ver_pacientes
 * y lo muestra en pantalla
 */
void MainMenu::on_pushButton_clicked()
{
    Registrar *registrar = new Registrar;
    registrar->show();
}

/**
 * Esta función se activa al presionar el menú
 * -Acerca_de- creando un objeto de tipo
 * Acer_de para mostrarlo en pantalla
 */
void MainMenu::on_actionAcerca_de_triggered()
{
    Acerca_de *acerca = new Acerca_de;
    acerca->show();
}

/**
 * Esta función se activa al presionar la opción
 * -No- creando un objeto de tipo
 * offregistro para mostrarlo en pantalla
 */
void MainMenu::on_pushButton_2_clicked()
{
    offregistro *Registro_offline = new offregistro;
    Registro_offline->show();
}
