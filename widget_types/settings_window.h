#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QColorDialog>

#include "../structes/structes.h"

namespace Ui {
class Settings_window;
}

class Settings_window : public QDialog
{
    Q_OBJECT

public:
    Settings_window(settingsMiniWidget &struct_settingsMiniWidget, QWidget *parent = 0);
    ~Settings_window();

private:
    Ui::Settings_window *ui;

    settingsMiniWidget *pSettingsMiniWidget;

    void setValues();
    QColor toColor(QString str);
    void selectType();

private slots:
    void    slotBorderColor();
    void on_actionBorderColor_triggered();
    void on_actionPath_triggered();
};

#endif // SETTINGS_WINDOW_H
