#include "clock.h"

#include <QPainter>

#include <QDebug>

Clock::Clock(QString textColor, QString backgroundColor, QWidget *parent) : QLCDNumber(parent)
{
    create_or_recreate_object(textColor, backgroundColor);
}

Clock::~Clock()
{
    delete timer;
}
void Clock::create_or_recreate_object(QString textColor, QString backgroundColor)
{
    this->backgroundColor   = backgroundColor;
    this->textColor         = textColor;

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

void Clock::setTextStyle(QMap<QString, QVariant> map)
{
    QString styleSheet = "background-color: %1; color: %2;";
    this->setStyleSheet( styleSheet.arg(backgroundColor, map["textColor"].toString()) );
    textColor = map["textColor"].toString();
}

void Clock::setBackgroundStyle(QString background)
{
    QString styleSheet = "background-color: %1; color: %2;";
    this->setStyleSheet( styleSheet.arg(background, textColor) );
    backgroundColor = background;
}
void Clock::slotShowTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
