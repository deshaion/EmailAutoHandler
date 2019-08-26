QT -= gui
QT += sql network

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp \
    src/simpleQtLogger.cpp \
    smtp_client/emailaddress.cpp \
    smtp_client/mimeattachment.cpp \
    smtp_client/mimecontentformatter.cpp \
    smtp_client/mimefile.cpp \
    smtp_client/mimehtml.cpp \
    smtp_client/mimeinlinefile.cpp \
    smtp_client/mimemessage.cpp \
    smtp_client/mimemultipart.cpp \
    smtp_client/mimepart.cpp \
    smtp_client/mimetext.cpp \
    smtp_client/quotedprintable.cpp \
    smtp_client/smtpclient.cpp \
    src/emailmanager.cpp

HEADERS += \
    src/simpleQtLogger.h \
    src/initdb.h \
    smtp_client/emailaddress.h \
    smtp_client/mimeattachment.h \
    smtp_client/mimecontentformatter.h \
    smtp_client/mimefile.h \
    smtp_client/mimehtml.h \
    smtp_client/mimeinlinefile.h \
    smtp_client/mimemessage.h \
    smtp_client/mimemultipart.h \
    smtp_client/mimepart.h \
    smtp_client/mimetext.h \
    smtp_client/quotedprintable.h \
    smtp_client/smtpclient.h \
    smtp_client/smtpexports.h \
    smtp_client/SmtpMime \
    src/emailsdao.h \
    src/email.h \
    src/emailmanager.h \
    src/secdata.h \
    src/utils.h
