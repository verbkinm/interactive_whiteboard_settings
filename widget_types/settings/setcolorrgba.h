#ifndef SETCOLORRGBA_H
#define SETCOLORRGBA_H

#include <QWidget>

namespace Ui {
class SetColorRGBA;
}

class SetColorRGBA : public QWidget
{
    Q_OBJECT

public:
    explicit SetColorRGBA(QWidget *parent = nullptr);
    ~SetColorRGBA();

    void    setTitle    (QString textTitle);
    void    setColor    (QColor color);

    QColor  getColor    ();

signals:
    void    signalColorChange();

private:
    Ui::SetColorRGBA *ui;
};

#endif // SETCOLORRGBA_H
