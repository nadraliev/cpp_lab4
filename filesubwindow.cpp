#include "filesubwindow.h"

FileSubWindow::FileSubWindow(QWidget *parent, const QString &text): QMdiSubWindow(parent)
{
    textEdit = new QTextEdit(text);
    setWidget(textEdit);
}

FileSubWindow::~FileSubWindow() {
     textEdit->~QTextEdit();
}
