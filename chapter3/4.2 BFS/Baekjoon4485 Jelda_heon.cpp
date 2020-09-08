/*2020/06/02 두번째 문제
백준4485 녹색 옷 입은 애가 젤다지?(완전탐색 + BFS)*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct state {
	int x;
	int y;
	int weight;
};
struct cmp {
	bool operator()(state a, state b) {
		return a.weight > b.weight;
	}
};
int main() {
	int index = 0;
	while (1) {
		index += 1;
		int n;
		int map[150][150];
		int dist[150][150];
		int ans = 0;
		priority_queue<state, vector<state>, cmp> q;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				dist[i][j] = INT_MAX;
			}
		}
		q.push({ 0,0,map[0][0] });
		dist[0][0] = map[0][0];
		while (!q.empty()) {
			state temp = q.top(); q.pop();
			int x = temp.x;
			int y = temp.y;
			int weight = temp.weight;
			if (x == n - 1 && y == n - 1) ans = weight;
			for (int i = 0; i < 4; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
					if (dist[next_x][next_y] > weight + map[next_x][next_y]) {
						dist[next_x][next_y] = weight + map[next_x][next_y];
						q.push({ next_x,next_y,dist[next_x][next_y] });
					}
				}
			}
		}
		cout << "Problem " << index << ": " << ans << endl;
	}
	return 0;
}