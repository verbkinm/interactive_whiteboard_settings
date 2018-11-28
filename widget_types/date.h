#ifndef DATE_H
#define DATE_H

#include <QLabel>

class Date : public QLabel
{
    Q_OBJECT
public:
    Date(QString textColor, int textSize, QString backgroundColor, QString datePattern, QWidget *parent = nullptr);

    void create_or_recreate_object(QString textColor, int textSize, QString backgroundColor, QString datePattern);
private:
    QString textColor, backgroundColor, datePattern;
    QTimer *timer = nullptr;
private slots:
     void slotShowDate();

signals:

public slots:
};

#endif // DATE_H
