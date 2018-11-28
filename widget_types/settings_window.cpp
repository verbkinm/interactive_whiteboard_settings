#include "settings_window.h"
#include "ui_settings_window.h"

#include <QFileDialog>
#include <QDebug>
#include <QDesktopWidget>

Settings_window::Settings_window(const settingsMiniWidget &struct_settingsMiniWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_window)
{
    ui->setupUi(this);

//диалоговое окно выбора цвета
    connect(ui->border_setColor,        SIGNAL(clicked()), this, SLOT(on_actionBorderColor_triggered()) );
    connect(ui->borderClick_setColor,   SIGNAL(clicked()), this, SLOT(on_actionBorderColor_triggered()) );

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
    connect(ui->border_color, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->borderClick_width, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->borderClick_color, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

    connect(ui->iconPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->dirPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->txtPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );
    connect(ui->xmlPath, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

    connect(ui->textSize, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->title, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

    connect(ui->speed, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );

    connect(ui->dynamicMiniWidget, SIGNAL(currentIndexChanged(int)), this, SLOT(slotChange()) );
    connect(ui->dynamicMiniWidgetTimer, SIGNAL(valueChanged(int)), this, SLOT(slotChange()) );
    connect(ui->pattern, SIGNAL(textChanged(QString)), this, SLOT(slotChange()) );

//указатель на переданную структуру
    pSettingsMiniWidget = &struct_settingsMiniWidget;

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
    else if( typeStr == "border_color")
        return BORDER_COLOR;
    else if( typeStr == "borderClick_width")
        return BORDERCLICK_WIDTH;
    else if( typeStr == "borderClick_color")
        return BORDERCLICK_COLOR;

    else if( typeStr == "iconPath")
        return ICON_PATH;
    else if( typeStr == "dirPath")
        return DIR_PATH;
    else if( typeStr == "txtPath")
        return TXT_PATH;
    else if( typeStr == "xmlPath")
        return XML_PATH;

    else if( typeStr == "textSize")
        return TEXT_SIZE;
    else if( typeStr == "title")
        return TITLE;

    else if( typeStr == "speed")
        return SPEED;

    else if( typeStr == "dynamicMiniWidget")
        return DYNAMICMINIWIDGET;
    else if( typeStr == "dynamicMiniWidgetTimer")
        return DYNAMICMINIWIDGET_TIMER;
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
        settingsMiniWidgetCopy.border.borderColor = ui->border_color->text();
        emit signal_Change_Settings(BORDER_COLOR, QVariant(ui->border_color->text()) );
        break;
    case BORDERCLICK_WIDTH:
        settingsMiniWidgetCopy.border.borderClickWidth = ui->borderClick_width->value();
        emit signal_Change_Settings(BORDERCLICK_WIDTH, QVariant(ui->borderClick_width->value()));
        break;
    case BORDERCLICK_COLOR:
        settingsMiniWidgetCopy.border.borderClickColor= ui->borderClick_color->text();
        emit signal_Change_Settings(BORDERCLICK_COLOR, QVariant(ui->borderClick_color->text()));
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

    case TEXT_SIZE:
        settingsMiniWidgetCopy.text.textSize = ui->textSize->value();
        emit signal_Change_Settings(TEXT_SIZE, QVariant(ui->textSize->value()));
        break;
    case TITLE:
        settingsMiniWidgetCopy.text.titleText = ui->title->text();
        emit signal_Change_Settings(TITLE, QVariant(ui->title->text()));
        break;

    case SPEED:
        settingsMiniWidgetCopy.miscellanea.speed = ui->speed->value();
        emit signal_Change_Settings(SPEED, QVariant(ui->speed->value()));
        break;

    case DYNAMICMINIWIDGET:
        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidget = ui->dynamicMiniWidget->currentIndex();
        emit signal_Change_Settings(DYNAMICMINIWIDGET, QVariant(ui->dynamicMiniWidget->currentIndex()));
        break;
    case DYNAMICMINIWIDGET_TIMER:
        settingsMiniWidgetCopy.miscellanea.dynamicMiniWidgetTimer = ui->dynamicMiniWidgetTimer->value();
        emit signal_Change_Settings(DYNAMICMINIWIDGET_TIMER, QVariant(ui->dynamicMiniWidgetTimer->value()));
        break;
    case PATTERN:
        settingsMiniWidgetCopy.miscellanea.datePattern = ui->pattern->text();
        emit signal_Change_Settings(PATTERN, QVariant(ui->pattern->text()));
        break;


    default:
        break;
    }
}
void Settings_window::selectType()
{
    switch (pSettingsMiniWidget->pGetType(pSettingsMiniWidget->miscellanea.type)) {
        case LABEL:
            ui->groupBox_dirPath->setDisabled(true);
            ui->groupBox_txtPath->setDisabled(true);
            ui->groupBox_xmlPath->setDisabled(true);
            ui->speed_tab->setDisabled(true);
            ui->text_tab->setDisabled(true);
            ui->other_tab->setDisabled(true);
            break;
        case CLOCK:
            ui->path_tab->setDisabled(true);
            ui->speed_tab->setDisabled(true);
            ui->text_tab->setDisabled(true);
            ui->other_tab->setDisabled(true);
             break;
        case DATE:
            ui->path_tab->setDisabled(true);
            ui->speed_tab->setDisabled(true);
            ui->title->setDisabled(true);
            ui->groupBox_dynamicMiniWidget->setDisabled(true);
             break;
        case RUN_STRING:
            ui->groupBox_dirPath->setDisabled(true);
            ui->groupBox_iconPath->setDisabled(true);
            ui->groupBox_xmlPath->setDisabled(true);
            ui->other_tab->setDisabled(true);
            ui->title->setDisabled(true);
             break;
        case SCHEDULE:
            ui->groupBox_dirPath->setDisabled(true);
            ui->groupBox_txtPath->setDisabled(true);
            ui->speed_tab->setDisabled(true);
            ui->other_tab->setDisabled(true);
            break;
        case IMAGE_VIEWER:
            ui->groupBox_xmlPath->setDisabled(true);
            ui->groupBox_txtPath->setDisabled(true);
            ui->speed_tab->setDisabled(true);
            ui->pattern->setDisabled(true);
            break;
        case DONT_CLICK:
            ui->speed_tab->setDisabled(true);
            ui->text_tab->setDisabled(true);
            ui->other_tab->setDisabled(true);
            ui->groupBox_txtPath->setDisabled(true);
            ui->groupBox_title->setDisabled(true);
            ui->groupBox_dirPath->setDisabled(true);
            ui->groupBox_xmlPath->setDisabled(true);
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
    ui->x->setValue(pSettingsMiniWidget->rect.x());

    ui->y->setMaximum(desktop.height());
    ui->horizontalSlider_y->setMaximum(desktop.height());
    ui->y->setValue(pSettingsMiniWidget->rect.y());

    ui->width->setMaximum(desktop.width());
    ui->horizontalSlider_width->setMaximum(desktop.width());
    ui->width->setValue(pSettingsMiniWidget->size.width());

    ui->height->setMaximum(desktop.height());
    ui->horizontalSlider_height->setMaximum(desktop.height());
    ui->height->setValue(pSettingsMiniWidget->size.height());

//рамка
    ui->border_width->setValue(pSettingsMiniWidget->border.borderWidth);
    ui->borderClick_width->setValue(pSettingsMiniWidget->border.borderClickWidth);
    ui->border_color->setText(pSettingsMiniWidget->border.borderColor);
    ui->borderClick_color->setText(pSettingsMiniWidget->border.borderClickColor);

//тип
    ui->type_list->setCurrentText(pSettingsMiniWidget->miscellanea.type);

//путь
    ui->iconPath->setText(pSettingsMiniWidget->path.iconPath);
    ui->dirPath->setText(pSettingsMiniWidget->path.dirPath);
    ui->txtPath->setText(pSettingsMiniWidget->path.txtPath);
    ui->xmlPath->setText(pSettingsMiniWidget->path.xmlPath);

//текст
    ui->textSize->setValue(pSettingsMiniWidget->text.textSize);
    ui->title->setText(pSettingsMiniWidget->text.titleText);

//скорость
    ui->speed->setValue(pSettingsMiniWidget->miscellanea.speed);

//разное
    ui->dynamicMiniWidget->setCurrentIndex(pSettingsMiniWidget->miscellanea.dynamicMiniWidget ? 1 : 0);
    ui->dynamicMiniWidgetTimer->setValue(pSettingsMiniWidget->miscellanea.dynamicMiniWidgetTimer);
    ui->pattern->setText(pSettingsMiniWidget->miscellanea.datePattern);

}
QColor Settings_window::toColor(QString str)
{
    QString result = str;

    result.remove("rgba(");
    result.remove(")");
    result.remove(" ");

    QStringList list = result.split(",");

    QColor color(list.at(0).toInt(), \
                 list.at(1).toInt(), \
                 list.at(2).toInt(), \
                 list.at(3).toInt() );

    return color;
}
Settings_window::~Settings_window()
{
    delete ui;
}

void Settings_window::on_actionBorderColor_triggered()
{
    QString colorTxt;

    if(sender()->objectName() == "border_setColor")
       colorTxt = ui->border_color->text();
    else if(sender()->objectName() == "borderClick_setColor")
        colorTxt = ui->borderClick_color->text();

    QColor color = QColorDialog::getColor(toColor(colorTxt), \
                                          this, \
                                          "Выбор цвета", \
                                          QColorDialog::ShowAlphaChannel);
    if ( color.isValid() ){
        QString result = "rgba(" + QString::number(color.red()) + \
                        "," + QString::number(color.green()) + \
                        "," + QString::number(color.blue()) + \
                        "," + QString::number(color.alpha()) + \
                        ")";
        if(sender()->objectName() == "border_setColor")
            ui->border_color->setText(result);
        else if(sender()->objectName() == "borderClick_setColor")
            ui->borderClick_color->setText(result);
    }
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
        ui->dirPath->setText(fileName);
    }
    else if(sender()->objectName() == "xmlPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "XML (*.xml);;All files (*.*)");
        ui->xmlPath->setText(fileName);
    }
    else if(sender()->objectName() == "iconPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "Images (*.png *.xpm *.jpg);;All files (*.*)");
        ui->iconPath->setText(fileName);
    }
    else if(sender()->objectName() == "txtPath_button")
    {
        fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "TXT (*.txt);;All files (*.*)");
        ui->txtPath->setText(fileName);
    }
}
