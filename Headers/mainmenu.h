#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QSqlDatabase>
#include "../Headers/registrar.h"
#include "../Headers/ver_pacientes.h"
#include <QMessageBox>
#include "../Headers/acerca_de.h"
#include <QSqlDatabase>
#include "../Headers/offregistro.h"
QT_BEGIN_NAMESPACE
//Se crea el espacio de trabajo que representa la ventana del Menu Principal
namespace Ui
{
    class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor y Destructor
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    //Metodos de la clase
    void on_pushButton_clicked();

    void on_actionAcerca_de_triggered();

    void on_pushButton_2_clicked();

private:
    //Apuntador a un objeto del tipo de la clase MainMenu
    Ui::MainMenu *ui;
};
#endif // MAINMENU_H
