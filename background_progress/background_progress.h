//
// Created by heiyt on 25-4-20.
//

#ifndef BACKGROUND_PROGRESS_H
#define BACKGROUND_PROGRESS_H

#include <QLabel>
#include <QWidget>
#include <QScreen>
#include <QTimer>
#include <QShortcut>

#include "google_translate_crawler.h"

namespace BACKGROUND
{
    QT_BEGIN_NAMESPACE

    namespace Ui
    {
        class background_progress;
    }

    QT_END_NAMESPACE

    class background_progress : public QWidget
    {
        Q_OBJECT
    public:
        explicit background_progress(QWidget* parent = nullptr);
        void handleTranslation_huaci() const;
        ~background_progress() override;

    private:
        Ui::background_progress* ui;
        QLabel* mousePopup;
        QShortcut* shortcut_huaci{};
        GOOGLE_TRANSLATE_CRAWLER::google_translate_crawler* translation_huaci;
    };
}// BACKGROUND

#endif //BACKGROUND_PROGRESS_H
