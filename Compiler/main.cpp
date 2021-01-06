#include "widget.h"

#include <QApplication>
#include<QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
