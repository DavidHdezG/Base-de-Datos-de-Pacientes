# Registro-de-Pacientes
El programa se conecta a una base de datos remota donde guarda la información de los pacientes, además crea una de manera local en caso de que no se tenga acceso a internet.
## Software necesario para compilar
1.- MySQL: https://dev.mysql.com/downloads/installer/ 
Recomiendo descargar el instalador web y cuando pregunte qué elementos instalar, sólo elegir MySQL Server y el Connector C++.	

2.- El IDE Qt Creator: https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4

Cuando pregunte qué elementos instalar es muy importante seleccionar:
	-En el apartado Qt 5.15.0 seleccione MingGW 8.1.0 64-bits (Aunque ya tenga el compilador instalado) y Sources.
	-En el apartado Developer and Designer Tools seleccione Qy Creator 4.12.2 CDB Debugger Support y Debugging Tools for Windows.

## ¿Cómo compilarlo?
Al descargar el proyecto abrir el archivo base_de_datos.pro con Qt Creator y compilarlo (ícono del martillo), luego se tiene que copiar el archivo libmysql.dll en la carpeta donde se cconstruyó el ejecutable, de esta manera ya se podrá utilizar este programa.

## Posibles problemas al ejecutarlo
### Driver not loaded
Este error significa que no existe el driver que conecta el programa a MySQL. La forma de solucionarlo es:

-Tener a la mano la ruta de instalación de MySQL Server sin espacios (se puede obtener con “dir /x” en la consola de Windows), por ejemplo: C:\PROGRA~1\MySQL\MYSQLS ~ 1.0\

-Igualmente con esta ruta (O parecida si se instaló en otro lugar) C:\Qt\5.15.0\Src\qtbase\src\plugins\sqldrivers

Ejecutar los siguientes comandos en la consola de Qt (Se encuentra en el menú de inicio, estará en la misma carpeta que Qt Creator):

1.- set mysql= "Ruta de MySQL sin espacios"

2.- cd C:\Qt\5.15.0\Src\qtbase\src\plugins\sqldrivers

3.- qmake

4.- cd mysql

5.- qmake INCLUDEPATH+=%mysql%\include LIBS+=%mysql%\lib\libmysql.lib -o mysql.pro

6.- mingw32-make

7.- mingw32-make install

Ahora entrar a la carpeta C:\Qt\5.15.0\Src\qtbase\src\plugins\sqldrivers y, si todo salió bien, se encontrarrá un archivo llamado qsqlmysql.dll, se tendrá que copiar a esta ruta: C:\Qt\5.15.0\mingw81_64\plugins\sqldrivers

Ahora podrás compilar el proyecto y ejecutarlo sin errores.

### No se encuentra la librería -libmysqld
Cambiar el modo de compilación de "Debug" a "Release" en los kits disponibles
