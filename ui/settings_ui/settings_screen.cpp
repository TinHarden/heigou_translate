//
// Created by heiyt on 25-4-4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_settings_screen.h" resolved

#include "settings_screen.h"
#include "ui_settings_screen.h"

namespace SETTING_UI
{
    settings_screen::settings_screen(QWidget *parent) :
        QWidget(parent), ui(new Ui::settings_screen) {
        ui->setupUi(this);
    }

    settings_screen::~settings_screen() {
        delete ui;
    }
}