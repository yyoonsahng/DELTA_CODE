// 비밀지도
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> foo(vector<int> v,int n){
    vector<string> answer;
    for(int e : v){
        string s1;
        int k = 0;
        while(e/2 != 0){
            if(e%2 == 1) s1+="#";
            else s1+=" ";
            e/=2;
            k++;
        }
        if(k > 0 || e==1)
            s1+="#";
        while(s1.length() < n)
            s1+=" ";
        reverse(s1.begin(),s1.end());
        answer.push_back(s1);
    }
    return answer;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<string> v1 = foo(arr1,n);
    vector<string> v2 = foo(arr2,n);
    for(int i = 0; i<n; i++){
        cout<<v2[i]<<endl;
    }
    for(int i = 0; i<n; i++){
        string s;
        for(int j = 0; j<n; j++){
            if(v1[i][j] == v2[i][j]) s+=v1[i][j];
            else s+="#";
        }
        answer.push_back(s);
    }

    return answer;
}
int main(){
    int n = 5;
    vector<int> a;
    a.push_back(9);
    a.push_back(20);
    a.push_back(28);
    a.push_back(18);
    a.push_back(11);
    
    vector<int> b;
    b.push_back(30);
    b.push_back(1);
    b.push_back(21);
    b.push_back(17);
    b.push_back(28);
    
    vector<string> ans = solution(n,a,b);
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<endl;
    }
}