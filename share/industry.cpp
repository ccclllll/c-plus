//
// Created by admin1 on 2018/9/18.
//

#include "industry.h"

const string &industry::getIndustryCategoryCode() const {
    return industryCategoryCode;
}

void industry::setIndustryCategoryCode(const string &industryCategoryCode) {
    industry::industryCategoryCode = industryCategoryCode;
}

const string &industry::getIndustryCode() const {
    return industryCode;
}

void industry::setIndustryCode(const string &industryCode) {
    industry::industryCode = industryCode;
}

const string &industry::getIndustryName() const {
    return industryName;
}

void industry::setIndustryName(const string &industryName) {
    industry::industryName = industryName;
}

ostream &operator<<(ostream &os, const industry &industry1) {
    os << "industryCategoryCode: " << industry1.industryCategoryCode << " industryCode: " << industry1.industryCode
       << " industryName: " << industry1.industryName;
    return os;
}
