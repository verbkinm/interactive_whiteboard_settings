#include "main_widget.h"

#include <QFile>
#include <QPainter>

#include <QDebug>
#include <QEvent>
#include <QTextCodec>


Main_Widget::Main_Widget()
    : QWidget(),   generals_settings(QSettings::IniFormat, QSettings::UserScope, "LYCEUM","interactive_whiteboard_generals"), \
                   widget_settings(QSettings::IniFormat, QSettings::UserScope, "LYCEUM","interactive_whiteboard_widgets")

{
    addMyWidgets();

    watcher.addPath(widget_settings.fileName());
    connect(&watcher, SIGNAL(fileChanged(QString)), this, SLOT(slotFileChange()));
}
void Main_Widget::slotFileChange()
{
    watcher.addPath(widget_settings.fileName());
    widget_settings.sync();

    foreach (QString str, getMiniWidgetRemoveList(getMiniWidgetStringList(list_miniWidgets), widget_settings.childGroups()))
        if( getMiniWidgetIndex(str) != -1)
        {
            Mini_Widget* miniWidget = list_miniWidgets.at(getMiniWidgetIndex(str));
            miniWidget->~Mini_Widget();
            list_miniWidgets.removeAt(getMiniWidgetIndex(str));
        }

    addMyWidgets();
}
int Main_Widget::getMiniWidgetIndex(QString objectName)
{
    int position = -1;

    for (int i = 0; i < list_miniWidgets.count(); ++i) {
        if(list_miniWidgets.at(i)->objectName() == objectName)
            position = i;
    }

    return position;
}
Mini_Widget* Main_Widget::getMiniWidgetPointer(QString objectName)
{
    foreach (Mini_Widget* pmini, list_miniWidgets)
        if( pmini->objectName() == objectName)
            return pmini;

    return nullptr;
}
QStringList Main_Widget::getMiniWidgetRemoveList(QStringList objectNameList, QStringList settingsList)
{
    QStringList toRemove;

    for (int i = 0; i < objectNameList.count(); ++i)
        if( !(settingsList.contains(objectNameList.at(i))) )
            toRemove << objectNameList.at(i);

    return toRemove;
}
QStringList Main_Widget::getMiniWidgetAddList(QStringList objectNameList, QStringList settingsList)
{
    QStringList toAdd;

    for (int i = 0; i < settingsList.count(); ++i)
        if( !(objectNameList.contains(settingsList.at(i))) )
            toAdd<< settingsList.at(i);

    return toAdd;
}
QStringList Main_Widget::getMiniWidgetStringList(QList<Mini_Widget *>)
{
    QStringList listObjectNames;
    foreach (Mini_Widget* miniwidget, list_miniWidgets)
        listObjectNames << miniwidget->objectName();

    return listObjectNames;
}
void Main_Widget::addMyWidgets()
{
//    generals_settings.setIniCodec("utf8");
//    widget_settings.setIniCodec("utf8");

    QStringList groups = widget_settings.childGroups();

    foreach (QString objectName, groups) {
        widget_settings.beginGroup(objectName);

// структура рамки для мини виджета
        struct_settingsMiniWidget = new settingsMiniWidget;
//        border struct_border;
//        text struct_text;
//        path struct_path;
//        background struct_background;
//        miscellanea struct_miscellanea;

//rectangle для мини виджета

        struct_settingsMiniWidget->rect.setX(widget_settings.value("x", 10).toInt());
        struct_settingsMiniWidget->rect.setY(widget_settings.value("y", 10).toInt());
        struct_settingsMiniWidget->rect.setWidth(widget_settings.value("width", 50).toInt());
        struct_settingsMiniWidget->rect.setHeight(widget_settings.value("height", 50).toInt());

        struct_settingsMiniWidget->border.borderWidth           = widget_settings.value("borderWidth", 10).toInt();
        struct_settingsMiniWidget->border.borderColor           = widget_settings.value("borderRGBA", "balck").toString();
        struct_settingsMiniWidget->border.borderClickWidth      = widget_settings.value("borderClickWidth", 10).toInt();
        struct_settingsMiniWidget->border.borderClickColor      = widget_settings.value("borderClickRGBA", "black").toString();

        struct_settingsMiniWidget->miscellanea.type             = widget_settings.value("type", "label").toString();
        struct_settingsMiniWidget->miscellanea.timerSec         = generals_settings.value("Generals/timerSec", 30).toInt();
        struct_settingsMiniWidget->miscellanea.dynamicMiniWidget= widget_settings.value("dynamicMiniWidget", false).toBool();
        struct_settingsMiniWidget->miscellanea.dynamicMiniWidgetTimer= widget_settings.value("dynamicMiniWidgetTimer", 0).toInt();
        struct_settingsMiniWidget->miscellanea.datePattern      = widget_settings.value("datePattern", "dd-mm-yy").toString();
        struct_settingsMiniWidget->miscellanea.speed            = widget_settings.value("speed", "-1").toInt();

        struct_settingsMiniWidget->background.backgroundColor   = widget_settings.value("backgroundColor", "black").toString();
        struct_settingsMiniWidget->background.backgroundImage   = generals_settings.value("Generals/backgoundImage", ":img/school2").toString();

        struct_settingsMiniWidget->text.textColor               = widget_settings.value("textColor", "green").toString();
        struct_settingsMiniWidget->text.textSize                = widget_settings.value("textSize", 12).toInt();
        struct_settingsMiniWidget->text.titleText               = widget_settings.value("title", "\0").toString();

        struct_settingsMiniWidget->path.dirPath                 = widget_settings.value("dirPath", "\0").toString();
        struct_settingsMiniWidget->path.xmlPath                 = widget_settings.value("xmlPath", "\0").toString();
        struct_settingsMiniWidget->path.iconPath                = widget_settings.value("iconPath", ":img/logo").toString();
        struct_settingsMiniWidget->path.txtPath                 = widget_settings.value("txtPath", "").toString();

        struct_settingsMiniWidget->widgetName                   = objectName;

        widget_settings.endGroup();

//        qDebug() << str << struct_miscellanea.dynamicMiniWidget;

        struct_settingsMiniWidget->size = QSize(struct_settingsMiniWidget->rect.width(), struct_settingsMiniWidget->rect.height());
        addMyWidget(struct_settingsMiniWidget, \
                    objectName);

        delete struct_settingsMiniWidget;
    }
}
void Main_Widget::addMyWidget(settingsMiniWidget *struct_settingsMiniWidget, \
                              QString objectName)
{
    if( !(list_miniWidgets.contains(getMiniWidgetPointer(objectName))) ){
        pmini = new  Mini_Widget(struct_settingsMiniWidget, this);

        pmini->setObjectName(objectName);

        pmini->move(struct_settingsMiniWidget->rect.x(), struct_settingsMiniWidget->rect.y());
        pmini->show();
        list_miniWidgets.append(pmini);

        connect(pmini, SIGNAL(signalSaveSettings(settingsMiniWidget&)), this, SLOT(slotSaveSettings(settingsMiniWidget&)));
    }
    else
    {
        pmini = list_miniWidgets.at(getMiniWidgetIndex(objectName));
        pmini->create_or_recreate_object(struct_settingsMiniWidget);
        pmini->move(struct_settingsMiniWidget->rect.x(), struct_settingsMiniWidget->rect.y());
    }

//    qDebug() << objectName << struct_settingsMiniWidget->miscellanea.type;

}
void Main_Widget::slotSaveSettings(settingsMiniWidget &settingsWindow)
{
    if(sender()->objectName() != settingsWindow.widgetName)
    {
        widget_settings.remove(sender()->objectName());
    }

    widget_settings.beginGroup(settingsWindow.widgetName);

    widget_settings.setValue("x", settingsWindow.rect.x());
    widget_settings.setValue("y", settingsWindow.rect.y());
    widget_settings.setValue("width", settingsWindow.size.width());
    widget_settings.setValue("height", settingsWindow.size.height());

    widget_settings.setValue("borderWidth", settingsWindow.border.borderWidth);
    widget_settings.setValue("borderRGBA", settingsWindow.border.borderColor);
    widget_settings.setValue("borderClickWidth", settingsWindow.border.borderClickWidth);
    widget_settings.setValue("borderClickRGBA", settingsWindow.border.borderClickColor);

    widget_settings.setValue("type", settingsWindow.miscellanea.type);

    widget_settings.setValue("dynamicMiniWidget", settingsWindow.miscellanea.dynamicMiniWidget);
    widget_settings.setValue("dynamicMiniWidgetTimer", settingsWindow.miscellanea.dynamicMiniWidgetTimer);
    widget_settings.setValue("datePattern", settingsWindow.miscellanea.datePattern);
    widget_settings.setValue("speed", settingsWindow.miscellanea.speed);

//    widget_settings.setValue("backgroundColor", settingsWindow.miscellanea.datePattern);

//    widget_settings.setValue("textColor", settingsWindow.text.);
    widget_settings.setValue("textSize", settingsWindow.text.textSize);
    widget_settings.setValue("title", settingsWindow.text.titleText);

    widget_settings.setValue("dirPath", settingsWindow.path.dirPath);
    widget_settings.setValue("xmlPath", settingsWindow.path.xmlPath);
    widget_settings.setValue("iconPath", settingsWindow.path.iconPath);
    widget_settings.setValue("txtPath", settingsWindow.path.txtPath);

//    widget_settings.setValue("widgetName", settingsWindow.widgetName);

    widget_settings.endGroup();

}
void Main_Widget::slotCreateNewWidget()
{
    qDebug() << "slotNewWidget";
    struct_settingsMiniWidget = new settingsMiniWidget;

    addMyWidget(struct_settingsMiniWidget, struct_settingsMiniWidget->widgetName);

    delete struct_settingsMiniWidget;
}
void Main_Widget::showContextMenu()
{
    if(pMenu == nullptr)
    {
        pMenu = new ContextMenu(this);
        connect(pMenu, SIGNAL(signalNewWidget()), this, SLOT(slotCreateNewWidget()));

        if( pMenu->exec(QCursor::pos()) )
            deleteContextMenu();
    }
    else
        deleteContextMenu();

}
void Main_Widget::deleteContextMenu()
{
//    disconnect(pMenu, SIGNAL(signalNewWidget()), this, SLOT(slotCreateNewWidget));
    pMenu->close();
    delete pMenu;
    pMenu = nullptr;
}
bool Main_Widget::event(QEvent *event)
{
//    qDebug() << event->type();
    if(event->type() == QEvent::MouseButtonRelease)
    {
        foreach (Mini_Widget* pmini, list_miniWidgets)
        {
            if( !(pmini->geometry().contains(this->mapFromGlobal(QCursor::pos()))) )
            {
                pmini->hideSettingsButton();
                showContextMenu();
            }
        }
        if(list_miniWidgets.length() == 0)
            showContextMenu();

    }

    return QWidget::event(event);
}
void Main_Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    QPixmap pixMap(generals_settings.value("Generals/backgoundImage", ":img/school2").toString());
    QPixmap newPix = pixMap.scaled(this->size(), Qt::IgnoreAspectRatio);
    painter.setBrush(QBrush(Qt::black, newPix));
    painter.drawRect(this->rect());
}
Main_Widget::~Main_Widget()
{
    if(pmini != nullptr)
        delete pmini;
//    if(struct_settingsMiniWidget != nullptr)
//        delete struct_settingsMiniWidget;
}
