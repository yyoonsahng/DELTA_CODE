//
//  백준2573 - 빙산.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

map<pair<int,int>,int> del;
bool visited[301][301];
int mountain[301][301];
int cnt = 0;

void dfs(int x,int y){
    cnt++;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(mountain[nx][ny] == 0){
            if(del.find({x,y}) != del.end()) del[{x,y}]++;
            else del.insert({{x,y},1});
        }else if(mountain[nx][ny] > 0){
            if(del.find({x,y}) == del.end()) del.insert({{x,y},0});
            if(!visited[nx][ny]) dfs(nx,ny);
        }
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    memset(mountain,-1,sizeof(mountain));
    pair<int,int> start;
    int notZeroCnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mountain[i][j];
            if(mountain[i][j] > 0) {
                notZeroCnt++;
                start = {i,j};
            }
        }
    }
    int year = 0;
    while(true){
        del.clear();
        cnt = 0;
        memset(visited,false,sizeof(visited));
        dfs(start.first,start.second);
        
        if(notZeroCnt == 0){
            cout << 0 << endl;
            return 0;
        }
        
        
        if(notZeroCnt != cnt) break;
        
        for(auto iter = del.begin();iter != del.end(); iter++){
            pair<int,int> coord = (*iter).first;
            int sub = (*iter).second;
            if(mountain[coord.first][coord.second] - sub <= 0) {
                notZeroCnt -= 1;
                mountain[coord.first][coord.second] = 0;
            }
            else{
                mountain[coord.first][coord.second] -= sub;
                start = coord;
            }
        }
        year+=1;
    }
    cout << year << endl;
    return 0;
}
