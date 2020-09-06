#include<bits/stdc++.h>

using namespace std;
struct node{
    int ind;
    int val;
    vector<int> vec;
};
int N;
vector<node> arr(20);

int bfs(vector<int>& toVisit){
    queue<int> que;
    int visited[11] = {0,};
    int idx = toVisit.front();
    que.push(idx);
    int sum = 0;
    int ssize = 0;
    while(!que.empty()){
        
        int start = que.front();
        que.pop();
        if(visited[start] == 1) {
            continue;
        }
        visited[start] = 1;

        ssize++;    
        sum += arr[start].val;

        for(int i = 0; i<arr[start].vec.size(); i++){
            for(int j = 0; j<toVisit.size(); j++){
                if(toVisit[j] == arr[start].vec[i] && visited[toVisit[j]] == 0){
                    que.push(toVisit[j]);
                }
            }
        }
    }
    if(ssize == toVisit.size()){
        return sum;
    }
    else{
        return -1;
    }
}

int main(){
    int total = 0;
    int mmin = 100000000;
    cin>>N;
    for(int i = 1; i<=N; i++){
        arr[i].ind = i;
        cin>>arr[i].val;
        total+=arr[i].val;
    }
    for(int i= 1; i<=N; i++){
        int temp;
        cin>>temp;
        for(int j = 0; j<temp; j++){
            int link; cin>>link;
            arr[i].vec.push_back(link);
        }
    }
    
    for(int i = 1; i<N; i++){
        vector<int> idx;

        for(int j = 1; j<=i; j++){
            idx.push_back(1);
        }
        for(int j = 1; j<=N-i; j++){
            idx.push_back(0);
        }

        sort(idx.begin(),idx.end());

        do{
            vector<int> toVisit;
            vector<int> toVisit2;
            for(int k = 0; k<idx.size(); k++){
                if(idx[k] == 1){
                    toVisit.push_back(arr[k+1].ind);
                    
                }
                else{
                    toVisit2.push_back(arr[k+1].ind);
                }
            }

            if(toVisit.size() == N || toVisit.size() == 0){
                continue;
            }
            if(toVisit2.size() == N || toVisit2.size() == 0){
                continue;
            }
            int prev = bfs(toVisit);

            if(prev == -1) {
                continue;
            }
            int next = bfs(toVisit2);

            if(next == -1) {
                continue;
            }
            mmin = min(mmin, abs(prev-next));

        }while(next_permutation(idx.begin(),idx.end()));
    }
    if(mmin == 100000000){
        mmin = -1;
    }
    printf("%d",mmin);
}