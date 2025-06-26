//
// Created by heiyt on 25-4-5.
//

#include "youdao_translate.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>

namespace TRANSLATE
{
    void youdao_translate::translate(const QString& text, const QString& to)
    {
        const QString salt = QString::number(QRandomGenerator::global()->generate());
        const QString curtime = QString::number(QDateTime::currentSecsSinceEpoch());
        QString input;
        if (text.length() > 20)
        {
            input = text.left(10)
                + QString::number(text.length())
                + text.right(10);
        }
        else
        {
            input = text;
        }
        const QByteArray sign = QCryptographicHash::hash(
            (appKey + input + salt + curtime + appSecret).toUtf8(),
            QCryptographicHash::Sha256
        ).toHex();
        QUrlQuery params;
        params.addQueryItem("q", text);
        params.addQueryItem("from", "auto");
        params.addQueryItem("to", to);
        params.addQueryItem("appKey", appKey);
        params.addQueryItem("salt", salt);
        params.addQueryItem("sign", sign);
        params.addQueryItem("signType", "v3");
        params.addQueryItem("curtime", curtime);
        QNetworkRequest request;
        request.setUrl(QUrl(url + "?" + params.toString()));
        QNetworkReply* reply = manager->get(request);
        connect(reply, &QNetworkReply::finished, [this, reply]
        {
            reply->deleteLater();
            if (reply->error() == QNetworkReply::NoError)
            {
                emit translationFinished(getTranslationReply(reply));
            }
            else
            {
                emit translationFinished("error1");
            }
        });
    }

    QString youdao_translate::getTranslationReply(QNetworkReply* reply)
    {
        QString show_words;
        QJsonObject rootObj = QJsonDocument::fromJson(reply->readAll()).object();
        if (rootObj["errorCode"].toString().toInt() == 0)
        {
            QJsonArray translateResults = rootObj["translateResults"].toArray();
            if (rootObj.contains("translateResults") && !translateResults.isEmpty())
            {
                for (const QJsonValue& result : translateResults)
                {
                    QJsonObject obj = result.toObject();
                    if (obj.contains("translation") && obj["translation"].isString())
                    {
                        show_words += obj["translation"].toString();
                    }
                }
            }
            else
            {
                show_words = "δ�ҵ�������";
            }
        }
        else
        {
            show_words = "error";
        }
        return show_words;
    }

    void youdao_translate::load_youdao_api()
    {
        const QSettings settings;
        appKey = settings.value("APPKEY").toString();
        appSecret = settings.value("APPSECRET").toString();
    }
}
