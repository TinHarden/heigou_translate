/********************************************************************************
** Form generated from reading UI file 'main_screen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_SCREEN_H
#define UI_MAIN_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

namespace MAIN_SCREEN {

class Ui_main_screen
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_translate;
    QTextBrowser *textBrowser_output;
    QTextEdit *textEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MAIN_SCREEN__main_screen)
    {
        if (MAIN_SCREEN__main_screen->objectName().isEmpty())
            MAIN_SCREEN__main_screen->setObjectName("MAIN_SCREEN__main_screen");
        MAIN_SCREEN__main_screen->resize(240, 300);
        MAIN_SCREEN__main_screen->setMinimumSize(QSize(240, 280));
        centralwidget = new QWidget(MAIN_SCREEN__main_screen);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(2, 0, 2, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(60, 30));
        comboBox->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(comboBox);

        pushButton_translate = new QPushButton(centralwidget);
        pushButton_translate->setObjectName("pushButton_translate");

        horizontalLayout->addWidget(pushButton_translate);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        textBrowser_output = new QTextBrowser(centralwidget);
        textBrowser_output->setObjectName("textBrowser_output");

        gridLayout->addWidget(textBrowser_output, 2, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MAIN_SCREEN__main_screen->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MAIN_SCREEN__main_screen);
        statusBar->setObjectName("statusBar");
        MAIN_SCREEN__main_screen->setStatusBar(statusBar);

        retranslateUi(MAIN_SCREEN__main_screen);

        QMetaObject::connectSlotsByName(MAIN_SCREEN__main_screen);
    } // setupUi

    void retranslateUi(QMainWindow *MAIN_SCREEN__main_screen)
    {
        MAIN_SCREEN__main_screen->setWindowTitle(QCoreApplication::translate("MAIN_SCREEN::main_screen", "\351\273\221\347\213\227\347\277\273\350\257\221", nullptr));
        pushButton_translate->setText(QCoreApplication::translate("MAIN_SCREEN::main_screen", "\347\277\273\350\257\221", nullptr));
    } // retranslateUi

};

} // namespace MAIN_SCREEN

namespace MAIN_SCREEN {
namespace Ui {
    class main_screen: public Ui_main_screen {};
} // namespace Ui
} // namespace MAIN_SCREEN

#endif // UI_MAIN_SCREEN_H
