//
//  Programmers17680 - 캐시.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int find(vector<string> &cache,string str){
    for(int i=0;i<cache.size();i++){
        if(cache[i] == str) return i;
    }
    return 987654321;
}
int max_used(vector<int> &used){
    int max = -1;
    int ret = -1;
    for(int i=0;i<used.size();i++){
        if(max < used[i]){
            max = used[i];
            ret = i;
        }
    }
    return ret;
}
string to_lower(string str){
    for(int i=0;i<str.size();i++){
        if(str[i] >='A' && str[i] <= 'Z') str[i] += 32;
    }
    return str;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<int> used;
    vector<string> cache;
    if(cacheSize == 0) return 5 * cities.size();
    for(int i=0;i<cities.size();i++){
        string city = to_lower(cities[i]);
        if(cache.size() < cacheSize){
            if(find(cache,city) == 987654321){
                cache.push_back(city);
                used.push_back(-1);
                answer += 5;
            }
            else{
                used[find(cache,city)] = -1;
                answer += 1;
            }
        }
        else{ // 교체
            if(find(cache,city) == 987654321){
                cache[max_used(used)] = city;
                used[max_used(used)] = -1;
                answer += 5;
            }
            else{
                used[find(cache,city)] = -1;
                answer += 1;
            }
        }
        for(int i=0;i<used.size();i++) used[i]++;
        for(int z=0;z<cache.size();z++){
            cout << cache[z] << " ";
        }
        cout << endl;
        cout << "=========="<<endl;
        
    }
    return answer;
}

int main(){
    cout << solution(2,{"Jeju", "Pangyo", "NewYork", "newyork"}) << endl;
    return 0;
}
