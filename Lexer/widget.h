#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "lex.h"
#define LEX_FILE "Lex.txt"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QString log_info;//日志信息
    QString source_path;

private slots:
    void on_pushButtonOpen_clicked();

    void on_pushButtonLex_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
