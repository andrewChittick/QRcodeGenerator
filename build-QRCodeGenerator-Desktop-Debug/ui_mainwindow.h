/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
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
    QLabel *label;
    QComboBox *comboBox_2;
    QMenuBar *menubar;
    QMenu *menuQRCodeGenerator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(561, 408);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        submitButton = new QPushButton(centralwidget);
        submitButton->setObjectName(QString::fromUtf8("submitButton"));
        submitButton->setGeometry(QRect(460, 330, 75, 23));
        primaryColor = new QLabel(centralwidget);
        primaryColor->setObjectName(QString::fromUtf8("primaryColor"));
        primaryColor->setGeometry(QRect(140, 140, 91, 21));
        secondaryColor = new QLabel(centralwidget);
        secondaryColor->setObjectName(QString::fromUtf8("secondaryColor"));
        secondaryColor->setGeometry(QRect(140, 180, 91, 16));
        userInput = new QLineEdit(centralwidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));
        userInput->setGeometry(QRect(130, 90, 351, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(310, 140, 111, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 80, 31, 41));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(310, 180, 111, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 561, 21));
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
        primaryColor->setText(QApplication::translate("MainWindow", "Primary Color:", nullptr));
        secondaryColor->setText(QApplication::translate("MainWindow", "Secondary Color:", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "Black", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Purple", nullptr));
        comboBox->setItemText(2, QString());

        label->setText(QApplication::translate("MainWindow", "QR:", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "White", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Yellow", nullptr));
        comboBox_2->setItemText(2, QString());

        menuQRCodeGenerator->setTitle(QApplication::translate("MainWindow", "QRCodeGenerator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
