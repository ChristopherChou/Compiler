#include "widget.h"
#include "ui_widget.h"
#include"generate.h"
#include"fourformat.h"
#include"object.h"
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

void Widget::subLex()
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
        this->ui->textEditLex->setFont(QFont("consolas",10));
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

    this->ui->textEditSrc->setFont(QFont("consolas",10));
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
        this->ui->textEditLex->setFont(QFont("consolas",10));
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

void Widget::on_pushButtonGram_clicked()
{
    subLex();
    Grammar gram_a;
       int n=gram_a.analyze(LEX_FILE);
       if(n<0)
       {
           log_info+=QDateTime::currentDateTime().toString();
           log_info+=" 语法分析错误 ,打开文件失败\n";
           //this->ui->textEdit_info->setText(log_info);
           QMessageBox::warning(this,tr("Error"),tr("Error"));
       }
       else if(n>0)
       {
          log_info=log_info+QDateTime::currentDateTime().toString()+" 词法分析错误 ";
          log_info=log_info+"error in line "+QString::number(n)+"\n";
          //this->ui->textEdit_info->setText(log_info);
          QMessageBox::warning(this,tr("Error"),tr("Error"));
       }
   //语法分析的显示
       else
       {
           QFile target(GRAM_FILE);
           if(!target.open(QFile::ReadOnly|QFile::Text))
           {
               log_info=log_info+QDateTime::currentDateTime().toString();
               log_info+=" 打开语法分析结果失败\n";
               //this->ui->textEdit_info->setText(log_info);
               QMessageBox::warning(this,tr("Error"),tr("Error"));
           }
           QTextStream file(&target);
           this->ui->textEditGram->setFont(QFont("consolas",10));
           this->ui->textEditGram->setText(file.readAll());
           target.close();
           log_info=log_info+QDateTime::currentDateTime().toString()+" 语法分析完成\n";
           //this->ui->textEdit_info->setText(log_info);

           QFile symbol("symbol.txt");
           if(!symbol.open(QFile::ReadOnly|QFile::Text))
           {
               log_info=log_info+QDateTime::currentDateTime().toString();
               log_info+=" 打开符号表结果失败\n";
               //this->ui->textEdit_info->setText(log_info);
               QMessageBox::warning(this,tr("Error"),tr("Error"));
           }
           QTextStream file_s(&symbol);
           //this->ui->textEdit_table->setFont(QFont("consolas",15));
           //this->ui->textEdit_table->setText(file_s.readAll());
           log_info=log_info+QDateTime::currentDateTime().toString();
           log_info+=" 符号表更新完成\n";
           //this->ui->textEdit_info->setText(log_info);
           symbol.close();
       }
}

void Widget::on_pushButtonMid_clicked()
{
    Grammar *gram_a = new Grammar;
       gram_a->analyze(LEX_FILE);
       Generate *gene_a=new Generate(gram_a->grammarTree);
       int n=gene_a->analyse();
       //qDebug()<<n;
       if(n<0)
       {
           log_info=log_info+QDateTime::currentDateTime().toString()+" 中间代码生成错误, ";
           log_info=log_info+"文件打开失败\n";
          // this->ui->textEdit_info->setText(log_info);
           QMessageBox::warning(this,tr("Error"),tr("Error"));
       }
       else
       {
           Fourformat f;
           f.getfourformat("generate.txt");
           QFile gene_file("format.txt");
           if(!gene_file.open(QFile::ReadOnly|QFile::Text))
           {
               ;
           }
           QTextStream file_s(&gene_file);
           this->ui->textEditMid->setFont(QFont("consolas",15));
           this->ui->textEditMid->setText(file_s.readAll());
           gene_file.close();


           log_info=log_info+QDateTime::currentDateTime().toString()+" 中间代码生成完成\n";
           //this->ui->textEdit_info->setText(log_info);
           QString table="";
           for(int i=0;i<gene_a->namelist.size();i++)
           {
               table=table+QString::fromStdString(gene_a->namelist[i]);
               table=table+"\n";
           }
           //this->ui->textEdit_table->setFont(QFont("consolas",15));
           //this->ui->textEdit_table->setText(table);
           QFile obj_table("obj_table.txt");
           if(!obj_table.open(QFile::WriteOnly|QFile::Text))
                  qDebug()<<"error";
           QTextStream file_obj(&obj_table);
           file_obj<<table;
           obj_table.close();


               //qDebug()<<s;
           //}
       }

}

void Widget::on_pushButtonTar_clicked()
{
    object ob_a;
    ob_a.get_format();
    ob_a.object_code();
    QFile target("target.asm");
    if(!target.open(QFile::ReadOnly|QFile::Text))
           qDebug()<<"error";
    QTextStream out_t(&target);
    this->ui->textEditTar->setFont(QFont("consolas",15));
    this->ui->textEditTar->setText(out_t.readAll());
    log_info=log_info+QDateTime::currentDateTime().toString();
    log_info+=" 目标代码生成完成\n";
    //this->ui->textEdit_info->setText(log_info);

}
