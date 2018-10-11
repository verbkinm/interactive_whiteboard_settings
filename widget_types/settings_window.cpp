#include "settings_window.h"
#include "ui_settings_window.h"

#include <QFileDialog>
#include <QDebug>

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


    setMaximum(this->children());

    setValues();
}
void Settings_window::setMaximum(QObjectList objectList)
{
    for (int i = 0; i < objectList.count(); ++i) {
        if( strcmp(objectList.at(i)->metaObject()->className(), "QSpinBox") == 0)
            qobject_cast<QSpinBox*>(objectList.at(i))->setMaximum(10000);
        else if( strcmp(objectList.at(i)->metaObject()->className(), "QSlider") == 0 )
            qobject_cast<QSlider*>(objectList.at(i))->setMaximum(10000);

        setMaximum(objectList.at(i)->children());
    }
}
void Settings_window::setValues()
{
//положение и размер
    ui->x->setValue(pSettingsMiniWidget->rect.x());
    ui->y->setValue(pSettingsMiniWidget->rect.y());
    ui->width->setValue(pSettingsMiniWidget->size.width());
    ui->height->setValue(pSettingsMiniWidget->size.height());
//рамка
    ui->border_width->setValue(pSettingsMiniWidget->border.borderWidth);
    ui->borderClick_width->setValue(pSettingsMiniWidget->border.borderClickWidth);
    ui->border_color->setText(pSettingsMiniWidget->border.borderColor);
    ui->borderClick_color->setText(pSettingsMiniWidget->border.borderClickColor);
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
