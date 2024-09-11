#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
	int to, cost;
	bool operator<(Edge right) const {
		return (cost > right.cost);
	}
};
int main() {
	int V, E, K;
	int dist[20001];	
	vector<Edge> v[20001];
	cin >> V >> E;
	for (int i = 0; i <= V; i++) {
		dist[i] = 21e8;
	}
	cin >> K;
	dist[K] = 0;
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
	}
	priority_queue<Edge> pq;
	pq.push({ K,0 });
	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];
			int nextcost = dist[now.to] + next.cost;
			if (nextcost >= dist[next.to])continue;
			pq.push({ next.to,nextcost });
			dist[next.to] = nextcost;
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 21e8)cout << "INF\n";
		else cout << dist[i]<<"\n";
	}
}