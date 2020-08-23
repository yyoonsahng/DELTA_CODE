//
//  Programmers60059 - 자물쇠와 열쇠.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/14.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct coordinate{
    int x;
    int y;
    coordinate(int x,int y) : x(x),y(y){}
    bool operator ==(const coordinate &rhs) const{
        if(x == rhs.x) return y > rhs.y;
        else return x > rhs.x;
    }
    bool operator <(const coordinate &rhs) const{
        if(x == rhs.x) return y > rhs.y;
        else return x > rhs.x;
    }
};

vector<vector<coordinate>> rotation(vector<coordinate> pre,int size_t){
    //90도,180도,270도 회전 시킨 결과를 리턴함.
    //90도
    size_t -= 1;
    vector<coordinate> element_90;
    for(int i=0;i<pre.size();i++) element_90.push_back(coordinate(pre[i].y, size_t - pre[i].x));
    //180도
    vector<coordinate> element_180;
    for(int i=0;i<element_90.size();i++) element_180.push_back(coordinate(element_90[i].y, size_t - element_90[i].x));
    //270도
    vector<coordinate> element_270;
    for(int i=0;i<element_180.size();i++) element_270.push_back(coordinate(element_180[i].y, size_t - element_180[i].x));
    return {element_90,element_180,element_270};
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    set<vector<coordinate>> visited;
    int size_key = int(key.size());
    int size_lock = int(lock.size());
    vector<coordinate> key_value;
    set<coordinate> lock_value;
    queue<vector<coordinate>> q;
    for(int i=0;i<key.size();i++){
        for(int j=0;j<key[i].size();j++){
            if(key[i][j] == 1) key_value.push_back(coordinate(i,j));
        }
    }
    for(int i=0;i<lock.size();i++){
        for(int j=0;j<lock[i].size();j++){
            if(lock[i][j] == 0) lock_value.insert(coordinate(i,j));
        }
    }
    //초기값 넣어주기
    visited.insert(key_value);
    q.push(key_value);
    while(!q.empty()){
        vector<coordinate> current = q.front(); q.pop();
        //이미 확인했던 지점이면
        
        //범위 넘어간 애들은 굳이 확인할 필요 없음.
        int over_num = 0;
        for(int i=0;i<current.size();i++){
            int x = current[i].x;
            int y = current[i].y;
            if((x<0 || x>= size_lock) || (y<0 || y>=size_lock)) over_num+=1;
        }
        if(current.size() - over_num < lock_value.size()) continue;
        //정답 체크
        int correct_check = 0;
        bool not_correct = false;
        for(int i=0;i<current.size();i++){
            if(lock_value.find(current[i]) != lock_value.end()){
                correct_check += 1;
            }else{
                if(!(current[i].x<0 || current[i].x>= size_lock
                   || current[i].y<0 || current[i].y>=size_lock)){
                    not_correct = true;
                }
            }
        }
        if(!not_correct && correct_check == lock_value.size()) return true;
        //4방향 회전
        auto container = rotation(current,size_key);
        for(int i=0;i<container.size();i++){
            vector<coordinate> next = container[i];
            if(visited.find(next) == visited.end()){
                q.push(next);
                visited.insert(next);
            }
        }
        vector<coordinate> next;
        //왼쪽 이동
        for(int i=0;i<current.size();i++) next.push_back(coordinate(current[i].x,current[i].y - 1));
                
        if(visited.find(next) == visited.end()){
            q.push(next);
            visited.insert(next);
        }
        
        //오른쪽 이동
        next.clear();
        for(int i=0;i<current.size();i++) next.push_back(coordinate(current[i].x,current[i].y + 1));
        if(visited.find(next) == visited.end()){
            q.push(next);
            visited.insert(next);
        }
        
        //위쪽 이동
        next.clear();
        for(int i=0;i<current.size();i++) next.push_back(coordinate(current[i].x - 1,current[i].y));
        if(visited.find(next) == visited.end()){
            q.push(next);
            visited.insert(next);
        }
        //아래쪽 이동
        next.clear();
        for(int i=0;i<current.size();i++) next.push_back(coordinate(current[i].x + 1,current[i].y));
        if(visited.find(next) == visited.end()){
            q.push(next);
            visited.insert(next);
        }
    }
    return false;
}

int main(){
    cout << solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}});
    return 0;
}
