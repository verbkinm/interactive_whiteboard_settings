#include "settings_window.h"
#include "ui_settings_window.h"

#include <QFileDialog>
#include <QDebug>
#include <QDesktopWidget>

Settings_window::Settings_window(settingsMiniWidget &struct_settingsMiniWidget, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings_window)
{
    ui->setupUi(this);

    connect(ui->border_setColor,        SIGNAL(clicked()), this, SLOT(on_actionBorderColor_triggered()) );
    connect(ui->borderClick_setColor,   SIGNAL(clicked()), this, SLOT(on_actionBorderColor_triggered()) );

    connect(ui->iconPath_button,        SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->dirPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->txtPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );
    connect(ui->xmlPath_button,         SIGNAL(clicked()), this, SLOT(on_actionPath_triggered()) );

    pSettingsMiniWidget = &struct_settingsMiniWidget;

    setValues();
    selectType();
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
//                createDontClickWidget();
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
void Settings_window::slotBorderColor()
{


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
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файл"),
                                QDir::homePath(),
                                "Images (*.png *.xpm *.jpg);;All files (*.*)");

    if(sender()->objectName() == "iconPath_button")
        ui->iconPath->setText(fileName);
    else if(sender()->objectName() == "dirPath_button")
        ui->dirPath->setText(fileName);
    if(sender()->objectName() == "txtPath_button")
        ui->txtPath->setText(fileName);
    else if(sender()->objectName() == "xmlPath_button")
        ui->xmlPath->setText(fileName);
}
