//
// Created by heiyt on 25-4-4.
//

#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H

#include <QWidget>

namespace SETTING_UI
{
    QT_BEGIN_NAMESPACE
    namespace Ui { class settings_screen; }
    QT_END_NAMESPACE

    class settings_screen : public QWidget {
        Q_OBJECT

        public:
        explicit settings_screen(QWidget *parent = nullptr);
        ~settings_screen() override;

    private:
        Ui::settings_screen *ui;
    };
}

#endif //SETTINGS_SCREEN_H
