#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int row, col;
int road[501][501];
int cache[501][501]; //(a,b)일 때 최대 경로
int cal(int x, int y) {
	if (x < 0 || y < 0 || x >= row || y >= col) return 0;
	if (cache[x][y] != -1) return cache[x][y];
	cache[x][y] = 0;
	int &ret = cache[x][y];
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= row || ny >= col) continue;
		else {
			if (road[nx][ny] < road[x][y]) {
				ret = ret + cal(nx,ny);
			}
		}
	}
	return ret;
}
int main() {
	memset(cache, -1, sizeof(cache));
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> road[i][j];
		}
	}
	cache[row - 1][col - 1] = 1;
	cout << cal(0, 0);
	return 0;
}