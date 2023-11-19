#include <QCoreApplication>
#include <interfejs.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    interfejs();
    return a.exec();
}
