#include "generalssettings_window.h"
#include "ui_generalssettings_window.h"

#include <QFileDialog>

GeneralsSettings_window::GeneralsSettings_window(QString background, uint timerSec, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneralsSettings_window)
{
    this->background    = background;
    this->timerSec      = timerSec;

    ui->setupUi(this);

    connect(ui->backgroundPath_button, SIGNAL(clicked()), this, SLOT(slotPathSet()) );

    setValues();
}

GeneralsSettings_window::~GeneralsSettings_window()
{
    delete ui;
}

QString GeneralsSettings_window::getBackgroundPath()
{
    return ui->backgroundPath->text();
}

uint GeneralsSettings_window::getTimerSec()
{
    return  uint(ui->timerSec_spinbox->value());
}

void GeneralsSettings_window::setValues()
{
    ui->backgroundPath->setText(background);
    ui->timerSec_horizontalSlider->setValue(int(timerSec));
}

void GeneralsSettings_window::slotPathSet()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this,
                            QString::fromUtf8("Выбрать файл"),
                            QDir::homePath(),
                            "Images (*.png *.xpm *.jpg);;All files (*.*)");
    if(!fileName.isEmpty())
        ui->backgroundPath->setText(fileName);

    emit signalBackgroundChancged(fileName);
}
