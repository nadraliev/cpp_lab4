#include <QApplication>
#include <QQmlApplicationEngine>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMainWindow>
#include <mainwindow.h>
#include <QTreeWidget>
#include <QList>
#include <QTreeWidgetItem>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QMdiArea *mdiArea = new QMdiArea();
    QMdiSubWindow *subWindow = new QMdiSubWindow();
    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    items[0]->addChild(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(00))));
    treeWidget->insertTopLevelItems(0, items);
    subWindow->setWidget(treeWidget);
    mdiArea->addSubWindow(subWindow);
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setCentralWidget(mdiArea);

    mainWindow->show();

    return app.exec();
}
