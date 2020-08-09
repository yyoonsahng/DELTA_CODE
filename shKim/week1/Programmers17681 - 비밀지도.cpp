//
//  Programmers17681 - 비밀지도.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/06.
//  Copyright © 2020 김성헌. All rights reserved.
//
//풀이시간 : 15분 , 시도횟수 : 2qjs
#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string ToBinary(int value,int n){
    stack<int> s;
    string ret = "";
    while(value/2 != 0){
        s.push(value % 2);
        value = value/2;
    }
    if(value != 0) s.push(1);
    while(s.size() < n){
        s.push(0);
    }
    while(!s.empty()){
        ret.append(to_string(s.top()));
        s.pop();
    }
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> map1;
    vector<string> map2;
    for(int i=0;i<arr1.size();i++){
        map1.push_back(ToBinary(arr1[i],n));
    }
    for(int i=0;i<arr2.size();i++){
        map2.push_back(ToBinary(arr2[i],n));
    }
    for(int i=0;i<n;i++){
        string str = "";
        for(int k=0;k<n;k++) str.append(" ");
        for(int j=0;j<n;j++){
            if(map1[i][j] == '1' || map2[i][j] == '1'){
                str[j] = '#';
            }
        }
        answer.push_back(str);
    }
    return answer;
}
int main(){
    vector<int> a = {9, 0 ,28,18,11};
    vector<int> b = {30,1,21,17,28};
    vector<string> arr = solution(5,a,b);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
    return 0;
}
