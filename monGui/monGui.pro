TEMPLATE = app
TARGET = monGui
QT += core \
    gui
HEADERS += desinscription.h \
    candidatinterface.h \
    electeurinterface.h \
    mongui.h
SOURCES += desinscription.cpp \
    candidatinterface.cpp \
    electeurinterface.cpp \
    main.cpp \
    mongui.cpp
FORMS += desinscription.ui \
    candidatinterface.ui \
    electeurinterface.ui \
    mongui.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
