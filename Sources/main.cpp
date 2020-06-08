#include "../Headers/mainmenu.h"

#include <QApplication>

/**
 * Se crea un objeto de tipo QApplication que
 * contiene todo lo necesario para ejecutar
 * el programa y se crea otro de tipo MainMenu
 * para mostrar la ventana Menú Principal
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}
