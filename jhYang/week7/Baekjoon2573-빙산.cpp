#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
using namespace std;
int n,m;
int arr[301][301];
int bias[301][301];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int visited[301][301] = {0,};
int island[301][301] = {0,};
queue<pair<int,int> > que;
int bfs(pair<int,int> p,int isl){
    int cnt = 0;
    que.push(p);
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if(visited[x][y] == 1){
            continue;
        }
        island[x][y] = 1;
        visited[x][y] = 1;
        cnt++;
        for(int k = 0; k<4; k++){
            int xx = x+dx[k];
            int yy = y+dy[k];
            if(xx>=0 && xx<n && yy>=0 && yy<m){
                if(arr[xx][yy]!=0&&island[xx][yy] == 0 && visited[xx][yy] == 0){
                    que.push(make_pair(xx,yy));
                }
            }
        }
    }
    return cnt;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int t = 0;
    //SEARCH
    int q = 0;
    while(true){
        q++;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                visited[i][j] = 0;
                island[i][j] = 0;
            }
        }
        t++;
        int color = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(island[i][j]==1) continue;
                if(arr[i][j]==0) continue;
                if(visited[i][j] == 1) continue;
                pair<int,int> p = make_pair(i,j);
                int res = bfs(p,color);
                if(res > 0){
                    color++;
                }
            }
        }
        //printf("%d\n",color);
        if(color >= 2){
            printf("%d",t-1);
            return 0;
        }
        else if(color == 0){
            printf("%d",0);
            return 0;
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] != 0){
                    int ncnt = 0;
                    for(int k = 0; k<4; k++){
                        int x = i+dx[k];
                        int y = j+dy[k];
                        if(x>=0 && x<n && y>=0 && y<m){
                            if(arr[x][y]==0){
                                ncnt++;
                            }
                        }
                    }
                    bias[i][j]+=ncnt;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                arr[i][j]-=bias[i][j];
                arr[i][j] = max(0,arr[i][j]);
                bias[i][j] = 0;
            }
        }
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m; j++){
        //         printf("%d ",arr[i][j]);
        //     }
        //     printf("\n");
        // }
    }
}