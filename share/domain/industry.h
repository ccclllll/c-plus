//
// Created by admin1 on 2018/9/18.
//
#include <string>
#include <ostream>

using namespace std;
#ifndef SHARE_INDUSTRY_H
#define SHARE_INDUSTRY_H

// 行业类
class industry {
private:
    string industryCategoryCode; // 行业类别代码
private:
    string industryCode; // 行业代码
private:
    string industryName; // 行业名称
public:
    const string &getIndustryCategoryCode() const;

    void setIndustryCategoryCode(const string &industryCategoryCode);

    const string &getIndustryCode() const;

    void setIndustryCode(const string &industryCode);

    const string &getIndustryName() const;

    void setIndustryName(const string &industryName);

    friend ostream &operator<<(ostream &os, const industry &industry1);
};


#endif //SHARE_INDUSTRY_H
