#ifndef CLOCK_H
#define CLOCK_H

#include <QLCDNumber>
#include <QTime>
#include <QTimer>

class Clock : public QLCDNumber
{
    Q_OBJECT
public:
    Clock(QString textColor, QString backgroundColor, QWidget *parent = nullptr);

    void    create_or_recreate_object(QString textColor, QString backgroundColor);
private:
    QString textColor, backgroundColor;
    QTimer *timer = nullptr;
private slots:
     void slotShowTime();

signals:

public slots:
};

#endif // CLOCK_H
