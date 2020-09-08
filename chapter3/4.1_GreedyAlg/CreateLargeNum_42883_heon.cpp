#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include<map>
using namespace std;
bool compare(pair<int, int> &a, pair<int, int> &b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
string solution(string num, int k) {
	string ans = "";
	vector<pair<int, int>> v;
	int pick;
	pick = num.length() - k;
	for (int i = 0; i < num.length(); i++) {
		v.push_back({ num[i] - '0',i });
	}
	sort(v.begin(), v.end(), compare);
	int pre = -1;
	vector<pair<int, int>> answer;
	map<int, pair<int, int>> m;
	int i = 0;
	while (1) {
		if (pick == 0) break;
		if (m.find(pick) != m.end()) {
			pre = m[pick].second;
			answer.push_back(m[pick]);
			pick--;
			continue;
		}
		if (v[i].second + pick > num.length()) {
			if (m.find(num.length() - v[i].second) == m.end()) {
				m.insert({ num.length() - v[i].second, v[i] });
			}
		}
		else {
			if (pre <= v[i].second) {
				pre = v[i].second;
				answer.push_back(v[i]);
				pick--;
			}
		}
		i++;
	}
	for (int i = 0; i < answer.size(); i++) {
		ans = ans + to_string(answer[i].first);
	}


	return ans;
}