//
// Created by heiyt on 25-4-7.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_screen.h" resolved

#include "main_screen.h"
#include "ui_main_screen.h"

#include "youdao_translate.h"

namespace MAIN_SCREEN
{
    main_screen::main_screen(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::main_screen)
    {
        ui->setupUi(this);

        setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);

        ui->comboBox->addItem("英语");
        ui->comboBox->addItem("中文");

        _youdao_translate = new TRANSLATE::youdao_translate(this);

        connect(ui->pushButton_translate, &QPushButton::clicked, this, &main_screen::handleTranslation);
        shortcut = new QShortcut(QKeySequence("Ctrl+Return"), this);
        connect(shortcut, &QShortcut::activated, this, &main_screen::handleTranslation);
    }

    void main_screen::handleTranslation() const
    {
        const QString words = ui->textEdit->toPlainText();
        if (words.isEmpty())
        {
            ui->textBrowser_output->setText("请输入待翻译内容");
            return;
        }
        const QString to_language = (ui->comboBox->currentIndex() == 0) ? "en" : "zh-CHS";
        _youdao_translate->translate(words, to_language);
        connect(_youdao_translate, &TRANSLATE::youdao_translate::translationFinished, [this](const QString& result)
        {
            ui->textBrowser_output->setText(result);
        });
    }

    main_screen::~main_screen()
    {
        delete ui;
    }
}
// MAIN_SCREEN
