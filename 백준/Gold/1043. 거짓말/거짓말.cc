#include <iostream>
#include <vector>
using namespace std;
int N, M;
int parent[51];
vector<int> party[50];
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
	int ans = 0;
	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	int whoknows;
	cin >> whoknows;
	for (int i = 0; i < whoknows; i++) {
		int a;
		cin >> a;
		parent[a] = 0;
	}
	for (int m = 0; m < M; m++) {
		int a;
		cin >> a;
		for (int i = 0; i < a; i++) {
			int k;
			cin >> k;
			party[m].push_back(k);
			Union(party[m][0], party[m][i]);
		}
	}
	for (int m = 0; m < M; m++) {
		if (Find(party[m][0]) != Find(parent[0]))ans++;
	}
	cout << ans;
	return 0;
}