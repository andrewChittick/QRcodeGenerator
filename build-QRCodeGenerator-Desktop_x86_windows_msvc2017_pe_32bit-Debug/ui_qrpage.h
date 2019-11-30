/********************************************************************************
** Form generated from reading UI file 'qrpage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRPAGE_H
#define UI_QRPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QRPage
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QRPage)
    {
        if (QRPage->objectName().isEmpty())
            QRPage->setObjectName(QString::fromUtf8("QRPage"));
        QRPage->resize(583, 478);
        centralwidget = new QWidget(QRPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 71, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(480, 410, 75, 23));
        QRPage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QRPage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 583, 21));
        QRPage->setMenuBar(menubar);
        statusbar = new QStatusBar(QRPage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QRPage->setStatusBar(statusbar);

        retranslateUi(QRPage);

        QMetaObject::connectSlotsByName(QRPage);
    } // setupUi

    void retranslateUi(QMainWindow *QRPage)
    {
        QRPage->setWindowTitle(QApplication::translate("QRPage", "MainWindow", nullptr));
        label->setText(QApplication::translate("QRPage", "Your QR Code:", nullptr));
        pushButton->setText(QApplication::translate("QRPage", "Download", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QRPage: public Ui_QRPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRPAGE_H
