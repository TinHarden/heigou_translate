
#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H

#include <QWidget>
#include <QSettings>

namespace SETTING_UI
{
    QT_BEGIN_NAMESPACE
    namespace Ui { class settings_screen; }
    QT_END_NAMESPACE

    class settings_screen final : public QWidget {
        Q_OBJECT

        public:
        explicit settings_screen(QWidget *parent = nullptr);
        ~settings_screen() override;

    private:
        Ui::settings_screen *ui;
    };
}

#endif //SETTINGS_SCREEN_H
