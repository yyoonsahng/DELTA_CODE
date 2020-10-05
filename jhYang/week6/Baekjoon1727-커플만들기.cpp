// 15:18
#include<bits/stdc++.h>

using namespace std;
int N,M;
int assign;
vector<int> male;
vector<int> female;

//dp[a][b] = 더 작은 배열의 a가 b까지 봤을 때 최소의 차이 합
//pair<매칭 수, 값>
pair<int,int> dp[1001][1001];

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first>b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
    }
    return false;
}
void memo(vector<int>& arr1, vector<int> &arr2){
    //arr1이 더 작은 배열
    dp[0][0].second = abs(arr1[0]-arr2[0]);
    dp[0][0].first = 1;
    for(int j = 1; j<arr2.size(); j++){
        dp[0][j].second = min(dp[0][j-1].second,abs(arr1[0]-arr2[j]));
        dp[0][j].first = 1;
    }
    for(int i = 1; i<arr1.size(); i++){
        for(int j = 1; j<arr2.size(); j++){
            dp[i][j].second = dp[i-1][j-1].second+abs(arr1[i]-arr2[j]);
        }
    }
}
int main(){
    
    cin>>N>>M;
    assign = min(N,M);
    for(int i = 0; i<N; i++){
        int temp;cin>>temp;
        male.push_back(temp);
    }
    for(int i = 0; i<M; i++){
        int temp;cin>>temp;
        female.push_back(temp);
    }
    sort(male.begin(),male.end());
    sort(female.begin(),female.end());
    if(N<M){
        memo(male,female);
        sort(dp[N-1],dp[N-1]+M,cmp);
        cout<<dp[N-1][0].second;
    }
    else{
        memo(female,male);
        sort(dp[M-1],dp[M-1]+N,cmp);
        cout<<dp[M-1][0].second;
    }
}
