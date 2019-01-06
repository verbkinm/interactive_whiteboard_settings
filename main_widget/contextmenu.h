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

//    bool isClosed = true;

private:

    QAction *newWidget, *exit, *listWidgets, *mainWidgetSettig;

    void        createActions();

virtual bool    event               (QEvent *event);

signals:
    void        signalNewWidget();
    void        signalGeneralSettings();
};

#endif // CONTEXTMENU_H
