#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeySequence>
#include <filesubwindow.h>

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

void MainWindow::showOpenFileDialog() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open file", "/", "Text files (*.txt)");
    cout << "Selected file: " << fileName.toStdString() << endl;
    if (fileName.trimmed().length() != 0) {
        showFileSubWindow(QString::fromStdString(Utils::readFile(fileName.toStdString())), fileName);
    }
}

//--------------------------- SLOTS ------------------------
void MainWindow::createNewDocument() {
    showFileSubWindow();
}

void MainWindow::openFile() {
    showOpenFileDialog();
}
