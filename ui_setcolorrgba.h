/********************************************************************************
** Form generated from reading UI file 'setcolorrgba.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCOLORRGBA_H
#define UI_SETCOLORRGBA_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetColorRGBA
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QSlider *alpha_scroll;
    QSlider *green_scroll;
    QSpinBox *alpha_spinbox;
    QSpinBox *blue_spinbox;
    QLabel *label_blue;
    QLabel *label_alpha;
    QSpinBox *red_spinbox;
    QLabel *label_green;
    QLabel *label_red;
    QSpinBox *green_spinbox;
    QSlider *blue_scroll;
    QSlider *red_scroll;

    void setupUi(QWidget *SetColorRGBA)
    {
        if (SetColorRGBA->objectName().isEmpty())
            SetColorRGBA->setObjectName(QStringLiteral("SetColorRGBA"));
        SetColorRGBA->resize(499, 281);
        gridLayout = new QGridLayout(SetColorRGBA);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(SetColorRGBA);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        alpha_scroll = new QSlider(groupBox);
        alpha_scroll->setObjectName(QStringLiteral("alpha_scroll"));
        alpha_scroll->setMaximum(255);
        alpha_scroll->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(alpha_scroll, 4, 3, 1, 1);

        green_scroll = new QSlider(groupBox);
        green_scroll->setObjectName(QStringLiteral("green_scroll"));
        green_scroll->setMaximum(255);
        green_scroll->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(green_scroll, 2, 3, 1, 1);

        alpha_spinbox = new QSpinBox(groupBox);
        alpha_spinbox->setObjectName(QStringLiteral("alpha_spinbox"));
        alpha_spinbox->setMinimumSize(QSize(75, 0));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        alpha_spinbox->setFont(font);
        alpha_spinbox->setReadOnly(true);
        alpha_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        alpha_spinbox->setMaximum(255);

        gridLayout_10->addWidget(alpha_spinbox, 4, 2, 1, 1);

        blue_spinbox = new QSpinBox(groupBox);
        blue_spinbox->setObjectName(QStringLiteral("blue_spinbox"));
        blue_spinbox->setMinimumSize(QSize(75, 0));
        blue_spinbox->setFont(font);
        blue_spinbox->setReadOnly(true);
        blue_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        blue_spinbox->setMaximum(255);

        gridLayout_10->addWidget(blue_spinbox, 3, 2, 1, 1);

        label_blue = new QLabel(groupBox);
        label_blue->setObjectName(QStringLiteral("label_blue"));

        gridLayout_10->addWidget(label_blue, 3, 0, 1, 1);

        label_alpha = new QLabel(groupBox);
        label_alpha->setObjectName(QStringLiteral("label_alpha"));

        gridLayout_10->addWidget(label_alpha, 4, 0, 1, 1);

        red_spinbox = new QSpinBox(groupBox);
        red_spinbox->setObjectName(QStringLiteral("red_spinbox"));
        red_spinbox->setMinimumSize(QSize(75, 0));
        red_spinbox->setFont(font);
        red_spinbox->setWrapping(false);
        red_spinbox->setFrame(true);
        red_spinbox->setReadOnly(true);
        red_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        red_spinbox->setKeyboardTracking(true);
        red_spinbox->setMaximum(255);

        gridLayout_10->addWidget(red_spinbox, 1, 2, 1, 1);

        label_green = new QLabel(groupBox);
        label_green->setObjectName(QStringLiteral("label_green"));

        gridLayout_10->addWidget(label_green, 2, 0, 1, 1);

        label_red = new QLabel(groupBox);
        label_red->setObjectName(QStringLiteral("label_red"));

        gridLayout_10->addWidget(label_red, 1, 0, 1, 1);

        green_spinbox = new QSpinBox(groupBox);
        green_spinbox->setObjectName(QStringLiteral("green_spinbox"));
        green_spinbox->setMinimumSize(QSize(75, 0));
        green_spinbox->setFont(font);
        green_spinbox->setReadOnly(true);
        green_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);
        green_spinbox->setMaximum(255);

        gridLayout_10->addWidget(green_spinbox, 2, 2, 1, 1);

        blue_scroll = new QSlider(groupBox);
        blue_scroll->setObjectName(QStringLiteral("blue_scroll"));
        blue_scroll->setMaximum(255);
        blue_scroll->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(blue_scroll, 3, 3, 1, 1);

        red_scroll = new QSlider(groupBox);
        red_scroll->setObjectName(QStringLiteral("red_scroll"));
        red_scroll->setMaximum(255);
        red_scroll->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(red_scroll, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(SetColorRGBA);
        QObject::connect(alpha_scroll, SIGNAL(valueChanged(int)), alpha_spinbox, SLOT(setValue(int)));
        QObject::connect(blue_scroll, SIGNAL(valueChanged(int)), blue_spinbox, SLOT(setValue(int)));
        QObject::connect(green_scroll, SIGNAL(valueChanged(int)), green_spinbox, SLOT(setValue(int)));
        QObject::connect(red_scroll, SIGNAL(valueChanged(int)), red_spinbox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(SetColorRGBA);
    } // setupUi

    void retranslateUi(QWidget *SetColorRGBA)
    {
        SetColorRGBA->setWindowTitle(QApplication::translate("SetColorRGBA", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SetColorRGBA", "text:", Q_NULLPTR));
        label_blue->setText(QApplication::translate("SetColorRGBA", "Blue: ", Q_NULLPTR));
        label_alpha->setText(QApplication::translate("SetColorRGBA", "Alpha: ", Q_NULLPTR));
        label_green->setText(QApplication::translate("SetColorRGBA", "Green: ", Q_NULLPTR));
        label_red->setText(QApplication::translate("SetColorRGBA", "Red: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetColorRGBA: public Ui_SetColorRGBA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCOLORRGBA_H
