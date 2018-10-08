#include "widgetforminiwidget.h"

#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

WidgetForMiniWidget::WidgetForMiniWidget(const struct path *struct_path, \
                                         const struct text *struct_text, \
                                         const struct miscellanea *struct_miscellanea, \
                                         QSize *size, \
                                          QWidget *parent) : QWidget(parent)
{
    create_or_recreate_object(struct_path, \
                              struct_text, \
                              struct_miscellanea, \
                              size);
}
void WidgetForMiniWidget::create_or_recreate_object(const struct path *struct_path, \
                                          const struct text *struct_text, \
                                          const struct miscellanea *struct_miscellanea, \
                                          QSize *size)
{
    this->setFixedSize(*size);

    if(layout == nullptr)
        layout      = new QVBoxLayout;

    if(title == nullptr)
        title       = new QLabel("Title");
    title->setStyleSheet("font-size:" + QString::number(struct_text->textSize) + "px;");

    if(image == nullptr)
        image       = new QLabel("Image");

    if(leafer == nullptr)
        leafer      = new Leafer(struct_text->textSize);
    else
        leafer->setTextSize(struct_text->textSize);


    layout->addWidget(title, 0, Qt::AlignHCenter);
    layout->addWidget(image, 2);
    layout->addWidget(leafer, 0, Qt::AlignHCenter);

    title->setText(struct_text->titleText);

    this->setLayout(layout);

    disconnect(leafer, SIGNAL(signalPrevios()), this, SLOT(slotPrevios()));
    disconnect(leafer, SIGNAL(signalNext()), this, SLOT(slotNext()));
    connect(leafer, SIGNAL(signalPrevios()), this, SLOT(slotPrevios()));
    connect(leafer, SIGNAL(signalNext()), this, SLOT(slotNext()));

    title->hide();
    leafer->hide();
    currentPix.load(correct_image(struct_path->iconPath));
    setImage();

    timer.stop();
    timer.setInterval(struct_miscellanea->dynamicMiniWidgetTimer*1000);

    dynamicWidget(struct_miscellanea, struct_path);
}
void WidgetForMiniWidget::dynamicWidget(const miscellanea *struct_miscellanea, const path *struct_path)
{
    if(struct_miscellanea->dynamicMiniWidget)
    {
        title->setVisible(true);
        leafer->setVisible(true);

        dirPath = struct_path->dirPath;
        createImageList(dirPath);

        if(!list.isEmpty())
        {
            currentPix.load(list.at(0));
            disconnect(&timer, SIGNAL(timeout()), this, SLOT(slotNext()));
            connect(&timer, SIGNAL(timeout()), this, SLOT(slotNext()));
            timer.start();
        }
    }
}
void WidgetForMiniWidget::createImageList(QString dirPath)
{
    dir.setPath(dirPath);

    dir.setSorting(QDir::Name);
    QStringList filters;
    filters << "*.jpg" << "*.JPG" << "*.png" << "*.PNG" << "*.gif" << "*.GIF";

    dir.setNameFilters(filters);

    QFileInfoList fl = dir.entryInfoList();

    list.clear();
    foreach (QFileInfo fi, fl)
        list << fi.filePath();

    leafer->setCounter(it+1, list.length());
}
void WidgetForMiniWidget::slotPrevios()
{
    createImageList(dirPath);

    if(!list.isEmpty())
    {
        --it;

        if(it > -1)
            currentPix  = QPixmap(list.at(it));
        if(it < 0){
            currentPix  = QPixmap(list.at(list.length()-1));
            it = list.length()-1;
        }
        setImage();
        leafer->setCounter(it+1, list.length());
    }
}
void WidgetForMiniWidget::slotNext()
{
    createImageList(dirPath);

    if(!list.isEmpty())
    {
        ++it;

        if(it < list.length())
            currentPix  = QPixmap(list.at(it));
        if(it >= list.length()){
            currentPix  = QPixmap(list.at(0));
            it = 0;
        }

        setImage();
        leafer->setCounter(it+1, list.length());
    }
}
int WidgetForMiniWidget::getCurrentPage()
{
    return it;
}
void WidgetForMiniWidget::setImage()
{
    QPixmap newPixmap = currentPix.scaled(image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    image->setPixmap(newPixmap);
    image->setStyleSheet("QLabel { background-color : rgba(255, 255, 255, 30%); color : blue; }");
    image->setAlignment(Qt::AlignCenter);
}
QString WidgetForMiniWidget::correct_image(QString path)
{
    QFile file(path);
    if(file.exists() && file.open(QIODevice::ReadOnly)){
        file.close();
        return path;
    }

    return QString(":/img/logo");
}
bool WidgetForMiniWidget::event(QEvent *event)
{
//    qDebug() << event->type();
    static bool cursorOnWidget;

    // при нажатии на виджет (а точнее на виджет изображения - image) появляется рамка, при ударживании кнопки мыши и вывыедения курсора за границы виджета рамка исчезает,
    // а при возвращении обратно (при удержании кнопки мыши) - рамка появляется
    if(event->type() == QEvent::MouseMove){
        if( image->geometry().contains(this->mapFromGlobal(QCursor::pos())) ){
            emit signalImagePressed();
            cursorOnWidget = true;
        }
        else {
            emit signalImageReleased();
            cursorOnWidget = false;
        }
    }
    if(event->type() == QEvent::MouseButtonPress){
        if(image->underMouse())
        {
            emit signalImagePressed();
            cursorOnWidget = true;
        }
    }
    // при отпускании кнопки проверяется, где в данный момент находится курсор - над виджетом или нет.
    // Если над виджетом - выполняются последующие действия
    if(event->type() == QEvent::MouseButtonRelease){
        emit signalImageReleased();
        if(cursorOnWidget)
            emit signalImageClicked();
    }

    if(event->type() == QEvent::Resize)
        setImage();

    return QWidget::event(event);
}

WidgetForMiniWidget::~WidgetForMiniWidget()
{
    delete title;
    delete image;
    delete leafer;
    delete layout;
}
