#ifndef GRAMMAR_H
#define GRAMMAR_H
#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>
#include<sstream>
#include"treeNode.h"
#include"vtable.h"
#define tokenNum 19
#define LeftS 21
#define OFileName "Gram.txt"
using namespace std;

class sentence
{
public:
    sentence* next;
    tokenTypes tokens[6];
    int tokenLen;
};

class generator
{
public:
    tokenTypes head;
    sentence* descri;
};

class Grammar
{
public:
    Grammar();
    ~Grammar();
    tokenTypes localStack[100] = {};
    int analyze(string filename);
    int getToken(string s);
    treeNode *grammarTree = NULL;

private:
    generator *rule = new generator[LeftS];
    sentence ***matrix = new sentence**[LeftS];
    void initialize();
    sentence* makerows(tokenTypes n, tokenTypes t, int cnt);
    void makeMatrix();
    string getmargin(int margin);
    void SplitString(const string& s, string& v, int &c);
    void generateTree();
    void delTree(treeNode *temp);
    VTable varTable;
    //int Expression(treeNode *express, char *place);
    void treeTra(treeNode *, int space);
};

#endif // GRAMMAR_H
