#include "main_widget.h"
#include "../widget_types/settings/generalssettings_window.h"

#include <QFile>
#include <QPainter>
#include <QDebug>
#include <QApplication>


Main_Widget::Main_Widget()
    : QWidget(),   generals_settings(QSettings::IniFormat, QSettings::UserScope, "INTERACTIVE_WHITEBOARD","interactive_whiteboard_generals"), \
                   widget_settings(QSettings::IniFormat, QSettings::UserScope, "INTERACTIVE_WHITEBOARD","interactive_whiteboard_widgets")

{
    generalSettings();
    addMyWidgets();
}
void Main_Widget::slotFileChange()
{
    watcher.addPath(widget_settings.fileName());
    watcher.addPath(generals_settings.fileName());
    widget_settings.sync();
    generals_settings.sync();

    foreach (QString str, getMiniWidgetRemoveList(getMiniWidgetStringList(list_miniWidgets), widget_settings.childGroups()))
        if( getMiniWidgetIndex(str) != -1)
        {
            Mini_Widget* miniWidget = list_miniWidgets.at(getMiniWidgetIndex(str));
            list_miniWidgets.removeAt(getMiniWidgetIndex(str));
            delete miniWidget;
        }

//    pmini = nullptr;
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

bool Main_Widget::cursorOnMiniWidget()
{
    foreach (Mini_Widget* pmini, list_miniWidgets)
        if( pmini->geometry().contains(this->mapFromGlobal(QCursor::pos())) )
            return true;

    return false;
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
    QStringList groups = widget_settings.childGroups();

    foreach (QString objectName, groups) {
        widget_settings.beginGroup(objectName);

// структура настроек для мини виджета
        struct_settingsMiniWidget = new settingsMiniWidget;

        struct_settingsMiniWidget->rect.setX(widget_settings.value("x", 10).toInt());
        struct_settingsMiniWidget->rect.setY(widget_settings.value("y", 10).toInt());
        struct_settingsMiniWidget->rect.setWidth(widget_settings.value("width", 100).toInt());
        struct_settingsMiniWidget->rect.setHeight(widget_settings.value("height", 100).toInt());

        struct_settingsMiniWidget->border.borderWidth           = widget_settings.value("borderWidth", 10).toInt();
        struct_settingsMiniWidget->border.borderColor           = widget_settings.value("borderRGBA", "#ffffffff").toString();
        struct_settingsMiniWidget->border.borderClickWidth      = widget_settings.value("borderClickWidth", 10).toInt();
        struct_settingsMiniWidget->border.borderClickColor      = widget_settings.value("borderClickRGBA", "#ff000000").toString();

        struct_settingsMiniWidget->miscellanea.type             = widget_settings.value("type", "label").toString();
        struct_settingsMiniWidget->miscellanea.timerSec         = generals_settings.value("Generals/timerSec", 30).toInt();
        struct_settingsMiniWidget->miscellanea.dynamicMiniWidget= widget_settings.value("dynamicMiniWidget", false).toBool();
        struct_settingsMiniWidget->miscellanea.dynamicMiniWidgetTimer= widget_settings.value("dynamicMiniWidgetTimer", 1).toInt();
        struct_settingsMiniWidget->miscellanea.datePattern      = widget_settings.value("datePattern", "dd-MM-yy").toString();
        struct_settingsMiniWidget->miscellanea.speed            = widget_settings.value("speed", "-1").toInt();

        struct_settingsMiniWidget->background.backgroundColor   = widget_settings.value("backgroundColor", "#ff000000").toString();
        struct_settingsMiniWidget->background.backgroundImage   = generals_settings.value("Generals/backgoundImage", ":img/school2").toString();

        struct_settingsMiniWidget->text.textColor               = widget_settings.value("textColor", "#ff000000").toString();
        struct_settingsMiniWidget->text.textSize                = widget_settings.value("textSize", 12).toInt();
        struct_settingsMiniWidget->text.titleText               = widget_settings.value("title", "\0").toString();
        struct_settingsMiniWidget->text.titleTextSize           = widget_settings.value("titleSize", 12).toInt();
        struct_settingsMiniWidget->text.titleColor              = widget_settings.value("titleColor", "#ff000000").toString();

        struct_settingsMiniWidget->path.dirPath                 = widget_settings.value("dirPath", "\0").toString();
        struct_settingsMiniWidget->path.xmlPath                 = widget_settings.value("xmlPath", "\0").toString();
        struct_settingsMiniWidget->path.iconPath                = widget_settings.value("iconPath", ":img/school2").toString();
        struct_settingsMiniWidget->path.txtPath                 = widget_settings.value("txtPath", "").toString();

        struct_settingsMiniWidget->widgetName                   = objectName;

        widget_settings.endGroup();

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
        connect(pmini, SIGNAL(signalDeleteWidget()), this, SLOT(slotDeleteWidget()));
    }
    else
    {
        pmini = list_miniWidgets.at(getMiniWidgetIndex(objectName));
        pmini->create_or_recreate_object(struct_settingsMiniWidget);
        pmini->move(struct_settingsMiniWidget->rect.x(), struct_settingsMiniWidget->rect.y());
    }

    pmini = nullptr;
}

void Main_Widget::settingSetValues(settingsMiniWidget *struct_settingsMiniWidget)
{
    widget_settings.beginGroup(struct_settingsMiniWidget->widgetName);

    widget_settings.setValue("x", struct_settingsMiniWidget->rect.x());
    widget_settings.setValue("y", struct_settingsMiniWidget->rect.y());
    widget_settings.setValue("width", struct_settingsMiniWidget->size.width());
    widget_settings.setValue("height", struct_settingsMiniWidget->size.height());

    widget_settings.setValue("borderWidth", struct_settingsMiniWidget->border.borderWidth);
    widget_settings.setValue("borderRGBA", struct_settingsMiniWidget->border.borderColor);
    widget_settings.setValue("borderClickWidth", struct_settingsMiniWidget->border.borderClickWidth);
    widget_settings.setValue("borderClickRGBA", struct_settingsMiniWidget->border.borderClickColor);

    widget_settings.setValue("type", struct_settingsMiniWidget->miscellanea.type);

    widget_settings.setValue("dynamicMiniWidget", struct_settingsMiniWidget->miscellanea.dynamicMiniWidget);
    widget_settings.setValue("dynamicMiniWidgetTimer", struct_settingsMiniWidget->miscellanea.dynamicMiniWidgetTimer);
    widget_settings.setValue("datePattern", struct_settingsMiniWidget->miscellanea.datePattern);
    widget_settings.setValue("speed", struct_settingsMiniWidget->miscellanea.speed);

    widget_settings.setValue("textSize", struct_settingsMiniWidget->text.textSize);
    widget_settings.setValue("textColor", struct_settingsMiniWidget->text.textColor);

    widget_settings.setValue("title", struct_settingsMiniWidget->text.titleText);
    widget_settings.setValue("titleSize", struct_settingsMiniWidget->text.titleTextSize);
    widget_settings.setValue("titleColor", struct_settingsMiniWidget->text.titleColor);

    widget_settings.setValue("backgroundColor", struct_settingsMiniWidget->background.backgroundColor);

    widget_settings.setValue("dirPath", struct_settingsMiniWidget->path.dirPath);
    widget_settings.setValue("xmlPath", struct_settingsMiniWidget->path.xmlPath);
    widget_settings.setValue("iconPath", struct_settingsMiniWidget->path.iconPath);
    widget_settings.setValue("txtPath", struct_settingsMiniWidget->path.txtPath);

    widget_settings.endGroup();
}
void Main_Widget::slotSaveSettings(settingsMiniWidget &settingsWindow)
{
    if(sender()->objectName() != settingsWindow.widgetName)
        widget_settings.remove(sender()->objectName());

    settingSetValues(&settingsWindow);
}

void Main_Widget::slotDeleteWidget()
{
    widget_settings.remove(sender()->objectName());
}
void Main_Widget::slotCreateNewWidget()
{
    struct_settingsMiniWidget = new settingsMiniWidget;

    addMyWidget(struct_settingsMiniWidget, struct_settingsMiniWidget->widgetName);
    settingSetValues(struct_settingsMiniWidget);

    delete struct_settingsMiniWidget;
}
void Main_Widget::slotShowContextMenu()
{
    pMenu->exec(QCursor::pos());
    circleClike.close();
}

void Main_Widget::slotGeneralSettings()
{
    GeneralsSettings_window *pGeneralsSettings_window = new GeneralsSettings_window(generals_settings.value("Generals/backgoundImage", ":img/school2").toString(), \
                                                                                    uint(generals_settings.value("Generals/timerSec", 30).toInt()) );

    connect(pGeneralsSettings_window, SIGNAL(signalBackgroundChancged(QString)), this, SLOT(slotBackgroundChanged(QString)) );

    if (pGeneralsSettings_window->exec()  ==   QDialog::Accepted){
        generals_settings.setValue("Generals/timerSec", pGeneralsSettings_window->getTimerSec() );
        generals_settings.setValue("Generals/backgoundImage", pGeneralsSettings_window->getBackgroundPath() );
    }
    else
    {
        slotBackgroundChanged(generals_settings.value("Generals/backgoundImage", "").toString() );
    }

    delete pGeneralsSettings_window;
}

void Main_Widget::slotBackgroundChanged(QString background)
{
    QPixmap bkgnd(background);

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
bool Main_Widget::event(QEvent *event)
{
//    qDebug() << event->type();
    if(event->type() == QEvent::MouseButtonRelease){
        foreach (Mini_Widget* pmini, list_miniWidgets)
            if(pmini != nullptr)
                if( !(pmini->geometry().contains(this->mapFromGlobal(QCursor::pos()))) )
                    pmini->hideSettingsButton();
        circleClike.close();
    }

    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if( !cursorOnMiniWidget() ) {
            circleClike.move(mouseEvent->x() - circleClike.width()/2, mouseEvent->y() - circleClike.height()/2 );
            circleClike.show();
        }
    }

    if(event->type() == QEvent::Resize){
        slotBackgroundChanged(generals_settings.value("Generals/backgoundImage", ":img/school2").toString());
    }

    return QWidget::event(event);
}
Main_Widget::~Main_Widget()
{
    if(pmini != nullptr)
        delete pmini;

    if(pMenu != nullptr)
        delete pMenu;
}

void Main_Widget::generalSettings()
{
//создать файлы настроек, если они не существуют
    if( !(QFile::exists(widget_settings.fileName()))){
        QFile file(widget_settings.fileName());
        QDir dir;
        dir.mkdir(QFileInfo(file).path());
        file.open(QIODevice::Append);
        file.close();
    }
    if( !(QFile::exists(generals_settings.fileName()))){
        QFile file(generals_settings.fileName());
        QDir dir;
        dir.mkdir(QFileInfo(file).path());
        file.open(QIODevice::Append);
        file.close();
    }

    watcher.addPath(widget_settings.fileName());
    watcher.addPath(generals_settings.fileName());

    connect(&watcher, SIGNAL(fileChanged(QString)), this, SLOT(slotFileChange()) );

    pMenu = new ContextMenu(this);
    connect(pMenu, SIGNAL(signalNewWidget()), this, SLOT(slotCreateNewWidget()) );
    connect(pMenu, SIGNAL(signalGeneralSettings()), this, SLOT(slotGeneralSettings()) );

//при отрисовки полного круга - вызывается контекстное меню
    circleClike.setParent(this);
    circleClike.close();
    connect(&circleClike, SIGNAL(signalCircleEnd()), this, SLOT(slotShowContextMenu()) );

//    qApp->setOverrideCursor(Qt::BlankCursor);
//    this->showFullScreen();
}
