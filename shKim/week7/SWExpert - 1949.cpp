#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
#include <set>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n,k;
int partAns = -1;
int map[9][9];
int copy_map[9][9];
int cache[9][9];

int dp(int x,int y){
    int &ret = cache[x][y];
    if(ret != 0) return ret;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n){
            if(copy_map[x][y] > copy_map[nx][ny]){
               ret = max(ret,dp(nx,ny)+1);
            }
        }
    }
    return ret;
}

int cal(pair<int,int> start,pair<int,int> del){
    partAns = -1;
    for(int i=1;i<=k;i++){
        for(int a=0;a<n;a++){
            for(int b=0;b<n;b++){
                copy_map[a][b] = map[a][b];
            }
        }
        memset(cache,0,sizeof(cache));
        copy_map[del.first][del.second] -= i;
        partAns = max(partAns,dp(start.first,start.second));
    }
    return partAns;
}


int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> n >> k;
        int m_height = -1;
        int answer = -1;
        vector<pair<int,int>> startArr;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> map[i][j];
                m_height = max(m_height,map[i][j]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j] == m_height) startArr.push_back({i,j});
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<startArr.size();k++){
                    answer = max(answer,cal(startArr[k],{i,j}));
                }
            }
        }
        
        cout << "#" <<t+1 << " " << answer+1 << endl;
        
    }
    return 0;
}
