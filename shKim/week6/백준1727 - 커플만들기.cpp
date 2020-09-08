//
//  백준1727 - 커플만들기.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n,m,element;
    long long answer = 1e11;
    cin >> n >> m;
    vector<int> man,woman,origin,comp;
    for(int i=0;i<n;i++){
        cin >> element;
        man.push_back(element);
    }
    for(int i=0;i<m;i++){
        cin >> element;
        woman.push_back(element);
    }
    if(man.size() > woman.size()){
        origin = man;
        comp = woman;
    }
    else{
        origin = woman;
        comp = man;
    }
    sort(origin.begin(),origin.end());
    sort(comp.begin(),comp.end());
    for(int i=0;i<origin.size();i++){
        long long temp = 0;
        for(int j=0;j<comp.size();j++){
            if(i+j>=origin.size()) temp += abs(comp[j] - origin[i+j-origin.size()]);
            else temp += abs(comp[j] - origin[i+j]);
        }
        answer = min(answer,temp);
    }
    cout << answer << endl;
    return 0;
}
