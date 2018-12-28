#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QVariant>

#include "../structes/structes.h"

namespace Ui {
class Settings_window;
}

class Settings_window : public QDialog
{
    Q_OBJECT

public:
    Settings_window(const settingsMiniWidget &struct_settingsMiniWidget, QWidget *parent = nullptr);
    ~Settings_window();

//копия переданной структуры
    settingsMiniWidget settingsMiniWidgetCopy;

    enum{X, Y, WIDTH, HEIGHT, \
         BORDER_WIDTH, BORDER_COLOR, BORDERCLICK_WIDTH, BORDERCLICK_COLOR,\
         WIDGET_TYPE, WIDGET_NAME, \
         ICON_PATH, DIR_PATH, TXT_PATH, XML_PATH, \
         TEXT_SIZE, TITLE, \
         SPEED, \
         DYNAMICMINIWIDGET, DYNAMICMINIWIDGET_TIMER, \
         PATTERN
        };

private:
    Ui::Settings_window *ui;

    const       settingsMiniWidget *pSettingsMiniWidget;

    void        setValues();
    QColor      toColor(QString str);
    void        selectType();

    int         getType(QString typeStr);

private slots:
    void        on_actionBorderColor_triggered();
    void        on_actionPath_triggered();
    void        slotChange();

signals:
    void        signal_Change_Settings(int objectName, QVariant data);

};

#endif // SETTINGS_WINDOW_H
