# Registro-de-Pacientes
El programa se conecta a una base de datos remota donde guarda la información de los pacientes, además crea una de manera local en caso de que no se tenga acceso a internet.
## Software necesario para compilar
1.- MySQL: https://dev.mysql.com/downloads/installer/ 
Recomiendo descargar el instalador web y cuando pregunte qué elementos instalar, sólo elegir MySQL Server y el Connector C++
2.- El IDE Qt Creator: https://www.qt.io/download-qt-installer?hsCtaTracking=99d9dd4f-5681-48d2-b096-470725510d34%7C074ddad0-fdef-4e53-8aa8-5e8a876d6ab4
Cuando pregunte qué elementos instalar es muy importante seleccionar:
	-En el apartado Qt 5.15.0 seleccione MingGW 8.1.0 64-bits (Aunque ya tenga el compilador instalado) y Sources
	-En el apartado Developer and Designer Tools seleccione Qy Creator 4.12.2 CDB Debugger Support y Debugging Tools for Windows.

## ¿Cómo compilarlo?
Al descargar el proyecto abrirlo con el Qt Creator y construirlo, luego se tiene que copiar el archivo libmysql.dll en la carpeta donde se construyó
