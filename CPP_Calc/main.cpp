#include "controller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller& w = Controller::getInstance();
    w.show();
    return a.exec();
}
