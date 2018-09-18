#include <map>

#include <string>

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include "utils/MyUtils.h"
#include "domain/share.h"
#include "domain/industry.h"
#include "service/MapService.h"
#include "service/QueryService.h"
#include <locale>
using namespace std;

int main(){
    string share_path = "F:\\workspace\\github\\c-plus\\work\\tdxhy.cfg";
    string industry_path = "F:\\workspace\\github\\c-plus\\work\\incon.dat";
    MapService mapService;
    QueryService queryService;

    map<string,vector<share>> shareMap = mapService.buildShareMap(share_path);
    map<string,vector<industry>> industryMap = mapService.buildIndustryMap(industry_path);

    // 根据股票代码查找所属行业
    cout<<"please enter share code"<<endl;
    string shareCode;
    cin>>shareCode;

    vector<industry> industry_result = queryService.findIndustryByShareCode(shareMap,industryMap,shareCode);
    //输出结果
    cout << "查找结果为：" << endl;
    if(industry_result.size() == 0){
        cout << "未找到任何结果" << endl;
        return 0;
    }
    for (vector<industry>::iterator it = industry_result.begin(); it != industry_result.end(); ++it) {
        cout << (*it) << endl;
    }

    // 根据行业名称查找所有的股票
    cout<<"please enter industry name"<<endl;
    string industry_name;
    cin>>industry_name;

    vector<share> share_result = queryService.findShareByIndustry(shareMap,industryMap,industry_name);
    cout << "查找结果为：" << endl;
    if(share_result.size() == 0){
        cout << "未找到任何结果" << endl;
        return 0;
    }
    for (vector<share>::iterator it = share_result.begin(); it != share_result.end(); ++it) {
        cout << (*it) << endl;
    }
    return 0;
}



