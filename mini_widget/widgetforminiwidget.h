#ifndef WIDGETFORMINIWIDGET_H
#define WIDGETFORMINIWIDGET_H

#include "../structes/structes.h"
#include "../widget_types/leafer.h"

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QEvent>
#include <QDir>
#include <QTimer>

class WidgetForMiniWidget : public QWidget
{
    Q_OBJECT

public:
    WidgetForMiniWidget(const path *struct_path, \
                        const text *struct_text, \
                        const miscellanea *struct_miscellanea,
                        QSize *size, \
                        QWidget *parent = 0);
    ~WidgetForMiniWidget();

    int getCurrentPage();

    void            dynamicWidget(const struct miscellanea *struct_miscellanea, const struct path *struct_path);

    void            create_or_recreate_object(const path *struct_path, \
                                    const text *struct_text, \
                                    const miscellanea *struct_miscellanea,
                                    QSize *size);
private:

    QLabel*         title       = nullptr;
    QLabel*         image       = nullptr;

    QPushButton*    previos     = nullptr;
    QPushButton*    next        = nullptr;

    QVBoxLayout*    layout      = nullptr;

    Leafer*         leafer      = nullptr;

    QPixmap         currentPix;

    QString         dirPath;
    QDir            dir;
    QStringList     list;

// таймер для динамического виджета(где переключаются картинки)
    QTimer          timer;
// итератор при листании слайдов
    int             it          = 0;
//если файл рисунка существует - возвращает его путь, если нет - файл рисунка по умолчание(logo)
    QString         correct_image       (QString path);

    void            setImage            ();
    void            createImageList     (QString dirPath);

    virtual bool    event               (QEvent *event);

private slots:
    void slotPrevios();
    void slotNext();

signals:
    void signalImagePressed();
    void signalImageReleased();
    void signalImageClicked();
};

#endif // WIDGETFORMINIWIDGET_H
