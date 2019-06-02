QT += core network
QT -= gui
QT += sql

CONFIG += c++11 console
CONFIG -= app_bundle

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
        main.cpp \
    myserver.cpp \
    dbservice.cpp \
    console.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    myserver.h \
    dbservice.h \
    console.h

unix|win32: LIBS += -L$$PWD/../OpenSSL/lib/ -lcrypto

INCLUDEPATH += $$PWD/../OpenSSL/include
DEPENDPATH += $$PWD/../OpenSSL/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../OpenSSL/lib/crypto.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../OpenSSL/lib/libcrypto.a

unix|win32: LIBS += -L$$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/ -lCipher

INCLUDEPATH += $$PWD/../Cipher
DEPENDPATH += $$PWD/../Cipher

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/Cipher.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../build-Cipher-Desktop_Qt_5_12_3_clang_64bit-Debug/libCipher.a
