/********************************************************************************
** Form generated from reading UI file 'settings_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_WINDOW_H
#define UI_SETTINGS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "widget_types/settings/setcolorrgba.h"
#include "widget_types/settings/settext.h"

QT_BEGIN_NAMESPACE

class Ui_Settings_window
{
public:
    QAction *actionPath;
    QGridLayout *gridLayout_4;
    QPushButton *save;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *settings;
    QWidget *position_and_size_tab;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QSpinBox *y;
    QLabel *label_y;
    QSpinBox *x;
    QLabel *label_x;
    QSlider *horizontalSlider_x;
    QSlider *horizontalSlider_y;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_11;
    QSpinBox *width;
    QLabel *label_4;
    QSpinBox *height;
    QLabel *label_3;
    QSlider *horizontalSlider_width;
    QSlider *horizontalSlider_height;
    QSpacerItem *verticalSpacer_5;
    QWidget *border_tab;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QSpinBox *borderClick_width;
    QSlider *horizontalSlider_borderClick_width;
    SetColorRGBA *borderClick_Color;
    QLabel *label_8;
    QSpacerItem *verticalSpacer_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QSpinBox *border_width;
    QSlider *horizontalSlider_border_width;
    QLabel *label_5;
    SetColorRGBA *borderColor;
    QWidget *type_tab;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_11;
    QComboBox *type_list;
    QLabel *label_12;
    QLineEdit *widgetName;
    QSpacerItem *verticalSpacer;
    QWidget *path_tab;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_dirPath;
    QGridLayout *gridLayout_7;
    QLineEdit *dirPath;
    QPushButton *dirPath_button;
    QGroupBox *groupBox_txtPath;
    QGridLayout *gridLayout_8;
    QLineEdit *txtPath;
    QPushButton *txtPath_button;
    QGroupBox *groupBox_iconPath;
    QGridLayout *gridLayout_6;
    QLineEdit *iconPath;
    QPushButton *iconPath_button;
    QGroupBox *groupBox_xmlPath;
    QGridLayout *gridLayout_9;
    QLineEdit *xmlPath;
    QPushButton *xmlPath_button;
    QSpacerItem *verticalSpacer_7;
    QWidget *text_tab;
    QVBoxLayout *verticalLayout_3;
    SetText *textWidget;
    QGroupBox *groupBox_title;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *title;
    SetText *titleWidget;
    QSpacerItem *verticalSpacer_2;
    QWidget *background_tab;
    QVBoxLayout *verticalLayout_4;
    SetColorRGBA *backgroundWidget;
    QSpacerItem *verticalSpacer_8;
    QWidget *speed_tab;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox_runString;
    QGridLayout *gridLayout_13;
    QSpinBox *speed;
    QSlider *horizontalSlider_speed;
    QLabel *label_17;
    QSpacerItem *verticalSpacer_3;
    QWidget *other_tab;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_dynamicMiniWidget;
    QGridLayout *gridLayout_12;
    QSpinBox *dynamicMiniWidgetTimer;
    QSlider *horizontalSlider_dynamicMiniWidgetTimer;
    QComboBox *dynamicMiniWidget;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *groupBox_pattern;
    QVBoxLayout *verticalLayout_12;
    QLineEdit *pattern;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *Settings_window)
    {
        if (Settings_window->objectName().isEmpty())
            Settings_window->setObjectName(QStringLiteral("Settings_window"));
        Settings_window->setWindowModality(Qt::ApplicationModal);
        Settings_window->resize(576, 577);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/settings_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings_window->setWindowIcon(icon);
        Settings_window->setSizeGripEnabled(true);
        actionPath = new QAction(Settings_window);
        actionPath->setObjectName(QStringLiteral("actionPath"));
        actionPath->setIcon(icon);
        gridLayout_4 = new QGridLayout(Settings_window);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        save = new QPushButton(Settings_window);
        save->setObjectName(QStringLiteral("save"));

        gridLayout_4->addWidget(save, 1, 1, 1, 1);

        cancel = new QPushButton(Settings_window);
        cancel->setObjectName(QStringLiteral("cancel"));

        gridLayout_4->addWidget(cancel, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        settings = new QTabWidget(Settings_window);
        settings->setObjectName(QStringLiteral("settings"));
        settings->setTabPosition(QTabWidget::North);
        settings->setTabShape(QTabWidget::Rounded);
        position_and_size_tab = new QWidget();
        position_and_size_tab->setObjectName(QStringLiteral("position_and_size_tab"));
        verticalLayout = new QVBoxLayout(position_and_size_tab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(position_and_size_tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        y = new QSpinBox(groupBox);
        y->setObjectName(QStringLiteral("y"));
        y->setMinimumSize(QSize(75, 0));
        y->setReadOnly(true);
        y->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_10->addWidget(y, 4, 0, 1, 1);

        label_y = new QLabel(groupBox);
        label_y->setObjectName(QStringLiteral("label_y"));

        gridLayout_10->addWidget(label_y, 3, 0, 1, 1);

        x = new QSpinBox(groupBox);
        x->setObjectName(QStringLiteral("x"));
        x->setMinimumSize(QSize(75, 0));
        x->setReadOnly(true);
        x->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_10->addWidget(x, 1, 0, 1, 1);

        label_x = new QLabel(groupBox);
        label_x->setObjectName(QStringLiteral("label_x"));

        gridLayout_10->addWidget(label_x, 0, 0, 1, 1);

        horizontalSlider_x = new QSlider(groupBox);
        horizontalSlider_x->setObjectName(QStringLiteral("horizontalSlider_x"));
        QFont font;
        font.setPointSize(8);
        horizontalSlider_x->setFont(font);
        horizontalSlider_x->setSingleStep(1);
        horizontalSlider_x->setTracking(true);
        horizontalSlider_x->setOrientation(Qt::Horizontal);
        horizontalSlider_x->setInvertedAppearance(false);
        horizontalSlider_x->setInvertedControls(false);
        horizontalSlider_x->setTickPosition(QSlider::NoTicks);

        gridLayout_10->addWidget(horizontalSlider_x, 1, 1, 1, 1);

        horizontalSlider_y = new QSlider(groupBox);
        horizontalSlider_y->setObjectName(QStringLiteral("horizontalSlider_y"));
        horizontalSlider_y->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalSlider_y, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(position_and_size_tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_11 = new QGridLayout(groupBox_2);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        width = new QSpinBox(groupBox_2);
        width->setObjectName(QStringLiteral("width"));
        width->setMinimumSize(QSize(75, 0));
        width->setReadOnly(true);
        width->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_11->addWidget(width, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_11->addWidget(label_4, 0, 0, 1, 1);

        height = new QSpinBox(groupBox_2);
        height->setObjectName(QStringLiteral("height"));
        height->setMinimumSize(QSize(75, 0));
        height->setReadOnly(true);
        height->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_11->addWidget(height, 4, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_11->addWidget(label_3, 3, 0, 1, 1);

        horizontalSlider_width = new QSlider(groupBox_2);
        horizontalSlider_width->setObjectName(QStringLiteral("horizontalSlider_width"));
        horizontalSlider_width->setOrientation(Qt::Horizontal);

        gridLayout_11->addWidget(horizontalSlider_width, 1, 1, 1, 1);

        horizontalSlider_height = new QSlider(groupBox_2);
        horizontalSlider_height->setObjectName(QStringLiteral("horizontalSlider_height"));
        horizontalSlider_height->setOrientation(Qt::Horizontal);

        gridLayout_11->addWidget(horizontalSlider_height, 4, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        settings->addTab(position_and_size_tab, QString());
        border_tab = new QWidget();
        border_tab->setObjectName(QStringLiteral("border_tab"));
        gridLayout = new QGridLayout(border_tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_4 = new QGroupBox(border_tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        borderClick_width = new QSpinBox(groupBox_4);
        borderClick_width->setObjectName(QStringLiteral("borderClick_width"));
        borderClick_width->setMinimumSize(QSize(75, 0));
        borderClick_width->setReadOnly(true);
        borderClick_width->setButtonSymbols(QAbstractSpinBox::NoButtons);
        borderClick_width->setSingleStep(1);

        gridLayout_3->addWidget(borderClick_width, 1, 0, 1, 2);

        horizontalSlider_borderClick_width = new QSlider(groupBox_4);
        horizontalSlider_borderClick_width->setObjectName(QStringLiteral("horizontalSlider_borderClick_width"));
        horizontalSlider_borderClick_width->setSingleStep(1);
        horizontalSlider_borderClick_width->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_borderClick_width, 1, 2, 1, 1);

        borderClick_Color = new SetColorRGBA(groupBox_4);
        borderClick_Color->setObjectName(QStringLiteral("borderClick_Color"));

        gridLayout_3->addWidget(borderClick_Color, 3, 0, 1, 3);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 3);


        gridLayout->addWidget(groupBox_4, 1, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(border_tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        border_width = new QSpinBox(groupBox_3);
        border_width->setObjectName(QStringLiteral("border_width"));
        border_width->setMinimumSize(QSize(75, 0));
        border_width->setReadOnly(true);
        border_width->setButtonSymbols(QAbstractSpinBox::NoButtons);
        border_width->setSingleStep(1);

        gridLayout_2->addWidget(border_width, 1, 0, 1, 2);

        horizontalSlider_border_width = new QSlider(groupBox_3);
        horizontalSlider_border_width->setObjectName(QStringLiteral("horizontalSlider_border_width"));
        horizontalSlider_border_width->setSingleStep(1);
        horizontalSlider_border_width->setTracking(true);
        horizontalSlider_border_width->setOrientation(Qt::Horizontal);
        horizontalSlider_border_width->setTickPosition(QSlider::NoTicks);

        gridLayout_2->addWidget(horizontalSlider_border_width, 1, 2, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 3);

        borderColor = new SetColorRGBA(groupBox_3);
        borderColor->setObjectName(QStringLiteral("borderColor"));

        gridLayout_2->addWidget(borderColor, 3, 0, 1, 3);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 1);

        settings->addTab(border_tab, QString());
        type_tab = new QWidget();
        type_tab->setObjectName(QStringLiteral("type_tab"));
        verticalLayout_2 = new QVBoxLayout(type_tab);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_11 = new QLabel(type_tab);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        type_list = new QComboBox(type_tab);
        type_list->setObjectName(QStringLiteral("type_list"));
        type_list->setEnabled(true);
        type_list->setFrame(true);
        type_list->setModelColumn(0);

        verticalLayout_2->addWidget(type_list);

        label_12 = new QLabel(type_tab);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        widgetName = new QLineEdit(type_tab);
        widgetName->setObjectName(QStringLiteral("widgetName"));
        widgetName->setClearButtonEnabled(true);

        verticalLayout_2->addWidget(widgetName);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        settings->addTab(type_tab, QString());
        path_tab = new QWidget();
        path_tab->setObjectName(QStringLiteral("path_tab"));
        gridLayout_5 = new QGridLayout(path_tab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_dirPath = new QGroupBox(path_tab);
        groupBox_dirPath->setObjectName(QStringLiteral("groupBox_dirPath"));
        gridLayout_7 = new QGridLayout(groupBox_dirPath);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        dirPath = new QLineEdit(groupBox_dirPath);
        dirPath->setObjectName(QStringLiteral("dirPath"));
        dirPath->setReadOnly(true);

        gridLayout_7->addWidget(dirPath, 0, 0, 1, 1);

        dirPath_button = new QPushButton(groupBox_dirPath);
        dirPath_button->setObjectName(QStringLiteral("dirPath_button"));
        dirPath_button->setMaximumSize(QSize(28, 16777215));

        gridLayout_7->addWidget(dirPath_button, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_dirPath, 2, 0, 1, 1);

        groupBox_txtPath = new QGroupBox(path_tab);
        groupBox_txtPath->setObjectName(QStringLiteral("groupBox_txtPath"));
        gridLayout_8 = new QGridLayout(groupBox_txtPath);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        txtPath = new QLineEdit(groupBox_txtPath);
        txtPath->setObjectName(QStringLiteral("txtPath"));
        txtPath->setReadOnly(true);

        gridLayout_8->addWidget(txtPath, 0, 0, 1, 1);

        txtPath_button = new QPushButton(groupBox_txtPath);
        txtPath_button->setObjectName(QStringLiteral("txtPath_button"));
        txtPath_button->setMaximumSize(QSize(28, 16777215));

        gridLayout_8->addWidget(txtPath_button, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_txtPath, 3, 0, 1, 1);

        groupBox_iconPath = new QGroupBox(path_tab);
        groupBox_iconPath->setObjectName(QStringLiteral("groupBox_iconPath"));
        gridLayout_6 = new QGridLayout(groupBox_iconPath);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        iconPath = new QLineEdit(groupBox_iconPath);
        iconPath->setObjectName(QStringLiteral("iconPath"));
        iconPath->setReadOnly(true);

        gridLayout_6->addWidget(iconPath, 0, 0, 1, 1);

        iconPath_button = new QPushButton(groupBox_iconPath);
        iconPath_button->setObjectName(QStringLiteral("iconPath_button"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iconPath_button->sizePolicy().hasHeightForWidth());
        iconPath_button->setSizePolicy(sizePolicy);
        iconPath_button->setMaximumSize(QSize(28, 16777215));

        gridLayout_6->addWidget(iconPath_button, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_iconPath, 0, 0, 1, 1);

        groupBox_xmlPath = new QGroupBox(path_tab);
        groupBox_xmlPath->setObjectName(QStringLiteral("groupBox_xmlPath"));
        gridLayout_9 = new QGridLayout(groupBox_xmlPath);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        xmlPath = new QLineEdit(groupBox_xmlPath);
        xmlPath->setObjectName(QStringLiteral("xmlPath"));
        xmlPath->setReadOnly(true);

        gridLayout_9->addWidget(xmlPath, 0, 0, 1, 1);

        xmlPath_button = new QPushButton(groupBox_xmlPath);
        xmlPath_button->setObjectName(QStringLiteral("xmlPath_button"));
        xmlPath_button->setMaximumSize(QSize(28, 16777215));

        gridLayout_9->addWidget(xmlPath_button, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_xmlPath, 4, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_7, 5, 0, 1, 1);

        settings->addTab(path_tab, QString());
        text_tab = new QWidget();
        text_tab->setObjectName(QStringLiteral("text_tab"));
        verticalLayout_3 = new QVBoxLayout(text_tab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        textWidget = new SetText(text_tab);
        textWidget->setObjectName(QStringLiteral("textWidget"));

        verticalLayout_3->addWidget(textWidget);

        groupBox_title = new QGroupBox(text_tab);
        groupBox_title->setObjectName(QStringLiteral("groupBox_title"));
        verticalLayout_7 = new QVBoxLayout(groupBox_title);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        title = new QLineEdit(groupBox_title);
        title->setObjectName(QStringLiteral("title"));
        title->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(title);

        titleWidget = new SetText(groupBox_title);
        titleWidget->setObjectName(QStringLiteral("titleWidget"));

        verticalLayout_7->addWidget(titleWidget);


        verticalLayout_3->addWidget(groupBox_title);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        settings->addTab(text_tab, QString());
        background_tab = new QWidget();
        background_tab->setObjectName(QStringLiteral("background_tab"));
        verticalLayout_4 = new QVBoxLayout(background_tab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        backgroundWidget = new SetColorRGBA(background_tab);
        backgroundWidget->setObjectName(QStringLiteral("backgroundWidget"));

        verticalLayout_4->addWidget(backgroundWidget);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        settings->addTab(background_tab, QString());
        speed_tab = new QWidget();
        speed_tab->setObjectName(QStringLiteral("speed_tab"));
        verticalLayout_8 = new QVBoxLayout(speed_tab);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox_runString = new QGroupBox(speed_tab);
        groupBox_runString->setObjectName(QStringLiteral("groupBox_runString"));
        gridLayout_13 = new QGridLayout(groupBox_runString);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        speed = new QSpinBox(groupBox_runString);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setMinimumSize(QSize(75, 0));
        speed->setReadOnly(true);
        speed->setButtonSymbols(QAbstractSpinBox::NoButtons);
        speed->setMinimum(-1);
        speed->setMaximum(50);

        gridLayout_13->addWidget(speed, 1, 0, 1, 1);

        horizontalSlider_speed = new QSlider(groupBox_runString);
        horizontalSlider_speed->setObjectName(QStringLiteral("horizontalSlider_speed"));
        horizontalSlider_speed->setMinimum(-1);
        horizontalSlider_speed->setMaximum(50);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout_13->addWidget(horizontalSlider_speed, 1, 1, 1, 1);

        label_17 = new QLabel(groupBox_runString);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_13->addWidget(label_17, 0, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_3, 3, 0, 1, 2);


        verticalLayout_8->addWidget(groupBox_runString);

        settings->addTab(speed_tab, QString());
        other_tab = new QWidget();
        other_tab->setObjectName(QStringLiteral("other_tab"));
        verticalLayout_11 = new QVBoxLayout(other_tab);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        groupBox_dynamicMiniWidget = new QGroupBox(other_tab);
        groupBox_dynamicMiniWidget->setObjectName(QStringLiteral("groupBox_dynamicMiniWidget"));
        gridLayout_12 = new QGridLayout(groupBox_dynamicMiniWidget);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        dynamicMiniWidgetTimer = new QSpinBox(groupBox_dynamicMiniWidget);
        dynamicMiniWidgetTimer->setObjectName(QStringLiteral("dynamicMiniWidgetTimer"));
        dynamicMiniWidgetTimer->setMinimumSize(QSize(75, 0));
        dynamicMiniWidgetTimer->setReadOnly(true);
        dynamicMiniWidgetTimer->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dynamicMiniWidgetTimer->setMinimum(1);
        dynamicMiniWidgetTimer->setMaximum(60);

        gridLayout_12->addWidget(dynamicMiniWidgetTimer, 3, 0, 1, 1);

        horizontalSlider_dynamicMiniWidgetTimer = new QSlider(groupBox_dynamicMiniWidget);
        horizontalSlider_dynamicMiniWidgetTimer->setObjectName(QStringLiteral("horizontalSlider_dynamicMiniWidgetTimer"));
        horizontalSlider_dynamicMiniWidgetTimer->setMinimum(1);
        horizontalSlider_dynamicMiniWidgetTimer->setMaximum(60);
        horizontalSlider_dynamicMiniWidgetTimer->setPageStep(1);
        horizontalSlider_dynamicMiniWidgetTimer->setOrientation(Qt::Horizontal);

        gridLayout_12->addWidget(horizontalSlider_dynamicMiniWidgetTimer, 3, 1, 1, 1);

        dynamicMiniWidget = new QComboBox(groupBox_dynamicMiniWidget);
        dynamicMiniWidget->setObjectName(QStringLiteral("dynamicMiniWidget"));

        gridLayout_12->addWidget(dynamicMiniWidget, 1, 0, 1, 2);

        label_2 = new QLabel(groupBox_dynamicMiniWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_12->addWidget(label_2, 2, 0, 1, 2);

        label = new QLabel(groupBox_dynamicMiniWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_12->addWidget(label, 0, 0, 1, 2);


        verticalLayout_11->addWidget(groupBox_dynamicMiniWidget);

        groupBox_pattern = new QGroupBox(other_tab);
        groupBox_pattern->setObjectName(QStringLiteral("groupBox_pattern"));
        verticalLayout_12 = new QVBoxLayout(groupBox_pattern);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        pattern = new QLineEdit(groupBox_pattern);
        pattern->setObjectName(QStringLiteral("pattern"));

        verticalLayout_12->addWidget(pattern);


        verticalLayout_11->addWidget(groupBox_pattern);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_4);

        settings->addTab(other_tab, QString());

        gridLayout_4->addWidget(settings, 0, 0, 1, 5);


        retranslateUi(Settings_window);
        QObject::connect(horizontalSlider_x, SIGNAL(valueChanged(int)), x, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_y, SIGNAL(valueChanged(int)), y, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_width, SIGNAL(valueChanged(int)), width, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_height, SIGNAL(valueChanged(int)), height, SLOT(setValue(int)));
        QObject::connect(border_width, SIGNAL(valueChanged(int)), horizontalSlider_border_width, SLOT(setValue(int)));
        QObject::connect(borderClick_width, SIGNAL(valueChanged(int)), horizontalSlider_borderClick_width, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_border_width, SIGNAL(valueChanged(int)), border_width, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_borderClick_width, SIGNAL(valueChanged(int)), borderClick_width, SLOT(setValue(int)));
        QObject::connect(speed, SIGNAL(valueChanged(int)), horizontalSlider_speed, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_speed, SIGNAL(valueChanged(int)), speed, SLOT(setValue(int)));
        QObject::connect(dynamicMiniWidgetTimer, SIGNAL(valueChanged(int)), horizontalSlider_dynamicMiniWidgetTimer, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_dynamicMiniWidgetTimer, SIGNAL(valueChanged(int)), dynamicMiniWidgetTimer, SLOT(setValue(int)));
        QObject::connect(save, SIGNAL(clicked()), Settings_window, SLOT(accept()));
        QObject::connect(cancel, SIGNAL(clicked()), Settings_window, SLOT(reject()));

        settings->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(Settings_window);
    } // setupUi

    void retranslateUi(QDialog *Settings_window)
    {
        Settings_window->setWindowTitle(QApplication::translate("Settings_window", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\262\320\270\320\264\320\266\320\265\321\202\320\260", Q_NULLPTR));
        actionPath->setText(QApplication::translate("Settings_window", "path", Q_NULLPTR));
        save->setText(QApplication::translate("Settings_window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        cancel->setText(QApplication::translate("Settings_window", "\320\236\321\202\320\274\320\265\320\275\320\260", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings_window", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265:", Q_NULLPTR));
        label_y->setText(QApplication::translate("Settings_window", "Y:", Q_NULLPTR));
        label_x->setText(QApplication::translate("Settings_window", "X:", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Settings_window", "\320\240\320\260\320\267\320\274\320\265\321\200:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Settings_window", "\320\250\320\270\321\200\320\270\320\275\320\260:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Settings_window", "\320\222\321\213\321\201\320\276\321\202\320\260:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(position_and_size_tab), QApplication::translate("Settings_window", "\320\237\320\276\320\273\320\276\320\266\320\265\320\275\320\270\320\265 \320\270 \321\200\320\260\320\267\320\274\320\265\321\200", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Settings_window", "\320\240\320\260\320\274\320\272\320\260, \320\277\321\200\320\270 \320\275\320\260\320\266\320\260\321\202\320\270\320\270:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Settings_window", "\320\250\320\270\321\200\320\270\320\275\320\260 \321\200\320\260\320\274\320\272\320\270:", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Settings_window", "\320\240\320\260\320\274\320\272\320\260:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Settings_window", "\320\250\320\270\321\200\320\270\320\275\320\260 \321\200\320\260\320\274\320\272\320\270:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(border_tab), QApplication::translate("Settings_window", "\320\240\320\260\320\274\320\272\320\260", Q_NULLPTR));
        label_11->setText(QApplication::translate("Settings_window", "\320\242\320\270\320\277 \320\262\320\270\320\264\320\266\320\265\321\202\320\260:", Q_NULLPTR));
        type_list->clear();
        type_list->insertItems(0, QStringList()
         << QApplication::translate("Settings_window", "clock", Q_NULLPTR)
         << QApplication::translate("Settings_window", "date", Q_NULLPTR)
         << QApplication::translate("Settings_window", "dont_click", Q_NULLPTR)
         << QApplication::translate("Settings_window", "image_viewer", Q_NULLPTR)
         << QApplication::translate("Settings_window", "label", Q_NULLPTR)
         << QApplication::translate("Settings_window", "run_string", Q_NULLPTR)
         << QApplication::translate("Settings_window", "schedule", Q_NULLPTR)
         << QApplication::translate("Settings_window", "bells_monitor", Q_NULLPTR)
        );
        label_12->setText(QApplication::translate("Settings_window", "\320\230\320\274\321\217 \320\262\320\270\320\264\320\266\320\265\321\202\320\260:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(type_tab), QApplication::translate("Settings_window", "\320\242\320\270\320\277", Q_NULLPTR));
        groupBox_dirPath->setTitle(QApplication::translate("Settings_window", "\320\237\321\203\321\202\321\214 \320\272 \320\272\320\260\321\202\320\260\320\273\320\276\320\263\321\203:", Q_NULLPTR));
        dirPath_button->setText(QApplication::translate("Settings_window", "...", Q_NULLPTR));
        groupBox_txtPath->setTitle(QApplication::translate("Settings_window", "\320\237\321\203\321\202\321\214 \320\272 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\274\321\203 \321\204\320\260\320\271\320\273\321\203:", Q_NULLPTR));
        txtPath_button->setText(QApplication::translate("Settings_window", "...", Q_NULLPTR));
        groupBox_iconPath->setTitle(QApplication::translate("Settings_window", "\320\237\321\203\321\202\321\214 \320\272 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\216:", Q_NULLPTR));
        iconPath_button->setText(QApplication::translate("Settings_window", "...", Q_NULLPTR));
        groupBox_xmlPath->setTitle(QApplication::translate("Settings_window", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217:", Q_NULLPTR));
        xmlPath_button->setText(QApplication::translate("Settings_window", "...", Q_NULLPTR));
        settings->setTabText(settings->indexOf(path_tab), QApplication::translate("Settings_window", "\320\237\321\203\321\202\321\214", Q_NULLPTR));
        groupBox_title->setTitle(QApplication::translate("Settings_window", "\320\227\320\260\320\263\320\276\320\273\320\276\320\262\320\276\320\272:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(text_tab), QApplication::translate("Settings_window", "\320\242\320\265\320\272\321\201\321\202", Q_NULLPTR));
        settings->setTabText(settings->indexOf(background_tab), QApplication::translate("Settings_window", "\320\244\320\276\320\275", Q_NULLPTR));
        groupBox_runString->setTitle(QApplication::translate("Settings_window", "\320\221\320\265\320\263\321\203\321\211\320\260\321\217 \321\201\321\202\321\200\320\276\320\272\320\260:", Q_NULLPTR));
        label_17->setText(QApplication::translate("Settings_window", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(speed_tab), QApplication::translate("Settings_window", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", Q_NULLPTR));
        groupBox_dynamicMiniWidget->setTitle(QApplication::translate("Settings_window", "dynamicMiniWidget:", Q_NULLPTR));
        dynamicMiniWidget->clear();
        dynamicMiniWidget->insertItems(0, QStringList()
         << QApplication::translate("Settings_window", "false", Q_NULLPTR)
         << QApplication::translate("Settings_window", "true", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Settings_window", "dynamicMiniWidgetTimer:", Q_NULLPTR));
        label->setText(QApplication::translate("Settings_window", "dynamicMiniWidget:", Q_NULLPTR));
        groupBox_pattern->setTitle(QApplication::translate("Settings_window", "\320\250\320\260\320\261\320\273\320\276\320\275 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \320\264\320\260\321\202\321\213:", Q_NULLPTR));
        settings->setTabText(settings->indexOf(other_tab), QApplication::translate("Settings_window", "\320\240\320\260\320\267\320\275\320\276\320\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings_window: public Ui_Settings_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_WINDOW_H
