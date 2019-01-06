#include "settings_window.h"
#include "ui_settings_window.h"
#include "ui_setcolorrgba.h"

#include <QFileDialog>
#include <QDebug>
#include <QDesktopWidget>
#include <QColor>
#include <QMap>

Settings_window::Settings_window(const settingsMiniWidget &struct_settingsMiniWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_window)
{
    ui->setupUi(this);

//диалоговое окно выбора папки или файла
    connect(ui->iconPath_button,        SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->dirPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->txtPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->xmlPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );

//при смене данных в окне настроек - меняются значения в структуре settingsMiniWidgetCopy
//(нужно для дальнейшего сохранения изменившихся параметров виджета)
    connect(ui->x, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->y, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->width, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->height, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );

    connect(ui->border_width, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->borderClick_width, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );

//выбора цвета рамки
    connect(ui->borderColor,        SIGNAL(signalColorChange()), this, SLOT(slotChange()));
    connect(ui->borderClick_Color,  SIGNAL(signalColorChange()), this, SLOT(slotChange()));

    connect(ui->widgetName, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->type_list, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotChange()) );

    connect(ui->iconPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->dirPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->txtPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->xmlPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

    connect(ui->textWidget, SIGNAL(signalTextChange()), this, SLOT(slotChange()) );
    connect(ui->title, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->titleWidget, SIGNAL(signalTextChange()), this, SLOT(slotChange()));

    connect(ui->backgroundWidget, SIGNAL(signalColorChange()), this, SLOT(slotChange()));

    connect(ui->speed, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );

    connect(ui->dynamicMiniWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChange()) );
    connect(ui->dynamicMiniWidgetTimer, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->pattern, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

//указатель на переданную структуру
    pSettingsMiniWidget = &struct_settingsMiniWidget;
    settingsMiniWidgetCopy = *pSettingsMiniWidget;

//установка значений из настроек
    setValues();

//выключение параметров в окне настроек, которые не подходят для виджета
    selectType();
}
int Settings_window::getType(QString typeStr)
{
    if( typeStr == "x" )
        return  X;
    else if( typeStr == "y" )
        return Y;
    else if( typeStr == "width" )
        return WIDTH;
    else if( typeStr == "height" )
        return  HEIGHT;

    else if( typeStr == "border_width")
        return BORDER_WIDTH;
    else if( typeStr == "borderColor")
        return BORDER_COLOR;

    else if( typeStr == "borderClick_width")
        return BORDER_CLICK_WIDTH;
    else if( typeStr == "borderClick_Color")
        return BORDER_CLICK_COLOR;

    else if( typeStr == "type_list")
        return WIDGET_TYPE;
    else if( typeStr == "widgetName")
        return WIDGET_NAME;

    else if( typeStr == "iconPath")
        return ICON_PATH;
    else if( typeStr == "dirPath")
        return DIR_PATH;
    else if( typeStr == "txtPath")
        return TXT_PATH;
    else if( typeStr == "xmlPath")
        return XML_PATH;

    else if( typeStr == "textWidget")
        return TEXT;
    else if( typeStr == "title")
        return TITLE;
    else if( typeStr == "titleWidget")
        return TITLE_TEXT;

    else if( typeStr == "backgroundWidget")
        return BACKGROUND;

    else if( typeStr == "speed")
        return SPEED;

    else if( typeStr == "dynamicMiniWidget")
        return DYNAMIC_MINI_WIDGET;
    else if( typeStr == "dynamicMiniWidgetTimer")
        return DYNAMIC_MINI_WIDGET_TIMER;
    else if( typeStr == "pattern")
        return PATTERN;

    return -1;
}
void Settings_window::slotChange()
{
    switch (getType(sender()->objectName()) ) {
    case X:
        settingsMiniWidgetCopy.rect.setX(ui->x->value());
        emit signal_Change_Settings(X, QVariant(ui->x->value()));
        break;
    case Y:
        settingsMiniWidgetCopy.rect.setY(ui->y->value());
        emit signal_Change_Settings(Y, QVariant(ui->y->value()));
        break;
    case WIDTH:
        settingsMiniWidgetCopy.size.setWidth(ui->width->value());
        emit signal_Change_Settings(WIDTH, QVariant(ui->width->value()));
        break;
    case HEIGHT:
        settingsMiniWidgetCopy.size.setHeight(ui->height->value());
        emit signal_Change_Settings(HEIGHT, QVariant(ui->height->value()));
        break;
    case BORDER_WIDTH:
        settingsMiniWidgetCopy.border.borderWidth = ui->border_width->value();
        emit signal_Change_Settings(BORDER_WIDTH, QVariant(ui->border_width->value()));
        break;
    case BORDER_COLOR:
        settingsMiniWidgetCopy.border.borderColor = ui->borderColor->getColor().name(QColor::HexArgb);
        emit signal_Change_Settings( BORDER_COLOR, QVariant(ui->borderColor->getColor().name(QColor::HexArgb)) );
        break;
    case BORDER_CLICK_WIDTH:
        settingsMiniWidgetCopy.border.borderClickWidth = ui->borderClick_width->value();
        emit signal_Change_Settings(BORDER_CLICK_WIDTH, QVariant(ui->borderClick_width->value()));
        break;
    case BORDER_CLICK_COLOR:
        settingsMiniWidgetCopy.border.borderClickColor = ui->borderClick_Color->getColor().name(QColor::HexArgb);
        emit signal_Change_Settings( BORDER_CLICK_COLOR, QVariant(ui->borderClick_Color->getColor().name(QColor::HexArgb)) );
        break;

    case WIDGET_TYPE:
        settingsMiniWidgetCopy.miscellanea.type = ui->type_list->currentText();
        emit signal_Change_Settings(WIDGET_TYPE, QVariant( ui->type_list->currentText()));
        break;
    case WIDGET_NAME:
        settingsMiniWidgetCopy.widgetName = ui->widgetName->text();
        emit signal_Change_Settings(WIDGET_NAME, QVariant(ui->widgetName->text()));
        break;

    case ICON_PATH:
        settingsMiniWidgetCopy.path.iconPath = ui->iconPath->text();
        emit signal_Change_Settings(ICON_PATH, QVariant(ui->iconPath->text()));
        break;
    case DIR_PATH:
        settingsMiniWidgetCopy.path.dirPath = ui->dirPath->text();
        emit signal_Change_Settings(DIR_PATH, QVariant(ui->dirPath->text()));
        break;
    case TXT_PATH:
        settingsMiniWidgetCopy.path.txtPath = ui->txtPath->text();
        emit signal_Change_Settings(TXT_PATH, QVariant(ui->txtPath->text()));
        break;
    case XML_PATH:
        settingsMiniWidgetCopy.path.xmlPath = ui->xmlPath->text();
        emit signal_Change_Settings(XML_PATH, QVariant(ui->xmlPath->text()));
        break;

    case TEXT:
        settingsMiniWidgetCopy.text.textSize  = ui->textWidget->getTextStyle()["textSize"].toInt();
        settingsMiniWidgetCopy.text.textColor = ui->textWidget->getTextStyle()["textColor"].toString();
        emit signal_Change_Settings(TEXT, QVariant(ui->textWidget->getTextStyle()));
        break;
    case TITLE:
        settingsMiniWidgetCopy.text.titleText = ui->title->text();
        emit signal_Change_Settings(TITLE, QVariant(ui->title->text()));
        break;
    case TITLE_TEXT:
        settingsMiniWidgetCopy.text.titleTextSize = ui->titleWidget->getTextStyle()["textSize"].toInt();
        settingsMiniWidgetCopy.text.titleColor = ui->titleWidget->getTextStyle()["textColor"].toString();
        emit signal_Change_Settings(TITLE_TEXT, QVariant(ui->titleWidget->getTextStyle()));
        break;

    case BACKGROUND:
        settingsMiniWidgetCopy.background.backgroundColor = ui->backgroundWidget->getColor().name(QColor::HexArgb);
        emit signal_Change_Settings(BACKGROUND, QVariant(ui->backgroundWidget->getColor().name(QColor::HexArgb)) );
        break;

    case SPEED:
        settingsMiniWidgetCopy.miscellanea.speed = ui->speed->value();
        emit signal_Change_Settings(SPEED, QVariant(ui->speed->value()));
        break;

    case DYNAMIC_MINI_WIDGET:
        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidget = ui->dynamicMiniWidget->currentIndex();
        emit signal_Change_Settings(DYNAMIC_MINI_WIDGET, QVariant(ui->dynamicMiniWidget->currentIndex()));
        break;
    case DYNAMIC_MINI_WIDGET_TIMER:
        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidgetTimer = ui->dynamicMiniWidgetTimer->value();
        emit signal_Change_Settings(DYNAMIC_MINI_WIDGET_TIMER, QVariant(ui->dynamicMiniWidgetTimer->value()));
        break;
    case PATTERN:
        settingsMiniWidgetCopy.miscellanea.datePattern = ui->pattern->text();
        emit signal_Change_Settings(PATTERN, QVariant(ui->pattern->text()));
        break;


    default:
        break;
    }
}

void Settings_window::slotDynamicMiniWidgetChanged()
{
    if(ui->dynamicMiniWidget->currentText() == "true"){
        ui->dynamicMiniWidgetTimer->setEnabled(true);
        ui->horizontalSlider_dynamicMiniWidgetTimer->setEnabled(true);
    }
    else if(ui->dynamicMiniWidget->currentText() == "false"){
        ui->dynamicMiniWidgetTimer->setEnabled(false);
        ui->horizontalSlider_dynamicMiniWidgetTimer->setEnabled(false);
    }
}
void Settings_window::selectType()
{
    switch (pSettingsMiniWidget->pGetType(pSettingsMiniWidget->miscellanea.type)) {
        case LABEL:
            ui->groupBox_txtPath->hide();
            ui->groupBox_xmlPath->hide();
            ui->speed_tab->hide();
            ui->text_tab->hide();
            ui->groupBox_pattern->hide();
            ui->settings->removeTab(5);
            ui->settings->removeTab(5);
            break;
        case CLOCK:
            ui->textWidget->hideTextSize();
            ui->groupBox_title->hide();
            ui->settings->removeTab(3);
            ui->settings->removeTab(5);
            ui->settings->removeTab(5);
             break;
        case DATE:
            ui->groupBox_title->hide();
            ui->settings->removeTab(3);
            ui->settings->removeTab(5);
            ui->groupBox_dynamicMiniWidget->hide();
             break;
        case RUN_STRING:
            ui->groupBox_dirPath->hide();
            ui->groupBox_iconPath->hide();
            ui->groupBox_xmlPath->hide();
            ui->groupBox_title->hide();
            ui->settings->removeTab(7);
             break;
        case SCHEDULE:
            ui->groupBox_dirPath->hide();
            ui->groupBox_txtPath->hide();
            ui->groupBox_title->hide();
            ui->titleWidget->hide();
            ui->settings->removeTab(5);
            ui->settings->removeTab(5);
            ui->settings->removeTab(5);
            break;
        case IMAGE_VIEWER:
            ui->groupBox_xmlPath->hide();
            ui->groupBox_txtPath->hide();
            ui->groupBox_pattern->hide();
            ui->settings->removeTab(5);
            ui->settings->removeTab(5);
            break;
        case DONT_CLICK:
            ui->groupBox_xmlPath->hide();
            ui->groupBox_txtPath->hide();
            ui->groupBox_dirPath->hide();
            ui->settings->removeTab(4);
            ui->settings->removeTab(4);
            ui->settings->removeTab(4);
            ui->settings->removeTab(4);
            break;

        default:
            break;
    }
}
void Settings_window::setValues()
{
    QDesktopWidget desktop;
//положение и размер
    ui->x->setMaximum(desktop.width());
    ui->horizontalSlider_x->setMaximum(desktop.width());
    ui->horizontalSlider_x->setValue(pSettingsMiniWidget->rect.x());

    ui->y->setMaximum(desktop.height());
    ui->horizontalSlider_y->setMaximum(desktop.height());
    ui->horizontalSlider_y->setValue(pSettingsMiniWidget->rect.y());

    ui->width->setMaximum(desktop.width());
    ui->horizontalSlider_width->setMaximum(desktop.width());
    ui->horizontalSlider_width->setValue(pSettingsMiniWidget->size.width());

    ui->height->setMaximum(desktop.height());
    ui->horizontalSlider_height->setMaximum(desktop.height());
    ui->horizontalSlider_height->setValue(pSettingsMiniWidget->size.height());

//рамка
    ui->border_width->setValue(pSettingsMiniWidget->border.borderWidth);
    ui->borderClick_width->setValue(pSettingsMiniWidget->border.borderClickWidth);
//цвет рамки
    QColor borderColor(pSettingsMiniWidget->border.borderColor);
    ui->borderColor->setTitle("Цвет рамки:");
    ui->borderColor->setColor(borderColor);
//цвет рамки при нажатии
    QColor borderClickColor(pSettingsMiniWidget->border.borderClickColor);
    ui->borderClick_Color->setTitle("Цвет рамки:");
    ui->borderClick_Color->setColor(borderClickColor);

//тип
    ui->type_list->setCurrentText(pSettingsMiniWidget->miscellanea.type);
    ui->widgetName->setText(pSettingsMiniWidget->widgetName);

//путь
    ui->iconPath->setText(pSettingsMiniWidget->path.iconPath);
    ui->dirPath->setText(pSettingsMiniWidget->path.dirPath);
    ui->txtPath->setText(pSettingsMiniWidget->path.txtPath);
    ui->xmlPath->setText(pSettingsMiniWidget->path.xmlPath);

//текст внутри виджета
    ui->textWidget->setTitle("Текст:");
    ui->textWidget->setTextSize(uint(pSettingsMiniWidget->text.textSize));
    ui->textWidget->setColor(pSettingsMiniWidget->text.textColor);

//заголовок виджета
    ui->titleWidget->setTitle("");
    ui->titleWidget->setTextSize(uint(pSettingsMiniWidget->text.titleTextSize));
    ui->titleWidget->setColor(pSettingsMiniWidget->text.titleColor);
    ui->title->setText(pSettingsMiniWidget->text.titleText);

//фон
    ui->backgroundWidget->setTitle("Цвет фона:");
    ui->backgroundWidget->setColor(pSettingsMiniWidget->background.backgroundColor);

//скорость
    ui->speed->setValue(pSettingsMiniWidget->miscellanea.speed);

//разное
    ui->dynamicMiniWidget->setCurrentIndex(pSettingsMiniWidget->miscellanea.dynamicMiniWidget ? 1 : 0);
    ui->dynamicMiniWidgetTimer->setValue(pSettingsMiniWidget->miscellanea.dynamicMiniWidgetTimer);
    ui->dynamicMiniWidgetTimer->setEnabled(pSettingsMiniWidget->miscellanea.dynamicMiniWidget ? 1 : 0);
    ui->horizontalSlider_dynamicMiniWidgetTimer->setValue(pSettingsMiniWidget->miscellanea.dynamicMiniWidgetTimer);
    ui->horizontalSlider_dynamicMiniWidgetTimer->setEnabled(pSettingsMiniWidget->miscellanea.dynamicMiniWidget ? 1 : 0);
    ui->pattern->setText(pSettingsMiniWidget->miscellanea.datePattern);
    connect(ui->dynamicMiniWidget, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotDynamicMiniWidgetChanged()));



}
Settings_window::~Settings_window()
{
    delete ui;
}


void Settings_window::on_actionPath_triggered()
{
    QString fileName;

    if(sender()->objectName() == "dirPath_button")
    {
        fileName = QFileDialog::getExistingDirectory(this,
                                   QString::fromUtf8("Открыть папку"),
                                   QDir::homePath(),
                                   QFileDialog::ShowDirsOnly
                                   | QFileDialog::DontResolveSymlinks);
        if(!fileName.isEmpty())
            ui->dirPath->setText(fileName);
    }
    else if(sender()->objectName() == "xmlPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "XML (*.xml);;All files (*.*)");
        if(!fileName.isEmpty())
            ui->xmlPath->setText(fileName);
    }
    else if(sender()->objectName() == "iconPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "Images (*.png *.xpm *.jpg);;All files (*.*)");
        if(!fileName.isEmpty())
            ui->iconPath->setText(fileName);
    }
    else if(sender()->objectName() == "txtPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "TXT (*.txt);;All files (*.*)");
        if(!fileName.isEmpty())
            ui->txtPath->setText(fileName);
    }
}

