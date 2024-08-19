#include <iostream>
#include <vector>
using namespace std;
int T, N,M;
int map[10][10];
int visited[10][10];
int island;
int dat[7][7];
int dat2[7][7];
int visited2[7];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans = 0;
vector<vector<int>> v;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}
void init() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < 7; i++) {
		visited2[i] = 0;
		for (int j = 0; j < 7; j++) {
			dat[i][j] = 0;
			dat2[i][j] = 0;
		}
	}
	island = 0;
	ans = 21e8;
}
void dfs(int y, int x, int cnt) {
	map[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
		if (map[ny][nx] == 0|| visited[ny][nx] == 1)continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, cnt);
	}

}
void dfs2(int k) {
	for (int i = 1; i <= island; i++) {
		if (dat[k][i] == 0||visited2[i]==1)continue;
		visited2[i] = 1;
		dfs2(i);
	}
}
void dfs4(int k) {
	for (int i = 1; i <= island; i++) {
		if (dat2[k][i] == 0 || visited2[i] == 1)continue;
		visited2[i] = 1;
		dfs4(i);
	}
}
void dfs3(int now) {
	if (now == island - 1) {
		for (int i = 1; i <= island; i++) {
			visited2[i] = 0;
		}
		visited2[1] = 1;
		dfs4(1);
		for (int i = 1; i <= island; i++) {
			if (visited2[i] == 0)return;
		}
		int hap = 0;
		for (int i = 0; i < v.size(); i++) {
			hap += dat[v[i][0]][v[i][1]];
		}
		if (ans > hap)ans = hap;
		return;
	}
	for (int i = 1; i <= island; i++) {
		for (int j = i; j <= island; j++) {
			if (dat[i][j] == 0||dat2[i][j]==1)continue;
			dat2[i][j] = 1;
			dat2[j][i] = 1;
			v.push_back({ i,j });
			dfs3(now + 1);
			v.pop_back();
			dat2[i][j] = 0;
			dat2[j][i] = 0;
		}
	}
}
int main() {
	init();
	input();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0 || visited[i][j] == 1)continue;
			island++;
			visited[i][j] = 1;
			dfs(i, j, island);
		}
	}
	for (int i = 0; i < N; i++) {//가로로
		int dis = 0;
		int st = -1;
		int ed;
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0)dis++;
			if (map[i][j] != 0&&st!=-1&&st!=map[i][j]) {
				ed = map[i][j];
				if (dis > 1) {
					if (dat[st][ed] == 0 || dat[st][ed] > dis) {
						dat[st][ed] = dis;
						dat[ed][st] = dis;
					}
				}
			}
			if (map[i][j] != 0) { 
				st = map[i][j];
				dis = 0;
			}
		}
	}//가로로끝
	for (int j = 0; j < M; j++) {//세로로
		int dis = 0;
		int st = -1;
		int ed;
		for (int i = 0; i <N; i++) {
			if (map[i][j] == 0)dis++;
			if (map[i][j] != 0 && st != -1 && st != map[i][j]) {
				ed = map[i][j];
				if (dis > 1) {
					if (dat[st][ed] == 0 || dat[st][ed] > dis) {
						dat[st][ed] = dis;
						dat[ed][st] = dis;
					}
				}
			}
			if (map[i][j] != 0) {
				st = map[i][j];
				dis = 0;
			}
		}
	}//세로로끝
	//연결되는지 체크
	visited2[1] = 1;
	dfs2(1);
	for (int i = 1; i <= island; i++) {
		if (visited2[i] == 0)ans = -1;
	}
	if (ans == -1) {
		cout << ans;
	}
	else {
		for (int i = 1; i <= island; i++) {
			for (int j = i; j <= island; j++) {
				if (dat[i][j] == 0)continue;
				dat2[i][j] = 1;
				dat2[j][i] = 1;
				v.push_back({ i,j });
				dfs3(1);
				dat2[i][j] = 0;
				dat2[j][i] = 0;
				v.pop_back();
			}
		}
		cout << ans;
	}
}