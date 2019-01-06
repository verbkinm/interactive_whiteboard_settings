#ifndef DATE_H
#define DATE_H

#include <QLabel>
#include <QMap>
#include <QVariant>

class Date : public QLabel
{
    Q_OBJECT
public:
    Date(QString textColor, int textSize, QString backgroundColor, QString datePattern, QWidget *parent = nullptr);
    ~Date();

    void create_or_recreate_object(QString textColor, int textSize, QString backgroundColor, QString datePattern);

    void setTextStyle(QMap<QString, QVariant> map);
    void setBackgroundStyle(QString background);

    void setPattern(QString pattern);
private:
    QString textColor, backgroundColor, datePattern, textSize;
    QTimer *timer = nullptr;

//    QString background, textColor, textSize;

private slots:
     void slotShowDate();

signals:

public slots:
};

#endif // DATE_H
