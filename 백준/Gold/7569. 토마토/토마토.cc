#include<iostream>
using namespace std;
#include<queue>
int box[100][100][100];
int main() {
	int M, N, H;
	cin >> M >> N >> H;
	struct pos {
		int y, x, z;
	};
	queue<pos> q;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				cin >> box[m][n][h];
				if (box[m][n][h] == 1) {
					q.push({ m,n,h });
				}
			}
		}
	}
	int dy[6] = { 1,0,-1,0,0,0 };
	int dx[6] = { 0,1,0,-1,0,0 };
	int dz[6] = { 0,0,0,0,1,-1 };
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int d = 0; d < 6; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			int nz = now.z + dz[d];
			if (ny < 0 || ny >= M || nx < 0 || nx >= N || nz < 0 || nz >= H)continue;
			if (box[ny][nx][nz] == 0) {
				box[ny][nx][nz] = box[now.y][now.x][now.z] + 1;
				q.push({ ny,nx,nz });
			}
		}
	}
	int flag = 0;
	int ans = 1;
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (box[m][n][h] == 0)flag = 1;
				if (box[m][n][h] > ans)ans = box[m][n][h];
			}
		}
	}
	if (flag == 1)cout << -1;
	else cout << ans - 1;
}