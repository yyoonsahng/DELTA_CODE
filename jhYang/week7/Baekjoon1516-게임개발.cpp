#include<bits/stdc++.h>
#include<queue>

using namespace std;

int btime[501] = {0,}; // build time
int ptime[501] = {0,}; // 누적 build time
pair<int,int> seq[501]; // inDegree, index
vector<int> tree[501]; // 그래프
queue<int> que; // seq( < inDegree, index > )

void bfs(){
    while(!que.empty()){
        int idx = que.front();
        que.pop();
        for(int i = 0; i<tree[idx].size(); i++){
            int k = tree[idx][i];

            seq[k].first-=1;
            if(seq[k].first == 0)
                que.push(k);
            ptime[k] = max(ptime[k],ptime[idx]+btime[idx]);
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;cin>>n;
    for(int i = 1; i<n+1; i++){
        int input;
        int cnt = 0;
        cin>>input;
        btime[i] = input;
        while(true){
            cin>>input;
            if(input == -1) 
                break;
            cnt++;
            tree[input].push_back(i);
        }
        seq[i].first = cnt;
        seq[i].second = i;
        if(cnt == 0){
            que.push(i);
        }
    }
    //BFS
    bfs();
    for(int i = 1; i<=n; i++){
        printf("%d\n",btime[i]+ptime[i]);
    }
}