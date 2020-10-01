#include<bits/stdc++.h>
#include<queue>

using namespace std;

int btime[501];
int ptime[501]={0,};
//pair<int,pair<int,int> > : arrnum / nodeidx / buildtime
vector<pair<int,int> > seq;
vector<vector<int> > arr;
vector<vector<int> > tree;
priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > pq;
int visited[501] = {0,};

int bfs(){
    while(!pq.empty()){
        pair<int,int> idx = pq.top();
        pq.pop();
        
        if(visited[idx.second]==1){
            continue;
        }
        //printf("%d ",idx.second);
        visited[idx.second] = 1;
        for(int i = 0; i<tree[idx.second].size(); i++){
            int k = tree[idx.second][i];
            if(visited[k]==0){
                seq[k].first-=1;
                if(seq[k].first == 0)
                    pq.push(seq[k]);
                ptime[seq[k].second] = max(ptime[seq[k].second],btime[seq[k].second]+ptime[idx.second]);
            }
        }
    }
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;cin>>n;
    arr.resize(n+1);
    seq.resize(n+1);
    tree.resize(n+1);
    for(int i = 1; i<n+1; i++){
        int input;
        cin>>input;
        btime[i] = input;
        ptime[i] = input;
        while(true){
            cin>>input;
            if(input == -1) 
                break;
            arr[i].push_back(input);
            tree[input].push_back(i);
        }
        seq[i].first = arr[i].size();
        seq[i].second = i;
        if(arr[i].size() == 0){
            pq.push(seq[i]);
        }
    }
    //BFS
    bfs();
    for(int i = 1; i<=n; i++){
        printf("%d\n",ptime[i]);
    }
}