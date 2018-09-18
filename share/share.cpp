//
// Created by admin1 on 2018/9/18.
//

#include "share.h"


const string &share::getShareCode() const {
    return shareCode;
}

void share::setShareCode(const string &shareCode) {
    share::shareCode = shareCode;
}

const string &share::getIndustryCategory() const {
    return industryCategory;
}

void share::setIndustryCategory(const string &industryCategory) {
    share::industryCategory = industryCategory;
}

const string &share::getIndustryCode() const {
    return industryCode;
}

void share::setIndustryCode(const string &industryCode) {
    share::industryCode = industryCode;
}

const string &share::getExchangeCode() const {
    return exchangeCode;
}

void share::setExchangeCode(const string &exchangeCode) {
    share::exchangeCode = exchangeCode;
}

ostream &operator<<(ostream &os, const share &share1) {
    os << "exchangeCode: " << share1.exchangeCode << " shareCode: " << share1.shareCode << " industryCategory: "
       << share1.industryCategory << " industryCode: " << share1.industryCode;
    return os;
}

