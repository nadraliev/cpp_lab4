#include <QApplication>
#include <QQmlApplicationEngine>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMainWindow>
#include <mainwindow.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QMdiArea *mdiArea = new QMdiArea();
    QMdiSubWindow *subWindow = new QMdiSubWindow();
    mdiArea->addSubWindow(subWindow);
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setCentralWidget(mdiArea);

    mainWindow->show();

    return app.exec();
}
