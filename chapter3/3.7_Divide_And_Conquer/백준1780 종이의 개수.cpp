#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> paper[2188];
int answer[3]; //-1,0,1 개수 저장

void search(int x,int y,int range) {
	//cout << "방문" << x << "\t" << y << "\t"<<range <<endl;
	if (x >= n || y >= n) {
		return;
	}
	if (range == 1){// 기저사례: range가 1
		if (paper[x][y] == -1) answer[2]++;
		else answer[paper[x][y]]++;
		return;
	}
	else {
		bool isDiff = false;
		for (int i = 0; i < range; i++) {
			for (int j = 0; j < range; j++) {
				//cout << "탐색" << x+i <<"\t" << y+j << endl;
				if (paper[x][y] != paper[x+i][y+j]) {
					for (int k = 0; k < 3; k++) {
						for (int l = 0; l < 3; l++) {
							search(x + range / 3 * k, y + range / 3 * l, range / 3);
						}
					}
					isDiff = true;
					break;
				}
			}
			if (isDiff) break;

		} 
		//range 범위까지 돌았을때
		if (!isDiff) {
			if (paper[x][y] == -1) answer[2]++;
			else answer[paper[x][y]]++;
			return;
		}
		else return;
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int element;
			cin >> element;
			paper[i].push_back(element);
		}
	}
	search(0, 0, n);
	cout << answer[2] << endl;
	cout << answer[0] << endl;
	cout << answer[1];

}