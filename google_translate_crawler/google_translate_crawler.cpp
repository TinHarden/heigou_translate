#include "Python.h"
#include "google_translate_crawler.h"
#include <QDir>
namespace GOOGLE_TRANSLATE_CRAWLER {
    google_translate_crawler::google_translate_crawler(QObject* parent)
    {
        Py_Initialize();
    }
    google_translate_crawler::~google_translate_crawler()
    {
        Py_FinalizeEx();
    }
    void google_translate_crawler::get_translated_words(const QString& words, const QString& target_lang)
    {
        PyGILState_STATE gil_state = PyGILState_Ensure();
        PyObject *pModule = nullptr, *pClass = nullptr, *pInstance = nullptr;
        PyObject *pResult = nullptr;
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(r'../google_translate_crawler')");
        const char* words_cstr = words.toUtf8().constData();
        const char* lang_cstr = target_lang.toUtf8().constData();
        pModule = PyImport_ImportModule("translate_web_crawler");
        pClass = PyObject_GetAttrString(pModule, "WebTranslator");
        pInstance = PyObject_CallObject(pClass, nullptr);
        pResult = PyObject_CallMethod(
            pInstance,
            "google_translate",
            "sss",
            words_cstr, "auto", lang_cstr
        );
        if (!pResult && PyUnicode_Check(pResult))
        {
            const char* translated = PyUnicode_AsUTF8(pResult);
            emit translationFinished(QString::fromUtf8(translated));
        }
        else
        {
            emit translationFinished("error");
        }
        Py_XDECREF(pResult);
        Py_XDECREF(pInstance);
        Py_XDECREF(pClass);
        Py_XDECREF(pModule);
        PyGILState_Release(gil_state);
    }
} // namespace GOOGLE_TRANSLATE_CRAWLER