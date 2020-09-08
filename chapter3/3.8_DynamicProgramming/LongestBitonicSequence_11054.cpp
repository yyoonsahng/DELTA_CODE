#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

int cache[1001][2]; //n에서 시작하는 가장 큰 부분 수열
//[n][0] => n에서 끝나는 증가수열 //[n][1] => n에서 시작하는 증가수열
int answer[1001];
vector<int> s;
int n;

int calculate(int x,bool isDown,int count,int init_x) {
	if (cache[x][0] != 0 && !isDown) return cache[x][0];
	else if (cache[x][1] != 0 && isDown) return cache[x][1];
	cache[x][0] = 1; cache[x][1] = 1;
	for (int i = x-1; i >= 0; i--) {
		if (s[x] > s[i]) {
			cache[x][0] = max(cache[x][0],1+calculate(i, false, count+1,init_x));
		}	
	}
	for (int i = x + 1; i < n; i++) {
		if (s[x] > s[i]) {
			cache[x][1] = max(cache[x][1], 1 + calculate(i, true, count + 1, init_x));
		}
	} //시작하는
	if (!isDown) return cache[x][0];
	else return cache[x][1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int element;
		cin >> element;
		s.push_back(element);
	}
	for (int i = 0; i < n; i++) {
		calculate(i, false, 1,i);
	}
	int answer = -1;
	for (int i = 0; i < n; i++) {
		answer = max(answer, cache[i][0] + cache[i][1]-1);
	}
	cout << answer;
	return 0;
}