//
//  Programmers17677 - 뉴스 클러스터링.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include<algorithm>
#include <string>
#include <set>
#include<map>
using namespace std;
int solution(string str1, string str2) {
    int answer = 0;
    multiset<string> ms1;
    multiset<string> ms2;
    set<string> all;
    set<string> gyojiphap;
    string str = "";
    for(int i=0;i<str1.length();i++){
        str = str + char(tolower(str1[i]));
        if(i != 0){
            if((str[0] >= 'a' && str[0] <= 'z') && (str[1] >= 'a' && str[1] <='z')){
                ms1.insert(str);
                all.insert(str);
                str = "";
            }
        }
        str = tolower(str1[i]);
    }
    for(int i=0;i<str2.length();i++){
        str = str + char(tolower(str2[i]));
        if(i != 0){
            if((str[0] >= 'a' && str[0] <= 'z') && (str[1] >= 'a' && str[1] <='z')){
                ms2.insert(str);
                if(all.count(str) == 0) all.insert(str);
                else gyojiphap.insert(str);
                str = "";
            }
        }
        str = tolower(str2[i]);
    }
//    for(auto iter = ms1.begin();iter != ms1.end();iter++){
//        cout << (*iter) << endl;
//    }
//    cout << "=====" << endl;
//    for(auto iter = ms2.begin();iter != ms2.end();iter++){
//        cout << (*iter) << endl;
//    }
//    cout << "=====" << endl;
//    for(auto iter = all.begin();iter != all.end();iter++){
//        cout << (*iter) << endl;
//    }
    int min_gyo = 0;
    int bunja = 0;
    int bunmo = ms1.size() + ms2.size();
    for(auto iter=gyojiphap.begin();iter!=gyojiphap.end();iter++){
        min_gyo = min(ms1.count(*iter),ms2.count(*iter));
        bunja += min_gyo;
        bunmo -= min_gyo;
    }
    cout << bunja << " " << bunmo << endl;
    if(bunmo == bunja) return 65536;
    answer = (double(bunja)/double(bunmo)) * 65536;
    return answer;
}
int main(){
    cout << solution("aa1+aa2", "AAAA12");
    return 0;
}
