#include "qrpage.h"
#include "ui_qrpage.h"
#include <iostream>

QRPage::QRPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPage)
{
    ui->setupUi(this);
    QString filename = "/icon.png";
    ui->label->setAlignment(Qt::AlignCenter);
    QPixmap pix;
    if (pix.load(filename))
    {
        std::cout << "here" << std::endl;
        pix = pix.scaled(ui->label->size(), Qt::KeepAspectRatio);
        ui->label->setPixmap(pix);
    }
}

QRPage::~QRPage()
{
    delete ui;
}
