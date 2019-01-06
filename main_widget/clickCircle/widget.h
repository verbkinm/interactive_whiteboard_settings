#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int spanAngle = 0;


private:
    QTimer timer;

private slots:
    void    slotDrawArc();

protected:
    virtual void paintEvent(QPaintEvent*);
};

#endif // WIDGET_H
