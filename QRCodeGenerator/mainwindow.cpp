#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <bitset>
#include <map>
#include <iostream>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::chooseVersion(std::string input) {
    if (input.length() <= 20) {
        return 1;
    }
    else if (input.length() <= 38) {
        return 2;
    }
    return 0;
}

std::string MainWindow::decimalToBinary(std::string input) {
    int number = std::stoi(input);
    std::string binaryNumber;
    for (int i = 7; i >= 0; i--) {
        int temp = number >> i;
        if (temp & 1) {
            binaryNumber.append("1");
        }
        else {
            binaryNumber.append("0");
        }
    }
    return binaryNumber;
}

std::string MainWindow::characterCount(std::string input, int versionNumber) {
    int stringLength = input.length();
    std::string finalCount;
    finalCount = std::bitset<9>(stringLength).to_string();
    return finalCount;
}

void  MainWindow::dataEncoding() {
    std::map<char, int> alphaNumericMap;
    alphaNumericMap.insert(std::make_pair('0', 0));
    alphaNumericMap.insert(std::make_pair('1', 1));
    alphaNumericMap.insert(std::make_pair('2', 2));
    alphaNumericMap.insert(std::make_pair('3', 3));
    alphaNumericMap.insert(std::make_pair('4', 4));
    alphaNumericMap.insert(std::make_pair('5', 5));
    alphaNumericMap.insert(std::make_pair('6', 6));
    alphaNumericMap.insert(std::make_pair('7', 7));
    alphaNumericMap.insert(std::make_pair('8', 8));
    alphaNumericMap.insert(std::make_pair('9', 9));
    alphaNumericMap.insert(std::make_pair('A', 10));
    alphaNumericMap.insert(std::make_pair('B', 11));
    alphaNumericMap.insert(std::make_pair('C', 12));
    alphaNumericMap.insert(std::make_pair('D', 13));
    alphaNumericMap.insert(std::make_pair('E', 14));
    alphaNumericMap.insert(std::make_pair('F', 15));
    alphaNumericMap.insert(std::make_pair('G', 16));
    alphaNumericMap.insert(std::make_pair('H', 17));
    alphaNumericMap.insert(std::make_pair('I', 18));
    alphaNumericMap.insert(std::make_pair('J', 19));
    alphaNumericMap.insert(std::make_pair('K', 20));
    alphaNumericMap.insert(std::make_pair('L', 21));
    alphaNumericMap.insert(std::make_pair('M', 22));
    alphaNumericMap.insert(std::make_pair('N', 23));
    alphaNumericMap.insert(std::make_pair('O', 24));
    alphaNumericMap.insert(std::make_pair('P', 25));
    alphaNumericMap.insert(std::make_pair('Q', 26));
    alphaNumericMap.insert(std::make_pair('R', 27));
    alphaNumericMap.insert(std::make_pair('S', 28));
    alphaNumericMap.insert(std::make_pair('T', 29));
    alphaNumericMap.insert(std::make_pair('U', 30));
    alphaNumericMap.insert(std::make_pair('V', 31));
    alphaNumericMap.insert(std::make_pair('W', 32));
    alphaNumericMap.insert(std::make_pair('X', 33));
    alphaNumericMap.insert(std::make_pair('Y', 34));
    alphaNumericMap.insert(std::make_pair('Z', 35));
    alphaNumericMap.insert(std::make_pair(' ', 36));
    alphaNumericMap.insert(std::make_pair('$', 37));
    alphaNumericMap.insert(std::make_pair('%', 38));
    alphaNumericMap.insert(std::make_pair('*', 39));
    alphaNumericMap.insert(std::make_pair('+', 40));
    alphaNumericMap.insert(std::make_pair('-', 41));
    alphaNumericMap.insert(std::make_pair('.', 42));
    alphaNumericMap.insert(std::make_pair('/', 43));
    alphaNumericMap.insert(std::make_pair(':', 44));

    std::string codeWords[16];
    std::string input = ui->userInput->text().toStdString();
    int versionNumber = chooseVersion(input);
    std::string characterCountIndicator = characterCount(input, versionNumber);
    int codeWordCount = 1;
    codeWords[0] = characterCountIndicator;

    // Encoding the input by taking two characters at a time and applying algorithm
    for (int i = 0; i < input.length(); i++) {
        std::map<char, int>::iterator it = alphaNumericMap.find(input.at(i));
        std::map<char, int>::iterator it2 = alphaNumericMap.find(input.at(i+1));
        int encodedDecimal = it->second * 45 + it2->second;
        std::string stringEncodedDecimal = std::to_string(encodedDecimal);
        std::string codeWord = decimalToBinary(stringEncodedDecimal);
        std::cout << codeWord << std::endl;
        codeWords[codeWordCount] = codeWord;
        codeWordCount++;
        i++;
    }
    for (int i = 0; i < codeWords->length(); i++) {
        std::cout << codeWords[i] << std::endl;
    }
}

void MainWindow::on_submitButton_clicked()
{
    dataEncoding();
}
