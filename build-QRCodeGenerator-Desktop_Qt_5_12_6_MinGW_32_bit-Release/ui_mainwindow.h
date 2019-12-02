/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *userInput;
    QLabel *primaryColor;
    QComboBox *comboBox;
    QPushButton *submitButton;
    QMenuBar *menubar;
    QMenu *menuQRCodeGenerator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(661, 228);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 611, 131));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        userInput = new QLineEdit(formLayoutWidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userInput);

        primaryColor = new QLabel(formLayoutWidget);
        primaryColor->setObjectName(QString::fromUtf8("primaryColor"));

        formLayout->setWidget(1, QFormLayout::LabelRole, primaryColor);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        submitButton = new QPushButton(formLayoutWidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, submitButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 661, 21));
        menuQRCodeGenerator = new QMenu(menubar);
        menuQRCodeGenerator->setObjectName(QString::fromUtf8("menuQRCodeGenerator"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuQRCodeGenerator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "QR:", nullptr));
        primaryColor->setText(QApplication::translate("MainWindow", "Primary Color:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Black", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Purple", nullptr));
        comboBox->setItemText(2, QString());

        submitButton->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        menuQRCodeGenerator->setTitle(QApplication::translate("MainWindow", "QRCodeGenerator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
