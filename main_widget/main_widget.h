#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QEvent>


#include "contextmenu.h"
#include "mini_widget/mini_widget.h"
#include "structes/structes.h"
#include "circleclick/circleclick.h"

class Main_Widget : public QWidget
{
    Q_OBJECT

public:
    Main_Widget();
    ~Main_Widget();

private:


//файл конфигураций для виджетов, добавляемых на доску
    QSettings                           generals_settings, widget_settings;

//здесь будут храниться указатели на все виджеты на доске
    QList<Mini_Widget*>                 list_miniWidgets;

//указатель на мини виджет
    Mini_Widget *pmini  = nullptr;
//указатель на структуру настроек
    settingsMiniWidget*                 struct_settingsMiniWidget   = nullptr;

//Отслеживание изменений в настройках
    QFileSystemWatcher                  watcher;

//контекстное меню, при нажатии на пустом месте главного окна
    ContextMenu*                        pMenu                       = nullptr;

//отрисовка круга в месте нажатия и удержания ЛКМ
    CircleClick                         circleClike;

//FUNCTIONS
    void            generalSettings     ();

    void            addMyWidgets        ();
    void            addMyWidget         (settingsMiniWidget *struct_settingsMiniWidget, \
                                         QString objectName);
    void            settingSetValues    (settingsMiniWidget *struct_settingsMiniWidget);

    int             getMiniWidgetIndex  (QString objectName);
    Mini_Widget*    getMiniWidgetPointer(QString objectName);
    QStringList     getMiniWidgetStringList(QList<Mini_Widget*>);
    QStringList     getMiniWidgetRemoveList(QStringList objectNameList, QStringList settingsList);
    QStringList     getMiniWidgetAddList(QStringList objectNameList, QStringList settingsList);

//возвращает true, если курсор находиться над любым виджетом
    bool            cursorOnMiniWidget  ();

protected:
    virtual bool    event               (QEvent *event);

//SLOTS
private slots:
//изменение содержимого файла настроек
    void            slotFileChange();
//сохранить в файл настроек
    void            slotSaveSettings(settingsMiniWidget &settingsWindow);
//удалить виджет
    void            slotDeleteWidget();
//создать виджет
    void            slotCreateNewWidget();

//показать контекстное меню на главном окне, при удержании ЛКМ
    void            slotShowContextMenu     ();

    void            slotGeneralSettings     ();
    void            slotBackgroundChanged   (QString background);


};

#endif // MAIN_WIDGET_H
