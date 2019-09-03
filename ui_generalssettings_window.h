/********************************************************************************
** Form generated from reading UI file 'generalssettings_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSSETTINGS_WINDOW_H
#define UI_GENERALSSETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GeneralsSettings_window
{
public:
    QGridLayout *gridLayout;
    QPushButton *save;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *backgroundPath;
    QPushButton *backgroundPath_button;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *timerSec_spinbox;
    QSlider *timerSec_horizontalSlider;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout;
    QCheckBox *fuulScreen;
    QCheckBox *showCursor;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel;

    void setupUi(QDialog *GeneralsSettings_window)
    {
        if (GeneralsSettings_window->objectName().isEmpty())
            GeneralsSettings_window->setObjectName(QStringLiteral("GeneralsSettings_window"));
        GeneralsSettings_window->resize(492, 351);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/settings_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        GeneralsSettings_window->setWindowIcon(icon);
        GeneralsSettings_window->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(GeneralsSettings_window);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        save = new QPushButton(GeneralsSettings_window);
        save->setObjectName(QStringLiteral("save"));

        gridLayout->addWidget(save, 1, 1, 1, 1);

        groupBox = new QGroupBox(GeneralsSettings_window);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        backgroundPath = new QLineEdit(groupBox_2);
        backgroundPath->setObjectName(QStringLiteral("backgroundPath"));
        backgroundPath->setReadOnly(true);

        horizontalLayout->addWidget(backgroundPath);

        backgroundPath_button = new QPushButton(groupBox_2);
        backgroundPath_button->setObjectName(QStringLiteral("backgroundPath_button"));
        backgroundPath_button->setMaximumSize(QSize(28, 16777215));

        horizontalLayout->addWidget(backgroundPath_button);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        timerSec_spinbox = new QSpinBox(groupBox_3);
        timerSec_spinbox->setObjectName(QStringLiteral("timerSec_spinbox"));
        timerSec_spinbox->setMinimumSize(QSize(75, 0));
        timerSec_spinbox->setMaximumSize(QSize(0, 16777215));
        timerSec_spinbox->setReadOnly(true);
        timerSec_spinbox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_2->addWidget(timerSec_spinbox);

        timerSec_horizontalSlider = new QSlider(groupBox_3);
        timerSec_horizontalSlider->setObjectName(QStringLiteral("timerSec_horizontalSlider"));
        timerSec_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timerSec_horizontalSlider);


        gridLayout_2->addWidget(groupBox_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(false);
        verticalLayout = new QVBoxLayout(groupBox_4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fuulScreen = new QCheckBox(groupBox_4);
        fuulScreen->setObjectName(QStringLiteral("fuulScreen"));

        verticalLayout->addWidget(fuulScreen);

        showCursor = new QCheckBox(groupBox_4);
        showCursor->setObjectName(QStringLiteral("showCursor"));
        showCursor->setAutoRepeat(false);

        verticalLayout->addWidget(showCursor);


        gridLayout_2->addWidget(groupBox_4, 3, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        cancel = new QPushButton(GeneralsSettings_window);
        cancel->setObjectName(QStringLiteral("cancel"));

        gridLayout->addWidget(cancel, 1, 2, 1, 1);


        retranslateUi(GeneralsSettings_window);
        QObject::connect(timerSec_horizontalSlider, SIGNAL(valueChanged(int)), timerSec_spinbox, SLOT(setValue(int)));
        QObject::connect(save, SIGNAL(clicked()), GeneralsSettings_window, SLOT(accept()));
        QObject::connect(cancel, SIGNAL(clicked()), GeneralsSettings_window, SLOT(reject()));

        QMetaObject::connectSlotsByName(GeneralsSettings_window);
    } // setupUi

    void retranslateUi(QDialog *GeneralsSettings_window)
    {
        GeneralsSettings_window->setWindowTitle(QApplication::translate("GeneralsSettings_window", "\320\236\321\201\320\275\320\276\320\262\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", Q_NULLPTR));
        save->setText(QApplication::translate("GeneralsSettings_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GeneralsSettings_window", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GeneralsSettings_window", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \321\204\320\276\320\275\320\260:", Q_NULLPTR));
        backgroundPath_button->setText(QApplication::translate("GeneralsSettings_window", "...", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("GeneralsSettings_window", "\320\242\320\260\320\271\320\274\320\265\321\200 \320\267\320\260\320\272\321\200\321\213\321\202\320\270\321\217 \320\276\320\272\320\276\320\275:", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("GeneralsSettings_window", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265:", Q_NULLPTR));
        fuulScreen->setText(QApplication::translate("GeneralsSettings_window", "\320\237\320\276\320\273\320\275\320\276\321\215\320\272\321\200\320\260\320\275\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        showCursor->setText(QApplication::translate("GeneralsSettings_window", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\260\321\202\321\214 \320\272\321\203\321\200\321\201\320\276\321\200", Q_NULLPTR));
        cancel->setText(QApplication::translate("GeneralsSettings_window", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GeneralsSettings_window: public Ui_GeneralsSettings_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSSETTINGS_WINDOW_H
