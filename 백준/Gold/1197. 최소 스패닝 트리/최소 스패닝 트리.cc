#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
	int to, cost;
	bool operator<(Edge right) const {
		return cost > right.cost;
	}
};
int V, E;
vector<Edge> v[10001];
int visited[10001] = { 0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}
	priority_queue<Edge> pq;
	int ans = 0;
	int cnt = 0;
	pq.push({ 1,0 });
	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (visited[now.to] == 1)continue;
		visited[now.to] = 1;
		ans += now.cost;
		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];
			if (visited[next.to] == 1)continue;
			pq.push(next);
		}
	}
	cout << ans;
}