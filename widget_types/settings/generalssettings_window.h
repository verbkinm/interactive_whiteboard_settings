#ifndef GENERALSSETTINGS_WINDOW_H
#define GENERALSSETTINGS_WINDOW_H

#include <QDialog>
#include <QWidget>
#include <QVariant>


namespace Ui {
class GeneralsSettings_window;
}

class GeneralsSettings_window : public QDialog
{
    Q_OBJECT

public:
    explicit GeneralsSettings_window(QString background, uint timerSec, \
                                     QWidget *parent = nullptr);
    ~GeneralsSettings_window();

    QString     getBackgroundPath();
    uint        getTimerSec();

private:
    Ui::GeneralsSettings_window *ui;

    QString     background;
    uint        timerSec;

    //установка значений из настроек
    void        setValues();

private slots:
    void        slotPathSet();

signals:
    void        signalBackgroundChancged(QString background);
};

#endif // GENERALSSETTINGS_WINDOW_H
