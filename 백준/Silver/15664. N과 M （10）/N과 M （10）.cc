#include <iostream>
#include <algorithm>
using namespace std;
int nums[8];
int ans[8];
int used[8] = { 0 };
int n, m;
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
		if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == 0)continue;
		if (used[i] == 1)continue;
		used[i] = 1;
		ans[cnt] = nums[i];
		dfs(cnt + 1);
		used[i] = 0;
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