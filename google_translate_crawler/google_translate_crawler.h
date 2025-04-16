//
// Created by heiyt on 25-4-16.
//

#ifndef GOOGLE_TRANSLATE_CRAWLER_H
#define GOOGLE_TRANSLATE_CRAWLER_H

#include <QObject>
#define _hypot hypot
#undef slots
#include <Python.h>

namespace GOOGLE_TRANSLATE_CRAWLER {
    class google_translate_crawler final : public QObject
    {
        Q_OBJECT
    public:
        explicit google_translate_crawler(QObject* parent = nullptr);
        ~google_translate_crawler() override;
        void get_translated_words(const QString& words, const QString& target_lang);
    signals:
        void translationFinished(const QString& result);
    private:
        PyObject *pModule, *pClass, *pInstance;
    };
} // GOOGLE_TRANSLATE_CRAWLER

#endif //GOOGLE_TRANSLATE_CRAWLER_H
