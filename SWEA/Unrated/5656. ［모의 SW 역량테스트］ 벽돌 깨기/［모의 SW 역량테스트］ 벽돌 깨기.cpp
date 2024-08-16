#include <iostream>
#include <vector>
using namespace std;
int T, N, W, H;
int map_i[15][12];
int map[15][12];
int cnt = 0;
int ans = 0;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<int> order;
int prtcnt = 0;
void input() {
	cin >> N >> W >> H;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			cin >> map_i[h][w];
		}
	}
}
void dfs(int y, int x) {
	int bomb = map[y][x];
	map[y][x] = 0;
	for (int d = 0; d < 4; d++) {
		for (int p = 1; p < bomb; p++) {
			int ny = y + dy[d] * p;
			int nx = x + dx[d] * p;
			if (ny < 0 || ny >= H || nx < 0 || nx >= W)break;
			if (map[ny][nx] == 0)continue;
			dfs(ny, nx);
		}
	}

}
void brick(int w){
	for (int h = 0; h < H; h++) {
		if (map[h][w] == 0)continue;
		dfs(h, w);
		break;
	}
}
void gravity() {
	for (int w = 0; w < W; w++) {
		int zerocnt = 0;
		for (int h = H - 1; h >= 0; h--) {
			map[h + zerocnt][w] = map[h][w];
			if (map[h][w] == 0)zerocnt++;
		}
		for (int h = 0; h < zerocnt; h++) {
			map[h][w] = 0;
		}
	}
}
void backtracking(int now) {
	if (now == N) {
		for (int h = 0; h < H; h++) {
			for (int w = 0; w < W; w++) {
				map[h][w] = map_i[h][w];
			}
		}
		for (int i = 0; i < N; i++) {
			brick(order[i]);
			gravity();
		}
		cnt = 0;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (map[y][x] == 0)continue;
				cnt++;
			}
		}

		ans = min(ans, cnt);
		return;
	}
	for (int i = 0; i < W; i++) {
		order.push_back(i);
		backtracking(now + 1);
		order.pop_back();
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		input();
		ans = W *H ;
		backtracking(0);
		cout << "#" << tc << " " << ans << "\n";
	}
}