#ifndef FILESINPUTSUBWINDOW_H
#define FILESINPUTSUBWINDOW_H

#include <QObject>
#include <QWidget>
#include <QMdiSubWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class FilesInputSubWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    explicit FilesInputSubWindow();
    virtual ~FilesInputSubWindow();

private slots:
    void findBtnClick();

private:
    QLineEdit *inputField;
};

#endif // FILESINPUTSUBWINDOW_H
