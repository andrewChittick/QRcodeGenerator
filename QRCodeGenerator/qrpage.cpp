#include "qrpage.h"
#include "ui_qrpage.h"
#include <iostream>
#include <windows.h>

QRPage::QRPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPage)
{
    ui->setupUi(this);
    SetCurrentDirectoryA("..");
    SetCurrentDirectoryA(".\\build-QRCodeGenerator-Desktop_Qt_5_12_6_MinGW_32_bit-Release");
    ui->label->setPixmap(QPixmap("QR.png"));
    ui->label->setScaledContents(true);

}

QRPage::~QRPage()
{
    delete ui;
}
