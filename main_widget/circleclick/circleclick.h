#ifndef CIRCLECLICKCIRCLECLICK_H
#define CIRCLECLICKCIRCLECLICK_H

#include <QWidget>
#include <QTimer>
#include <QEvent>

class CircleClick : public QWidget
{
    Q_OBJECT
public:
    CircleClick(QWidget *parent = nullptr);

    void    stop();
    void    start();

private:
    int spanAngle = 0;
    QTimer timer;

private slots:
    void    slotDrawArc();

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual bool event(QEvent *event);

signals:
    void    signalCircleEnd();

public slots:
};

#endif // CIRCLECLICKCIRCLECLICK_H
