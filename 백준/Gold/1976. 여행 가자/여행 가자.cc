#include <iostream>
using namespace std;
int parent[201];
int Find(int A) {
	if (parent[A] == A)return A;
	return parent[A] = Find(parent[A]);
}
void Union(int A, int B) {
	int rootA = Find(A);
	int rootB = Find(B);
	if (rootA == rootB)return;
	parent[rootB] = rootA;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	int graph[201][201];
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
		}
	}
	int route[1000];
//	int used[1001] = { 0 };
	for (int i = 0; i < M; i++) {
		cin >> route[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (graph[i][j] == 0)continue;
			Union(i, j);
		}
	}
	int flag = 0;
	int root = Find(route[0]);
	for (int i = 1; i < M; i++) {
		if (Find(route[i]) == root)continue;
		flag = 1;
	}
	if (flag == 0)cout << "YES";
	else cout << "NO";
}