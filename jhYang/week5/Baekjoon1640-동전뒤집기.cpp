#include<bits/stdc++.h>
using namespace std;
int N,M;
int arr[1001][1001];
int xodd[1001];
int yodd[1001];
int main(){
    cin>>N>>M;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>arr[i][j];
        }
    }
    for(int i= 0; i<N; i++){
        int sum = 0;
        for(int j = 0; j<M; j++){
            sum+=arr[i][j];
        }
        xodd[i] = sum;
    }
    for(int i= 0; i<M; i++){
        int sum = 0;
        for(int j = 0; j<N; j++){
            sum+=arr[j][i];
        }
        yodd[i] = sum;
    }
    
}