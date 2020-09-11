#include<bits/stdc++.h>
using namespace std;
int N,K;
int dp[501][501];
int foo(int n, int k){
    if(dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k] = 10000000;
    for(int i = 1; i<n; i++)
        dp[n][k] = min(dp[n][k],(max(foo(i-1,k-1)+1,foo(n-i,k)+1)));
    return dp[n][k];
}
int main(){
    cin>>N>>K;
    for(int i = 1; i<=N; i++) 
        for(int j = 1; j<=K; j++) 
            dp[i][j] = -1;
    for(int i = 1; i<=N; i++){
        dp[i][1] = i;
        dp[1][i] = 1;
    }
    foo(N,K);
    cout<<dp[N][K]<<endl;
}