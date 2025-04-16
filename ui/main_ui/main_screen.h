
#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <QMainWindow>
#include <QShortcut>

#include "google_translate_crawler.h"

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
        explicit main_screen(QWidget* parent = nullptr);
        void handleTranslation() const;
        ~main_screen() override;

    private:
        Ui::main_screen* ui;
        QShortcut* shortcut{};
        QShortcut* shortcut_close{};
        GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler* translation;
    };
}
// MAIN_SCREEN

#endif //MAIN_SCREEN_H
