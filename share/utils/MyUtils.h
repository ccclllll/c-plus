//
// Created by admin1 on 2018/9/18.
//
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>

#include <vector>

using namespace std;

#ifndef SHARE_FILEUTILS_H
#define SHARE_FILEUTILS_H
/**
*
* @tparam T 生成对象的类型
* @tparam F 生成对象的策略
* @param filePath
* @param func
* @return
*/
class MyUtils {
public:
    string readTextFile(string file) {
        string ret;
        cout << file.data() << endl;

        ifstream infile;
        infile.open(file.data());   //将文件流对象与文件连接起来

        if(!infile.is_open()){
            cout<<"not open file"<<endl;
            return NULL;
        }

        string s;
        while (getline(infile, s)) {
       /*     cout << s << endl;*/
            ret += s;
        }
        infile.close();             //关闭文件输入流
        return ret;
    }
    //字符串分割函数
public:
    std::vector<std::string> split(std::string str,std::string pattern)
    {
        std::string::size_type pos;
        std::vector<std::string> result;
        str+=pattern;//扩展字符串以方便操作
        int size=str.size();

        for(int i=0; i<size; i++)
        {
            pos=str.find(pattern,i);
            if(pos<size)
            {
                std::string s=str.substr(i,pos-i);
                result.push_back(s);
                i=pos+pattern.size()-1;
            }
        }
        return result;
    }

    std::string& trim(std::string &s)
    {
        if (s.empty())
        {
            return s;
        }

        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }
};


#endif //SHARE_FILEUTILS_H
