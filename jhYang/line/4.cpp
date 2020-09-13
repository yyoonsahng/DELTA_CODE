#include <string>
#include <vector>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 
//하우상좌

bool leftWall(vector<vector<int> >& maze,int x,int y){
    if(x<0 || x>=maze.size() || y<0 ||y>=maze.size()){
        return true;
    }
    if(maze[x][y] == 1){
        return true;
    }
    return false;
}
int solution(vector<vector<int>> maze) {
    int answer = 0;
    int x = 0,y = 0;
    int d = 0;
    int dist = 0;
    int n = maze.size();
    int k = 0;
    //while(k<=20){
    while(!(x==n-1&&y==n-1)){
        k++;
        //printf("%d %d : %d\n",x,y,d);
        if(d == 0){
            if(leftWall(maze,x,y+1)==false){
                d = (d+1)%4;
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else if(leftWall(maze,x+1,y)==false){
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else{
                d=3;
                continue;
            }
            
        }
        else if(d==1){
            if(leftWall(maze,x-1,y)==false){
                d = (d+1)%4;
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else if(leftWall(maze,x,y+1)==false){
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else{
                d=0;
                continue;
            }
            
        }
        else if(d==2){
            if(leftWall(maze,x,y-1)==false){
                d = (d+1)%4;
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else if(leftWall(maze,x-1,y)==false){
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else{
                d=1;
                continue;
            }
            
        }
        else{
            if(leftWall(maze,x+1,y)==false){
                d = (d+1)%4;
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }   
            else if(leftWall(maze,x,y-1)==false){
                x+=dx[d];
                y+=dy[d];
                dist++;
                continue;
            }
            else{
                d=2;
                continue;
            }
            
        }
    }
    answer = dist;
    return answer;
}