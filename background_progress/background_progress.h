//
// Created by heiyt on 25-4-20.
//

#ifndef BACKGROUND_PROGRESS_H
#define BACKGROUND_PROGRESS_H

#include <QWidget>
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
        explicit background_progress(const QString& words, const QPoint& point, QWidget* parent = nullptr);
        ~background_progress() override;
    private:
        Ui::background_progress* ui;
        QShortcut* shortcut_close{};
    };
}// BACKGROUND

#endif //BACKGROUND_PROGRESS_H