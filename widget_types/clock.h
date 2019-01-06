#ifndef CLOCK_H
#define CLOCK_H

#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QMap>
#include <QVariant>

class Clock : public QLCDNumber
{
    Q_OBJECT
public:
    Clock(QString textColor, QString backgroundColor, QWidget *parent = nullptr);
    ~Clock();

    void    create_or_recreate_object(QString textColor, QString backgroundColor);

    void    setTextStyle(QMap<QString, QVariant> map);
    void    setBackgroundStyle(QString background);
private:
    QString textColor, backgroundColor;
    QTimer *timer = nullptr;
private slots:
     void slotShowTime();

signals:

public slots:
};

#endif // CLOCK_H
