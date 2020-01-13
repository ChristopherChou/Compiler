#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QDateTime>
#include<QTextEdit>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonOpen_clicked()
{
    source_path=QFileDialog::getOpenFileName(this,tr("文件"),"");
    QFile source(source_path);

    if(!source.open(QFile::ReadOnly|QFile::Text))
    {
        //QMessageBox::warning(this,tr("Error"),
                                 //tr("read file error"));
        log_info+=QDateTime::currentDateTime().toString();
        log_info=log_info+" 打开文件 "+source_path+" 失败\n";
    }
    else
    {
        log_info+=QDateTime::currentDateTime().toString();
        log_info=log_info+" 打开文件 "+source_path+" 成功\n";
    }

    QTextStream file(&source);
    QFont font("consolas",15);

    this->ui->textEditSrc->setFont(QFont("consolas",15));
    this->ui->textEditSrc->setText(file.readAll());
    source.close();
}

void Widget::on_pushButtonLex_clicked()
{
    Lex lex_a;
    int i=0;
    for(i=source_path.size()-1;i>0;i--)
    {
        if(source_path[i]=='/')
            break;
    }
    source_path.remove(0,i+1);
    int n=lex_a.analyze(source_path.toStdString());
    if(n<0)
    {
        log_info+=QDateTime::currentDateTime().toString();
        log_info+=" error:";
        log_info+=QString::number(n,10);
        log_info+=" 词法分析错误 ,打开源代码失败\n";
    }
    else if(n>0)
    {
        log_info=log_info+QDateTime::currentDateTime().toString()+" 词法分析错误 ";
        log_info=log_info+"error in line "+QString::number(n)+"\n";
    }
    //词法分析的显示
    else
    {
        QFile target(LEX_FILE);
        if(!target.open(QFile::ReadOnly|QFile::Text))
        {
            log_info=log_info+QDateTime::currentDateTime().toString();
            log_info+=" 打开词法分析结果失败\n";
        }
        QTextStream file_t(&target);
        this->ui->textEditLex->setFont(QFont("consolas",13));
        this->ui->textEditLex->setText(file_t.readAll());
        target.close();
        log_info=log_info+QDateTime::currentDateTime().toString()+" 词法分析完成\n";

        QFile symbol("symbol.txt");
        if(!symbol.open(QFile::ReadOnly|QFile::Text))
        {
            log_info=log_info+QDateTime::currentDateTime().toString();
            log_info+=" 打开符号表失败\n";
        }
        QTextStream file_s(&symbol);
        symbol.close();
    }
}
