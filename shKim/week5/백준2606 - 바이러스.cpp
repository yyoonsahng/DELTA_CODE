//
//  백준2606 - 바이러스.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/01.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
    int n,m;
    vector<int> v[101];
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int start,dest;
        cin >> start >> dest;
        v[start].push_back(dest);
        v[dest].push_back(start);
    }
    queue<int> q;
    bool visited[101];
    memset(visited,false,sizeof(visited));
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int top = q.front(); q.pop();
        for(int i=0;i<v[top].size();i++){
            int next = v[top][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    int answer = 0;
    for(int i=0;i<101;i++){
        if(visited[i]) answer++;
    }
    cout << answer - 1;
    return 0;
}
