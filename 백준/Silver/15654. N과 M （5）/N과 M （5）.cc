#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int nums[8];
int used[8] = { 0 };
int arr[8];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		arr[cnt] = nums[i];
		dfs(cnt + 1);
		used[i] = 0;
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums,nums+n);
	dfs(0);
}
