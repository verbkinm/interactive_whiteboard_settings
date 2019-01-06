#include "circleclick.h"

#include <QPainter>
#include <QStyleOption>

#define LINE_WIDTH 5
#define CIRCLE_RADIUS 50
#define INTERVAL 15

CircleClick::CircleClick(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("QWidget {background: rgba(0,0,0,0%); }");
    this->setFixedSize(CIRCLE_RADIUS + LINE_WIDTH*2, CIRCLE_RADIUS + LINE_WIDTH*2);
    timer.setInterval(INTERVAL);
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotDrawArc()));
}

void CircleClick::stop()
{
    timer.stop();
    spanAngle = 0;
    repaint();
}

void CircleClick::start()
{
    timer.start();
}

void CircleClick::slotDrawArc()
{
    if(spanAngle >= 360){
        stop();
        emit signalCircleEnd();
    }

    spanAngle += 10;
    repaint();
}

void CircleClick::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(Qt::blue, LINE_WIDTH, Qt::SolidLine));

    painter.drawArc(LINE_WIDTH, LINE_WIDTH, CIRCLE_RADIUS, CIRCLE_RADIUS, 90 * 16, spanAngle * -16);
}

bool CircleClick::event(QEvent *event)
{
    if(event->type() == QEvent::Show)
        this->start();
    if(event->type() == QEvent::Close)
        this->stop();
    return QWidget::event(event);
}
