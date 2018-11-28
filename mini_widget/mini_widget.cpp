#include "mini_widget.h"

#include <QDebug>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTextCodec>

#include <QVariant>

//задержка анимациив
#define DURATION 1000

Mini_Widget::Mini_Widget(settingsMiniWidget *struct_settingsMiniWidget, \
                         QWidget *parent) : QWidget(parent)
{
    create_or_recreate_object(struct_settingsMiniWidget);
}
void Mini_Widget::create_or_recreate_object(settingsMiniWidget *struct_settingsMiniWidget)
{
    this->pStruct_settingsMiniWidget = struct_settingsMiniWidget;

    generalSettings();

    switch (pStruct_settingsMiniWidget->pGetType(pStruct_settingsMiniWidget->miscellanea.type)) {
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

        //bells

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
                                  "border-radius: 15px;"
                                  "background: rgba(100,100,100,70%);");
    disconnect(buttonSettings, SIGNAL(clicked(bool)), this, SLOT(slotSettingsButtonClicked()));
    connect(buttonSettings, SIGNAL(clicked(bool)), this, SLOT(slotSettingsButtonClicked()));
}
void Mini_Widget::generalSettings()
{
//рамка, которая будет появлятся при нажатии
    if(borderClick == nullptr)
        borderClick              = new QLabel(this);
    //example: border-color: rgba(255, 0, 0, 75%)
    borderClick->setStyleSheet("background-color:" + pStruct_settingsMiniWidget->border.borderClickColor + ";");
    borderClick->setFixedSize(pStruct_settingsMiniWidget->size.width() \
                              + \
                              pStruct_settingsMiniWidget->border.borderClickWidth, \
                              pStruct_settingsMiniWidget->size.height() \
                              + \
                              pStruct_settingsMiniWidget->border.borderClickWidth);
//    borderClick->hide();

//рамка
    if( border == nullptr)
        border              = new QLabel(this);
    //example: border-color: rgba(255, 0, 0, 75%)
    border->setStyleSheet("background-color:" + pStruct_settingsMiniWidget->border.borderColor + ";");
    border->setFixedSize(pStruct_settingsMiniWidget->size.width() \
                         + \
                         pStruct_settingsMiniWidget->border.borderWidth, \
                         pStruct_settingsMiniWidget->size.height() \
                         + \
                         pStruct_settingsMiniWidget->border.borderWidth);
    border->move(pStruct_settingsMiniWidget->border.borderClickWidth / 2 \
                 - \
                 pStruct_settingsMiniWidget->border.borderWidth / 2, \
                 pStruct_settingsMiniWidget->border.borderClickWidth / 2 \
                 - \
                 pStruct_settingsMiniWidget->border.borderWidth / 2);

    this->setStyleSheet("border-radius: 20px;");
    this->setFixedSize(borderClick->size());
}
void Mini_Widget::createLabelWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, \
                                                             this);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
    }
     centralWidgetForMiniWidget->move(pStruct_settingsMiniWidget->border.borderClickWidth / 2, \
                         pStruct_settingsMiniWidget->border.borderClickWidth / 2);
}
void Mini_Widget::createClockWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, \
                                                             this);
        pClock = new Clock(pStruct_settingsMiniWidget->text.textColor, \
                           pStruct_settingsMiniWidget->background.backgroundColor, \
                           centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
        pClock->create_or_recreate_object(pStruct_settingsMiniWidget->text.textColor, \
                                          pStruct_settingsMiniWidget->background.backgroundColor);
    }
    centralWidgetForMiniWidget->move(pStruct_settingsMiniWidget->border.borderClickWidth / 2, \
                                      pStruct_settingsMiniWidget->border.borderClickWidth / 2);
    pClock->setFixedSize(pStruct_settingsMiniWidget->size);
}
void Mini_Widget::createDateWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, \
                                                             this);
        pDate = new Date(pStruct_settingsMiniWidget->text.textColor, \
                         pStruct_settingsMiniWidget->text.textSize, \
                         pStruct_settingsMiniWidget->background.backgroundColor, \
                         pStruct_settingsMiniWidget->miscellanea.datePattern, \
                         centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
        pDate->create_or_recreate_object(pStruct_settingsMiniWidget->text.textColor, \
                                         pStruct_settingsMiniWidget->text.textSize, \
                                         pStruct_settingsMiniWidget->background.backgroundColor, \
                                         pStruct_settingsMiniWidget->miscellanea.datePattern);
    }
    centralWidgetForMiniWidget->move(pStruct_settingsMiniWidget->border.borderClickWidth / 2, \
                                      pStruct_settingsMiniWidget->border.borderClickWidth / 2);
    pDate->setFixedSize(pStruct_settingsMiniWidget->size);
}
void Mini_Widget::createRunStringWidget()
{
    QString text;
    QFile file(pStruct_settingsMiniWidget->path.txtPath);

    if( !(file.open(QIODevice::ReadOnly)) || file.size() > 10 * 1024)
        text = "ОШИБКА ОТКРЫТИЯ ФАЙЛА \"" + pStruct_settingsMiniWidget->path.txtPath + "\"!";
    else
        text = QString::fromUtf8(file.readAll());

    file.close();

    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, \
                                                             this);
        pRun_String = new Run_String(pStruct_settingsMiniWidget->text.textColor, \
                                     pStruct_settingsMiniWidget->text.textSize, \
                                     pStruct_settingsMiniWidget->background.backgroundColor, \
                                     text, \
                                     pStruct_settingsMiniWidget->miscellanea.speed, \
                                     centralWidgetForMiniWidget);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
        pRun_String->create_or_recreate_object(pStruct_settingsMiniWidget->text.textColor, \
                                               pStruct_settingsMiniWidget->text.textSize, \
                                               pStruct_settingsMiniWidget->background.backgroundColor, \
                                               text, \
                                               pStruct_settingsMiniWidget->miscellanea.speed);
    }
    centralWidgetForMiniWidget->move(pStruct_settingsMiniWidget->border.borderClickWidth / 2, \
                                     pStruct_settingsMiniWidget->border.borderClickWidth / 2);
    pRun_String->setFixedSize(pStruct_settingsMiniWidget->size);
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
//        qDebug() << this->objectName() << event->type();
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
void Mini_Widget::slotSettingsButtonClicked()
{
    Settings_window *pSettingsWindow = new Settings_window(*pStruct_settingsMiniWidget);

    connect(pSettingsWindow, SIGNAL(signal_Change_Settings(int, QVariant)), this, SLOT(slotSettingsChange(int, QVariant)));

    this->hideSettingsButton();

    if (pSettingsWindow->exec()  ==   QDialog::Accepted){
        //связь в main_widget
        emit signalSaveSettings(pSettingsWindow->settingsMiniWidgetCopy);
    }
    else
    {
        emit signalSaveSettings(*pStruct_settingsMiniWidget);
    }

    delete pSettingsWindow;
}
void Mini_Widget::slotSettingsChange(int objectName, QVariant data)
{
    switch (objectName) {
    case Settings_window::X:
        this->move(data.toInt(), this->y());
        break;
    case Settings_window::Y:
        this->move(this->x(), data.toInt());
        break;
    case Settings_window::WIDTH:
        this->setFixedWidth(data.toInt());
        centralWidgetForMiniWidget->setFixedWidth(data.toInt());
        border->setFixedWidth(data.toInt() - pStruct_settingsMiniWidget->border.borderClickWidth);
        borderClick->setFixedWidth(data.toInt());
        break;
//    case HEIGHT:
//        settingsMiniWidgetCopy.size.setHeight(ui->height->value());
//        break;

//    case BORDER_WIDTH:
//        settingsMiniWidgetCopy.border.borderWidth = ui->border_width->value();
//        break;
//    case BORDER_COLOR:
//        settingsMiniWidgetCopy.border.borderColor = ui->border_color->text();
//        break;
//    case BORDERCLICK_WIDTH:
//        settingsMiniWidgetCopy.border.borderClickWidth = ui->borderClick_width->value();
//        break;
//    case BORDERCLICK_COLOR:
//        settingsMiniWidgetCopy.border.borderClickColor= ui->borderClick_color->text();
//        break;

//    case ICON_PATH:
//        settingsMiniWidgetCopy.path.iconPath = ui->iconPath->text();
//        break;
//    case DIR_PATH:
//        settingsMiniWidgetCopy.path.dirPath = ui->dirPath->text();
//        break;
//    case TXT_PATH:
//        settingsMiniWidgetCopy.path.txtPath = ui->txtPath->text();
//        break;
//    case XML_PATH:
//        settingsMiniWidgetCopy.path.xmlPath = ui->xmlPath->text();
//        break;

//    case TEXT_SIZE:
//        settingsMiniWidgetCopy.text.textSize = ui->textSize->value();
//        break;
//    case TITLE:
//        settingsMiniWidgetCopy.text.titleText = ui->title->text();
//        break;

//    case SPEED:
//        settingsMiniWidgetCopy.miscellanea.speed = ui->speed->value();
//        break;

//    case DYNAMICMINIWIDGET:
//        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidget = ui->dynamicMiniWidget->currentIndex();
//        break;
//    case DYNAMICMINIWIDGET_TIMER:
//        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidgetTimer = ui->dynamicMiniWidgetTimer->value();
//        break;
//    case PATTERN:
//        settingsMiniWidgetCopy.miscellanea.datePattern = ui->pattern->text();
//        break;


    default:
        break;
    }
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
