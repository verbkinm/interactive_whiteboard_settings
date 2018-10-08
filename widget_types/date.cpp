#include "date.h"
#include <QDate>
#include <QTimer>

Date::Date(QString textColor, int textSize, QString backgroundColor, QString datePattern, QWidget *parent) : QLabel(parent)
{
    create_or_recreate_object(textColor, textSize, backgroundColor, datePattern);
}
void Date::create_or_recreate_object(QString textColor, int textSize, QString backgroundColor, QString datePattern)
{
    this->datePattern = datePattern;
    slotShowDate();
    this->setAlignment(Qt::AlignCenter);


    this->setStyleSheet("background-color: " + backgroundColor + ";color: " + textColor + "; \
                        font: bold " + QString::number(textSize) + "px;");

    if(timer == nullptr)
        timer = new QTimer(this);

    disconnect(timer, SIGNAL(timeout()), this, SLOT(slotShowDate()));
    connect(timer, SIGNAL(timeout()), this, SLOT(slotShowDate()));

    timer->stop();
    timer->start(60000);
}
void Date::slotShowDate()
{
    this->setText(QDate::currentDate().toString(datePattern));
}
