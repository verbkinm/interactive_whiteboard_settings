#ifndef MINI_WIDGET_H
#define MINI_WIDGET_H

#include "widget_types/schedule.h"
#include "widget_types/myWidgets/viewer/viewer.h"
#include "widget_types/clock.h"
#include "widget_types/date.h"
#include "widget_types/run_string.h"
#include "widgetforminiwidget.h"
#include "../widget_types/settings_window.h"


#include "content/content.h"
#include "structes/structes.h"

#include <QWidget>
#include <QLabel>
#include <QSize>
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


// создание кнопки настроек
    void createSettingsButton();

    WidgetForMiniWidget *centralWidgetForMiniWidget = nullptr;

//    enum TYPE_WIDGETS{LABEL, CLOCK, DATE, RUN_STRING, SCHEDULE, IMAGE_VIEWER, DONT_CLICK};
//рамка
    QLabel*                 border          = nullptr;
//рамка, которая будет появлятся при нажатии
    QLabel*                 borderClick     = nullptr;
// кнопка настроек
    QPushButton*            buttonSettings  = nullptr;
// структура настроек для мини виджета
    settingsMiniWidget *pStruct_settingsMiniWidget = nullptr;


// указатель для анимаций
//    QPropertyAnimation* panimOpen           = nullptr;

//центральная миниатюра
    QLabel*                 centralLabel    = nullptr;
//указатель на содержимое мини виджета, всё что открывается - находится в контейнере класса Content
//    Content*                pContent        = nullptr;

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
// просто создание мини виджета с миниатюрой
    void    createLabelForMiniWidget();

signals:
//сохранить настройки
    void signalSaveSettings(settingsMiniWidget &settingsWindow);

private slots:
// удаление объекта из памяти при закрытии окна
    void slotDeleteWidgetInContent();

    void slotWidgetPressed();
    void slotWidgetReleased();
    void slotWidgetClicked();

    void slotSettingsButtonClicked();

    //реагирование на изменение в окне настроек
    void slotSettingsChange(int objectName, QVariant data);
};

#endif // MINI_WIDGET_H
