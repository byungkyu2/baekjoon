#include <iostream>
#include <vector>
using namespace std;
int N;
int visited[100001] = { 0 };
vector<int> v[100001];
int parent = 1;
void dfs(int k) {
	visited[k] = parent;
	parent = k;
	for (int i = 0; i < v[k].size(); i++) {
		if (visited[v[k][i]] != 0)continue;
		parent = k;
		dfs(v[k][i]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << visited[i] << "\n";
	}
}