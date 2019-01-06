#ifndef RUN_STRING_H
#define RUN_STRING_H

#include <QLabel>
#include <QTimer>
#include <QMap>
#include <QVariant>

class Run_String : public QLabel
{
    Q_OBJECT
public:
    Run_String(QString textColor, int textSize, QString backgroundColor, QString text, int speed, QWidget *parent = nullptr);
    ~Run_String();

    void create_or_recreate_object(QString textColor, int textSize, QString backgroundColor, QString text, int speed);

    void setTextStyle(QMap<QString, QVariant> map);
    void setBackgroundStyle(QString background);
    void setSpeed(int speed);
    void setText(QString text);

protected:
    virtual void paintEvent(QPaintEvent*);

private:
    int x, x_end;
    int stringLenght;
    QTimer timer;

    QString textColor, backgroundColor, textSize;

    QString str, str_tail;
    QFont *font = nullptr;
    QFontMetrics* fontMetric = nullptr;

private slots:
    void slotRunLine();
};

#endif // RUN_STRING_H
