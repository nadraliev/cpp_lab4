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

void MainWindow::findStringInFiles(const QString &text, const QVector<QFileInfo*> *files, vector<FileEntries> *result) {
    for (QFileInfo *fileInfo: *files) {
        FileEntries *temp = new FileEntries();
        findStringInFile(text, *fileInfo, temp);
        result->push_back(*temp);
    }
}

void MainWindow::findStringInFile(const QString &text, QFileInfo &fileInfo, FileEntries *entries) {
    string fileText = Utils::readFile(fileInfo.absoluteFilePath().toStdString());
    istringstream stream(fileText);
    int lineIndex = 0;
    string line;
    while (getline(stream, line)) {
        findStringInLine(text, line, entries, lineIndex);
        lineIndex++;
    }
}

void MainWindow::findStringInLine(const QString &text, string &line, FileEntries *entries, int lineIndex) {
    int index = 0;
    while (true) {
        index = line.find(text.toStdString(), index);
        if (index == string::npos) break;

        entries->addEntry(lineIndex, index);

        index += text.size();
    }
}

void MainWindow::parseFilesPaths(const QString &filesListStr, QVector<QFileInfo*> *filesList) {
    string filesListStdStr = filesListStr.toStdString();
    Utils::replaceAll(filesListStdStr, "\n", "");
    Utils::replaceAll(filesListStdStr, "\r", "");
    if (!validateFilesPathsStr(filesListStr)) return;
    vector<string> *tokens = new vector<string>();
    Utils::stringTokenizer(&filesListStdStr, ',', tokens);
    QFileInfo *temp;
    string invalidFilesStr = "Invalid files paths: ";
    int invalidFilesCount = 0;
    for (string path: *tokens) {
        temp = new QFileInfo(QString::fromStdString(path));
        if (temp->exists() && temp->isFile()) {
            filesList->push_back(temp);
        } else {
            invalidFilesCount++;
            invalidFilesStr += path + ", ";
        }
    }
    if (invalidFilesCount != 0)
        showErrorDialog(QString::fromStdString(invalidFilesStr));
}

bool MainWindow::validateFilesPathsStr(const QString &filesList) {
    if (filesList.trimmed().size() == 0) {
        showErrorDialog("Files list is blank");
        return false;
    }
    return true;
}

void MainWindow::showErrorDialog(const QString &text) {
    QErrorMessage *errorDialog = new QErrorMessage(this);
    errorDialog->setAttribute(Qt::WA_DeleteOnClose);
    errorDialog->showMessage(text);
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
        FileSubWindow *activeWindow = dynamic_cast<FileSubWindow*>(ui->mdiArea->activeSubWindow());
        if (activeWindow == nullptr) {
            showErrorDialog("No file selected");
            return;
        }
        QString filesListStr = activeWindow->getText();
        QVector<QFileInfo*> *filesList = new QVector<QFileInfo*>();
        parseFilesPaths(filesListStr, filesList);
        if (filesList->size() == 0) return;
        vector<FileEntries> *entries = new vector<FileEntries>();
        findStringInFiles(url, filesList, entries);
        int a = 1;
    }
}
