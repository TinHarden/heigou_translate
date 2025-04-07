/********************************************************************************
** Form generated from reading UI file 'settings_screen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_SCREEN_H
#define UI_SETTINGS_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

namespace SETTING_UI {

class Ui_settings_screen
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *SETTING_UI__settings_screen)
    {
        if (SETTING_UI__settings_screen->objectName().isEmpty())
            SETTING_UI__settings_screen->setObjectName("SETTING_UI__settings_screen");
        SETTING_UI__settings_screen->resize(260, 282);
        SETTING_UI__settings_screen->setMinimumSize(QSize(260, 282));
        SETTING_UI__settings_screen->setMaximumSize(QSize(260, 282));
        textEdit = new QTextEdit(SETTING_UI__settings_screen);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 30, 201, 70));
        label = new QLabel(SETTING_UI__settings_screen);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 121, 20));
        pushButton = new QPushButton(SETTING_UI__settings_screen);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 240, 90, 30));
        pushButton->setMinimumSize(QSize(90, 30));
        pushButton->setMaximumSize(QSize(90, 30));

        retranslateUi(SETTING_UI__settings_screen);

        QMetaObject::connectSlotsByName(SETTING_UI__settings_screen);
    } // setupUi

    void retranslateUi(QWidget *SETTING_UI__settings_screen)
    {
        SETTING_UI__settings_screen->setWindowTitle(QCoreApplication::translate("SETTING_UI::settings_screen", "settings_screen", nullptr));
        label->setText(QCoreApplication::translate("SETTING_UI::settings_screen", "\346\234\211\351\201\223\347\277\273\350\257\221api", nullptr));
        pushButton->setText(QCoreApplication::translate("SETTING_UI::settings_screen", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

} // namespace SETTING_UI

namespace SETTING_UI {
namespace Ui {
    class settings_screen: public Ui_settings_screen {};
} // namespace Ui
} // namespace SETTING_UI

#endif // UI_SETTINGS_SCREEN_H
