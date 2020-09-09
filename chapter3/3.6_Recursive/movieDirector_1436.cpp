#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int digits(int num) {
	int count = 0;
	do {
		num = int(num / 10);
		count++;
	} while (num > 0);
	return count;
}
int main(){
	int n;
	unsigned long long num[100001];
	memset(num, ULLONG_MAX, sizeof(num));
	num[0] = 666;
	cin >> n;
	vector<unsigned long long> answer;
	//수열 만들기
	for (int i = 1; i <= n; i++) {
		unsigned long long Case1 = num[i - 1] + 1;
		unsigned long long Case2 = num[i - 1] * 10;
		unsigned long long Case3 = num[i - 1] + pow(10,(digits(num[i - 1])));
		unsigned long long Case4 = num[i - 1] + pow(10,(digits(num[i - 1]) - 1));
		//cout << Case1 << "\t" << Case2 << "\t" << Case3 << "\t" << Case4 << "\t" << endl;
		if (to_string(Case1).find("666")!=-1) {
			answer.push_back(Case1);
		}
		if (to_string(Case2).find("666") != -1) {
			answer.push_back(Case2);
		}
		if (to_string(Case3).find("666") != -1) {
			answer.push_back(Case3);
		}
		if (to_string(Case4).find("666") != -1) {
			answer.push_back(Case4);
		}
		sort(answer.begin(), answer.end());
		num[i] = answer[i];
		
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\t";
	}
	
	//cout << answer[n-1];
	return 0;
}