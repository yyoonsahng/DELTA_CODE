//
//  Programmers60058 - 괄호변환.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/14.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool correct(string w){
    stack<char> s;
    for(int i=0;i<w.size();i++){
        if(s.empty()) s.push(w[i]);
        else{
            if(s.top() == '(' && w[i] == ')') s.pop();
            else s.push(w[i]);
        }
    }
    if(s.empty()) return true;
    else return false;
}

string split(string w){
    if(w.size() == 0) return "";
    string u = ""; string v = "";
    int open = 0; int close = 0;
    for(int i=0;i<w.size();i++){
        if(w[i] == '(') open++;
        else if(w[i] == ')') close++;
        if(open == close && open != 0){
            for(int j=0;j<=i;j++) u.push_back(w[j]);
            for(int j=i+1;j<w.size();j++) v.push_back(w[j]);
            break;
        }
    }
//    cout << "u : " << u << endl;
//    cout << "v : " << v << endl;
    if(correct(u)) return u+split(v);
    else{
        string str = "(" + split(v) + ")";
        u.erase(u.begin()); u.pop_back();
        for(int i=0;i<u.size();i++){
            if(u[i] == '(') u[i] = ')';
            else if(u[i] == ')') u[i] = '(';
        }
        str += u;
        return str;
    }
}
string solution(string p) {
    string answer = "";
    if(correct(p)) return p;
    else return split(p);
}

int main(){
    cout << solution("()))((()") << endl;
    return 0;
}
