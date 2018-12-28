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
    borderClickLayout = new QVBoxLayout;
    borderClick->setLayout(borderClickLayout);

    pStruct_settingsMiniWidget = new settingsMiniWidget();

    create_or_recreate_object(struct_settingsMiniWidget);
}
void Mini_Widget::create_or_recreate_object(settingsMiniWidget *struct_settingsMiniWidget)
{
    *pStruct_settingsMiniWidget = *struct_settingsMiniWidget;

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
    result.setWidth( int(this->width() * 0.7) );
    result.setHeight( int(this->height() * 0.7) );

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
    borderClick->setStyleSheet("background-color:" + pStruct_settingsMiniWidget->border.borderClickColor + "; border-radius: 20px;");
    borderClick->resize(pStruct_settingsMiniWidget->size);
    borderClick->layout()->setMargin(pStruct_settingsMiniWidget->border.borderClickWidth);
//рамка
    if( border == nullptr){
        border              = new QWidget(this);
        borderClickLayout->addWidget(border);

        borderLayout = new QVBoxLayout;
        border->setLayout(borderLayout);
    }
    border->layout()->setMargin(pStruct_settingsMiniWidget->border.borderWidth);
    //example: border-color: rgba(255, 0, 0, 75%)
    border->setStyleSheet("background-color:" + pStruct_settingsMiniWidget->border.borderColor + ";");
}
void Mini_Widget::createLabelWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, border);
        borderLayout->addWidget(centralWidgetForMiniWidget);
    }
    else
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
}
void Mini_Widget::createClockWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, border);
        borderLayout->addWidget(centralWidgetForMiniWidget);

        pClock = new Clock(pStruct_settingsMiniWidget->text.textColor, \
                           pStruct_settingsMiniWidget->background.backgroundColor, \
                           centralWidgetForMiniWidget);

        centralWidgetForMiniWidget->addMainWidget(pClock);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
        pClock->create_or_recreate_object(pStruct_settingsMiniWidget->text.textColor, \
                                          pStruct_settingsMiniWidget->background.backgroundColor);
    }
}
void Mini_Widget::createDateWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, border);
        borderLayout->addWidget(centralWidgetForMiniWidget);

        pDate = new Date(pStruct_settingsMiniWidget->text.textColor, \
                         pStruct_settingsMiniWidget->text.textSize, \
                         pStruct_settingsMiniWidget->background.backgroundColor, \
                         pStruct_settingsMiniWidget->miscellanea.datePattern, \
                         centralWidgetForMiniWidget);

        centralWidgetForMiniWidget->addMainWidget(pDate);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(pStruct_settingsMiniWidget);
        pDate->create_or_recreate_object(pStruct_settingsMiniWidget->text.textColor, \
                                         pStruct_settingsMiniWidget->text.textSize, \
                                         pStruct_settingsMiniWidget->background.backgroundColor, \
                                         pStruct_settingsMiniWidget->miscellanea.datePattern);
    }
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
        centralWidgetForMiniWidget = new WidgetForMiniWidget(pStruct_settingsMiniWidget, border);
        borderLayout->addWidget(centralWidgetForMiniWidget);

        pRun_String = new Run_String(pStruct_settingsMiniWidget->text.textColor, \
                                     pStruct_settingsMiniWidget->text.textSize, \
                                     pStruct_settingsMiniWidget->background.backgroundColor, \
                                     text, \
                                     pStruct_settingsMiniWidget->miscellanea.speed, \
                                     centralWidgetForMiniWidget);

        centralWidgetForMiniWidget->addMainWidget(pRun_String);
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

void Mini_Widget::hideSettingsButton()
{
    buttonSettings->hide();
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

void Mini_Widget::slotSettingsButtonClicked()
{
    Settings_window *pSettingsWindow = new Settings_window(*pStruct_settingsMiniWidget);

    connect(pSettingsWindow, SIGNAL(signal_Change_Settings(int, QVariant)), this, SLOT(slotSettingsChange(int, QVariant)));

    this->hideSettingsButton();

    if (pSettingsWindow->exec()  ==   QDialog::Accepted){
        //связь в main_widget
        qDebug() << pSettingsWindow->settingsMiniWidgetCopy.miscellanea.type;
        *pStruct_settingsMiniWidget = pSettingsWindow->settingsMiniWidgetCopy;
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
        break;
    case Settings_window::HEIGHT:
        this->setFixedHeight(data.toInt());
        break;

    case Settings_window::BORDER_WIDTH:
        border->layout()->setMargin(data.toInt());
        break;
//    case Settings_window::BORDER_COLOR:

//    break;
    case Settings_window::BORDERCLICK_WIDTH:
        borderClick->layout()->setMargin(data.toInt());
        break;
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


//    if(borderClick != nullptr)
//        delete borderClick;

//    if(border != nullptr)
//        delete border;

//    if(buttonSettings != nullptr)
//        delete buttonSettings;

//    if(pStruct_settingsMiniWidget != nullptr)
//        delete pStruct_settingsMiniWidget;

//    if(pClock != nullptr)
//        delete pClock;

//    if(pDate != nullptr)
//        delete pDate;

//    if(centralWidgetForMiniWidget != nullptr)
//        delete centralWidgetForMiniWidget;

//    if(borderClickLayout != nullptr)
//        delete borderClickLayout;
//    if(borderLayout != nullptr)
//        delete borderLayout;
}
void Mini_Widget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
