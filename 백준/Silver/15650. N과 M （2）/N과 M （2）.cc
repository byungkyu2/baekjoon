#include <iostream>
using namespace std;
int n, m;
int arr[8];
int index = 0;
void dfs(int k) {
	if (index==m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] + 1 << " ";
		}
		cout << '\n';
		return;
	}
	if (k == n) {
		return;
	}
	for (int i = k; i < n; i++) {
		arr[index] = i;
		index++;
		dfs(i+1);
		index--;
	}

}
int main() {
	cin >> n >> m;
	dfs(0);
}