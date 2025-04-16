#include "Python.h"
#include "google_translate_crawler.h"

namespace GOOGLE_TRANSLATE_CRAWLER {
    void google_translate_crawler::get_translated_words(const QString& words, const QString& target_lang)
    {
        Py_Initialize();
        PyObject *pModule = nullptr, *pClass = nullptr, *pInstance = nullptr;
        PyObject *pArgs = nullptr, *pResult = nullptr;
        try {
            PyRun_SimpleString("import sys");
            PyRun_SimpleString("sys.path.append(r\"..\\google_translate_crawler\")");  // 使用原始字符串语法
            const QByteArray wordsUtf8 = words.toUtf8();
            const QByteArray langUtf8 = target_lang.toUtf8();
            const char* words_cstr = wordsUtf8.constData();
            const char* lang_cstr = langUtf8.constData();
            pModule = PyImport_ImportModule("translate_web_crawler");
            pClass = PyObject_GetAttrString(pModule, "WebTranslator");
            pInstance = PyObject_CallObject(pClass, nullptr);
            pArgs = PyTuple_New(3);
            PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(words_cstr));
            PyTuple_SetItem(pArgs, 1, PyUnicode_FromString("auto"));
            PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(lang_cstr));
            pResult = PyObject_CallMethod(pInstance, "google_translate", nullptr, pArgs);
            if (PyUnicode_Check(pResult)) {
                const char* translated = PyUnicode_AsUTF8(pResult);
                emit translationFinished(QString::fromUtf8(translated));
            } else {
                emit translationFinished("error");
            }
        } catch (const std::exception& e) {
            emit translationFinished("error");
        }
        Py_XDECREF(pResult);
        Py_XDECREF(pArgs);
        Py_XDECREF(pInstance);
        Py_XDECREF(pClass);
        Py_XDECREF(pModule);
        Py_FinalizeEx();
    }
} // namespace GOOGLE_TRANSLATE_CRAWLER