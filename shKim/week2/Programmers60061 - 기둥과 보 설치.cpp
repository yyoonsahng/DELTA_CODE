//
//  Programmers60061 - 기둥과 보 설치.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/18.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include<algorithm>

using namespace std;

pair<int,int> map[110][110]; //pair<보,기둥>
bool check_build_gidung(int x,int y){
    if(x == 0) return true;
    if(map[x-1][y].second == 1 || map[x][y].first == 1 || map[x][y-1].first == 1) return true;
    return false;
}
bool check_build_bo(int x,int y){
    if(x == 0) return false;
    if(map[x-1][y].second == 1 || map[x-1][y+1].second == 1) return true;
    if(map[x][y+1].first == 1 && map[x][y-1].first == 1) return true;
    return false;
}
bool check_remove_gidung(int x,int y,int n){
    //지우면 안되는 경우
    map[x][y].second = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].second == 1){
                if(!(i == 0 || map[i][j].first == 1 ||
                     map[i][j-1].first == 1 || map[i-1][j].second == 1)) return false;
            }
            if(map[i][j].first == 1){
                if(!(map[i-1][j].second == 1||map[i-1][j+1].second == 1||
                     (map[i][j-1].first == 1 && map[i][j+1].first == 1))) return false;
            }
        }
    }
    return true;
}
bool check_remove_bo(int x,int y,int n){
    map[x][y].first = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j].second == 1){
                if(!(i == 0 || map[i][j].first == 1 ||
                     map[i][j-1].first == 1 || map[i-1][j].second == 1)) return false;
            }
            if(map[i][j].first == 1){
                if(!(map[i-1][j].second == 1||map[i-1][j+1].second == 1||
                     (map[i][j-1].first == 1 && map[i][j+1].first == 1))) return false;
            }
        }
    }
    return true;
}

vector<vector<int>> solution(int n,vector<vector<int>> build){
    vector<vector<int>> answer;
    set<vector<int>> add;
    for(int i=0;i<110;i++){
        for(int j=0;j<110;j++){
            map[i][j] = {0,0};
        }
    }
    for(int i=0;i<build.size();i++){
        //0이 기둥, 1이 보
        //0이 삭제, 1은 설치
        int y = build[i][0]; int x = build[i][1]; int a = build[i][2]; int b = build[i][3];
        if(a == 0 && b == 1){ //기둥 설치
            if(check_build_gidung(x, y)) {
                cout << x<< "," << y <<" 기둥 설치" << endl;
                add.insert({x,y,0});
                map[x][y].second = 1;
            }
        }
        else if(a==1 && b==1){ //보를 설치
            if(check_build_bo(x, y)){
                cout << x<< "," << y <<" 보 설치" << endl;
                add.insert({x,y,1});
                map[x][y].first = 1;
            }
        }
        else if(a==0 && b==0){
            if(check_remove_gidung(x, y,n)){
                if(add.find({x,y,0}) != add.end()) add.erase(add.find({x,y,0}));
            }else map[x][y].second = 1;
        }else if(a==1 && b==0){
            if(check_remove_bo(x,y,n)){
                if(add.find({x,y,1}) != add.end()) add.erase(add.find({x,y,1}));
            }else map[x][y].first = 1;
        }
        
    }
    
    for(auto iter=add.begin(); iter != add.end(); iter++){
        vector<int> temp = *iter;
        answer.push_back({temp[1],temp[0],temp[2]});
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main(){
    
    vector<vector<int>> a = solution(5, {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1},{3, 2, 1, 1}});
    cout << a.size() << endl;
    for(int i=6;i>=0;i--){
        for(int j=0;j<6;j++){
            cout << "("<<map[i][j].first << ","<< map[i][j].second <<")  ";
        }
        cout << endl;
    }
    
    
    
    
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
