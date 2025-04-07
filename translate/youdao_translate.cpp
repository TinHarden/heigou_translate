//
// Created by heiyt on 25-4-5.
//

#include "youdao_translate.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QUrlQuery>

namespace TRANSLATE
{
    void youdao_translate::translate(const QString& text, const QString& to)
    {
        // 生成签名参数
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
        // 构建请求参数
        QUrlQuery params;
        params.addQueryItem("q", text);
        params.addQueryItem("from", "auto");
        params.addQueryItem("to", to);
        params.addQueryItem("appKey", appKey);
        params.addQueryItem("salt", salt);
        params.addQueryItem("sign", sign);
        params.addQueryItem("signType", "v3");
        params.addQueryItem("curtime", curtime);
        // 发送请求
        QNetworkRequest request;
        request.setUrl(QUrl(url + "?" + params.toString()));
        // 获取返回的数据
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
        if (QJsonObject rootObj = QJsonDocument::fromJson(reply->readAll()).object(); rootObj["errorCode"].toString().toInt() == 0)
        {
            if (rootObj.contains("translateResults"))
            {
                if (QJsonArray translateResults = rootObj["translateResults"].toArray(); !translateResults.isEmpty())
                {
                   for (const QJsonValue& result : translateResults) {
                       if (QJsonObject obj = result.toObject(); obj.contains("translation") && obj["translation"].isString()) {
                           show_words += obj["translation"].toString();
                       }
                   }
                }
                else
                {
                    show_words = "未找到翻译结果";
                }
            }
        }
        else
        {
            show_words = "error";
            qDebug() << rootObj["errorCode"].toString().toInt();
        }
        return show_words;
    }
}
