#include <map>

#include <string>

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include "MyUtils.h"
#include "share.h"
#include "industry.h"
#include <locale>
using namespace std;

map<string,vector<share>> readShare(string file) {
    vector<string> result;
    vector<share> shares;
    map<string,vector<share>> shareMap;
    MyUtils myUtils;
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来

    if (!infile.is_open()) {
        cout << "not open file" << endl;
    }

    string s;

    while (getline(infile, s)) {
        share share1;

        result = myUtils.split(s, "|");
        share1.setExchangeCode(result[0]);
        share1.setShareCode(result[1]);
        share1.setIndustryCategory(result[2]);
        share1.setIndustryCode(result[3]);
        if(!&shareMap[share1.getIndustryCategory()]){
            vector<share> shares1;
            shares1.push_back(share1);
            shareMap.insert(pair<string,vector<share>>(share1.getIndustryCategory(),shares1));
            shareMap.insert(pair<string,vector<share>>(share1.getIndustryCode(),shares1));
            shareMap.insert(pair<string,vector<share>>(share1.getShareCode(),shares1));
        }else{
            shareMap[share1.getIndustryCategory()].push_back(share1);
            shareMap[share1.getIndustryCode()].push_back(share1);
            shareMap[share1.getShareCode()].push_back(share1);
        }


        shares.push_back(share1);
    }
    infile.close();             //关闭文件输入流
    return shareMap;
}

// map<string,industry> string:行业名称
map<string,vector<industry>> readIndustry(string file) {
    vector<string> result;
    vector<industry> industries;
    map<string,vector<industry>> industryMap;
    MyUtils myUtils;
    ifstream infile;
    infile.open(file.data());   //将文件流对象与文件连接起来

    if (!infile.is_open()) {
        cout << "not open file" << endl;
    }

    string s;
    while (getline(infile, s)) {
        industry industry1;
        result = myUtils.split(s,"|");
        if(result.size()>=2){
            industry1.setIndustryCode(myUtils.trim(result[0]));
            industry1.setIndustryName(myUtils.trim(result[1]));
            if(!&industryMap[industry1.getIndustryName()]){
                vector<industry> values;
                values.push_back(industry1);
                industryMap.insert(pair<string,vector<industry>>(industry1.getIndustryName(),values));
                industryMap.insert(pair<string,vector<industry>>(industry1.getIndustryCode(),values));
            }else{
                industryMap[industry1.getIndustryName()].push_back(industry1);
                industryMap[industry1.getIndustryCode()].push_back(industry1);
            }

        }
        industries.push_back(industry1);
    }
/*    for (vector<industry>::iterator it = industries.begin(); it != industries.end(); ++it) {
        cout << (*it) << endl;
    }*/
    return industryMap;
}

/**
 *
 * @tparam T 生成对象的类型
 * @tparam F 生成对象的策略
 * @param filePath
 * @param func
 * @return
 */
template<class T, class F>
vector<T> readText(string filePath, F func) {
    vector<T> result;

    MyUtils myUtils;
    ifstream infile;
    infile.open(filePath.data());   //将文件流对象与文件连接起来

    if (!infile.is_open()) {
        cout << "not open file" << endl;
    }

    string s;

    while (getline(infile, s)) {
        result.push_back(func(s));
    }
    infile.close();             //关闭文件输入流
    return result;
}


int main() {

    map<string,vector<industry>> industryMap;
    map<string,vector<share>> shareMap;
    industryMap = readIndustry("c:\\cl\\c++\\work\\incon.dat");
    shareMap = readShare("c:\\cl\\c++\\work\\tdxhy.cfg");
    cout<<"please enter industry name"<<endl;
    string s;
    cin>>s;
    // 根据行业名称查找所有的股票
    vector<industry> industries = industryMap[s];
    for(vector<industry>::iterator it1 = industries.begin();it1!=industries.end();++it1){
        vector<share> shares = shareMap[(*it1).getIndustryCode()];
        for (vector<share>::iterator it2 = shares.begin(); it2 != shares.end(); ++it2) {

            cout<<(*it2)<<endl;
        }
    }

    // 根据股票代码查找所属行业
    cout<<"please enter share code"<<endl;
    string shareCode;
    cin>>shareCode;
    vector<share> share1 = shareMap[shareCode]; // 根据股票代码找到对应的股票
    for(vector<share>::iterator it3 = share1.begin();it3!=share1.end();++it3){
        cout<<(*it3)<<endl;
        //根据行业代号或者行业类别找到相应的行业
        vector<industry> industries1 = industryMap[(*it3).getIndustryCode()];
        vector<industry> industries2 = industryMap[(*it3).getIndustryCategory()];

        industries1.insert(industries1.end(),industries2.begin(),industries2.end());
        for (vector<industry>::iterator it4 = industries1.begin(); it4 != industries1.end(); ++it4) {
            cout<<(*it4)<<endl;
        }
    }

    return 0;
}



