
#include "Python.h"
#include "google_translate_crawler.h"

namespace GOOGLE_TRANSLATE_CRAWLER {
    void google_translate_crawler::get_translated_words(const QString& words, const QString& target_lang)
    {
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(\"..\\google_translate_crawler\")"); // ȷ��ģ��·����ȷ
        PyObject* pModule = PyImport_ImportModule("translate_web_crawler");
        PyObject* pClass = PyObject_GetAttrString(pModule, "WebTranslator");
        PyObject* pInstance = PyObject_CallObject(pClass, nullptr); // �޲�������
        PyObject* pArgs = PyTuple_New(3);
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(words.toStdString().c_str()));
        PyTuple_SetItem(pArgs, 1, PyUnicode_FromString("auto"));
        PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(target_lang.toStdString().c_str()));
        PyObject* pResult = PyObject_CallMethod(pInstance, "google_translate", nullptr, pArgs);
        if (pResult && PyUnicode_Check(pResult))
        {
            emit translationFinished(PyUnicode_AsUTF8(pResult));
        }
        else
        {
            emit translationFinished("error");
        }
        Py_DECREF(pResult);
        Py_DECREF(pArgs);
        Py_DECREF(pInstance);
        Py_DECREF(pClass);
        Py_DECREF(pModule);
        Py_Finalize();
    }
} // GOOGLE_TRANSLATE_CRAWLER