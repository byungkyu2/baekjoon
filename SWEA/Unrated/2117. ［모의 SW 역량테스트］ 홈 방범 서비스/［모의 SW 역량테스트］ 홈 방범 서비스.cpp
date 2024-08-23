#include <iostream>
#include <queue>
using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int T, N, M;
int ans;
int map[20][20];
int visited[20][20];
struct Edge {
	int y, x;
};
void init() {
	ans = 0;

}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++){
			cin >> map[i][j];
		}
	}
}
void visited_reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x) {
	visited[y][x] = 1;
	int k = 1;
	int cost = k * k + (k - 1)*(k - 1);
	int cnt = 0;
	queue<Edge> q;
	q.push({ y,x });
	while(!q.empty()){
		Edge now = q.front(); q.pop();
		if (visited[now.y][now.x] == k + 1) {
			cost = k * k + (k - 1)*(k - 1)-cnt*M;
			if (cost <= 0) {
				if (ans < cnt)ans = cnt;
			}
			k++;
		}
		if (map[now.y][now.x] == 1) {
			cnt++;
		}
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] != 0)continue;
			visited[ny][nx] =visited[now.y][now.x]+ 1;
			q.push({ ny,nx });
		}
	}
	cost = k * k + (k - 1)*(k - 1) - cnt * M;
	if (cost <= 0) {
		if (ans < cnt)ans = cnt;
	}
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited_reset();
				bfs(i, j);
			}
		}
		cout << "#" << tc << " " << ans<<"\n";
	}
}