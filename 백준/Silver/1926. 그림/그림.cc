#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;
int paper[500][500];
int visited[500][500] = { 0 };
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}
	int cnt = 0;
	int ans = 0;
	struct Node {
		int y, x;
	};
	queue<Node> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paper[i][j] == 0 || visited[i][j] == 1)continue;
			q.push({ i,j });
			visited[i][j] = 1;
			cnt++;
			int pic = 1;
			while (!q.empty()) {
				Node now = q.front();
				q.pop();
				for (int d = 0; d < 4; d++) {
					Node next = { now.y + dy[d],now.x + dx[d] };
					if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m)continue;
					if (paper[next.y][next.x] == 0)continue;
					if (visited[next.y][next.x] == 1)continue;
					q.push(next);
					visited[next.y][next.x] = 1;
					pic++;
				}
			}
			if (pic > ans)ans = pic;
		}
	}
	cout << cnt << "\n";
	cout << ans;
}