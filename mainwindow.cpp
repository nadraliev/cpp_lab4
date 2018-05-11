#include "mainwindow.h"
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QMdiArea *mdiArea = new QMdiArea();
    QMdiSubWindow *subWindow = new QMdiSubWindow();
    subWindow->setSystemMenu(NULL);
    subWindow->setWindowTitle(QString("shit"));
    subWindow->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint);
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    items[0]->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(00))));
    treeWidget->insertTopLevelItems(0, items);
    subWindow->setWidget(treeWidget);
    mdiArea->addSubWindow(subWindow);
    setCentralWidget(mdiArea);
    QMdiSubWindow *inputWindow = new FilesInputSubWindow();
    inputWindow->move(0, mdiArea->size().height());
    mdiArea->addSubWindow(inputWindow);
}
