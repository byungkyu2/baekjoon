#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, M;
	struct Edge {
		int to, cost;
		bool operator<(Edge right) const {
			return (cost > right.cost);
		}
	};
	int dist[1001];
	priority_queue<Edge> pq;
	vector<Edge> v[1001];
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		dist[i] = 21e8;
	}
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
	int st, ed;
	cin >> st >> ed;
	for (int i = 0; i < v[st].size(); i++) {
		pq.push(v[st][i]);
	}
	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if (dist[now.to] <=now.cost)continue;//이미 지나간곳
		dist[now.to] = now.cost;
		for (int i = 0; i < v[now.to].size(); i++) {
			if (dist[v[now.to][i].to] < dist[now.to]+ v[now.to][i].cost)continue;
			pq.push({ v[now.to][i].to,dist[now.to] + v[now.to][i].cost });
		}
	}
	cout << dist[ed];
}