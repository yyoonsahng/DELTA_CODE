#include <string>
#include <vector>
#include<memory.h>
#include<algorithm>
#include<iostream>
using namespace std;
int cache1[1000001]; //처음 집에서 훔치는 경우
int cache2[1000001]; //안훔치는 경우
int cal(int index, vector<int>& money) {
	int &ret = cache1[index];
	if (ret != -1) return ret;
	ret = max(money[index] + cal(index-2,money), cal(index - 1, money));
	return ret;
}
int cal2(int index, vector<int>& money) {
	int &ret = cache2[index];
	if (ret != -1) return ret;
	ret = max(money[index] + cal2(index - 2, money), cal2(index - 1, money));
	return ret;
}
int solution(vector<int> money) {
	int answer = 0;
	memset(cache1,-1,sizeof(cache1));
	memset(cache2, -1, sizeof(cache2));
	cache1[0] = money[0];
	cache1[1] = money[0];
	cache2[0] = 0;
	cache2[1] = money[1];
	answer = max(cal(money.size() - 2, money),cal2(money.size() - 1, money));
	return answer;
}
int main() {
	vector<int> v;
	v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(1); v.push_back(1); v.push_back(1); v.push_back(1); v.push_back(1);
	cout << solution(v);
	return 0;
}