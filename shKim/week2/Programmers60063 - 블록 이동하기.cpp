//
//  Programmers60063 - 블록 이동하기.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/23.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct coord{
    int x;
    int y;
    coord(int x,int y):x(x),y(y){};
    bool operator >(const coord &rhs) const{
        return x > rhs.x;
    }
    bool operator ==(const coord &rhs) const{
        return x == rhs.x && y == rhs.y;
    }
};
struct info{
    coord first;
    coord second;
    int time;
    info(coord first,coord second,int time):first(first),second(second),time(time){};
    bool operator >(const info &rhs) const{
        if(time != rhs.time)  return time > rhs.time;
        else{
            if(first == rhs.first) return second > rhs.second;
            else return first > rhs.first;
        }
        
    }
    bool operator ==(info &rhs) const{
        return rhs.time == time;
    }
};
bool visited[101][101][101][101];
int solution(vector<vector<int>> board) {
    int size = int(board.size());
    priority_queue<info,vector<info>,greater<info>> q;
    q.push(info(coord(0,0),coord(0,1),0));
    while(!q.empty()){
        info current = q.top(); q.pop();
        coord first = current.first;
        coord second = current.second;
        int time = current.time;
        //answer
        if((first.x == size-1 && first.y == size-1) || (second.x == size-1 && second.y == size-1)) return time;
        if(visited[first.x][first.y][second.x][second.y] || visited[second.x][second.y][first.x][first.y]) continue;
        //cout << first.x << ":" << first.y << " " <<second.x << ":" << second.y << " " << time << endl;
        visited[first.x][first.y][second.x][second.y] = true;
        //상하좌우 움직이는 액션
        for(int i=0;i<4;i++){
            coord next_first = coord(first.x + dx[i],first.y + dy[i]);
            coord next_second = coord(second.x + dx[i], second.y + dy[i]);
            if(next_first.x >= size || next_first.y>= size || next_second.x >= size || next_second.y >= size) continue;
            if(next_first.x < 0 || next_first.y < 0 || next_second.x < 0 || next_second.y < 0) continue;
            if(board[next_first.x][next_first.y] == 1 || board[next_second.x][next_second.y] == 1) continue;
            q.push(info(next_first,next_second,time+1));
        }
        //대각선으로 움직이는 액션
        //1. 가로 움직임 second 고정
        for(int i=0;i<4;i++){
            coord next_first = coord(second.x + dx[i],second.y + dy[i]);
            coord next_second = coord(second.x, second.y);
            if(next_first.x >= size || next_first.y>= size || next_second.x >= size || next_second.y >= size) continue;
            if(next_first.x < 0 || next_first.y < 0 || next_second.x < 0 || next_second.y < 0) continue;
            if(board[next_first.x][next_first.y] == 1 || board[next_second.x][next_second.y] == 1) continue;
            if(first.x + dx[i] < 0 || first.y + dy[i] <0 || first.x + dx[i] >= size || first.y + dy[i] >= size) continue;
            if(board[first.x+dx[i]][first.y+dy[i]] == 1) continue;
            q.push(info(next_first,next_second,time+1));
        }
        //2. first 고정
        for(int i=0;i<4;i++){
            coord next_first = coord(first.x,first.y);
            coord next_second = coord(first.x + dx[i], first.y + dy[i]);
            if(next_first.x >= size || next_first.y>= size || next_second.x >= size || next_second.y >= size) continue;
            if(next_first.x < 0 || next_first.y < 0 || next_second.x < 0 || next_second.y < 0) continue;
            if(board[next_first.x][next_first.y] == 1 || board[next_second.x][next_second.y] == 1) continue;
            if(second.x + dx[i] < 0 || second.y + dy[i] <0 || second.x + dx[i] >= size || second.y + dy[i] >= size) continue;
            if(board[second.x+dx[i]][second.y+dy[i]] == 1) continue;
            q.push(info(next_first,next_second,time+1));
        }
    }
    
    return 0;
}

int main(){
    cout << solution({{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}});
    return 0;
}
