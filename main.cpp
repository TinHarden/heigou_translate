#include <QApplication>
#include "main_screen.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MAIN_SCREEN::main_screen main_screen{};
    main_screen.show();

    return QApplication::exec();
}