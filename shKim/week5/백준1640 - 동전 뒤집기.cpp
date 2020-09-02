////
////  백준1640 - 동전 뒤집기.cpp
////  DeltaCode
////
////  Created by 김성헌 on 2020/09/01.
////  Copyright © 2020 김성헌. All rights reserved.
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <map>
//using namespace std;
//
//int row,col;
//queue<string> q;
//map<string,int> m;
//
////row 변환하는 함수
//string change_row(string top,int initIndex){
//    for(int j = 0;j <col;j++){
//        int current = initIndex + j;
//        if(top[current] == '0') top[current] = '1';
//        else top[current] = '0';
//    }
//    return top;
//}
////col 변환하는 함수
//string change_col(string top,int initIndex){
//    for(int j=0;j<row;j++){
//        int current = initIndex + j * col;
//        if(top[current] == '0') top[current] = '1';
//        else top[current] = '0';
//    }
//    return top;
//}
////행과 열 모두 짝수인지 검사하는 함수
//bool check(string top){
//    int one = 0;
//    for(int i=0;i<row;i++){
//        int initIndex = i * col;
//        for(int j=0;j<col;j++){
//            int current = initIndex + j;
//            if(top[current] == '1') one += 1;
//        }
//        if(one % 2 != 0) return false;
//    }
//    
//    for(int i=0;i<col;i++){
//        int initIndex = i;
//        for(int j=0;j<row;j++){
//            int current = initIndex + j * col;
//            if(top[current] == '1') one += 1;
//        }
//        if(one % 2 != 0) return false;
//    }
//  
//    return true;
//}
//int main(){
//    cin >> row >> col;
//    
//    string start = "";
//    
//    for(int i=0;i<row;i++){
//        string str;
//        cin >> str;
//        start += str;
//    }
//    
//    q.push(start);
//    m.insert({start,0});
//    
//    while(!q.empty()){
//        string top = q.front(); q.pop();
//        if(check(top)){
//            cout << m[top] << endl;
//            return 0;
//        }
//        
//        //행 뒤집기
//        for(int i=0;i<row;i++){
//            int initIndex = i * col;
//            string cand = change_row(top,initIndex);
//            cout << cand << endl;
//            if(m.find(cand) == m.end()){
//                m.insert({cand,m[top]+1});
//                q.push(cand);
//            }
//        }
//        //열 뒤집기
//        for(int i=0;i<col;i++){
//            int initIndex = i;
//            string cand = change_col(top, initIndex);
//            if(m.find(cand) == m.end()){
//                m.insert({cand,m[top]+1});
//                q.push(cand);
//            }
//        }
//    }
//    cout << -1 << endl;
//    return 0;
//}
