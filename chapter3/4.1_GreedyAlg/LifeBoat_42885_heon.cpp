#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
bool cmp(int &a, int &b) {
	return a > b;
}
int solution(vector<int> people, int limit) {
	int answer = 0;
	vector<int> reverse = people;
	set<int> s;
	sort(people.begin(), people.end());
	sort(reverse.begin(), reverse.end(), cmp);
	int p_index = 0;
	int r_index = 0;
	bool check = false;
	for (int i = 0; i < people.size(); i++) {
		if (people[i] == -1) break;
		while (1) {
			if (people.size() - 1 - r_index <= p_index) {
				check = true;
				break;
			}
			if (people[p_index] + reverse[r_index] <= limit) {
				people[people.size() - 1 - r_index] = -1;
				people[p_index] = -1;
				p_index++;
				r_index++;
				answer++;
				break;
			}
			else r_index++;
		}
		if (check) break;
	}
	for (int i = 0; i < people.size(); i++) {
		if (people[i] != -1) answer++;
	}
	return answer;
}