#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug() << "open sucess";
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug() << "open fail";

    }

    MainWindow w;
    w.show();
    return a.exec();
}
