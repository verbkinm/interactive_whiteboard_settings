#include "run_string.h"

#include <QPainter>

Run_String::Run_String(QString textColor, int textSize, QString backgroundColor, QString text, int speed, QWidget *parent) : QLabel(parent)
{
    create_or_recreate_object(textColor, textSize, backgroundColor, text, speed);
}
void Run_String::create_or_recreate_object(QString textColor, \
                                           int textSize, \
                                           QString backgroundColor, \
                                           QString text, \
                                           int speed)
{
    this->backgroundColor   = backgroundColor;
    this->textColor         = textColor;
    this->textSize          = QString::number(textSize);

    x = this->width();

    disconnect(&timer, SIGNAL(timeout()), this, SLOT(slotRunLine()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotRunLine()));
    timer.stop();
    timer.setInterval(speed);
    timer.start();

    str = text;

    if(font == nullptr)
        font = new QFont("Arial", textSize, QFont::Bold);
    else
        font->setPixelSize(textSize);

    if(fontMetric == nullptr)
        fontMetric = new QFontMetrics(*font);

    stringLenght = fontMetric->width(str);

    this->setStyleSheet("background-color: " + backgroundColor + ";color: " + textColor + ";");
}

void Run_String::setTextStyle(QMap<QString, QVariant> map)
{
    QString styleSheet = "background-color: %1; color: %2;";
    this->setStyleSheet( styleSheet.arg(backgroundColor, map["textColor"].toString()) );
    font->setPixelSize(map["textSize"].toInt());

    textColor = map["textColor"].toString();
    textSize  = map["textSize"].toString();
}

void Run_String::setBackgroundStyle(QString background)
{
    QString styleSheet = "background-color: %1; color: %2;";
    this->setStyleSheet( styleSheet.arg(background, textColor) );
    font->setPixelSize(textSize.toInt());
}

void Run_String::setSpeed(int speed)
{
    timer.setInterval(speed);
}

void Run_String::setText(QString text)
{
    create_or_recreate_object(textColor, textSize.toInt(), backgroundColor, text, timer.interval());
}
void Run_String::slotRunLine()
{
    x -= 1;

    repaint();
}
void Run_String::paintEvent(QPaintEvent*)
{
    x_end = x + fontMetric->width(str);

    if(x_end == 0)
        x = this->width();

    QPainter painter(this);

    painter.setFont(*font);

    int width;
    if(stringLenght < this->width())
        width = this->width();
    else
        width = stringLenght;

    painter.drawText(x,0, width, this->height(), Qt::AlignVCenter | Qt::TextSingleLine | Qt::TextExpandTabs, str);
}
Run_String::~Run_String()
{
    delete fontMetric;
    delete font;
}
