#include "setcolorrgba.h"
#include "ui_setcolorrgba.h"

SetColorRGBA::SetColorRGBA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetColorRGBA)
{
    ui->setupUi(this);

    connect(ui->red_scroll, SIGNAL(valueChanged(int)), this, SIGNAL(signalColorChange()));
    connect(ui->green_scroll, SIGNAL(valueChanged(int)), this, SIGNAL(signalColorChange()));
    connect(ui->blue_scroll, SIGNAL(valueChanged(int)), this, SIGNAL(signalColorChange()));
    connect(ui->alpha_scroll, SIGNAL(valueChanged(int)), this, SIGNAL(signalColorChange()));
}

SetColorRGBA::~SetColorRGBA()
{
    delete ui;
}

void SetColorRGBA::setTitle(QString textTitle)
{
    ui->groupBox->setTitle(textTitle);
}

void SetColorRGBA::setColor(QColor color)
{
    ui->red_scroll->setValue(color.red());
    ui->green_scroll->setValue(color.green());
    ui->blue_scroll->setValue(color.blue());
    ui->alpha_scroll->setValue(color.alpha());
}

QColor SetColorRGBA::getColor()
{
    QColor color(ui->red_scroll->value(),  ui->green_scroll->value(),  ui->blue_scroll->value(),  ui->alpha_scroll->value());
    return color;
}
