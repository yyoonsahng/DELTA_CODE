#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> route) {
	int answer = 0;
	for (int i = 0; i < route.size(); i++) {
		int temp = 0;
		if (route[i][0] > route[i][1]) {
			temp = route[i][0];
			route[i][0] = route[i][1];
			route[i][1] = temp;
		}
	}
	sort(route.begin(), route.end());
	answer = 1;
	int temp = route[0][1];
	for (int i = 0; i < route.size() - 1; i++) {
		if (temp > route[i][1]) temp = route[i][1];
		if (temp < route[i + 1][0]) {
			answer += 1;
			temp = route[i + 1][1];

		}
	}
	return answer;
}