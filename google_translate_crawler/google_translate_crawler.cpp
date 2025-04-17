
#include "google_translate_crawler.h"

namespace GOOGLE_TRANSLATE_CRAWLER {
    google_translate_crawler::google_translate_crawler(QObject* parent)
    {
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(r\".\")");
        this->pModule = PyImport_ImportModule("translate_web_crawler");
        this->pClass = PyObject_GetAttrString(pModule, "WebTranslator");
        this->pInstance = PyObject_CallObject(pClass, nullptr);
    }
    google_translate_crawler::~google_translate_crawler()
    {
        Py_XDECREF(this->pInstance);
        Py_XDECREF(this->pClass);
        Py_XDECREF(this->pModule);
        Py_FinalizeEx();
    }
    void google_translate_crawler::get_translated_words(const QString& words, const QString& target_lang)
    {
        PyGILState_STATE gil_state = PyGILState_Ensure();
        PyObject* pResult = PyObject_CallMethod(
            this->pInstance,
            "google_translate",
            "sss",
            words.toUtf8().constData(), "auto", target_lang.toUtf8().constData()
        );
        if (pResult && PyUnicode_Check(pResult))
        {
            emit translationFinished(QString::fromUtf8(PyUnicode_AsUTF8(pResult)));
        }
        else
        {
            emit translationFinished("error");
        }
        Py_XDECREF(pResult);
        PyGILState_Release(gil_state);
    }
} // namespace GOOGLE_TRANSLATE_CRAWLER