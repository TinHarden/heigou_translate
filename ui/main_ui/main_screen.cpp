
// You may need to build the project (run Qt uic code generator) to get "ui_main_screen.h" resolved

#include "main_screen.h"
#include "ui_main_screen.h"

namespace MAIN_SCREEN
{
    main_screen::main_screen(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::main_screen)
    {
        ui->setupUi(this);
        // 界面永远位于上方
        setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
        // 控件设置
        ui->comboBox->addItem("英语");
        ui->comboBox->addItem("中文");
        // 初始化翻译实例
        translation = new GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler;
        // 设置快捷键
        shortcut = new QShortcut(QKeySequence("Ctrl+Return"), this);
        shortcut_close = new QShortcut(QKeySequence("Ctrl+W"), this);
        // 信号连接
        connect(ui->pushButton_translate, &QPushButton::clicked, this, &main_screen::handleTranslation);
        connect(shortcut, &QShortcut::activated, this, &main_screen::handleTranslation);
        connect(shortcut_close, &QShortcut::activated, this, [this]{
            this->close();
        });
    }

    void main_screen::handleTranslation() const
    {
        const QString words = ui->textEdit->toPlainText();
        if (words.isEmpty())
        {
            ui->textBrowser_output->setText("请输入待翻译内容");
            return;
        }
        const QString to_language = (ui->comboBox->currentIndex() == 0) ? "en" : "zh-CH";
        // 翻译并修改显示的内容
        translation->get_translated_words(words, to_language);
        connect(translation, &GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler::translationFinished, this,
                [this](const QString& result)
                {
                    ui->textBrowser_output->setText(result);
                });
    }

    main_screen::~main_screen()
    {
        delete ui;
        delete translation;
    }
}
