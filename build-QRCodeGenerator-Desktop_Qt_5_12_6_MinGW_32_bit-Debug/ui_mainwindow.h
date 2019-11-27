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
    QPushButton *submitButton;
    QLabel *primaryColor;
    QLabel *secondaryColor;
    QLineEdit *userInput;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QMenu *menuQRCodeGenerator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(880, 522);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(740, 440, 75, 23));
        primaryColor = new QLabel(centralwidget);
        primaryColor->setObjectName(QString::fromUtf8("primaryColor"));
        primaryColor->setGeometry(QRect(210, 180, 91, 21));
        secondaryColor = new QLabel(centralwidget);
        secondaryColor->setObjectName(QString::fromUtf8("secondaryColor"));
        secondaryColor->setGeometry(QRect(590, 180, 91, 16));
        userInput = new QLineEdit(centralwidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));
        userInput->setGeometry(QRect(210, 90, 611, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 90, 111, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 880, 21));
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
        submitButton->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        primaryColor->setText(QApplication::translate("MainWindow", "Primary Color", nullptr));
        secondaryColor->setText(QApplication::translate("MainWindow", "Secondary Color", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "URL", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Text", nullptr));

        menuQRCodeGenerator->setTitle(QApplication::translate("MainWindow", "QRCodeGenerator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
