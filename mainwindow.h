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
    void showOpenFileDialog();

private slots:
    void createNewDocument();
    void openFile();
};

#endif // MAINWINDOW_H
