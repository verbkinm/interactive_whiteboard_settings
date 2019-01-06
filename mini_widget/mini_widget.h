#ifndef MINI_WIDGET_H
#define MINI_WIDGET_H

#include "widget_types/clock.h"
#include "widget_types/date.h"
#include "widget_types/run_string.h"
#include "widgetforminiwidget.h"
#include "../widget_types/settings/settings_window.h"

#include "structes/structes.h"

#include <QWidget>
#include <QLabel>
#include <QSize>
#include <QPaintEvent>
//#include <QPropertyAnimation>


class Mini_Widget : public QWidget
{
    Q_OBJECT
public:

    Mini_Widget(struct settingsMiniWidget *struct_settingsMiniWidget, \
                QWidget *parent);

    ~Mini_Widget();

    void create_or_recreate_object(settingsMiniWidget *struct_settingsMiniWidget);

    void hideSettingsButton();
private:
// функции для создания виджетов по их типу
    void createLabelWidget();
    void createClockWidget();
    void createDateWidget();
    void createRunStringWidget();
    void createScheduleWidget();
    void createImageViewerWidget();
    void createDontClickWidget();
    void createBellsMonitor();


// создание кнопки настроек и кнопки удаления
    void createSettingsButton();

    QString txtFileToString(QString filePath);

    WidgetForMiniWidget *centralWidgetForMiniWidget = nullptr;

//рамка
    QWidget                border;
//рамка, которая будет появлятся при нажатии
    Mini_Widget*            borderClick     = this;

// панель дополнительных действий при нажатии на виджет
    QWidget                 onClickWidget;
    QPushButton             buttonSettings, buttonDeleteWidget;
    QGridLayout             onClickWidgetLayout;

// структура настроек для мини виджета
    settingsMiniWidget mainStruct_settingsMiniWidget;

    QVBoxLayout            borderClickLayout;
    QVBoxLayout            borderLayout;

//нужно для перевода типа виджета из QString в enum TYPE_WIDGETS
    int                     type            = -1;

//указатели на типы содержиого мини виджета
    Clock*                  pClock          = nullptr;
    Date*                   pDate           = nullptr;
    Run_String*             pRun_String     = nullptr;
//    Schedule                *pSchedule      = nullptr;
//    viewer                  *pImageViewer   = nullptr;

//FUNCTIONS

    virtual bool event              (QEvent *event);

// для установления общих параметров для всех виджетов
    void    generalSettings         ();

protected:
    void paintEvent(QPaintEvent *);

signals:
//сохранить настройки
    void signalSaveSettings(settingsMiniWidget &settingsWindow);
    void signalDeleteWidget();

private slots:


    void slotSettingsButtonClicked();
    void slotDeleteButtonClicked();

    //реагирование на изменение в окне настроек
    void slotSettingsChange(int objectName, QVariant data);
};

#endif // MINI_WIDGET_H
