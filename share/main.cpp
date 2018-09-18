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

    // ���ݹ�Ʊ�������������ҵ
    cout<<"please enter share code"<<endl;
    string shareCode;
    cin>>shareCode;

    vector<industry> industry_result = queryService.findIndustryByShareCode(shareMap,industryMap,shareCode);
    //������
    cout << "���ҽ��Ϊ��" << endl;
    if(industry_result.size() == 0){
        cout << "δ�ҵ��κν��" << endl;
        return 0;
    }
    for (vector<industry>::iterator it = industry_result.begin(); it != industry_result.end(); ++it) {
        cout << (*it) << endl;
    }

    // ������ҵ���Ʋ������еĹ�Ʊ
    cout<<"please enter industry name"<<endl;
    string industry_name;
    cin>>industry_name;

    vector<share> share_result = queryService.findShareByIndustry(shareMap,industryMap,industry_name);
    cout << "���ҽ��Ϊ��" << endl;
    if(share_result.size() == 0){
        cout << "δ�ҵ��κν��" << endl;
        return 0;
    }
    for (vector<share>::iterator it = share_result.begin(); it != share_result.end(); ++it) {
        cout << (*it) << endl;
    }
    return 0;
}



