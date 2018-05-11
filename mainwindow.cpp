#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <filesubwindow.h>
#include <dialog.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showFileSubWindow(const QString &text, const QString &title) {
    FileSubWindow *fileSubWindow = new FileSubWindow(ui->mdiArea, text);
    fileSubWindow->setAttribute(Qt::WA_DeleteOnClose);
    fileSubWindow->setWindowTitle(title);
    fileSubWindow->show();
}

void MainWindow::findStringInFiles(const QString &text, const QVector<QFile> files) {

}

QVector<QFile> MainWindow::parseFilesPaths(const QString &filesList) {

}

//--------------------------- SLOTS ------------------------
void MainWindow::createNewDocument() {
    showFileSubWindow();
}

void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "/", "Text files (*.txt)");
    cout << "Selected file: " << fileName.toStdString() << endl;
    if (fileName.trimmed().length() != 0) {
        showFileSubWindow(QString::fromStdString(Utils::readFile(fileName.toStdString())), fileName);
    }
}

void MainWindow::findInFiles() {
    QString url = Dialog::getUrl();
    cout << "Url entered: " << url.toStdString() << endl;
    if (url.trimmed().length() != 0) {
        //TODO read contents of selected subwindow, parse files paths, perform search
    }
}
