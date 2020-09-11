//
//  백준1516 - 게임 개발.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/09.
//  Copyright © 2020 김성헌. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <set>
#include <queue>
using namespace std;

int cache[501];
int tTime[501];
vector<int> v[501];
vector<int> reverseV[501];
vector<pair<int,int>> cnt_v;
int depth[501];

bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second < b.second;
}

int cal(int n){
    int &ret = cache[n];
    if(ret != -1) return ret;
    int temp = 987654321;
    for(int i=0;i<v[n].size();i++){
        int nx = v[n][i];
        if(depth[nx] == depth[n]-1){
            temp = min(temp,tTime[n] + cal(nx));
        }
    }
    if(temp == 987654321) ret = tTime[n];
    else ret = temp;
    return ret;
}

void dfs(int n,int dep,int parent){
    depth[n] = max(depth[n],dep);
    for(int i=0;i<reverseV[n].size();i++){
        int nx = reverseV[n][i];
        if(parent != nx) {
            dfs(nx,dep+1,n);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    memset(tTime,0,sizeof(tTime));
    memset(depth,-1,sizeof(depth));
    for(int i=1;i<=n;i++){
        int time,building;
        cin >> time;
        while(true){
            cin >> building;
            tTime[i] = time;
            if(building == -1) break;
            v[i].push_back(building);
            reverseV[building].push_back(i);
        }
        cnt_v.push_back({i,int(v[i].size())});
    }
    
    sort(cnt_v.begin(), cnt_v.end(), cmp);
    
    dfs(cnt_v[0].first,0,-1);
    
    for(int i=1;i<=n;i++){
        cout << cal(i) << endl;
    }
    return 0;
}
