
#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <QMainWindow>
#include <QShortcut>

#include "settings_screen.h"

namespace TRANSLATE
{
    class youdao_translate;
}

namespace MAIN_SCREEN
{
    QT_BEGIN_NAMESPACE

    namespace Ui
    {
        class main_screen;
    }

    QT_END_NAMESPACE

    class main_screen final : public QMainWindow
    {
        Q_OBJECT

    public:
        TRANSLATE::youdao_translate* _youdao_translate{};
        explicit main_screen(QWidget* parent = nullptr);
        void handleTranslation() const;
        ~main_screen() override;

    private:
        Ui::main_screen* ui;
        SETTING_UI::settings_screen settings_screen{};
        QShortcut* shortcut{};
        QShortcut* shortcut_close{};
    };
}
// MAIN_SCREEN

#endif //MAIN_SCREEN_H
