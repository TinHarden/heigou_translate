
#include "background_progress.h"
#include "ui_background_progress.h"

namespace BACKGROUND
{
    background_progress::background_progress(const QString& words, const QPoint& point, QWidget* parent) :
        QWidget(parent), ui(new Ui::background_progress)
    {
        ui->setupUi(this);
        setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        move(point);
        ui->textBrowser->setText(words);
        // 快捷键关闭
        shortcut_close = new QShortcut(QKeySequence("Ctrl+W"), this);
        connect(shortcut_close, &QShortcut::activated, this, [this]
        {
            this->close();
        });
    }
    bool background_progress::eventFilter_bkgp(QObject *obj, QEvent *event)
    {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (!this->geometry().contains(mouseEvent->globalPos())) {
                this->close();
            }
        }
        return QWidget::eventFilter(obj, event);
    }
    background_progress::~background_progress()
    {
        delete ui;
    }
}// BACKGROUND