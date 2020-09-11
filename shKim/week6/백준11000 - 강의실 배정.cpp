//
//  백준11000 - 강의실 배정.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/09.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n,start,dest;
    multiset<int> s;
    vector<pair<int,int>> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> start >> dest;
        v.push_back({start,dest});
    }
    
    sort(v.begin(),v.end()); //끝나는 시간 목록
    int answer = -1;
    for(int i=0;i<v.size();i++){
        if(s.size() == 0) s.insert(v[i].second);
        else{
            if((*s.begin()) > v[i].first) s.insert(v[i].second);
            else{
                s.erase(s.begin());
                s.insert(v[i].second);
            }
        }
        answer = max(answer,int(s.size()));
    }
    cout << answer << endl;
    return 0;
}
