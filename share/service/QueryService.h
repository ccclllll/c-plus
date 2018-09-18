//
// Created by Administrator on 2018/9/18/018.
//
#include <string>
#include <map>
#include <vector>
#include <string.h>
#include "../utils/MyUtils.h"
#include "../domain/share.h"
#include "../domain/industry.h"
#include "MapService.h"

using namespace std;
#ifndef SHARE_QUERYSERVICE_H
#define SHARE_QUERYSERVICE_H


class QueryService {

/** 根据股票代码查找所属行业*/
public:
    vector<industry>
    findIndustryByShareCode(map<string, vector<share>> shareMap, map<string, vector<industry>> industryMap,
                            string shareCode) {
        vector<share> share1 = shareMap[shareCode];
        vector<industry> ret;
        for (vector<share>::iterator it3 = share1.begin(); it3 != share1.end(); ++it3) {
            //根据行业代号或者行业类别找到相应的行业
            vector<industry> industries1 = industryMap[(*it3).getIndustryCode()];
            vector<industry> industries2 = industryMap[(*it3).getIndustryCategory()];
            ret.insert(ret.end(), industries1.begin(), industries1.end());
            ret.insert(ret.end(), industries2.begin(), industries2.end());
        }
        return ret;
    }

/**  根据行业名称查找所有的股票 */
public:
    vector<share> findShareByIndustry(map<string, vector<share>> shareMap, map<string, vector<industry>> industryMap,
                                      string industryName) {
        vector<share> ret;
        vector<industry> industries = industryMap[industryName];
        for (vector<industry>::iterator it1 = industries.begin(); it1 != industries.end(); ++it1) {
            vector<share> shares = shareMap[(*it1).getIndustryCode()];
            ret.insert(ret.end(), shares.begin(), shares.end());
        }
        return ret;
    }
};


#endif //SHARE_QUERYSERVICE_H
