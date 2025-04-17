#include<iostream>
using namespace std;
int main() {
	int dy[4] = {-1,0,1,0};
	int dx[4] = {0,1,0,-1};
	struct Node {
		int y, x, dir;
	};
	int n, m;
	int map[50][50];
	cin >> n >> m;
	Node now;
	cin >> now.y >> now.x >> now.dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	while (true) {
		
		if (map[now.y][now.x] == 0) {
			map[now.y][now.x] = 2;
			ans++;
		}
		int flag = 0;
		for (int d= 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (map[ny][nx] == 0)flag = 1;
		}
		if (flag == 0) {
			int ny = now.y + dy[(now.dir + 2) % 4];
			int nx = now.x + dx[(now.dir + 2) % 4];
			if (map[ny][nx] == 1)break;
			now.y = ny;
			now.x = nx;
		}
		else if(flag==1){
			for (int i = 0; i < 4; i++) {
				now.dir = (now.dir + 3) % 4;
				int ny = now.y + dy[now.dir];
				int nx = now.x + dx[now.dir];
				if (map[ny][nx] == 0) {
					now.y = ny;
					now.x = nx;
					break;
				}
			}
		}
	}
	cout << ans;
}