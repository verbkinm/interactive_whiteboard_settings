#include "mini_widget.h"

#include <QDebug>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTextCodec>

//задержка анимациив
#define DURATION 1000

Mini_Widget::Mini_Widget(const struct border &struct_border, QSize size, \
                         const struct path &struct_path, \
                         const struct background &struct_background, \
                         const struct text &struct_text, \
                         const struct miscellanea &struct_miscellanea, \
                         QWidget *parent) : QWidget(parent)
{
    create_or_recreate_object(struct_border, size, \
                 struct_path, \
                 struct_background, \
                 struct_text, \
                 struct_miscellanea);
}
void Mini_Widget::create_or_recreate_object(const struct border &struct_border, QSize size, \
                               const struct path &struct_path, \
                               const struct background &struct_background, \
                               const struct text &struct_text, \
                               const struct miscellanea &struct_miscellanea)
{
    this->struct_border     = struct_border;
    this->struct_text       = struct_text;
    this->struct_path       = struct_path;
    this->struct_background = struct_background;
    this->struct_miscellanea= struct_miscellanea;

    this->_size             = size;

    generalSettings();
    setTypeValue(this->struct_miscellanea.type);

    switch (this->type) {
        case LABEL:
                createLabelWidget();
            break;
        case CLOCK:
                createClockWidget();
             break;
        case DATE:
                createDateWidget();
             break;
        case RUN_STRING:
                createRunStringWidget();
             break;
        case SCHEDULE:
                createScheduleWidget();
            break;
        case IMAGE_VIEWER:
                createImageViewerWidget();
            break;
        case DONT_CLICK:
                createDontClickWidget();
            break;

        default:
            break;
    }

    createSettingsButton();
}
void Mini_Widget::createSettingsButton()
{
    if(buttonSettings == nullptr)
        buttonSettings = new QPushButton(this);
    buttonSettings->setIcon(QIcon(":/img/img/settings_button.png"));

    QSize result;
    result.setWidth(this->width() * 0.7);
    result.setHeight(this->height() * 0.7);

    buttonSettings->setFixedSize(this->size());
    buttonSettings->setIconSize(result);

    buttonSettings->hide();

    buttonSettings->setStyleSheet("color: rgb(255, 255, 255);"
                                  "border: 2px solid rgb(100,200,200); "
                                  "border-radius: 5px;"
                                  "background: rgba(100,100,100,70%);");
}
void Mini_Widget::generalSettings()
{
//рамка, которая будет появлятся при нажатии
    if(borderClick == nullptr)
        borderClick              = new QLabel(this);
    //example: border-color: rgba(255, 0, 0, 75%)
    borderClick->setStyleSheet("background-color:" + struct_border.borderClickColor + ";");
    borderClick->setFixedSize(_size.width() + struct_border.borderClickWidth, _size.height() + struct_border.borderClickWidth);
//    borderClick->hide();

//рамка
    if( border == nullptr)
        border              = new QLabel(this);
    //example: border-color: rgba(255, 0, 0, 75%)
    border->setStyleSheet("background-color:" + struct_border.borderColor + ";");
    border->setFixedSize(_size.width() + struct_border.borderWidth, _size.height() + struct_border.borderWidth);
    border->move(struct_border.borderClickWidth / 2 - struct_border.borderWidth / 2, struct_border.borderClickWidth / 2 - struct_border.borderWidth / 2);

    this->setStyleSheet("border-radius: 20px;");
    this->setFixedSize(borderClick->size());
}
void Mini_Widget::createLabelWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&struct_path, \
                                                             &struct_text, \
                                                             &struct_miscellanea, \
                                                             &_size, \
                                                             this);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&struct_path, \
                                                              &struct_text, \
                                                              &struct_miscellanea, \
                                                              &_size);
    }
     centralWidgetForMiniWidget->move(struct_border.borderClickWidth / 2, \
                         struct_border.borderClickWidth / 2);
}
void Mini_Widget::createClockWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&struct_path, \
                                                             &struct_text, \
                                                             &struct_miscellanea, \
                                                             &_size, \
                                                             this);
        pClock = new Clock(struct_text.textColor, struct_background.backgroundColor, centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&struct_path, \
                                                              &struct_text, \
                                                              &struct_miscellanea, \
                                                              &_size);
        pClock->create_or_recreate_object(struct_text.textColor, struct_background.backgroundColor);
    }
    centralWidgetForMiniWidget->move(struct_border.borderClickWidth / 2, \
                                      struct_border.borderClickWidth / 2);
    pClock->setFixedSize(_size);
}
void Mini_Widget::createDateWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&struct_path, \
                                                             &struct_text, \
                                                             &struct_miscellanea, \
                                                             &_size, \
                                                             this);
        pDate = new Date(struct_text.textColor, struct_text.textSize, \
                        struct_background.backgroundColor, struct_miscellanea.datePattern, \
                        centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&struct_path, \
                                                              &struct_text, \
                                                              &struct_miscellanea, \
                                                              &_size);
        pDate->create_or_recreate_object(struct_text.textColor, struct_text.textSize, \
                                         struct_background.backgroundColor, struct_miscellanea.datePattern);
    }
    centralWidgetForMiniWidget->move(struct_border.borderClickWidth / 2, \
                                      struct_border.borderClickWidth / 2);
    pDate->setFixedSize(_size);
}
void Mini_Widget::createRunStringWidget()
{
    QString text;
    QFile file(struct_path.txtPath);

    if( !(file.open(QIODevice::ReadOnly)) || file.size() > 10 * 1024)
        text = "ОШИБКА ОТКРЫТИЯ ФАЙЛА \"" + struct_path.txtPath + "\"!";
    else
        text = QString::fromUtf8(file.readAll());

    file.close();

    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&struct_path, \
                                                             &struct_text, \
                                                             &struct_miscellanea, \
                                                             &_size, \
                                                             this);
        pRun_String = new Run_String(struct_text.textColor, struct_text.textSize, \
                                struct_background.backgroundColor, text, struct_miscellanea.speed, \
                                centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&struct_path, \
                                                              &struct_text, \
                                                              &struct_miscellanea, \
                                                              &_size);
        pRun_String->create_or_recreate_object(struct_text.textColor, struct_text.textSize, \
                                         struct_background.backgroundColor, text, struct_miscellanea.speed);
    }
    centralWidgetForMiniWidget->move(struct_border.borderClickWidth / 2, \
                                      struct_border.borderClickWidth / 2);
    pRun_String->setFixedSize(_size);
}
void Mini_Widget::createScheduleWidget()
{
    createLabelWidget();
}
void Mini_Widget::createImageViewerWidget()
{
    createLabelWidget();
}
void Mini_Widget::createDontClickWidget()
{
    createLabelWidget();
}
void Mini_Widget::setTypeValue(QString typeStr)
{
    if( typeStr == "label" )
        type =  int(LABEL);
    else if( typeStr == "clock" )
        type =  int(CLOCK);
    else if( typeStr == "date" )
        type =  int(DATE);
    else if( typeStr == "run_string" )
        type =  int(RUN_STRING);
    else if( typeStr == "schedule" )
        type =  int(SCHEDULE);
    else if( typeStr == "image_viewer" )
        type =  int(IMAGE_VIEWER);
    else if( typeStr == "dont_click" )
        type =  int(DONT_CLICK);
}

void Mini_Widget::createLabelForMiniWidget()
{
//   centralWidgetForMiniWidget = new WidgetForMiniWidget(&struct_path, \
//                                                        &struct_text, \
//                                                        &struct_miscellanea, \
//                                                        &_size, \
//                                                        this);
//    centralWidgetForMiniWidget->move(struct_border.borderClickWidth / 2, \
//                        struct_border.borderClickWidth / 2);

//    connect(centralWidgetForMiniWidget, SIGNAL(signalImagePressed()), this, SLOT(slotWidgetPressed()));
//    connect(centralWidgetForMiniWidget, SIGNAL(signalImageReleased()), this, SLOT(slotWidgetReleased()));
//    connect(centralWidgetForMiniWidget, SIGNAL(signalImageClicked()), this, SLOT(slotWidgetClicked()));
}
void Mini_Widget::hideSettingsButton()
{
    buttonSettings->hide();
}
void Mini_Widget::slotWidgetPressed()
{
//    borderClick->setVisible(true);
}
void Mini_Widget::slotWidgetReleased()
{
//    borderClick->setVisible(false);
}
void Mini_Widget::slotWidgetClicked()
{
//    slotWidgetReleased();
//    if(pContent != 0 && type != 0){
//        switch (*type) {
//            case LABEL:

//                break;
//            case CLOCK:
//                break;
//            case DATE:
//                break;
//            case RUN_STRING:
//                break;

//            case SCHEDULE:{
//                pSchedule = new Schedule(struct_path.xmlPath, struct_text.textColor, struct_text.textSize, pContent);
//                if(!pSchedule->CRITICAL_ERROR)
//                {
//                    pSchedule->setObjectName("Schedule");
//                    connect(pSchedule, SIGNAL(signalTimerStart()), pContent, SLOT(slotRestartTimer()));
//                    pContent->addWidget(pSchedule);
//                    pContent->setTitle(pSchedule->getTitle());
//                    connect(pContent, SIGNAL(signalClose()), this, SLOT(slotDeleteWidgetInContent()));

//                    panimOpen = new QPropertyAnimation(pContent, "geometry");
//                    panimOpen->setDuration(DURATION);
//                    panimOpen->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
//                    panimOpen->setEndValue(QRect(static_cast<QWidget*>(this->parent())->rect()));
//                    panimOpen->setEasingCurve(QEasingCurve::Linear);
//                    panimOpen->start();
//                }
//                else
//                {
//                    pSchedule->~Schedule();
//                    pSchedule = nullptr;
//                    pContent->slotAnimCloseWindow();
//                }

//            }
//                break;

//            case IMAGE_VIEWER:{
//                pImageViewer = new viewer(struct_path.dirPath, struct_text.textColor, struct_text.textSize, \
//                                          centralWidgetForMiniWidget->getCurrentPage(), pContent);
//                if(!pImageViewer->CRITICAL_ERROR)
//                {
//                    pImageViewer->setObjectName("ImageViewer");
//                    connect(pImageViewer, SIGNAL(signalTimerStart()), pContent, SLOT(slotRestartTimer()));
//                    pContent->addWidget(pImageViewer);
//                    connect(pContent, SIGNAL(signalClose()), this, SLOT(slotDeleteWidgetInContent()));

//                    panimOpen = new QPropertyAnimation(pContent, "geometry");
//                    panimOpen->setDuration(DURATION);
//                    panimOpen->setStartValue( QRect(this->x(), this->y(), this->width(), this->height()) );
//                    panimOpen->setEndValue(QRect(static_cast<QWidget*>(this->parent())->rect()));
//                    panimOpen->setEasingCurve(QEasingCurve::InQuad);
//                    panimOpen->start();
//                }
//                else
//                {
//                    pImageViewer->~viewer();
//                    pImageViewer = nullptr;
//                    pContent->slotAnimCloseWindow();
//                }
//            }
//                break;

//            default:
//                break;
//        }
//        pContent->setWindowFlag(Qt::SplashScreen);
//        pContent->setWindowModality(Qt::ApplicationModal);
//        pContent->show();
//    }
}
bool Mini_Widget::event(QEvent *event)
{
//    qDebug() << event->type();
    if(event->type() == QEvent::MouseButtonRelease){
        qDebug() << this->objectName() << event->type();
        buttonSettings->setVisible(true);
    }

    return QWidget::event(event);
}
void Mini_Widget::slotDeleteWidgetInContent()
{
//    if(pSchedule != nullptr){
//        disconnect(pSchedule, SIGNAL(signalTimerStart()), pContent, SLOT(slotRestartTimer()));
//        pSchedule->~Schedule();
//        pSchedule = nullptr;
//        disconnect(pContent, SIGNAL(signalClose()),this, SLOT(slotDeleteWidgetInContent()));
//    }
//    if(pImageViewer != nullptr){
//        disconnect(pImageViewer, SIGNAL(signalTimerStart()), pContent, SLOT(slotRestartTimer()));
//        pImageViewer->~viewer();
//        pImageViewer = nullptr;
//        disconnect(pContent, SIGNAL(signalClose()),this, SLOT(slotDeleteWidgetInContent()));
//    }
//    delete panimOpen;

}
Mini_Widget::~Mini_Widget()
{
//    if(pSchedule != nullptr)
//        delete pSchedule;

//    if(pImageViewer != nullptr)
//        delete pImageViewer;

//    if(type != nullptr)
//        delete type;


//    if(pContent != nullptr)
//        delete pContent;

    if(centralLabel != nullptr)
        delete centralLabel;

    if(borderClick != nullptr)
        delete borderClick;

    if(border != nullptr)
        delete border;

    if(buttonSettings != nullptr)
        delete buttonSettings;
}
