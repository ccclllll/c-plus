//
// Created by Administrator on 2018/9/18/018.
//

#ifndef SHARE_MAPSERVICE_H
#define SHARE_MAPSERVICE_H


#include <string>
#include <map>
#include <vector>
#include <string.h>
#include "../utils/MyUtils.h"
#include "../domain/share.h"
#include "../domain/industry.h"

using namespace std;

class MapService {

/** 生成与股票查询相关的map**/
public:
    map<string, vector<share>> buildShareMap(string file) {
        vector<string> result;
        vector<share> shares;
        map<string, vector<share>> shareMap;
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
            if (!&shareMap[share1.getIndustryCategory()]) {
                vector<share> shares1;
                shares1.push_back(share1);
                shareMap.insert(pair<string, vector<share>>(share1.getIndustryCategory(), shares1));
                shareMap.insert(pair<string, vector<share>>(share1.getIndustryCode(), shares1));
                shareMap.insert(pair<string, vector<share>>(share1.getShareCode(), shares1));
            } else {
                shareMap[share1.getIndustryCategory()].push_back(share1);
                shareMap[share1.getIndustryCode()].push_back(share1);
                shareMap[share1.getShareCode()].push_back(share1);
            }


            shares.push_back(share1);
        }
        infile.close();             //关闭文件输入流
        return shareMap;
}

/** 生成与行业查询相关的map**/
// map<string,industry> string:行业名称
public:
    map<string, vector<industry>> buildIndustryMap(string file) {
        vector<string> result;
        vector<industry> industries;
        map<string, vector<industry>> industryMap;
        MyUtils myUtils;
        ifstream infile;
        infile.open(file.data());   //将文件流对象与文件连接起来

        if (!infile.is_open()) {
            cout << "not open file" << endl;
        }

        string s;
        while (getline(infile, s)) {
            industry industry1;
            result = myUtils.split(s, "|");
            if (result.size() >= 2) {
                industry1.setIndustryCode(myUtils.trim(result[0]));
                industry1.setIndustryName(myUtils.trim(result[1]));
                if (!&industryMap[industry1.getIndustryName()]) {
                    vector<industry> values;
                    values.push_back(industry1);
                    industryMap.insert(pair<string, vector<industry>>(industry1.getIndustryName(), values));
                    industryMap.insert(pair<string, vector<industry>>(industry1.getIndustryCode(), values));
                } else {
                    industryMap[industry1.getIndustryName()].push_back(industry1);
                    industryMap[industry1.getIndustryCode()].push_back(industry1);
                }

            }
            industries.push_back(industry1);
        }
        return industryMap;
    }
};


#endif //SHARE_MAPSERVICE_H
