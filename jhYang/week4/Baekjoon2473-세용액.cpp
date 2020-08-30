#include<bits/stdc++.h>
using namespace std;

struct ans{
    long long val;
    vector<long long> liq;
};
int main(){
    int n;cin>>n;
    vector<long long> arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());

    long long mmin = 4000000000;
    ans a;
    a.val = mmin;
    a.liq.resize(3);

    if(n == 3){
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
        return 0;
    }

    for(int i = 0; i<n-2; i++){
        int j = i+1;
        int k = n-1;
        while(j<k){
            long long sumliq = arr[i]+arr[j]+arr[k];
            long long temp;

            if(sumliq < 0) temp = -1*sumliq;
            else temp = sumliq;
            if(a.val>temp){
                a.val = temp;
                a.liq[0] = arr[i];
                a.liq[1] = arr[j];
                a.liq[2] = arr[k];
            } 
            if(sumliq>0){
                --k;
            }
            else{
                ++j;
            }
        }
    }
    for(auto i : a.liq)
        cout<<i<<" ";
}
