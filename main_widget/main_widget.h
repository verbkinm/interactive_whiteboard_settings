#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QSettings>
#include <QFileSystemWatcher>

#include "contextmenu.h"
#include "mini_widget/mini_widget.h"
#include "structes/structes.h"

class Main_Widget : public QWidget
{
    Q_OBJECT

public:
    Main_Widget();
    ~Main_Widget();

private:

//файл конфигураций для виджетов, добавляемых на доску
    QSettings                       generals_settings, widget_settings;

//здесь будут храниться указатели на все виджеты на доске
    QList<Mini_Widget*>                 list_miniWidgets;

//указатель на мини виджет
    Mini_Widget *pmini  = nullptr;
//указатель на структуру настроек
    settingsMiniWidget *struct_settingsMiniWidget = nullptr;

//Отслеживание изменений в настройках
    QFileSystemWatcher watcher;

//контекстное меню, при нажатии на пустом месте главного окна
    ContextMenu*    pMenu    = nullptr;
//FUNCTIONS
    void            addMyWidgets        ();
    void            addMyWidget         (settingsMiniWidget *struct_settingsMiniWidget, \
                                         QString objectName);

    int             getMiniWidgetIndex  (QString objectName);
    Mini_Widget*    getMiniWidgetPointer(QString objectName);
    QStringList     getMiniWidgetStringList(QList<Mini_Widget*>);
    QStringList     getMiniWidgetRemoveList(QStringList objectNameList, QStringList settingsList);
    QStringList     getMiniWidgetAddList(QStringList objectNameList, QStringList settingsList);

    void            showContextMenu     ();
    void            deleteContextMenu   ();

    void            paintEvent          (QPaintEvent*);
    virtual bool    event               (QEvent *event);

//SLOTS
private slots:
    void            slotFileChange();
    void            slotSaveSettings(settingsMiniWidget &settingsWindow);

    void            slotCreateNewWidget();

};

#endif // MAIN_WIDGET_H
