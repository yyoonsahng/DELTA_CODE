//
//  백준1640 - 동전 뒤집기2.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/01.
//  Copyright © 2020 김성헌. All rights reserved.
//
// MARK:@모르겠음..... 27% out
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int row,col;
    int row_count = 0;
    int col_count = 0;
    cin >> row >> col;
    int odd = 0;
    int even = 0;
    vector<string> v;
    
    for(int i=0;i<row;i++){
        int one = 0;
        string str;
        cin >> str;
        v.push_back(str);
        for(int i=0;i<str.length();i++){
            if(str[i] == '1') one++;
        }
        if(one % 2 == 0) even++;
        else odd++;
    }
    
    int target = 0;
    if(max(odd,even) == even) target = 1;
    else target = 0;
    
    for(int i=0;i<row;i++){
        int one = 0;
        string str = v[i];
        for(int j=0;j<col;j++){
            if(str[j] == '1') one+=1;
        }
        if(one % 2 == target){
            row_count += 1;
            for(int j=0;j<col;j++){
                if(v[i][j] == '1') v[i][j] = '0';
                else v[i][j] = '1';
            }
        }
    }
    
  
    for(int i=0;i<col;i++){
        int one = 0;
        for(int j=0;j<row;j++){
            if(v[j][i] == '1') one+=1;
        }
        if(one%2 == 1) {
            col_count += 1;
            for(int j=0;j<col;j++){
                if(v[j][i] == '1') v[j][i] = '0';
                else v[j][i] = '1';
            }
        }
    }
    
    for(int i=0;i<row;i++){
        int one = 0;
        for(int j=0;j<col;j++){
            if(v[i][j] == '1') one+=1;
        }
        if(one == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    for(int i=0;i<col;i++){
        int one = 0;
        for(int j=0;j<row;j++){
            if(v[j][i] == '1') one+=1;
        }
        if(one == 0){
            cout << -1 << endl;
            return 0;
        }
    }
        
    if(col_count % 2 == target) cout << -1 << endl;
    else cout << row_count + col_count << endl;
    
    return 0;
}
