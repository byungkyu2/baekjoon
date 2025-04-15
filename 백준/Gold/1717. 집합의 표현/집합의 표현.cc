#include <iostream>
using namespace std;

int parent[1000000];
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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int q, a, b;
		cin >> q >> a >> b;
		if(q==0){
			Union(a, b);
		}
		if (q == 1) {
			if (Find(a) == Find(b))cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}