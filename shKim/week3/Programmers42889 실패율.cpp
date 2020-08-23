//
//  Programmers42889 실패율.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/23.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
bool compare(const pair<int, float> &a, const pair<int, float> &b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> temp;
    for (int i = 1; i <= N; i++) {
        int all = 0;
        int no_clear = 0;
        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] >= i) {
                if (stages[j] == i) no_clear++;
                all++;
            }
        }
        if(all == 0) temp.push_back(make_pair(i,0));
        else temp.push_back(make_pair(i, (float)no_clear / (float)all));
    }
    sort(temp.begin(), temp.end(), compare);
    for (int i = 0; i < temp.size(); i++) {
        answer.push_back(temp[i].first);
    }
    return answer;
}
