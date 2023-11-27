#include "encryption.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Encryption w;
    w.show();
    return a.exec();
}
