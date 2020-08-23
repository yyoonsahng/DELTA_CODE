//
//  Programmers42891 - 무지의 먹방 라이브.cpp
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
bool compare(pair<int, int>&a, pair<int, int> &b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}
int solution(vector<int> food, long long k) {
    int answer = 0;
    vector<pair<int, int>> v; //먹는시간,인덱스 2개의 값을 저장하는 배열
    for (int i = 0; i < food.size(); i++) {
        v.push_back(make_pair(food[i], i));
    }
    sort(v.begin(), v.end());
    int row = 0;
    int before = 0;
    while (row < food.size()) {
        int time = v[row].first;
        int start = row;
        while (row + 1 < food.size() && v[row + 1].first == time) row++;
        //다른 숫자가 나옴.
        int cnt = food.size() - start;
        //뺄 수 있는 ...
        if (k < (long long)(time - before) * (long long)cnt) {
            sort(v.begin() + start, v.end(), compare);
            answer = v[start + (k%cnt)].second + 1;
            break;
        }
        k -= (time - before) * cnt;
        before = time;
        row++;
    }
    return answer;
}
