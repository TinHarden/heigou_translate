//
// Created by heiyt on 25-4-20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_background_progress.h" resolved

#include "background_progress.h"

#include <QProcess>

#include "ui_background_progress.h"

namespace BACKGROUND
{
    background_progress::background_progress(QWidget* parent) :
        QWidget(parent), ui(new Ui::background_progress)
    {
        ui->setupUi(this);
        mousePopup = new QLabel(nullptr, Qt::ToolTip | Qt::FramelessWindowHint);
        mousePopup->hide();
        mousePopup->setTextInteractionFlags(Qt::TextSelectableByMouse); // 可选：允许文本选择
        translation_huaci = new GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler();
        shortcut_huaci = new QShortcut(QKeySequence("H"), this);
        connect(shortcut_huaci, &QShortcut::activated, this, &background_progress::handleTranslation_huaci);
        connect(translation_huaci, &GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler::translationFinished, this,
                [this](const QString& result)
                {
                    mousePopup->setText(result);
                    mousePopup->adjustSize();
                    QPoint cursorPos = QCursor::pos();
                    QScreen* screen = QGuiApplication::screenAt(cursorPos);
                    QRect screenRect = screen->availableGeometry();
                    int x = cursorPos.x() + 16;
                    int y = cursorPos.y() + 16;
                    if (x + mousePopup->width() > screenRect.right()) {
                        x = cursorPos.x() - mousePopup->width() - 16;
                    }
                    if (y + mousePopup->height() > screenRect.bottom()) {
                        y = cursorPos.y() - mousePopup->height() - 16;
                    }
                    mousePopup->move(x, y);
                    mousePopup->show();
                    QTimer::singleShot(5000, mousePopup, [this]() {
                        if (mousePopup) mousePopup->hide();
                           });
                });
    }
    void background_progress::handleTranslation_huaci() const
    {
        QProcess process;
        process.start("xclip", {"-selection", "primary", "-out"});
        process.waitForFinished();
        const QString words = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
        // const QString to_language = (ui->comboBox->currentIndex() == 0) ? "en" : "zh-CH";
        translation_huaci->get_translated_words(words, "en");
    }

    background_progress::~background_progress()
    {
        delete ui;
        delete mousePopup;
        delete translation_huaci;
    }
}// BACKGROUND
