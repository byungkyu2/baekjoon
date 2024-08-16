#include <iostream>
using namespace std;
int T, N, K; //N: 맵크기 , K 공사가능깊이
int map[8][8];
int visited[8][8];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans, dis;
void dfs(int y, int x) {
	ans = max(ans, dis);
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
		if (visited[ny][nx] == 1)continue;
		if (map[y][x] <= map[ny][nx])continue;
		dis++;
		visited[ny][nx] = 1;
		dfs(ny, nx);
		visited[ny][nx] = 0;
		dis--;
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		int maxh = 0;
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				visited[i][j] = 0;
				maxh = max(maxh, map[i][j]);
			}
		}
		for (int ky = 0; ky < N; ky++) {
			for (int kx = 0; kx < N; kx++) {//공사 완전탐색
				for (int k = 0; k <= K; k++) {//공사하기
					map[ky][kx] -= k;
					for (int sy = 0; sy < N; sy++) {
						for (int sx = 0; sx < N; sx++) {//봉우리 완전탐색
							if (map[sy][sx] != maxh)continue;//가장높지않으면 x
							dis = 0;
							visited[sy][sx] = 1;
							dis++;
							dfs(sy, sx);
							dis--;
							visited[sy][sx] = 0;
						}//sx끝
					}//sy끝
					map[ky][kx] += k;
				}//공사 k끝
			}//공사 kx끝
		}//공사 ky끝
		cout << "#" << tc << " " << ans<<"\n";
	}//tc 끝

}