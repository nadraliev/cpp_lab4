#ifndef FILESUBWINDOW_H
#define FILESUBWINDOW_H

#include <QObject>
#include <QWidget>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QString>

class FileSubWindow : public QMdiSubWindow
{
    Q_OBJECT

public:
    FileSubWindow(QWidget *parent, const QString &text = nullptr);
    ~FileSubWindow();

private:
    QTextEdit *textEdit;
};

#endif // FILESUBWINDOW_H
