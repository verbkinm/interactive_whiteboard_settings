#include "settings_window.h"
#include "ui_settings_window.h"

#include <QFileDialog>
#include <QDebug>

Settings_window::Settings_window(QWidget *parent) :
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
    QColor color = QColorDialog::getColor(Qt::white, this, "Выбор цвета", QColorDialog::ShowAlphaChannel);
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
