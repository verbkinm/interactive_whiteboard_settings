#include "clock.h"

#include <QPainter>

#include <QDebug>

Clock::Clock(QString textColor, QString backgroundColor, QWidget *parent) : QLCDNumber(parent)
{
    create_or_recreate_object(textColor, backgroundColor);
}
void Clock::create_or_recreate_object(QString textColor, QString backgroundColor)
{
    this->setSegmentStyle(QLCDNumber::Flat);
    if(timer == nullptr)
        timer = new QTimer(this);

    disconnect(timer, SIGNAL(timeout()), this, SLOT(slotShowTime()));
    connect(timer, SIGNAL(timeout()), this, SLOT(slotShowTime()));
    timer->stop();
    timer->start(200);
//чтобы при первом запуске не показывало 0
    display(QTime::currentTime().toString("hh:mm"));

    this->setStyleSheet("background-color: " + backgroundColor + ";color: " + textColor + ";");
}
void Clock::slotShowTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
