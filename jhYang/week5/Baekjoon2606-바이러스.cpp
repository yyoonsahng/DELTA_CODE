#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;cin>>N;
    int M;cin>>M;
    int cnt = 0;
    vector<vector<int> > arr(N+1);
    queue<int> que;
    vector<int> visited(N+1);
    fill(visited.begin(),visited.end(),0);
    for(int i = 0; i<M; i++){
        int from,to;
        cin>>from>>to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    que.push(1);
    while(!que.empty()){
        int idx = que.front();
        que.pop();
        if(visited[idx] == 1) continue;
        visited[idx] = 1;
        cnt++;
        for(int i = 0; i<arr[idx].size(); i++){
            if(visited[arr[idx][i]]==0){
                que.push(arr[idx][i]);
            }
        }
    }
    std::cout<<cnt-1<<endl;
}