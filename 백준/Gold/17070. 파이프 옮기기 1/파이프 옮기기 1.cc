#include <iostream>
using namespace std;
int N;
int arr[16][16];
int dy[3] = { 0,1,1 };//우 , 대각 , 하
int dx[3] = { 1,1,0 };
int ans;
void dfs(int y, int x, int dir) {
	if (y == N - 1 && x == N - 1) {
		ans++;
		return;
	}
	if (dir == 0 || dir == 1) {//우로 이동
		int ny = y;
		int nx = x + 1;
		if (nx < N && arr[ny][nx] == 0) {
			dfs(ny, nx, 0);
		}
	}
	if (dir == 1 || dir == 2) {//아래로 이동
		int ny = y + 1;
		int nx = x;
		if (ny < N && arr[ny][nx] == 0) {
			dfs(ny, nx, 2);
		}
	}
	//대각이동
	int ny = y + 1;
	int nx = x + 1;
	if (ny < N&&nx < N&&arr[ny][nx] == 0 && arr[y][nx] == 0 && arr[ny][x] == 0) {
		dfs(ny, nx, 1);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 1, 0);
	cout << ans;
}