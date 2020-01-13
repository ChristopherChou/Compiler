#ifndef LEX_H
#define LEX_H
#pragma once
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<fstream>
#include"symtable.h"
//#define SFNAME "source.c"
#define TFNAME "Lex.txt"
#define SYMFNAME "symbol.txt"
typedef int sInt;

using namespace std;
class Lex
{
public:
    Lex();
    ~Lex();

    int analyze(string fileName);
    //TUnit *getTokenHead();
    //SUnit *getSymbol();

private:

    SymTable stable;
    char buffer[2][81];

    int lineNum;

    FILE *source;
    FILE *target;

    ofstream symbol;

    long beginp[5];   //记录文件指针的开始位置
    long endp[5];    //记录文件指针的结束位置

    char idStr[80] = "";   //保存标识符中间值
    int state[5] = { 0 }; //不同记号类型的状态
    char unaryOP[16] = { '+','-','*','/','<','>','=',';',',','(',')','{','}', '!' }; //保存一元运算符
    char *p[6] = { "int", "void", "while", "if", "else", "return" };  //系统保留字
    char *strToken[19] = { "关键字INT","关键字VOID","标识符ID","左括号LP","右括号RP", "左大括号LB", "右大括号RB", "关键字WHILE", "关键字IF", "关键字ELSE", "关键字RETURN", "赋值ASSIGN", "算符OP1", "算符OP2", "算符RELOP", "界符DEL", "分隔符SEP", "数字NUM", "换行符NL" };
    char *strOP[4] = { "<=", "!=", "==", ">=" };
    typedef enum { INT, VOID, ID, LP, RP, LB, RB, WHILE, IF, ELSE, RETURN, ASSIGN, OP1, OP2, RELOP, DEL, SEP, NUM, NL }tokenType; //记号类型

    void clearState();
    int strPrintf(long begin, long end, tokenType t);
    void unaryPrintf(char s, tokenType t); //解释一元运算符
    bool isOperator(char ch); //是否为一元运算符
    int comment(char ch, int i);
    int number(char ch, int i);
    int myOperator(char ch, int i);
    bool isLiter(char ch);
    bool isNum(char ch);
    int isResw(char *s);
    int identifier(char ch, int i);
    void addNewLine();
    int startScanner();
};
#endif // LEX_H
