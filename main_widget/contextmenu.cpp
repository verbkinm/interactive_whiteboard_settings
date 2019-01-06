#include "contextmenu.h"
#include <QApplication>

#include <QDebug>

ContextMenu::ContextMenu(QWidget *parent) : QMenu(parent)
{
    createActions();

    this->addAction(newWidget);
    this->addAction(listWidgets);
    this->addAction(mainWidgetSettig);
    this->addSeparator();
    this->addAction(exit);
}
void ContextMenu::createActions()
{
    newWidget = new QAction(QIcon(":/img/plus"), "Добавить новый виджет");
    connect(newWidget, SIGNAL(triggered()), this, SIGNAL(signalNewWidget()));

    exit = new QAction(QIcon(":/img/exit"), "Выход");
    connect(exit, SIGNAL(triggered()), qApp, SLOT(quit()));

    listWidgets = new QAction(QIcon(":/img/list"), "Список виджетов");
    //    connect(exit, SIGNAL(triggered()), qApp, SLOT(quit()));

    mainWidgetSettig = new QAction(QIcon(":img/img/settings_button.png"), "Настройки");
    connect(mainWidgetSettig, SIGNAL(triggered()), this, SIGNAL(signalGeneralSettings()));
}

bool ContextMenu::event(QEvent *event)
{
//    qDebug() << event->type();

    return QWidget::event(event);
}
ContextMenu::~ContextMenu()
{
    delete newWidget;
    delete exit;
    delete listWidgets;
}
