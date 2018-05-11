#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QtGui>
#include <QMdiArea>
#include <QString>
#include <QFileDialog>
#include <iostream>
#include <utils.h>
#include <QVector>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void showFileSubWindow(const QString &text = nullptr, const QString &title = nullptr);
    void findStringInFiles(const QString &text, const QVector<QFile> files);
    QVector<QFile> parseFilesPaths(const QString &filesList);

private slots:
    void createNewDocument();
    void openFile();
    void findInFiles();
};

#endif // MAINWINDOW_H
