QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    myapp.cpp \
    myapp_horizontal.cpp \
    popup_thu.cpp \
    popupchi.cpp

HEADERS += \
    IncludeLibrary.h \
    myapp.h \
    myapp_horizontal.h \
    popup_thu.h \
    popupchi.h

FORMS += \
    horizontal.ui \
    myapp.ui \
    myapp_horizontal.ui \
    popup_thu.ui \
    popupchi.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ResourceFile.qrc
