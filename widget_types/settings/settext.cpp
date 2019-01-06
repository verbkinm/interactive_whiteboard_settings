#include "settext.h"
#include "ui_settext.h"

SetText::SetText(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetText)
{
    ui->setupUi(this);

    ui->textColor->setTitle("Цвет текста:");

    connect(ui->textSize_scroll, SIGNAL(valueChanged(int)), this, SIGNAL(signalTextChange()));
    connect(ui->textColor, SIGNAL(signalColorChange()), this, SIGNAL(signalTextChange()));
}

SetText::~SetText()
{
    delete ui;
}

void SetText::setTitle(QString textTitle)
{
    ui->groupBox->setTitle(textTitle);
}

void SetText::setColor(QColor color)
{
    ui->textColor->setColor(color);
}

void SetText::setTextSize(uint size)
{
    ui->textSize_scroll->setValue(int(size));
}

QColor SetText::getColor()
{
    return ui->textColor->getColor();
}

uint SetText::getTextSize()
{
    return uint(ui->textSize_scroll->value());
}

QMap<QString, QVariant> SetText::getTextStyle()
{
    QMap<QString, QVariant> map;
    map["textSize"] = this->getTextSize();
    map["textColor"]= this->getColor().name(QColor::HexArgb);

    return map;
}

void SetText::hideTextSize()
{
    ui->label_size->setDisabled(true);
    ui->textSize_scroll->setDisabled(true);
    ui->textSize_spinbox->setDisabled(true);
}
