#ifndef SETTINGS_WINDOW_H
#define SETTINGS_WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QColorDialog>

namespace Ui {
class Settings_window;
}

class Settings_window : public QDialog
{
    Q_OBJECT

public:
    Settings_window(QWidget *parent = 0);
    ~Settings_window();

private:
    Ui::Settings_window *ui;

private slots:
    void    slotBorderColor();
    void on_actionBorderColor_triggered();
    void on_actionPath_triggered();
};

#endif // SETTINGS_WINDOW_H
