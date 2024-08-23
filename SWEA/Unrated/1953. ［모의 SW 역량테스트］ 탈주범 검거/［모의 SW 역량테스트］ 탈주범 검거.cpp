#include <iostream>
#include <queue>
using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ttype[8][4] = {
{0,0,0,0},//0
{1,1,1,1},//1
{0,1,0,1},//2
{1,0,1,0},//3
{1,0,0,1},//4
{1,1,0,0},//5
{0,1,1,0},//6
{0,0,1,1}//7
};
int map[50][50];
int visited[50][50];
int T,N, M;
int R, C, L;
int ans;
struct Coord {
	int y, x;
};
void initAndinput(){
	ans = 0;
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visited[i][j] = 0;
		}
	}
}
void bfs(int y, int x, int t) {
	queue<Coord> q;
	visited[y][x] = 1;
	q.push({ y,x });
	while (!q.empty()) {
		Coord now = q.front(); q.pop();
		if (visited[now.y][now.x] == t + 1)break;
		ans++;
		for (int d = 0; d < 4; d++) {
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;//범위 밖
			if (visited[ny][nx] != 0)continue;//이미 방문한 곳
			//현재위치, 방향으로 파이프 뚤려있는지
			if (ttype[map[now.y][now.x]][d] == 0)continue;
			//다음위치, 현재 방향과 반대 방향으로 파이프 뚤려있는지
			if (ttype[map[ny][nx]][(d + 2) % 4] == 0)continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		initAndinput();
		bfs(R, C, L);
		cout << "#" << tc << " " << ans<<"\n";
	}	
}
