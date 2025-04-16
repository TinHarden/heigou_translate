//
// Created by heiyt on 25-4-16.
//

#ifndef GOOGLE_TRANSLATE_CRAWLER_H
#define GOOGLE_TRANSLATE_CRAWLER_H
#include <QObject>

namespace GOOGLE_TRANSLATE_CRAWLER {
    class google_translate_crawler : public QObject
    {
        Q_OBJECT
    public:
        static void google_translate_crawler::get_translated_words(const QString& words, const QString& target_lang);
        signals:
           static void translationFinished(const QString& result);
    };
} // GOOGLE_TRANSLATE_CRAWLER

#endif //GOOGLE_TRANSLATE_CRAWLER_H
