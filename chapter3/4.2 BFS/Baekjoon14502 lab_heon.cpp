#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M;
int map[9][9];
int copy_map[9][9];
bool visited[9][9];
int ans = -987654321;
vector<pair<int, int>> virus;
vector<pair<int, int>> comb;
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		pair<int, int> x = q.front(); q.pop();
		copy_map[x.first][x.second] = 2;
		for (int i = 0; i < 4; i++) {
			int next_x = x.first + dx[i];
			int next_y = x.second + dy[i];
			if (next_x > 0 && next_y > 0 && next_x <= N && next_y <= M) {
				if (copy_map[next_x][next_y] == 0) {
					visited[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}
void select(int x, int y) {
	if (x > N || y > M || x < 1 || y < 1) return;
	if (comb.size() == 3) {
		//cout << endl;
		int check = 0;
		for (int i = 0; i < comb.size(); i++) {
			copy_map[comb[i].first][comb[i].second] = 1;
		}// 벽세우기
		for (int i = 0; i < virus.size(); i++) {
			q.push(virus[i]);
			visited[virus[i].first][virus[i].second] = true;
		}
		bfs();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				//cout << copy_map[i][j] << " ";
				if (copy_map[i][j] == 0) check++;
				copy_map[i][j] = map[i][j];
			}
			//cout << endl;
		}//복구
		ans = max(ans, check);
		return;
	}
	for (int i = 0; i <= N; i++) {
		if (i == 0) {
			for (int j = 1; j <= M; j++) {
				if (x + i <= N && y + j <= M) {
					if (map[x + i][y + j] == 0) {
						comb.push_back(make_pair(x + i, y + j));
						select(x + i, y + j);
						comb.pop_back();
					}
				}
			}
		}
		else if (i != 0) {
			for (int j = 0; j <= M; j++) {
				if (x + i <= N && j <= M) {
					if (map[x + i][j] == 0) {
						comb.push_back(make_pair(x + i, j));
						select(x + i, j);
						comb.pop_back();
					}
				}
			}
		}

	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			if (map[i][j] == 2) virus.push_back(make_pair(i, j));
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 0) {
				comb.push_back(make_pair(i, j));
				select(i, j);
				comb.pop_back();
			}
		}
	}
	cout << ans;
	return 0;
}