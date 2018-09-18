//
// Created by admin1 on 2018/9/18.
//

#ifndef SHARE_SHARE_H
#define SHARE_SHARE_H

#include <string>
#include <ostream>

using namespace std;
class share {
private:
    string exchangeCode; // 交易所代号
private:
    string shareCode; // 股票代码
private:
    string industryCategory; // 行业类别代码
public:
    string industryCode; // 行业代码
    const string &getExchangeCode() const;

    void setExchangeCode(const string &exchangeCode);

    const string &getShareCode() const;

    void setShareCode(const string &shareCode);

    const string &getIndustryCategory() const;

    void setIndustryCategory(const string &industryCategory);

    const string &getIndustryCode() const;

    void setIndustryCode(const string &industryCode);


    friend ostream &operator<<(ostream &os, const share &share1);


};


#endif //SHARE_SHARE_H
