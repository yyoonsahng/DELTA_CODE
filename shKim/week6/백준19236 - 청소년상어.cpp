//
//  백준19236 - 청소년상어.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/09.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,-1,-1,-1,0,1,1,1};
int answer = 0;
struct info{
    int x;
    int y;
    int dir;
    bool operator <(const info &rhs) const{
        return x > rhs.x;
    }
};


void dfs(pair<int,int> sl,int sd,map<int,info> m,map<pair<int,int>,pair<int,int>> rm,int eat){
    //상어 이동
    int eatnum = rm[sl].first;
    eat += eatnum;
    
    answer = max(answer,eat);
    
    sd = rm[sl].second;
    
    if(rm.find(sl) != rm.end()) rm.erase(rm.find(sl));
    if(m.find(eatnum) != m.end()) m.erase(m.find(eatnum));
    
    rm.insert({sl,{-1,sd}});
    
    int board[4][4];
    for(auto iter=rm.begin();iter!=rm.end();iter++){
        pair<int,int> coord = (*iter).first;
        pair<int,int> value = (*iter).second;
        board[coord.first][coord.second] = value.first;
    }
    cout << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    //물고기 이동
    for(int i=1;i<=16;i++){
        //이미 먹혔으면 패스
        if(m.find(i) == m.end()) continue;
        //방향
        info current = m[i];
        int x = current.x;
        int y = current.y;
        int dir = current.dir;
        for(int j=0;j<8;j++){
            int nx = x + dx[(dir+j)%8];
            int ny = y + dy[(dir+j)%8];
            if(nx>=4 || nx<0 || ny>=4 || ny<0) continue;
            if(rm.find({nx,ny}) == rm.end()){//빈칸이면
                //////
                if(rm.find({x,y}) != rm.end()) rm[{x,y}] = {0,0};
                /////
                rm.insert({{nx,ny},{i,dir}});
                m[i] = {nx,ny,(dir+j)%8};
                break;
            }
            if(rm[{nx,ny}].first != -1){//상어가 아니면, 즉 물고기면
                pair<int,int> change = rm[{nx,ny}];
                int changeNum = change.first;
                int changeDir = change.second;
                //////
                if(rm.find({x,y}) != rm.end()) rm.erase(rm.find({x,y}));
                if(rm.find({nx,ny}) != rm.end()) rm.erase(rm.find({nx,ny}));
                ///////
                rm.insert({{nx,ny},{i,(dir+j)%8}});
                rm.insert({{x,y},change});
                
                m[i] = {nx,ny,(dir+j)%8};
                m[changeNum] = {x,y,changeDir};
                break;
            }
        }
    }
    
    for(auto iter=rm.begin();iter!=rm.end();iter++){
        pair<int,int> coord = (*iter).first;
        pair<int,int> value = (*iter).second;
        board[coord.first][coord.second] = value.first;
    }
    cout << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    //상어 이동,선택에 따라 다른 재귀
    vector<pair<int,int>> cand; //갈 수 있는곳 후보
    int x = sl.first;
    int y = sl.second;
    
    
    while(true){
        x = x + dx[sd];
        y = y + dy[sd];
        if(!(x>=0 && x<4 && y>=0 && y<4)) break;
        cand.push_back({x,y});
    }
    
    for(int i=0;i<cand.size();i++){
        //상어가 먹는 부분
        pair<int,int> coord = cand[i];
        rm[{sl.first,sl.second}] = {0,0};
        dfs(coord, rm[coord].second, m, rm,eat);
    }
}

int main(){
    map<int,info> m;
    map<pair<int,int>,pair<int,int>> rm;
    pair<int,int> sl = {0,0};
    int sd = -1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int num,dir;
            cin >> num >> dir;
            m.insert({num,{i,j,dir-1}});
            rm.insert({{i,j},{num,dir-1}});
        }
    }

    dfs(sl, sd, m, rm,0);
    cout << answer << endl;
    
    return 0;
}
