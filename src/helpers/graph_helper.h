
//
// Created by Administrator on 2022/5/1.
//
#ifndef COMPILER_GRAPH_HELPER_H
#define COMPILER_GRAPH_HELPER_H
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstdlib>
using namespace std;
enum class graphType{
    LiuChengTu,//流程图
    ShiXuTu,//时序图
    ZhuangTaiTu,//状态图
    LeiTu,//类图
    GanTeTu,//甘特图
    BingTu,//饼图
};
void writeLineToTxt(std::string file,string line);
void graph_open(string file,graphType gType,string name,string comment);
void graph_close(string file,string name,string comment);
class graph{
public:
	string file;
	string filePath;
	string dotPath;
    graphType gType;
    string name;
    string comment;
    void set(string file,graphType gType,string name,string comment);
    void begin();
    void LiuChengTu_add(string s_1,string s_2,string detail);
    void LeiTu_add(string s_1,string s_2);
    void LeiTu_add_attr(string s,string attr);
    void ZhuangTaiTu_add(string s_1,string s_2);
    void BingTu_add(string s_1,string s_2);
    void finish(string name,string comment);
    void close();
};
#endif

