#ifndef CONTEXTMENU_H
#define CONTEXTMENU_H

#include <QMenu>
#include <QAction>

class ContextMenu : public QMenu
{
    Q_OBJECT
public:
    ContextMenu(QWidget* parent);
    ~ContextMenu();

private:

    QAction *newWidget, *exit, *listWidgets;

    void createActions();

signals:
    void signalNewWidget();
};

#endif // CONTEXTMENU_H
