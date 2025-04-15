//
// Created by heiyt on 25-4-16.
//
#include "Python.h"

#include "google_translate_crawler.h"

namespace GOOGLE_TRANSLATE_CRAWLER {
    void google_translate_crawler::get_translated_words()
    {
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(\"..\\translate_web_crawler\")");
        PyObject* pModule = PyImport_ImportModule("translate_web_crawler");
        PyObject* pFunc = PyObject_GetAttrString(pModule, "hello");
        PyObject_CallFunction(pFunc, nullptr);
        Py_DECREF(pFunc);
        Py_DECREF(pModule);
        Py_Finalize();
    }
} // GOOGLE_TRANSLATE_CRAWLER