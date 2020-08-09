//
//  Programmers17679 - 프렌즈4블록.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/07.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<memory.h>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool nomore = false;
    while(true){
        set<pair<int,int>> s;
        if(nomore) break;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1>=m || j+1>=n) continue;
                if(board[i][j] == '*') continue;
                if(board[i][j] == board[i+1][j] && board[i][j] == board[i][j+1]
                   && board[i][j] == board[i+1][j+1]){
                    s.insert({i,j}); s.insert({i+1,j});
                    s.insert({i,j+1}); s.insert({i+1,j+1});
                }
            }
        }
        if(s.size() == 0) {
            nomore = true;
            continue;
        }
        for(auto iter = s.begin();iter != s.end(); iter++){
            board[iter->first][iter->second] = '*';
            answer++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << " =========== " << endl;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j] != '*') continue;
                vector<string> copy_board = board;
                char current = copy_board[i][j];
                int index = i;
                while(true){
                    if(current != '*') {
                        board[index][j] = '*';
                        board[i][j] = copy_board[index][j];
                        break;
                    }
                    index--;
                    if(index < 0) break;
                    current = copy_board[index][j];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << " =========== " << endl;
    }
    
    return answer;
}

int main(){
    //cout << solution(4, 5, {"CCBDE","AAADE","AAABF","CCBBF"});
    //cout << solution(3,2, {"AA", "AA", "AB"});
    //cout << solution(4,2, {"CC", "AA", "AA", "CC"});
    //cout << solution(8,2,{"BB","BB","CC","AA","BB","BB","AA","CB"});
    return 0;
}
