#include "contextmenu.h"
#include <QApplication>

ContextMenu::ContextMenu(QWidget *parent) : QMenu(parent)
{
    createActions();

    this->addAction(newWidget);
    this->addAction(listWidgets);
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
}
ContextMenu::~ContextMenu()
{
    delete newWidget;
    delete exit;
    delete listWidgets;
}
