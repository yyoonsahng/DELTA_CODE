//14:33

#include<iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct rob{
  int x,y,d,c;
};
// x,y,state(0,1) ,0dㅡㄴ 가로로 
int visited[101][101][2] = {0};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[2] = {0,1};
int ddy[2] = {1,0};
queue<rob> que;
int solution(vector<vector<int> > board) {
  int answer = 0;
  int m = board.size(); //세로
  int n = board[0].size();  //가로
  rob r ={0,0,0,0};
  que.push(r);
  while(!que.empty()){
    rob t = que.front();
    que.pop();
    if((t.x == m-1 && t.y == n-1)||
    (t.x+ddx[t.d] == m-1 && t.y+ddy[t.d]==n-1)){
      return t.c;
    }
    if(visited[t.x][t.y][t.d] == 1) continue;
    visited[t.x][t.y][t.d] = 1;
    for(int i = 0; i<4; i++){
      int x = dx[i]+t.x;
      int y = dy[i]+t.y;
      int x2 = x+ddx[t.d];
      int y2 = y+ddy[t.d];
      int c = t.c+1;
      if(x>m-1 || x<0 || y>n-1 || y<0 ||
      x2>m-1 || x2<0 || y2>n-1 || y2<0)
        continue;
      if(board[x][y] == 1 || board[x2][y2] == 1)
        continue;
      if(visited[x][y][t.d] == 1)
        continue;
      rob tt = {x,y,t.d,c};
      que.push(tt);
    }
    if(t.d == 0){
      int x = t.x+1;
      int y = t.y+1;
      int c = t.c+1;
      if(x<=m-1 && x>=0 && y<=n-1 && y>=0 &&
        board[x][y] == 0 && board[x][t.y] == 0){
        rob tt = {t.x,t.y,1,c};
        if(visited[t.x][t.y][1] == 0)
          que.push(tt);
        rob tt2 = {t.x,y,1,c};
        if(visited[t.x][y][1] == 0)
          que.push(tt2);
      }
      x = t.x-1;
      y = t.y+1;
      if(x<=m-1 && x>=0 && y<=n-1 && y>=0 &&
        board[x][y] == 0 && board[x][t.y] == 0){
        rob tt = {x,t.y,1,c};
        if(visited[x][t.y][1] == 0)
          que.push(tt);
        rob tt2 = {x,y,1,c};
        if(visited[x][y][1] == 0)
          que.push(tt2);
      }
    }
    else{
      int x = t.x+1;
      int y = t.y-1;
      int c = t.c+1;
      if(x<=m-1&& x>=0 && y<=n-1 && y>=0 &&
        board[t.x][y] == 0 && board[x][y] == 0){
          rob tt = {t.x,y,0,c};
          if(visited[t.x][y][0] == 0)
            que.push(tt);
          rob tt2 = {x,y,0,c};
          if(visited[x][y][0] == 0) 
            que.push(tt2);
      }
      x = t.x+1;
      y = t.y+1;
      if(x<=m-1 && x>=0 && y<=n-1 && y>=0 &&
        board[t.x][y] == 0 && board[x][y] == 0){
          rob tt = {t.x,t.y,0,c};
          if(visited[t.x][t.y][0] == 0)
            que.push(tt);
          rob tt2 = {x,t.y,0,c};
          if(visited[x][t.y][0] ==0)
            que.push(tt2);
      }
    }
  }
  return answer;
}