#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int nums[8];
int ans[8];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (cnt > 0 && ans[cnt - 1] > nums[i])continue;
		ans[cnt] = nums[i];
		dfs(cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	dfs(0);
}