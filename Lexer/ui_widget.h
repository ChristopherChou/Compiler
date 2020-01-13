/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButtonOpen;
    QPushButton *pushButtonLex;
    QLabel *labelSrc;
    QLabel *labelLex;
    QTextEdit *textEditSrc;
    QTextEdit *textEditLex;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1200, 800);
        pushButtonOpen = new QPushButton(Widget);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        pushButtonOpen->setGeometry(QRect(0, 0, 150, 50));
        pushButtonLex = new QPushButton(Widget);
        pushButtonLex->setObjectName(QString::fromUtf8("pushButtonLex"));
        pushButtonLex->setGeometry(QRect(150, 0, 150, 50));
        labelSrc = new QLabel(Widget);
        labelSrc->setObjectName(QString::fromUtf8("labelSrc"));
        labelSrc->setGeometry(QRect(10, 50, 150, 40));
        labelLex = new QLabel(Widget);
        labelLex->setObjectName(QString::fromUtf8("labelLex"));
        labelLex->setGeometry(QRect(610, 50, 150, 40));
        textEditSrc = new QTextEdit(Widget);
        textEditSrc->setObjectName(QString::fromUtf8("textEditSrc"));
        textEditSrc->setGeometry(QRect(10, 100, 580, 680));
        textEditLex = new QTextEdit(Widget);
        textEditLex->setObjectName(QString::fromUtf8("textEditLex"));
        textEditLex->setGeometry(QRect(610, 100, 580, 680));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushButtonOpen->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        pushButtonLex->setText(QApplication::translate("Widget", "\350\257\215\346\263\225\345\210\206\346\236\220", nullptr));
        labelSrc->setText(QApplication::translate("Widget", "\346\272\220\347\250\213\345\272\217", nullptr));
        labelLex->setText(QApplication::translate("Widget", "\350\257\215\346\263\225\345\210\206\346\236\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
