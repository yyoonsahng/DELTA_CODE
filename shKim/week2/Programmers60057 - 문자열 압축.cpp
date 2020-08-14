//
//  Programmers60057 - 문자열 압축.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/13.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 987654321;
    for(int jump=1;jump<=1000;jump++){
        if(s.size() <= jump) break;
        string ans = "";
        string str = "";
        string cmp = "";
        int consecutive = 1;
        int current = jump;
        for(int j=0;j<jump;j++) str.push_back(s[j]);
        while(current < s.length()){
            cmp = "";
            for(int k=current;k<current + jump;k++) {
                if(k >= s.size()) break;
                cmp.push_back(s[k]);
            }
            if(str == cmp) consecutive++;
            else{
                if(consecutive == 1) ans += str;
                else ans += (to_string(consecutive)+str);
                str = cmp;
                consecutive = 1;
            }
            current += jump;
        }
        if(consecutive == 1) ans += str;
        else ans += (to_string(consecutive)+str);
        answer = min(answer,int(ans.length()));
    }
    return answer;
}
int main(){
    cout << solution("abcabcdede") << endl;
    return 0;
}
