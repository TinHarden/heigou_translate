
// You may need to build the project (run Qt uic code generator) to get "ui_settings_screen.h" resolved

#include "settings_screen.h"
#include "ui_settings_screen.h"

namespace SETTING_UI
{
    settings_screen::settings_screen(QWidget *parent) :
        QWidget(parent), ui(new Ui::settings_screen) {
        ui->setupUi(this);

        connect(ui->pushButton_ok,&QPushButton::clicked,this,[this]
        {
            if (!ui->textEdit_appKEY->toPlainText().isEmpty() && !ui->textEdit_appSECRET->toPlainText().isEmpty())
            {
                QSettings settings;
                settings.setValue("APPKEY", ui->textEdit_appKEY->toPlainText());
                settings.setValue("APPSECRET", ui->textEdit_appSECRET->toPlainText());
            }
        });
    }

    settings_screen::~settings_screen() {
        delete ui;
    }
}
