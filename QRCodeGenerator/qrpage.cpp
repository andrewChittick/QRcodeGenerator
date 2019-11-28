#include "qrpage.h"
#include "ui_qrpage.h"

QRPage::QRPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRPage)
{
    ui->setupUi(this);
}

QRPage::~QRPage()
{
    delete ui;
}
