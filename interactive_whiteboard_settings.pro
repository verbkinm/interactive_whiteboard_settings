#-------------------------------------------------
#
# Project created by QtCreator 2018-06-21T16:23:04
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interactive_whiteboard_settings
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


RESOURCES += \
    img.qrc

FORMS += \
    widget_types/leafer.ui \
    widget_types/settings/settings_window.ui \
    widget_types/settings/setcolorrgba.ui \
    widget_types/settings/settext.ui \
    widget_types/settings/generalssettings_window.ui

HEADERS += \
    main_widget/main_widget.h \
    mini_widget/mini_widget.h \
    widget_types/clock.h \
    structes/structes.h \
    mini_widget/widgetforminiwidget.h \
    widget_types/leafer.h \
    widget_types/date.h \
    widget_types/run_string.h \
    widget_types/settings/settings_window.h \
    main_widget/contextmenu.h \
    widget_types/settings/setcolorrgba.h \
    widget_types/settings/settext.h \
    main_widget/circleclick/circleclick.h \
    widget_types/settings/generalssettings_window.h

SOURCES += \
    main_widget/main_widget.cpp \
    mini_widget/mini_widget.cpp \
    widget_types/clock.cpp \
    main.cpp \
    mini_widget/widgetforminiwidget.cpp \
    widget_types/leafer.cpp \
    widget_types/date.cpp \
    widget_types/run_string.cpp \
    widget_types/settings/settings_window.cpp \
    structes/structes.cpp \
    main_widget/contextmenu.cpp \
    widget_types/settings/setcolorrgba.cpp \
    widget_types/settings/settext.cpp \
    main_widget/circleclick/circleclick.cpp \
    widget_types/settings/generalssettings_window.cpp

