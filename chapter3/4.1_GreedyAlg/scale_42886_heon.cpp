#include<iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<set>
using namespace std;
int pre[10001];
int solution(vector<int> weight) {
	int answer = 0;
	vector<int> c_weight;
	c_weight.push_back(0);
	for (int i = 0; i < weight.size(); i++) {
		c_weight.push_back(weight[i]);
	}
	sort(c_weight.begin(), c_weight.end());
	pre[0] = c_weight[0];
	for (int i = 1; i < weight.size(); i++) {
		pre[i] = pre[i - 1] + c_weight[i];
		//cout << i << " " <<pre[i] << endl;
	}
	for (int i = 0; i < c_weight.size() - 1; i++) {
		if (pre[i] + 1 < c_weight[i + 1]) {
			answer = pre[i] + 1;
			break;
		}
	}
	if (answer != 0) return answer;
	else return pre[c_weight.size() - 1] + 1;
}