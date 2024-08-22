#include <iostream>
using namespace std;
int main() {
	int dp[21];
	dp[0] = 0;
	dp[1] = 1;
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout<<dp[n];
}