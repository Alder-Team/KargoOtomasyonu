QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UI/ListeFormlari/krgkargolistesi.cpp \
    UI/ListeFormlari/krgsubelistesi.cpp \
    UI/VeriFormlari/krgsubebilgileriekle.cpp \
    UI/VeriFormlari/krgyenikargoekle.cpp \
    Veri/VeriListesi/krgalicibilgileri.cpp \
    Veri/VeriListesi/krggondericibilgileri.cpp \
    Veri/VeriListesi/krgkargobilgileri.cpp \
    Veri/VeriListesi/krgsubebilgileri.cpp \
    Veri/VeriYonetisi/krgalicibilgileriyoneticisi.cpp \
    Veri/VeriYonetisi/krggondericibilgileriyoneticisi.cpp \
    Veri/VeriYonetisi/krgkargobilgileriyoneticisi.cpp \
    Veri/VeriYonetisi/krgsubebilgileriyoneticisi.cpp \
    Veri/krggenelveriyoneticisi.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    UI/ListeFormlari/krgkargolistesi.h \
    UI/ListeFormlari/krgsubelistesi.h \
    UI/VeriFormlari/krgsubebilgileriekle.h \
    UI/VeriFormlari/krgyenikargoekle.h \
    Veri/VeriListesi/krgalicibilgileri.h \
    Veri/VeriListesi/krggondericibilgileri.h \
    Veri/VeriListesi/krgkargobilgileri.h \
    Veri/VeriListesi/krgsubebilgileri.h \
    Veri/VeriYonetisi/krgalicibilgileriyoneticisi.h \
    Veri/VeriYonetisi/krggondericibilgileriyoneticisi.h \
    Veri/VeriYonetisi/krgkargobilgileriyoneticisi.h \
    Veri/VeriYonetisi/krgsubebilgileriyoneticisi.h \
    Veri/VeriYonetisi/temel_veri_yoneticisi.h \
    Veri/krggenelveriyoneticisi.h \
    Veri/tanimlar.h \
    mainwindow.h

FORMS += \
    UI/ListeFormlari/krgkargolistesi.ui \
    UI/ListeFormlari/krgsubelistesi.ui \
    UI/VeriFormlari/krgsubebilgileriekle.ui \
    UI/VeriFormlari/krgyenikargoekle.ui \
    mainwindow.ui

TRANSLATIONS += \
    IST2004KargoOtomasyonu_tr_TR.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
