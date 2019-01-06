#include "date.h"
#include <QDate>
#include <QTimer>
#include <QtDebug>

Date::Date(QString textColor, int textSize, QString backgroundColor, QString datePattern, QWidget *parent) : QLabel(parent)
{
    create_or_recreate_object(textColor, textSize, backgroundColor, datePattern);
}

Date::~Date()
{
    delete timer;
}
void Date::create_or_recreate_object(QString textColor, int textSize, QString backgroundColor, QString datePattern)
{
    this->datePattern = datePattern;
    slotShowDate();
    this->setAlignment(Qt::AlignCenter);

    this->backgroundColor   = backgroundColor;
    this->textColor         = textColor;
    this->textSize          = QString::number(textSize);

    this->setStyleSheet("background-color: " + backgroundColor + ";color: " + textColor + "; \
                        font: bold " + QString::number(textSize) + "px;");

    if(timer == nullptr)
        timer = new QTimer(this);

    disconnect(timer, SIGNAL(timeout()), this, SLOT(slotShowDate()));
    connect(timer, SIGNAL(timeout()), this, SLOT(slotShowDate()));

    timer->stop();
    timer->start(60000);
}

void Date::setTextStyle(QMap<QString, QVariant> map)
{
    QString styleSheet = "background-color: %1; color: %2; font: bold %3px;";
    this->setStyleSheet( styleSheet.arg(backgroundColor, map["textColor"].toString(), map["textSize"].toString()) );
    textColor = map["textColor"].toString();
    textSize = map["textSize"].toString();
}

void Date::setBackgroundStyle(QString background)
{
    QString styleSheet = "background-color: %1; color: %2; font: bold %3px;";
    this->setStyleSheet( styleSheet.arg(background, textColor, textSize) );
    backgroundColor = background;
}

void Date::setPattern(QString pattern)
{
    datePattern = pattern;
    slotShowDate();
}
void Date::slotShowDate()
{
    this->setText(QDate::currentDate().toString(datePattern));
}
