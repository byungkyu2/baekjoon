#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[1000][3];
	int dp[1000][3];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	for (int i = 0; i < 3; i++) {
		dp[0][i] = arr[0][i];
	}
	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
	}
	int ans = min(dp[N - 1][0], dp[N - 1][1]);
	ans = min(ans, dp[N - 1][2]);
	cout << ans;
}