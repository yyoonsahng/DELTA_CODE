//
//  Programmers42890 - 후보키.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/23.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <string>
#include <vector>
#include<iostream>
#include<string.h>
#include<set>
using namespace std;
vector<int> comb;
vector<string> cand;
int n;
int ans = 0;
void combination(int start,int k, vector<vector<string>> relation) {
    if (comb.size() == k) {
        string temp = "";
        bool check = false;
        for (int i = 0; i < comb.size(); i++) {
            temp = temp + to_string(comb[i]);
        }
        for (int i = 0; i < cand.size(); i++) {
            /*if (temp.find(cand[i]) != string::npos) {
                check = true;
            }*/
            int count = 0;
            for (int j = 0; j < cand[i].length(); j++) {
                cout << temp << " " << cand[i][j] << endl;
                if (temp.find(to_string(cand[i][j] - 48)) != string::npos) {
                    count++;
                }
            }
            if (count == cand[i].length()) check = true;
        }
        if (!check) {
            set<string> s;
            for (int i = 0; i < relation.size(); i++) {
                string str = "";
                for (int j = 0; j < comb.size(); j++) {
                    str = str + relation[i][comb[j]] + " ";
                }
                s.insert(str);
            }
            if (s.size() == relation.size()) {
                string temp = "";
                for (int i = 0; i < comb.size(); i++) {
                    temp = temp + to_string(comb[i]);
                }
                cand.push_back(temp);
                ans++;
            }
        }
    }
    for (int i = start; i < n; i++) {
        comb.push_back(i);
        combination(i+1,k,relation);
        comb.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    n = relation[0].size();
    for (int i = 1; i <= relation[0].size(); i++) {
        combination(0,i,relation);
    }
    answer = ans;
    return answer;
}
