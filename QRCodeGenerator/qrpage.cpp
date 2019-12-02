#include "qrpage.h"
#include "ui_qrpage.h"
#include <iostream>

QRPage::QRPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPage)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap("QR.png"));
    ui->label->setScaledContents(true);

}

QRPage::~QRPage()
{
    delete ui;
}
