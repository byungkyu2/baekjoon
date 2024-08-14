#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int T, N;
int cals[4];
int used[4];
int nums[12];
int mini;
int maxi;
int ans;
void init() {
	mini = 21e8;
	maxi = -21e8;
	v.resize(0);
	for (int i = 0; i < 4; i++) {
		used[i] = 0;
	}
}
void input() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> cals[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
}
void func(int now) {
	if (now == N-1) {
		ans = nums[0];
		for (int i = 0; i < N - 1; i++) {
			if (v[i] == 0)ans = ans + nums[i + 1];
			if (v[i] == 1)ans = ans - nums[i + 1];
			if (v[i] == 2)ans = ans * nums[i + 1];
			if (v[i] == 3)ans = ans / nums[i + 1];
		}
		mini = min(mini, ans);
		maxi = max(maxi, ans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (used[i] == cals[i])continue;
		v.push_back(i);
		used[i]++;
		func(now + 1);
		used[i]--;
		v.pop_back();
	}
}
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		func(0);
		cout << "#" << tc << " " << maxi - mini<<"\n";
	}
}
