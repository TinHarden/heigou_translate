
#include "Python.h"
#include "google_translate_crawler.h"

namespace GOOGLE_TRANSLATE_CRAWLER {
    void google_translate_crawler::get_translated_words(const char* words, const char* target_lang,const char* result)
    {
        Py_Initialize();
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append(\"..\\translate_crawler\")"); // 确保模块路径正确
        PyObject* pModule = PyImport_ImportModule("translate_web_crawler");
        PyObject* pClass = PyObject_GetAttrString(pModule, "WebTranslator");
        // 3. 创建 WebTranslator 实例（调用构造函数）
        PyObject* pInstance = PyObject_CallObject(pClass, nullptr); // 无参数构造
        // 4. 准备调用方法 google_translate 的参数
        PyObject* pArgs = PyTuple_New(3);
        PyTuple_SetItem(pArgs, 0, PyUnicode_FromString(words));
        PyTuple_SetItem(pArgs, 1, PyUnicode_FromString("auto"));
        PyTuple_SetItem(pArgs, 2, PyUnicode_FromString(target_lang));
        // 5. 调用实例方法 google_translate
        PyObject* pResult = PyObject_CallMethodObjArgs(
            pInstance,
            PyUnicode_FromString("google_translate"), // 方法名
            pArgs, // 参数元组
            NULL
        );
        // 6. 处理结果
        if (pResult && PyUnicode_Check(pResult))
        {
            result = PyUnicode_AsUTF8(pResult);
        }
        else
        {
            result = "error";
        }
        // 7. 清理资源
        Py_DECREF(pResult);
        Py_DECREF(pArgs);
        Py_DECREF(pInstance);
        Py_DECREF(pClass);
        Py_DECREF(pModule);
        Py_Finalize();
    }
} // GOOGLE_TRANSLATE_CRAWLER