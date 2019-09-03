/********************************************************************************
** Form generated from reading UI file 'settext.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTEXT_H
#define UI_SETTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget_types/settings/setcolorrgba.h"

QT_BEGIN_NAMESPACE

class Ui_SetText
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpinBox *textSize_spinbox;
    QSlider *textSize_scroll;
    QLabel *label_size;
    SetColorRGBA *textColor;

    void setupUi(QWidget *SetText)
    {
        if (SetText->objectName().isEmpty())
            SetText->setObjectName(QStringLiteral("SetText"));
        SetText->resize(400, 300);
        verticalLayout = new QVBoxLayout(SetText);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(SetText);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textSize_spinbox = new QSpinBox(groupBox);
        textSize_spinbox->setObjectName(QStringLiteral("textSize_spinbox"));
        textSize_spinbox->setMinimumSize(QSize(75, 0));
        textSize_spinbox->setReadOnly(true);
        textSize_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(textSize_spinbox, 1, 0, 1, 1);

        textSize_scroll = new QSlider(groupBox);
        textSize_scroll->setObjectName(QStringLiteral("textSize_scroll"));
        textSize_scroll->setMinimum(1);
        textSize_scroll->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(textSize_scroll, 1, 1, 1, 1);

        label_size = new QLabel(groupBox);
        label_size->setObjectName(QStringLiteral("label_size"));

        gridLayout->addWidget(label_size, 0, 0, 1, 2);

        textColor = new SetColorRGBA(groupBox);
        textColor->setObjectName(QStringLiteral("textColor"));

        gridLayout->addWidget(textColor, 3, 0, 1, 2);


        verticalLayout->addWidget(groupBox);


        retranslateUi(SetText);
        QObject::connect(textSize_scroll, SIGNAL(valueChanged(int)), textSize_spinbox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(SetText);
    } // setupUi

    void retranslateUi(QWidget *SetText)
    {
        SetText->setWindowTitle(QApplication::translate("SetText", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SetText", "text:", Q_NULLPTR));
        label_size->setText(QApplication::translate("SetText", "\320\240\320\260\320\267\320\274\320\265\321\200 \321\202\320\265\320\272\321\201\321\202\320\260:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetText: public Ui_SetText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTEXT_H
