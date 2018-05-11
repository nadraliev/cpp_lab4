#include "filesinputsubwindow.h"
#include <QCoreApplication>
#include <string>
#include <vector>
#include <utils.h>
#include <iostream>

using namespace std;

FilesInputSubWindow::FilesInputSubWindow(): QMdiSubWindow()
{
    setWindowFlags(Qt::CustomizeWindowHint);
    inputField = new QLineEdit();
    QPushButton *findBnt = new QPushButton("Find");
    connect(findBnt, SIGNAL(released()), this, SLOT(findBtnClick()));
    QHBoxLayout *boxLayout = new QHBoxLayout();
    boxLayout->addWidget(inputField);
    boxLayout->addWidget(findBnt);
    QWidget *windowWidget = new QWidget;
    windowWidget->setLayout(boxLayout);
    setWidget(windowWidget);
}

void FilesInputSubWindow::findBtnClick() {
    string input = inputField->text().toStdString();
    vector<string> files;
    Utils::stringTokenizer(&input, ',', &files);
    for (string file: files) {
        cout << file;
    }
}

FilesInputSubWindow::~FilesInputSubWindow() {

}
