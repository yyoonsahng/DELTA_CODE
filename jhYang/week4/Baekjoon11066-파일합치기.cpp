
#include<bits/stdc++.h>
#define MMAX 500000000;
using namespace std;

int t,k;
vector<vector<int> > dp;
vector<int> arr;
vector<int> acm_sum;
int div_con(int start, int end){
    if(dp[start][end] > 0){
        return dp[start][end];
    } 
    if(start == end){
        dp[start][end] = 0;
        return 0;
    }
    //붙어있는 경우 -> 처리 안해주면 둘다 0반환
    if(start+1 == end){
        dp[start][end] = arr[start]+arr[end];
        return dp[start][end];
    }
    dp[start][end] = MMAX;
    int mid = start;
    while(mid<end){
        dp[start][end] = min(dp[start][end],div_con(start,mid)+div_con(mid+1,end));
        mid++;
    }
    if(start == 0){
        dp[start][end] += acm_sum[end];
    }
    else{
        dp[start][end] += acm_sum[end]-acm_sum[start-1];
    }
    return dp[start][end];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;

    while(t--){
        cin>>k;
        arr.resize(k);
        dp.resize(k);
        acm_sum.resize(k);
        fill(acm_sum.begin(),acm_sum.end(),0);

        for(int i = 0; i<k; i++){
            dp[i].resize(k);
            fill(dp[i].begin(),dp[i].end(),-1);
            cin>>arr[i];
            acm_sum[i] = (i==0?arr[i]:acm_sum[i-1]+arr[i]);
        }
        div_con(0,k-1);
        cout<<dp[0][k-1]<<'\n';
    } 
    
}