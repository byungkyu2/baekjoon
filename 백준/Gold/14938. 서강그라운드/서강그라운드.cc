#include <iostream>
#include <queue>
#include <vector>
struct Edge {
	int to, cost;
	bool operator<(Edge right) const {
		return cost > right.cost;
	}
};
using namespace std;

int main() {
	int n, m, r;
	int items[101];
	int ans = 0;
	vector<Edge> v[101];
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	for (int i = 0; i < r; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to,cost });
		v[to].push_back({ from,cost });
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<Edge> pq;
		int dist[101];
		int anstemp = 0;
		for (int j = 1; j <= n; j++) {
			dist[j] = 9999;
		}
		dist[i] = 0;
		pq.push({ i,0 });
		while (!pq.empty()) {
			Edge now = pq.top(); pq.pop();
			for (int k = 0; k < v[now.to].size(); k++) {
				Edge next = v[now.to][k];
				int nextcost = now.cost + next.cost;
				if (nextcost >= dist[next.to])continue;
				dist[next.to] = nextcost;
				pq.push({ next.to,nextcost });
			}
		}
		for (int i = 1; i <= n; i++) {
			//cout << dist[i];
			if (dist[i] <= m)anstemp += items[i];
		}
		//cout << "\n";
		if (ans < anstemp)ans = anstemp;
	}
	cout << ans;
}