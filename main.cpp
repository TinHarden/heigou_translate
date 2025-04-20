#include <QApplication>
#include "main_screen.h"
#include "background_progress.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MAIN_SCREEN::main_screen main_screen{};
    main_screen.show();

    return QApplication::exec();
}