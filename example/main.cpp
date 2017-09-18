#include <QCoreApplication>

#include <QDebug>
#include <XSys>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << XSys::FS::TmpFilePath("test");

    return a.exec();
}
