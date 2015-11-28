#include "videoeditmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VideoEditMainWindow w;
    w.show();

    return a.exec();
}
