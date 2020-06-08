QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/main.cpp \
    Sources/mainmenu.cpp \
    Sources/registrar.cpp \
    Sources/ver_pacientes.cpp \
    Sources/acerca_de.cpp \
    Sources/ver_pacientes_offline.cpp \
    Sources/offregistro.cpp \
    Sources/offver_database.cpp \
    Sources/databasemysql.cpp \
    Sources/databasesqlite.cpp

HEADERS += \
    Headers/mainmenu.h \
    Headers/registrar.h \
    Headers/ver_pacientes.h \
    Headers/acerca_de.h \
    Headers/ver_pacientes_offline.h \
    Headers/offregistro.h \
    Headers/offver_database.h \
    Headers/databasemysql.h \
    Headers/databasesqlite.h

FORMS += \
    acerca_de.ui \
    mainmenu.ui \
    offregistro.ui \
    offver_database.ui \
    registrar.ui \
    ver_pacientes.ui \
    ver_pacientes_offline.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/-llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/-llibmysqld
else:unix: LIBS += -L$$PWD/-llibmysql

INCLUDEPATH += $$PWD/Headers
DEPENDPATH += $$PWD/Headers

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibmysqld
else:unix: LIBS += -L$$PWD/./ -llibmysql

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
