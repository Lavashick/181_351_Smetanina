#-------------------------------------------------
#
# Project created by QtCreator 2019-05-31T18:48:48
#
#-------------------------------------------------

QT       += core gui
QT       += core network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    client.cpp \
    dbservice.cpp \
    user.cpp \
    qbytearrayparcer.cpp \
    dialog.cpp \
    dialogadmin.cpp \
    hash.cpp \
    city.cpp \
    human.cpp \
    pansionat.cpp

HEADERS += \
    client.h \
    dbservice.h \
    user.h \
    qbytearrayparcer.h \
    dialog.h \
    dialogadmin.h \
    hash.h \
    city.h \
    human.h \
    pansionat.h

FORMS += \
    dialog.ui \
    dialogadmin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../openssl/lib/ -lcrypto
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../openssl/lib/ -lcryptod
else:unix: LIBS += -L$$PWD/../openssl/lib/ -lcrypto

INCLUDEPATH += $$PWD/../openssl/include
DEPENDPATH += $$PWD/../openssl/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../openssl/lib/libcrypto.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../openssl/lib/libcryptod.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../openssl/lib/crypto.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../openssl/lib/cryptod.lib
else:unix: PRE_TARGETDEPS += $$PWD/../openssl/lib/libcrypto.a


unix|win32: LIBS += -L$$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/ -lCipher

INCLUDEPATH += $$PWD/../Cipher
DEPENDPATH += $$PWD/../Cipher

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/Cipher.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/libCipher.a
