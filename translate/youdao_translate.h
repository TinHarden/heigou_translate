//
// Created by heiyt on 25-4-5.
//

#ifndef YOUDAO_TRANSLATE_H
#define YOUDAO_TRANSLATE_H
#include <QJsonDocument>
#include <QNetworkReply>
#include <QRandomGenerator>
#include <QWidget>

#include "user_youdao_key.h"

namespace TRANSLATE
{
    class youdao_translate final : public QWidget {
        Q_OBJECT
    public:
        explicit youdao_translate(QWidget* parent) : QWidget(parent),
            appKey(APPKEY),
            appSecret(APPSECRET),
            url("https://openapi.youdao.com/v2/api") {
            manager = new QNetworkAccessManager(this);
        }
        void translate(const QString& text, const QString& to);

        signals:
        void translationFinished(const QString& result);

    private:
        QNetworkAccessManager* manager{};

        const QString appKey;
        const QString appSecret;
        const QString url;
        static QString getTranslationReply(QNetworkReply* reply);

    };
}


#endif //YOUDAO_TRANSLATE_H
