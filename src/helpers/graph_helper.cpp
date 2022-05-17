
//
// Created by Administrator on 2022/5/1.
//
#include "graph_helper.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstdlib>
using namespace std;
void writeLineToTxt(std::string file,std::string line)
{
	std::ofstream ofs;
    ofs.open(file.c_str(),std::ios::out|std::ios::app);	//以输出追加方式打开文件，不存在则创建
    assert(ofs.is_open());   				//若失败,则输出错误消息,并终止程序运行
	ofs<<line<<std::endl;						//写入一行
	ofs.close();
}
void graph_open(std::string file,graphType gType,std::string name="graph",std::string comment="comment"){
    std::string type;
    switch (gType)
    {
        case graphType::LiuChengTu:type="graph TD;";break;
        case graphType::ShiXuTu:type="sequenceDiagram";break;
        case graphType::ZhuangTaiTu:type="stateDiagram";break;
        case graphType::LeiTu:type="classDiagram";break;
        case graphType::GanTeTu:type="gantt";break;
        case graphType::BingTu:type="pie";break;          
    }
    writeLineToTxt(file,"#### "+name+"");
    writeLineToTxt(file,"###### "+comment+"");
    writeLineToTxt(file,"```mermaid");
    writeLineToTxt(file,type+"");
    switch (gType)
    {
        case graphType::LiuChengTu:type="graph TD;";break;
        case graphType::ShiXuTu:type="sequenceDiagram";break;
        case graphType::ZhuangTaiTu:type="stateDiagram";break;
        case graphType::LeiTu:type="classDiagram";break;
        case graphType::GanTeTu:type="gantt"; writeLineToTxt(file,"\ttitle "+name+"");break;
        case graphType::BingTu:type="pie";writeLineToTxt(file,"\ttitle "+name+"");break;          
    }

    //dot
    switch (gType)
    {  
        case graphType::LiuChengTu:type="digraph";break;
        case graphType::ShiXuTu:type="digraph";break;
        case graphType::ZhuangTaiTu:type="digraph";break;
        case graphType::LeiTu:type="digraph";break;
        case graphType::GanTeTu:type="digraph";break;
        case graphType::BingTu:type="digraph";break;          
    }
    writeLineToTxt(file+".txt",type+" "+name+" {");
}

void graph_close(std::string file,std::string name,std::string comment){
    writeLineToTxt(file,"```");
    writeLineToTxt(file,"#### "+name+"");
    writeLineToTxt(file,"###### "+comment+"");
    writeLineToTxt(file+".txt","}");
}

void graph::set(std::string file,graphType gType,std::string name,std::string comment){
    graph::filePath = file+".txt";
    graph::dotPath = filePath+".txt";
    graph::file = file;
    graph::gType = gType;
    graph::name = name;
    graph::comment = comment;
}
void graph::begin(){
    graph_open(graph::filePath,gType,name,comment);
}
void graph::LiuChengTu_add(std::string s_1,std::string s_2,std::string detail){
    if(detail==""){
        writeLineToTxt(graph::filePath,"\t"+s_1+"-->"+s_2+";");
    }
    else{
        writeLineToTxt(graph::filePath,"\t"+s_1+"--"+detail+"-->"+s_2+";");
    }
    //dot
    writeLineToTxt(graph::dotPath,"\t"+s_1+"->"+s_2+"[color=""pink""];");
    writeLineToTxt(graph::dotPath,"\t"+s_1+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
    writeLineToTxt(graph::dotPath,"\t"+s_2+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
}
void graph::LeiTu_add(std::string s_1,std::string s_2){
    writeLineToTxt(graph::filePath,"\t"+s_1+"-->"+s_2+"");
    //dot
    writeLineToTxt(graph::dotPath,"\t"+s_1+"->"+s_2+"[color=""pink""];");
    writeLineToTxt(graph::dotPath,"\t"+s_1+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
    writeLineToTxt(graph::dotPath,"\t"+s_2+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
}
void graph::LeiTu_add_attr(std::string s,std::string attr){
    writeLineToTxt(graph::filePath,"\t"+s+" : "+attr+"");
}
void graph::ZhuangTaiTu_add(std::string s_1,std::string s_2){
    writeLineToTxt(graph::filePath,"\t"+s_1+" --> "+s_2+"");
    //dot
    if(s_1 == "[*]"){
        s_1 = "start";
    }
    if(s_2 == "[*]"){
        s_2 = "end";
    }
    writeLineToTxt(graph::dotPath,"\t"+s_1+"->"+s_2+"[color=""pink""];");
    writeLineToTxt(graph::dotPath,"\t"+s_1+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
    writeLineToTxt(graph::dotPath,"\t"+s_2+"[style = ""filled"", color = ""gray"", fillcolor = ""pink""]");
}
void graph::BingTu_add(std::string s_1,std::string s_2){
    writeLineToTxt(graph::filePath,"\t\""+s_1+"\" : "+s_2+"");
}
void graph::finish(std::string name,std::string comment){
    graph_close(graph::filePath,name,comment);
    writeLineToTxt(graph::filePath,"------");
}
void graph::close(){
    system(("mv "+graph::file+".txt "+graph::file+".md").c_str());
    system(("mv "+graph::file+".txt.txt "+graph::file+".dot").c_str());
}