#include "myapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyApp w;
    w.show();
    return a.exec();
}
