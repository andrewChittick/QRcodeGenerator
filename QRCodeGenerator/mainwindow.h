#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <map>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submitButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    void dataEncoding();
    int chooseVersion(std::string input);
    std::string characterCount(std::string input, int versionNumber);
    std::string decimalToBinary(std::string input, int binarySize);
};
#endif // MAINWINDOW_H
