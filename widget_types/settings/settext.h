#ifndef SETTEXT_H
#define SETTEXT_H

#include <QWidget>
#include <QMap>

namespace Ui {
class SetText;
}

class SetText : public QWidget
{
    Q_OBJECT

public:
    explicit SetText(QWidget *parent = nullptr);
    ~SetText();

    void    setTitle    (QString textTitle);
    void    setColor    (QColor color);
    void    setTextSize (uint size);

    QColor  getColor    ();
    uint    getTextSize ();

    QMap<QString, QVariant>
            getTextStyle();

    void    hideTextSize();

signals:
    void    signalTextChange();
private:
    Ui::SetText *ui;
};

#endif // SETTEXT_H
