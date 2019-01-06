#include "widget.h"

#include <QPainter>
#include <QPen>
#include <QStyleOption>

#define LINE_WIDTH 5
#define CIRCLE_RADIUS 50
#define INTERVAL 3

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setStyleSheet("QWidget {background: rgba(0,0,0,0%); }");
    this->setFixedSize(CIRCLE_RADIUS + LINE_WIDTH*2, CIRCLE_RADIUS + LINE_WIDTH*2);
    timer.setInterval(INTERVAL);
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotDrawArc()));
    timer.start();
}

Widget::~Widget()
{

}

void Widget::slotDrawArc()
{
    if(spanAngle == 360)
        spanAngle = 0;

    spanAngle += 1;
    repaint();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, LINE_WIDTH, Qt::SolidLine));

    painter.drawArc(LINE_WIDTH, LINE_WIDTH, CIRCLE_RADIUS, CIRCLE_RADIUS, 270 * 16, spanAngle * -16);


}
