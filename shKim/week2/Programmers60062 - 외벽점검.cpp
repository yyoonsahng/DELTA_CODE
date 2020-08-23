//
//  Programmers60062 - 외벽점검.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/19.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool cmp(pair<pair<int,int>,pair<int,int>> &left, pair<pair<int,int>,pair<int,int>> &right){
    return left.second.first > right.second.first;
}
bool reverse_cmp(pair<pair<int,int>,pair<int,int>> &left, pair<pair<int,int>,pair<int,int>> &right){
    return left.second.second > right.second.second;
}

map<pair<int,int>,pair<int,int>> m; //시계,반tlrP
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    for(int i=0;i<weak.size()-1;i++){
        for(int j=i+1;j<weak.size();j++){
            m.insert({{i,j},{weak[j]-weak[i],n - (weak[j] - weak[i])}});
            m.insert({{j,i},{n - (weak[j] - weak[i]),weak[j]-weak[i]}});
        }
    }
    vector<pair<pair<int,int>,pair<int,int>>> vec(m.begin(),m.end());
    sort(vec.begin(),vec.end(),cmp);
    sort(dist.begin(),dist.end(),greater<int>());
    for(int i=0;i<dist.size();i++){
        int current = dist[i];
        for(auto iter = m.begin(); iter != m.end(); iter++){
            
        }
    }
    return answer;
}
int main(){
    //12, [1, 5, 6, 10], [1, 2, 3, 4]
    cout << solution(12, {1,5,6,10}, {1,2,3,4});
}
