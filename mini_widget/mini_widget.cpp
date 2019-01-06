#include "mini_widget.h"

#include <QDebug>
#include <QEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QTextCodec>
#include <QMessageBox>

#include <QVariant>
#include <QStyleOption>

Mini_Widget::Mini_Widget(settingsMiniWidget *struct_settingsMiniWidget, \
                         QWidget *parent) : QWidget(parent)
{
    borderClick->setLayout(&borderClickLayout);

    create_or_recreate_object(struct_settingsMiniWidget);
}
void Mini_Widget::create_or_recreate_object(settingsMiniWidget *struct_settingsMiniWidget)
{
    mainStruct_settingsMiniWidget = *struct_settingsMiniWidget;

    generalSettings();

    switch (mainStruct_settingsMiniWidget.pGetType(mainStruct_settingsMiniWidget.miscellanea.type)) {
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
    buttonSettings.setIcon(QIcon(":/img/img/settings_button.png"));
    buttonDeleteWidget.setIcon(QIcon(":/img/delete"));

    QSize result;
    result.setWidth( int(this->width() * 0.4) );
    result.setHeight( int(this->height() * 0.4) );

    onClickWidget.setParent(this);

    onClickWidget.setFixedSize(this->size());
    onClickWidget.hide();

    onClickWidget.setStyleSheet("QWidget {color: rgb(255, 255, 255);"
                                  "border: 2px solid rgb(100,200,200); "
                                  "border-radius: 15px;"
                                  "background: rgba(100,100,100,70%); }");

    onClickWidgetLayout.addWidget(&buttonSettings, 0,0);
    onClickWidgetLayout.addWidget(&buttonDeleteWidget, 0,1);

    buttonSettings.setFixedSize(result);
    buttonSettings.setIconSize(result);
    buttonDeleteWidget.setFixedSize(result);
    buttonDeleteWidget.setIconSize(result);

    onClickWidgetLayout.setMargin(0);
    onClickWidget.setLayout(&onClickWidgetLayout);

    disconnect(&buttonSettings, SIGNAL(clicked(bool)), this, SLOT(slotSettingsButtonClicked()));
    connect(&buttonSettings, SIGNAL(clicked(bool)), this, SLOT(slotSettingsButtonClicked()));

    disconnect(&buttonDeleteWidget, SIGNAL(clicked(bool)), this, SLOT(slotDeleteButtonClicked()));
    connect(&buttonDeleteWidget, SIGNAL(clicked(bool)), this, SLOT(slotDeleteButtonClicked()));
}

QString Mini_Widget::txtFileToString(QString filePath)
{
    QString text;
    QFile file(filePath);

    if( !(file.open(QIODevice::ReadOnly)) || file.size() > 1000 * 1024)
        text = "ОШИБКА ОТКРЫТИЯ ФАЙЛА \"" + filePath + "\"!";
    else
        text = QString::fromUtf8(file.readAll());

    file.close();

    return text;
}
void Mini_Widget::generalSettings()
{
//рамка, которая будет появлятся при нажатии
    borderClick->setStyleSheet("background-color:" + mainStruct_settingsMiniWidget.border.borderClickColor + "; border-radius: 20px;");
    borderClick->setFixedSize(mainStruct_settingsMiniWidget.size);
    borderClick->layout()->setMargin(mainStruct_settingsMiniWidget.border.borderClickWidth);
//рамка
    borderClickLayout.addWidget(&border);
    border.setLayout(&borderLayout);

    border.layout()->setMargin(mainStruct_settingsMiniWidget.border.borderWidth);
    //example: border-color: rgba(255, 0, 0, 75%)
    border.setStyleSheet("background-color:" + mainStruct_settingsMiniWidget.border.borderColor + ";");
}
void Mini_Widget::createLabelWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&mainStruct_settingsMiniWidget, &border);
        borderLayout.addWidget(centralWidgetForMiniWidget);
    }
    else
        centralWidgetForMiniWidget->create_or_recreate_object(&mainStruct_settingsMiniWidget);
}
void Mini_Widget::createClockWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&mainStruct_settingsMiniWidget, &border);
        borderLayout.addWidget(centralWidgetForMiniWidget);

        pClock = new Clock(mainStruct_settingsMiniWidget.text.textColor, \
                           mainStruct_settingsMiniWidget.background.backgroundColor, \
                           centralWidgetForMiniWidget);

        pClock->setObjectName("clock");

        centralWidgetForMiniWidget->addMainWidget(pClock);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&mainStruct_settingsMiniWidget);
        pClock->create_or_recreate_object(mainStruct_settingsMiniWidget.text.textColor, \
                                          mainStruct_settingsMiniWidget.background.backgroundColor);
    }
}
void Mini_Widget::createDateWidget()
{
    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&mainStruct_settingsMiniWidget, &border);
        borderLayout.addWidget(centralWidgetForMiniWidget);

        pDate = new Date(mainStruct_settingsMiniWidget.text.textColor, \
                         mainStruct_settingsMiniWidget.text.textSize, \
                         mainStruct_settingsMiniWidget.background.backgroundColor, \
                         mainStruct_settingsMiniWidget.miscellanea.datePattern, \
                         centralWidgetForMiniWidget);
        pDate->setObjectName("date");

        centralWidgetForMiniWidget->addMainWidget(pDate);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&mainStruct_settingsMiniWidget);
        pDate->create_or_recreate_object(mainStruct_settingsMiniWidget.text.textColor, \
                                         mainStruct_settingsMiniWidget.text.textSize, \
                                         mainStruct_settingsMiniWidget.background.backgroundColor, \
                                         mainStruct_settingsMiniWidget.miscellanea.datePattern);
    }
}
void Mini_Widget::createRunStringWidget()
{
    QString text = txtFileToString(mainStruct_settingsMiniWidget.path.txtPath);

    if(centralWidgetForMiniWidget == nullptr){
        centralWidgetForMiniWidget = new WidgetForMiniWidget(&mainStruct_settingsMiniWidget, &border);
        borderLayout.addWidget(centralWidgetForMiniWidget);

        pRun_String = new Run_String(mainStruct_settingsMiniWidget.text.textColor, \
                                     mainStruct_settingsMiniWidget.text.textSize, \
                                     mainStruct_settingsMiniWidget.background.backgroundColor, \
                                     text, \
                                     mainStruct_settingsMiniWidget.miscellanea.speed, \
                                     centralWidgetForMiniWidget);
        pRun_String->setObjectName("run_string");

        centralWidgetForMiniWidget->addMainWidget(pRun_String);
    }
    else
    {
        centralWidgetForMiniWidget->create_or_recreate_object(&mainStruct_settingsMiniWidget);
        pRun_String->create_or_recreate_object(mainStruct_settingsMiniWidget.text.textColor, \
                                               mainStruct_settingsMiniWidget.text.textSize, \
                                               mainStruct_settingsMiniWidget.background.backgroundColor, \
                                               text, \
                                               mainStruct_settingsMiniWidget.miscellanea.speed);
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
    onClickWidget.hide();
}

bool Mini_Widget::event(QEvent *event)
{
//    qDebug() << event->type();
    if(event->type() == QEvent::MouseButtonRelease){
//        qDebug() << this->objectName() << event->type();
        onClickWidget.setVisible(true);
    }

    return QWidget::event(event);
}

void Mini_Widget::slotSettingsButtonClicked()
{
    Settings_window *pSettingsWindow = new Settings_window(mainStruct_settingsMiniWidget);

    connect(pSettingsWindow, SIGNAL(signal_Change_Settings(int, QVariant)), this, SLOT(slotSettingsChange(int, QVariant)));

    this->hideSettingsButton();

    if (pSettingsWindow->exec()  ==   QDialog::Accepted){
        //связь в main_widget
        mainStruct_settingsMiniWidget = pSettingsWindow->settingsMiniWidgetCopy;
        emit signalSaveSettings(pSettingsWindow->settingsMiniWidgetCopy);
    }
    else
        emit signalSaveSettings(mainStruct_settingsMiniWidget);

    delete pSettingsWindow;
}

void Mini_Widget::slotDeleteButtonClicked()
{
    QMessageBox mesg(QMessageBox::Question,  \
                     QString::fromUtf8("Удаление виджета"), \
                     QString::fromUtf8("Вы уверены, что хотиде удалить данный виджет?"), QMessageBox::Yes | QMessageBox::No );
    mesg.setWindowIcon(QIcon(":img/delete"));

    if (mesg.exec() == QMessageBox::Yes)
        emit signalDeleteWidget();
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
        border.layout()->setMargin(data.toInt());
        break;
    case Settings_window::BORDER_COLOR:
        border.setStyleSheet("background-color:" + data.toString() + ";");
    break;
    case Settings_window::BORDER_CLICK_WIDTH:
        borderClick->layout()->setMargin(data.toInt());
        break;
    case Settings_window::BORDER_CLICK_COLOR:
        borderClick->setStyleSheet("background-color:" + data.toString() + "; border-radius: 20px;");
        break;

    case Settings_window::ICON_PATH:
        centralWidgetForMiniWidget->setIconPath(data.toString());
        break;
    case Settings_window::DIR_PATH:
        centralWidgetForMiniWidget->setDirPath(data.toString());
        break;
    case Settings_window::TXT_PATH:
        centralWidgetForMiniWidget->setText(txtFileToString(data.toString()) );
        break;
    case Settings_window::XML_PATH:
//        settingsMiniWidgetCopy.path.xmlPath = ui->xmlPath->text();
        break;

    case Settings_window::TEXT:
        centralWidgetForMiniWidget->setStyleMainWidget(data.toMap());
        break;
    case Settings_window::TITLE:
        centralWidgetForMiniWidget->setTitleText(data.toString());
        break;
    case Settings_window::TITLE_TEXT:
        centralWidgetForMiniWidget->setTitleStyle(data.toMap());
        break;

    case Settings_window::BACKGROUND:
        centralWidgetForMiniWidget->setBackgroundMainWidget(data.toString());
        break;

    case Settings_window::SPEED:
        centralWidgetForMiniWidget->setSpeedMainWidget(data.toInt());
        break;

    case Settings_window::DYNAMIC_MINI_WIDGET:
        centralWidgetForMiniWidget->dynamicWidget("", data.toBool());
        break;
    case Settings_window::DYNAMIC_MINI_WIDGET_TIMER:
        centralWidgetForMiniWidget->setTimerInterval(uint(data.toInt()));
//        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidgetTimer = ui->dynamicMiniWidgetTimer->value();
        break;
    case Settings_window::PATTERN:
        centralWidgetForMiniWidget->setPatternMainWidget(data.toString());
        break;


    default:
        break;
    }
}
Mini_Widget::~Mini_Widget()
{
    if(pClock != nullptr)
        delete pClock;

    if(pDate != nullptr)
        delete pDate;

    if(pRun_String != nullptr)
        delete pRun_String;

    if(centralWidgetForMiniWidget != nullptr)
        delete centralWidgetForMiniWidget;

}
void Mini_Widget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
