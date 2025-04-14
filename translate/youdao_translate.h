//
// Created by heiyt on 25-4-5.
//

#ifndef YOUDAO_TRANSLATE_H
#define YOUDAO_TRANSLATE_H

#include <QNetworkReply>
#include <QRandomGenerator>
#include <QSettings>
#include <QWidget>

namespace TRANSLATE
{
    class youdao_translate final : public QWidget {
        Q_OBJECT
    public:
        QString appKey;
        QString appSecret;

        explicit youdao_translate(QWidget* parent) : QWidget(parent),
            url("https://openapi.youdao.com/v2/api") {
            load_youdao_api();
            manager = new QNetworkAccessManager(this);
        }
        void translate(const QString& text, const QString& to);
        void load_youdao_api();

        signals:
        void translationFinished(const QString& result);

    private:
        QNetworkAccessManager* manager{};
        const QString url;
        static QString getTranslationReply(QNetworkReply* reply);
    };
}


#endif //YOUDAO_TRANSLATE_H
