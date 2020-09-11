//
//  백준12784 인하니카 공화국.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/31.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

vector<int> bridge[1001];
int cost[1001][1001];
bool visited[1001];
int depth[1001];

int dfs(int n,int parent){
    visited[n] = true;
    int sumOfSon = 0;
    bool check = false;
    for(int i=0;i<bridge[n].size();i++){
        int next = bridge[n][i];
        if(!visited[next] && depth[n] < depth[next]) {
            check = true;
            sumOfSon += dfs(next,n);
        }
    }
    if(check == false) return cost[n][parent];
    else return min(sumOfSon,cost[n][parent]);
}

int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        
        memset(cost, 0, sizeof(cost));
        memset(depth,-1,sizeof(depth));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<1001;i++) bridge[i].clear();
        
        int n,m;
        cin >> n >> m;
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        for(int i=0;i<m;i++){
            int start,dest,num;
            cin >> start >> dest >> num;
            bridge[start].push_back(dest);
            bridge[dest].push_back(start);
            cost[start][dest] = num;
            cost[dest][start] = num;
        }
        //bfs를 통하여 depth구하기
        queue<pair<int,int>> q;
        q.push({1,0});
        depth[1] = 0;
        cost[1][0] = 987654321;
        //depth구하기
        while(!q.empty()){
            pair<int,int> front = q.front(); q.pop();
            int start = front.first;
            for(int j=0;j<bridge[start].size();j++){
                int next = bridge[start][j];
                if(depth[next] == -1){
                    depth[next] = depth[start]+1;
                    q.push({next,cost[start][next]});
                }
            }
        }
        
        cout << dfs(1,0) << endl;
        
    }
    return 0;
}
