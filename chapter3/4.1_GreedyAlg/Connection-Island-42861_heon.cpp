//
//  프로그래머스 - 42861 - 섬 연결하기.cpp
//  백준문제풀이
//
//  Created by 김성헌 on 2020/04/28.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<memory.h>
#include<stack>
#include<set>
using namespace std;
bool visited[101];
vector<int> map[101];
bool check = false;
bool cmp(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}
void dfs(int idx, int pre) {
	visited[idx] = true;
	for (int i = 0; i < map[idx].size(); i++) {
		int next = map[idx][i];
		if (next != pre && !visited[next]) dfs(next, idx);
		else if (next != pre && visited[next]) check = true;
	}
	return;
}
int solution(int n, vector<vector<int>> cost) {
	int answer = 0;
	sort(cost.begin(), cost.end(), cmp);
	int idx = 0;
	vector<int> a;
	while (1) {
		check = false;
		memset(visited, false, sizeof(visited));
		map[cost[idx][0]].push_back(cost[idx][1]);
		map[cost[idx][1]].push_back(cost[idx][0]);
		dfs(cost[idx][0], -1);
		if (!check) {
			a.push_back(cost[idx][2]);
		}
		else {
			//cout << "has cycle" << endl;
			map[cost[idx][0]].pop_back();
			map[cost[idx][1]].pop_back();
		}
		if (a.size() == n - 1) break;
		idx++;
	}
	for (int i = 0; i < a.size(); i++) {
		answer = answer + a[i];
	}
	return answer;
}
int main() {
	//[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]
	int a = 4;
	vector<vector<int>> c;
	c.push_back({ 0,1,1 });
	c.push_back({ 0,2,2 });
	c.push_back({ 1,2,5 });
	c.push_back({ 1,3,1 });
	c.push_back({ 2,3,8 });
	cout << solution(a, c);
	return 0;
}